#ifndef QBARCODE_PAYLOADQRSTRING_H
#define QBARCODE_PAYLOADQRSTRING_H

#include "qbarcode/payloads/payload.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadQrStringPrivate;
class QBAR_EXPORT PayloadQrString : public Payload
{
public:
    PayloadQrString();
    PayloadQrString(const QString &data);

    PayloadQrString(const PayloadQrString &other);
    PayloadQrString &operator=(const PayloadQrString &other);

    PayloadQrString(PayloadQrString &&other) noexcept;
    PayloadQrString &operator=(PayloadQrString &&) noexcept;

    virtual ~PayloadQrString();

public:
    void setString(const QString &data);

private:
    Q_DECLARE_PRIVATE(PayloadQrString)
};

/*****************************/
/* Qt specific methods       */
/*****************************/

QBAR_EXPORT QDebug operator<<(QDebug debug, const PayloadQrString &payload);

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

#endif // QBARCODE_PAYLOADQRSTRING_H
