#include "qbarcode/payloads/payloadqrwifi.h"

#include "payloads/payload_priv.h"

#include <QHash>
#include <QSet>

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::PayloadQrWifi
 *
 * \brief Store QrCode WIFI data
 * \details
 * Allow to easily set wifi datas of a QrCode. \n
 * All will be taking care :
 * - Escaping special characters
 * - Encoding to UTF-8
 * - Manage fields of each security type
 *
 * For reference, QrCode wifi data formatting is based on this format:
 * - https://github.com/zxing/zxing/wiki/Barcode-Contents#wi-fi-network-config-android-ios-11
 */

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

private:
    QString escapeCharsMecard(const QString &string);

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
    PayloadPrivate(PayloadType::PAYLOAD_TYPE_QR_WIFI, parent),
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
    /* Verify that mandatory fields are set */
    if(m_ssid.isEmpty()){
        return BarError::QBAR_ERR_ITEM_INVALID;
    }

    /* Create data to encode */
    // Security type + SSID
    QString strWifi = QStringLiteral("WIFI:T:%1;S:%2;").arg(
        PayloadQrWifi::securityTypeToString(m_idSecurity),
        escapeCharsMecard(m_ssid)
    );

    // Password
    if(m_idSecurity != PayloadQrWifi::SecurityType::NO_SECURITY){
        if(m_passwd.isEmpty()){
            return BarError::QBAR_ERR_ITEM_INVALID;
        }

        strWifi.append(QStringLiteral("P:%1;").arg(escapeCharsMecard(m_passwd)));
    }

    // Is it an hidden network ?
    if(m_isHidden){
        strWifi.append(QStringLiteral("H:true;"));
    }

    // End
    strWifi.append(QStringLiteral(";"));

    /* Perform UTF-8 conversion */
    m_data = strWifi.toUtf8();
    return BarError::QBAR_ERR_NO_ERROR;
}

/*!
 * \brief Allow to escape special characters of the
 * \b MeCARD format.
 *
 * \param[in] string
 * String to escape.
 *
 * \return
 * Return escaped string.
 */
QString PayloadQrWifiPrivate::escapeCharsMecard(const QString &string)
{
    /* Define characters to escape */
    static const QSet<QChar> TO_ESCAPE = {
        QChar('\\'), QChar(';'), QChar(','), QChar('"'), QChar('\''), QChar(':')
    };

    /* Recreate the string */
    QString fmt;
    for(const QChar &c : string){
        if(TO_ESCAPE.contains(c)){
            fmt.append(QChar('\\')); // Put backslash before adding the character
        }

        fmt.append(c);
    }

    return fmt;
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

/*!
 * \brief Create an empty wifi payload.
 *
 * \sa isValid()
 * \sa setSecurityType(), setSsid(), setPassword(), setIsHidden()
 */
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

/*!
 * \brief Retrieve security type.
 *
 * \return
 * Returns current security type of wifi payload.
 *
 * \sa setSecurityType()
 */
PayloadQrWifi::SecurityType PayloadQrWifi::getSecurityType() const
{
    Q_D(const PayloadQrWifi);
    return d->m_idSecurity;
}

/*!
 * \brief Retrieve SSID.
 *
 * \return
 * Returns current SSID of wifi payload.
 *
 * \sa setSsid()
 * \sa getPassword(), setPassword()
 */
QString PayloadQrWifi::getSsid() const
{
    Q_D(const PayloadQrWifi);
    return d->m_ssid;
}

/*!
 * \brief Retrieve password.
 *
 * \return
 * Returns current password of wifi payload.
 *
 * \sa setPassword()
 * \sa getSsid(), setSsid()
 */
QString PayloadQrWifi::getPassword() const
{
    Q_D(const PayloadQrWifi);
    return d->m_passwd;
}

/*!
 * \brief Do current wifi network payload is set
 * as an hidden network
 *
 * \return
 * Returns \true if network payload is hidden.
 *
 * \sa setIsHidden()
 */
bool PayloadQrWifi::isHidden() const
{
    Q_D(const PayloadQrWifi);
    return d->m_isHidden;
}

/*!
 * \brief Set security type.
 *
 * \param[in] idSecurity
 * Security ID to use.
 *
 * \sa getSecurityType()
 */
void PayloadQrWifi::setSecurityType(SecurityType idSecurity)
{
    Q_D(PayloadQrWifi);

    d->m_idSecurity = idSecurity;
    d->updateData();
}

/*!
 * \brief Set SSID.
 *
 * \param[in] ssid
 * SSID to use.
 *
 * \sa getSsid()
 * \sa setPassword(), getPassword()
 */
void PayloadQrWifi::setSsid(const QString &ssid)
{
    Q_D(PayloadQrWifi);

    d->m_ssid = ssid;
    d->updateData();
}

/*!
 * \brief Set password.
 *
 * \param[in] passwd
 * Password to use.
 *
 * \sa getPassword()
 * \sa setSsid(), getSsid()
 */
void PayloadQrWifi::setPassword(const QString &passwd)
{
    Q_D(PayloadQrWifi);

    d->m_passwd = passwd;
    d->updateData();
}

/*!
 * \brief Set network hidden status.
 *
 * \param[in] isHidden
 * Set to \c true if network is hidden.
 *
 * \sa isHidden()
 */
void PayloadQrWifi::setIsHidden(bool isHidden)
{
    Q_D(PayloadQrWifi);

    d->m_isHidden = isHidden;
    d->updateData();
}

/*!
 * \brief Use to convert security type
 * to string.
 *
 * \param[in] idSecurity
 * Security ID to convert. \n
 * If unknown, string "unknown" will be returned.
 *
 * \return
 * Returns string equivalent.
 */
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

QDebug operator<<(QDebug debug, const PayloadQrWifi &payload)
{
    QDebugStateSaver saver(debug);

    const Payload &base = payload;

    debug.nospace() << "PayloadQrWifi("
                    << "base: " << base << ", "
                    << "security-type: " << payload.getSecurityType() << ", "
                    << "ssid: '" << payload.getSsid() << "', "
                    << "passwd: '" << payload.getPassword() << "', "
                    << "is-hidden: " << payload.isHidden() << ")";
    return debug;
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
