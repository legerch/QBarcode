#include "gtest/gtest.h"

#include "helpers/testsutils.h"

#include "qbarcode/datas/qrcode.h"
#include "qbarcode/renderers/rendererqrcode.h"

#define TST_QR_EXPORT_IMGS  0

struct QrCodeData
{
    qbar::Payload inPayload;
    qbar::QrLevelEcc inLvl;

    bool isValid;
    int expVersion;
};

class QrCodeTest : public testing::Test
{
protected:
    using IdQrLvl = qbar::QrLevelEcc;

protected:
    void SetUp() override
    {
        m_renderer.setSizeRequested(QSize(200, 200));
        m_renderer.setMargins(QMargins(0, 0, 0, 0));
        m_renderer.setColorBackground(Qt::white);
        m_renderer.setColorForeground(Qt::black);
    }

protected:
    void create(const QrCodeData &data)
    {
        m_qr = qbar::QrCode::create(data.inPayload, data.inLvl);
        ASSERT_EQ(m_qr.isValid(), data.isValid);
        if(!m_qr.isValid()){
            return;
        }

        /* Verify its properties */
        EXPECT_EQ(m_qr.getType(), qbar::BarType::QBAR_TYPE_QRCODE);
        EXPECT_EQ(m_qr.getIdLevelEcc(), data.inLvl);
        EXPECT_EQ(m_qr.getVersion(), data.expVersion);
    }

    void render(const QString &expFile)
    {
        /* Create image */
        const QImage imgRes = m_renderer.toImage(m_qr);
        const bool isInvalid = expFile.isEmpty();

        ASSERT_EQ(isInvalid, imgRes.isNull());
        if(isInvalid){
            return;
        }

        /* Export result image (useful for debugging) */
        const QFileInfo pathImgExp = TestsUtils::getPathRsc(expFile);
#if TST_QR_EXPORT_IMGS
        const QFileInfo pathImgRes = TestsUtils::getPathRscCustom(pathImgExp, pathImgExp.baseName() + "_out");
        EXPECT_TRUE(imgRes.save(pathImgRes.absoluteFilePath()));
#endif

        /* Load expected image */
        const QImage imgExp(pathImgExp.absoluteFilePath());
        ASSERT_FALSE(imgExp.isNull());

        ASSERT_EQ(imgRes, imgExp);
    }

protected:
    qbar::QrCode m_qr;
    qbar::RendererQrCode m_renderer;
};

TEST_F(QrCodeTest, generateInvalid)
{
    const QrCodeData data = {
        .inPayload = qbar::PayloadQrWifi(),
        .inLvl = IdQrLvl::QR_ECC_LOW, .isValid = false, .expVersion = 1
    };

    create(data);
    render(""); // Also verify that no rendering is done if invalid
}

TEST_F(QrCodeTest, generateValidLow)
{
    const QrCodeData data = {
        .inPayload = TestsUtils::createPayloadWifi(IdWifiSec::WPA, "My Custom Network", "my very complicated password", false),
        .inLvl = IdQrLvl::QR_ECC_LOW, .isValid = true, .expVersion = 4
    };

    create(data);
    render("qrcodes/qr_wifi_low.png");
}

TEST_F(QrCodeTest, generateValidHigh)
{
    /* Verify creation */
    const QrCodeData data = {
        .inPayload = TestsUtils::createPayloadWifi(IdWifiSec::WPA, "My Custom Network", "my very complicated password", false),
        .inLvl = IdQrLvl::QR_ECC_HIGH, .isValid = true, .expVersion = 7
    };

    create(data);
    render("qrcodes/qr_wifi_high.png");

    /* Verify valid rendering */
    m_renderer.setMargins(QMargins(10, 0, 10, 0));
    render("qrcodes/qr_wifi_high_margin-L10-R10-T0-B0.png");

    m_renderer.setMargins(QMargins(10, 10, 10, 10));
    render("qrcodes/qr_wifi_high_margin-L10-R10-T10-B10.png");

    m_renderer.setMargins(QMargins(20, 5, 15, 10));
    m_renderer.setColorForeground(qRgb(28, 113, 216));
    render("qrcodes/qr_wifi_high_margin-L20-R15-T5-B10_fg-blue.png");

    /* Verify invalid rendering */
    m_renderer.setSizeRequested(QSize(40, 40)); // In version 7, matrix size is 45x45
    m_renderer.setMargins(QMargins(0, 0, 0, 0));
    render("");
}
