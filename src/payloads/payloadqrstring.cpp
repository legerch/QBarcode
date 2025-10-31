#include "qbarcode/payloads/payloadqrstring.h"

#include "payloads/payload_priv.h"

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

class PayloadQrStringPrivate : public PayloadPrivate
{
    Q_DECLARE_PUBLIC(PayloadQrString)
    QBAR_DISABLE_COPY_MOVE(PayloadQrStringPrivate)

protected:
    virtual BarError convert() override;

public:
    explicit PayloadQrStringPrivate(PayloadQrString *parent);
    virtual ~PayloadQrStringPrivate();

protected:
    QString m_string;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadQrStringPrivate::PayloadQrStringPrivate(PayloadQrString *parent)
    : PayloadPrivate(PayloadType::PAYLOAD_TYPE_GENERIC_STRING, parent)
{
    /* Nothing to do */
}

PayloadQrStringPrivate::~PayloadQrStringPrivate()
{
    /* Nothing to do */
}

BarError PayloadQrStringPrivate::convert()
{
    /* Verify that string is valid */
    if(m_string.isEmpty()){
        return BarError::QBAR_ERR_ITEM_INVALID;
    }

    /* Perform UTF-8 conversion */
    m_data = m_string.toUtf8();
    return BarError::QBAR_ERR_NO_ERROR;
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

PayloadQrString::PayloadQrString()
    : Payload(std::make_unique<PayloadQrStringPrivate>(this))
{
    /* Nothing to do */
}

PayloadQrString::PayloadQrString(const QString &data)
    : PayloadQrString()
{
    setString(data);
}

PayloadQrString::PayloadQrString(PayloadQrString &&other) noexcept = default;
PayloadQrString &PayloadQrString::operator=(PayloadQrString &&) noexcept = default;

PayloadQrString::~PayloadQrString()
{
    /* Nothing to do */
}

void PayloadQrString::setString(const QString &data)
{
    Q_D(PayloadQrString);

    d->m_string = data;
    d->updateData();
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
