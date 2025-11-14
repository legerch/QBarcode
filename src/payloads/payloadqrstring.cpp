#include "qbarcode/payloads/payloadqrstring.h"

#include "payloads/payload_priv.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::PayloadQrString
 *
 * \brief Store QrCode string data
 * \details
 * String data will be properly encoded
 * to UTF-8 datas.
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

class PayloadQrStringPrivate : public PayloadPrivate
{
    Q_DECLARE_PUBLIC(PayloadQrString)
    QBAR_DISABLE_COPY_MOVE(PayloadQrStringPrivate)

public:
    explicit PayloadQrStringPrivate(Payload *parent);
    virtual ~PayloadQrStringPrivate();

public:
    virtual std::unique_ptr<PayloadPrivate> clone(Payload *parent) const override;

protected:
    virtual BarError convert() override;

protected:
    QString m_string;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadQrStringPrivate::PayloadQrStringPrivate(Payload *parent)
    : PayloadPrivate(PayloadType::PAYLOAD_TYPE_GENERIC_STRING, parent)
{
    /* Nothing to do */
}

PayloadQrStringPrivate::~PayloadQrStringPrivate()
{
    /* Nothing to do */
}

std::unique_ptr<PayloadPrivate> PayloadQrStringPrivate::clone(Payload *parent) const
{
    /* Perform base copy */
    auto copy = std::make_unique<PayloadQrStringPrivate>(parent);
    copyBaseTo(copy.get());

    /* Copy child members */
    copy->m_string = m_string;

    return copy;
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

/*!
 * \brief Create an empty payload string.
 * \details
 * This payload will be invalid.
 *
 * \sa isValid()
 * \sa setString()
 */
PayloadQrString::PayloadQrString()
    : Payload(std::make_unique<PayloadQrStringPrivate>(this))
{
    /* Nothing to do */
}

/*!
 * \brief Allow to create a payload string from datas.
 *
 * \param[in] data
 * Payload data to use.
 *
 * \sa isValid()
 * \sa setString()
 */
PayloadQrString::PayloadQrString(const QString &data)
    : PayloadQrString()
{
    setString(data);
}

PayloadQrString::PayloadQrString(const PayloadQrString &other)
    : PayloadQrString()
{
    *this = other;
}

PayloadQrString &PayloadQrString::operator=(const PayloadQrString &other)
{
    if(this != &other){
        d_ptr = other.d_ptr->clone(this);
    }

    return *this;
}

PayloadQrString::PayloadQrString(PayloadQrString &&other) noexcept = default;
PayloadQrString &PayloadQrString::operator=(PayloadQrString &&) noexcept = default;

PayloadQrString::~PayloadQrString()
{
    /* Nothing to do */
}

/*!
 * \brief Allow to set string payload datas.
 *
 * \param[in] data
 * Payload data to use.
 */
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
