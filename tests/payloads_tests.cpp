#include "gtest/gtest.h"

#include "qbarcode/payloads/payloadqrstring.h"
#include "qbarcode/payloads/payloadqrurl.h"
#include "qbarcode/payloads/payloadqrwifi.h"

struct DataPayload
{
    qbar::Payload input;

    bool isValid;
    QByteArray data;
};

class PayloadTest : public testing::Test
{
protected:
    using ListDatas = QVector<DataPayload>;
    using IdWifiSec = qbar::PayloadQrWifi::SecurityType;

protected:
    void validate(const ListDatas &listItems)
    {
        for(auto it = listItems.cbegin(); it != listItems.cend(); ++it)
        {
            const qbar::Payload &payload = it->input;

            ASSERT_EQ(payload.isValid(), it->isValid);
            if(it->isValid){
                ASSERT_EQ(payload.getData(), it->data);
            }
        }
    }

    qbar::PayloadQrWifi createPayloadWifi(IdWifiSec idSec, const QString &ssid, const QString &passwd, bool isHidden)
    {
        qbar::PayloadQrWifi payload;

        payload.setSecurityType(idSec);
        payload.setSsid(ssid);
        payload.setPassword(passwd);
        payload.setIsHidden(isHidden);

        return payload;
    }
};

TEST_F(PayloadTest, validateQrString)
{
    const ListDatas lists = {
        {.input = qbar::PayloadQrString(""), .isValid = false, .data = ""},
        {.input = qbar::PayloadQrString("azerty"), .isValid = true, .data = "azerty"},
        {.input = qbar::PayloadQrString("La fenêtre spéciale coûte 1 299$, soit 80.57%"), .isValid = true, .data = "La fenêtre spéciale coûte 1 299$, soit 80.57%"}
    };

    validate(lists);
}

TEST_F(PayloadTest, validateQrUrl)
{
    const ListDatas lists = {
        {.input = qbar::PayloadQrUrl(QUrl("")), .isValid = false, .data = ""},
        {.input = qbar::PayloadQrUrl(QUrl("azerty")), .isValid = false, .data = ""},
        {.input = qbar::PayloadQrUrl(QUrl("my/file")), .isValid = false, .data = ""},

        {.input = qbar::PayloadQrUrl(QUrl("https://www.google.com/")), .isValid = true, .data = "https://www.google.com/"},
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/alpha beta")), .isValid = true, .data = "https://example.com/alpha%20beta"},
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/?q=a&b=c")), .isValid = true, .data = "https://example.com/?q=a&b=c"}, // Characters "? = &" are valid
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/hello<>")), .isValid = true, .data = "https://example.com/hello%3C%3E"},
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/hello world/€ price")), .isValid = true, .data = "https://example.com/hello%20world/%E2%82%AC%20price"},
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/ümlaut")), .isValid = true, .data = "https://example.com/%C3%BCmlaut"}, // Manage special chars (UTF-8)
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/👍/file")), .isValid = true, .data = "https://example.com/%F0%9F%91%8D/file"},
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/search?q=10% increase")), .isValid = true, .data = "https://example.com/search?q=10%25%20increase"},
        {.input = qbar::PayloadQrUrl(QUrl("https://example.com/file%20name.txt")), .isValid = true, .data = "https://example.com/file%20name.txt"}, // Input datas already encoded*/
    };

    validate(lists);
}

TEST_F(PayloadTest, validateQrWifi)
{
    const ListDatas lists = {
        {.input = createPayloadWifi(IdWifiSec::NB_SECURITY_TYPE, "", "", false), .isValid = false, .data = ""},

        {.input = createPayloadWifi(IdWifiSec::NO_SECURITY, "", "", false), .isValid = false, .data = ""},
        {.input = createPayloadWifi(IdWifiSec::NO_SECURITY, "Open Network", "", false), .isValid = true, .data = "WIFI:T:nopass;S:Open Network;;"},
        {.input = createPayloadWifi(IdWifiSec::NO_SECURITY, "Open Network", "A password", true), .isValid = true, .data = "WIFI:T:nopass;S:Open Network;H:true;;"},

        {.input = createPayloadWifi(IdWifiSec::WEP, "", "", false), .isValid = false, .data = ""},
        {.input = createPayloadWifi(IdWifiSec::WEP, "My wep network", "", false), .isValid = false, .data = ""},
        {.input = createPayloadWifi(IdWifiSec::WEP, "My wep network", "A password", true), .isValid = true, .data = "WIFI:T:WEP;S:My wep network;P:A password;H:true;;"},

        {.input = createPayloadWifi(IdWifiSec::WPA, "", "", false), .isValid = false, .data = ""},
        {.input = createPayloadWifi(IdWifiSec::WPA, "My WPA network", "", false), .isValid = false, .data = ""},
        {.input = createPayloadWifi(IdWifiSec::WPA, R"(My;complicated:net foo:bar\baz)", R"(p"ass:and ;try)", true), .isValid = true, .data = R"(WIFI:T:WPA;S:My\;complicated\:net foo\:bar\\baz;P:p\"ass\:and \;try;H:true;;)"},
        {.input = createPayloadWifi(IdWifiSec::WPA, R"($péçiàl ñ€ẗẅôяж)", R"(фд55ωõʀd)", false), .isValid = true, .data = R"(WIFI:T:WPA;S:$péçiàl ñ€ẗẅôяж;P:фд55ωõʀd;;)"},
    };

    validate(lists);
}
