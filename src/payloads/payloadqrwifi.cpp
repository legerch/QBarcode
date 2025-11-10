#include "qbarcode/payloads/payloadqrwifi.h"

#include "payloads/payload_priv.h"

#include <QHash>

/*****************************/
/* Class documentations      */
/*****************************/

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Start namespace           */
/*****************************/

namespace qbar
{

/*****************************/
/* Functions definitions     */
/*      Private Class        */
/*****************************/

class PayloadQrWifiPrivate : public PayloadPrivate
{
    Q_DECLARE_PUBLIC(PayloadQrWifi)
    QBAR_DISABLE_COPY_MOVE(PayloadQrWifiPrivate)

public:
    explicit PayloadQrWifiPrivate(Payload *parent);
    virtual ~PayloadQrWifiPrivate();

public:
    virtual std::unique_ptr<PayloadPrivate> clone(Payload *parent) const override;

protected:
    virtual BarError convert() override;

protected:
    PayloadQrWifi::SecurityType m_idSecurity;
    QString m_ssid;
    QString m_passwd;
    bool m_isHidden;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadQrWifiPrivate::PayloadQrWifiPrivate(Payload *parent) :
    PayloadPrivate(PayloadType::PAYLOAD_TYPE_GENERIC_STRING, parent),
    m_idSecurity(PayloadQrWifi::SecurityType::WPA), m_isHidden(false)
{
    /* Nothing to do */
}

PayloadQrWifiPrivate::~PayloadQrWifiPrivate()
{
    /* Nothing to do */
}

std::unique_ptr<PayloadPrivate> PayloadQrWifiPrivate::clone(Payload *parent) const
{
    /* Perform base copy */
    auto copy = std::make_unique<PayloadQrWifiPrivate>(parent);
    copyBaseTo(copy.get());

    /* Copy child members */
    copy->m_idSecurity = m_idSecurity;
    copy->m_ssid = m_ssid;
    copy->m_passwd = m_passwd;
    copy->m_isHidden = m_isHidden;

    return copy;
}

BarError PayloadQrWifiPrivate::convert()
{
    //TODO: implement
    return BarError::QBAR_ERR_ITEM_INVALID;

#if 0
    /* Verify that string is valid */
    if(m_string.isEmpty()){
        return BarError::QBAR_ERR_ITEM_INVALID;
    }

    /* Perform UTF-8 conversion */
    m_data = m_string.toUtf8();
    return BarError::QBAR_ERR_NO_ERROR;
#endif
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

PayloadQrWifi::PayloadQrWifi()
    : Payload(std::make_unique<PayloadQrWifiPrivate>(this))
{
    /* Nothing to do */
}

PayloadQrWifi::PayloadQrWifi(const PayloadQrWifi &other)
    : PayloadQrWifi()
{
    *this = other;
}

PayloadQrWifi &PayloadQrWifi::operator=(const PayloadQrWifi &other)
{
    if(this != &other){
        d_ptr = other.d_ptr->clone(this);
    }

    return *this;
}

PayloadQrWifi::PayloadQrWifi(PayloadQrWifi &&other) noexcept = default;
PayloadQrWifi &PayloadQrWifi::operator=(PayloadQrWifi &&) noexcept = default;

PayloadQrWifi::~PayloadQrWifi()
{
    /* Nothing to do */
}

PayloadQrWifi::SecurityType PayloadQrWifi::getSecurityType() const
{
    Q_D(const PayloadQrWifi);
    return d->m_idSecurity;
}

QString PayloadQrWifi::getSsid() const
{
    Q_D(const PayloadQrWifi);
    return d->m_ssid;
}

QString PayloadQrWifi::getPassword() const
{
    Q_D(const PayloadQrWifi);
    return d->m_passwd;
}

bool PayloadQrWifi::isHidden() const
{
    Q_D(const PayloadQrWifi);
    return d->m_isHidden;
}

void PayloadQrWifi::setSecurityType(SecurityType idSecurity)
{
    Q_D(PayloadQrWifi);

    d->m_idSecurity = idSecurity;
    d->updateData();
}

void PayloadQrWifi::setSsid(const QString &ssid)
{
    Q_D(PayloadQrWifi);

    d->m_ssid = ssid;
    d->updateData();
}

void PayloadQrWifi::setPassword(const QString &passwd)
{
    Q_D(PayloadQrWifi);

    d->m_passwd = passwd;
    d->updateData();
}

void PayloadQrWifi::setIsHidden(bool isHidden)
{
    Q_D(PayloadQrWifi);

    d->m_isHidden = isHidden;
    d->updateData();
}

QString PayloadQrWifi::securityTypeToString(SecurityType idSecurity)
{
    static const QHash<SecurityType, QString> MAP_SEC_TO_STR =
    {
        {SecurityType::NO_SECURITY, "nopass"},
        {SecurityType::WEP, "WEP"},
        {SecurityType::WPA, "WPA"}
    };

    return MAP_SEC_TO_STR.value(idSecurity, "unknown");
}

/*****************************/
/* Qt specific methods       */
/*****************************/

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
