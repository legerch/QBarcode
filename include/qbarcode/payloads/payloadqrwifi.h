#ifndef QBARCODE_PAYLOADQRWIFI_H
#define QBARCODE_PAYLOADQRWIFI_H

#include "qbarcode/payloads/payload.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadQrWifiPrivate;
class QBAR_EXPORT PayloadQrWifi : public Payload
{
public:
    enum class SecurityType
    {
        NO_SECURITY = 0,
        WEP,
        WPA,
    };
    Q_ENUM(SecurityType);

public:
    PayloadQrWifi();

    PayloadQrWifi(const PayloadQrWifi &other);
    PayloadQrWifi &operator=(const PayloadQrWifi &other);

    PayloadQrWifi(PayloadQrWifi &&other) noexcept;
    PayloadQrWifi &operator=(PayloadQrWifi &&) noexcept;

    virtual ~PayloadQrWifi();

public:
    static QString securityTypeToString(SecurityType idSecurity);

private:
    Q_DECLARE_PRIVATE(PayloadQrWifi)
};

/*****************************/
/* Qt specific methods       */
/*****************************/

/*****************************/
/* Alias for related types   */
/*****************************/

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_PAYLOADQRWIFI_H
