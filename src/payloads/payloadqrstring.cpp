#include "qbarcode/payloads/payloadqrstring.h"

#include "payloads/payloadbase_priv.h"

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

class PayloadQrStringPrivate : public PayloadBasePrivate
{
    Q_DECLARE_PUBLIC(PayloadQrString)
    QBAR_DISABLE_COPY_MOVE(PayloadQrStringPrivate)

public:
    explicit PayloadQrStringPrivate(PayloadQrString *parent);
    virtual ~PayloadQrStringPrivate();
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadQrStringPrivate::PayloadQrStringPrivate(PayloadQrString *parent)
    : PayloadBasePrivate(parent)
{
    /* Nothing to do */
}

PayloadQrStringPrivate::~PayloadQrStringPrivate()
{
    /* Nothing to do */
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

PayloadQrString::PayloadQrString()
    : PayloadBase(std::make_unique<PayloadQrStringPrivate>(this))
{
    /* Nothing to do */
}

PayloadQrString::PayloadQrString(PayloadQrString &&other) noexcept = default;
PayloadQrString &PayloadQrString::operator=(PayloadQrString &&) noexcept = default;

PayloadQrString::~PayloadQrString()
{
    /* Nothing to do */
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
