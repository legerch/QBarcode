#ifndef QBARCODE_PAYLOADQRSTRING_H
#define QBARCODE_PAYLOADQRSTRING_H

#include "qbarcode/payloads/payloadbase.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadQrStringPrivate;
class QBAR_EXPORT PayloadQrString : public PayloadBase
{
    QBAR_DISABLE_COPY(PayloadQrString)

public:
    PayloadQrString();
    PayloadQrString(PayloadQrString &&other) noexcept;
    PayloadQrString &operator=(PayloadQrString &&) noexcept;

    virtual ~PayloadQrString();

private:
    Q_DECLARE_PRIVATE(PayloadQrString)
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

#endif // QBARCODE_PAYLOADQRSTRING_H
