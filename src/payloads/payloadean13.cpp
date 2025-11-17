#include "qbarcode/payloads/payloadean13.h"

#include "payloads/payload_priv.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::PayloadEan13
 *
 * \brief Store EAN-13 data
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

class PayloadEan13Private : public PayloadPrivate
{
    Q_DECLARE_PUBLIC(PayloadEan13)
    QBAR_DISABLE_COPY_MOVE(PayloadEan13Private)

public:
    explicit PayloadEan13Private(Payload *parent);
    virtual ~PayloadEan13Private();

public:
    virtual std::unique_ptr<PayloadPrivate> clone(Payload *parent) const override;

protected:
    virtual BarError convert() override;

protected:
    QString m_digits;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadEan13Private::PayloadEan13Private(Payload *parent)
    : PayloadPrivate(PayloadType::PAYLOAD_TYPE_GENERIC_STRING, parent)
{
    /* Nothing to do */
}

PayloadEan13Private::~PayloadEan13Private()
{
    /* Nothing to do */
}

std::unique_ptr<PayloadPrivate> PayloadEan13Private::clone(Payload *parent) const
{
    /* Perform base copy */
    auto copy = std::make_unique<PayloadEan13Private>(parent);
    copyBaseTo(copy.get());

    /* Copy child members */
    copy->m_digits = m_digits;

    return copy;
}

BarError PayloadEan13Private::convert()
{
    /* Verify that string is valid */
    if(m_digits.isEmpty()){
        return BarError::QBAR_ERR_ITEM_INVALID;
    }

    //TODO: implement (regex for digit only/space but perform a trim before)
    return BarError::QBAR_ERR_UNKNOWN;
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

/*!
 * \brief Create an empty EAN-13 payload.
 * \details
 * This payload will be invalid.
 *
 * \sa isValid()
 * \sa setString()
 */
PayloadEan13::PayloadEan13()
    : Payload(std::make_unique<PayloadEan13Private>(this))
{
    /* Nothing to do */
}

PayloadEan13::PayloadEan13(const PayloadEan13 &other)
    : PayloadEan13()
{
    *this = other;
}

PayloadEan13 &PayloadEan13::operator=(const PayloadEan13 &other)
{
    if(this != &other){
        d_ptr = other.d_ptr->clone(this);
    }

    return *this;
}

PayloadEan13::PayloadEan13(PayloadEan13 &&other) noexcept = default;
PayloadEan13 &PayloadEan13::operator=(PayloadEan13 &&) noexcept = default;

PayloadEan13::~PayloadEan13()
{
    /* Nothing to do */
}

/*****************************/
/* Qt specific methods       */
/*****************************/

QDebug operator<<(QDebug debug, const PayloadEan13 &payload)
{
    //TODO: implement
    QDebugStateSaver saver(debug);

    const Payload &base = payload;

    debug.nospace() << "PayloadEan13("
                    << "base: " << base << ", "
                    << "digits: '" << payload.getString() << "')";
    return debug;
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
