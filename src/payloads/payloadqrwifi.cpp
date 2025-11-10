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
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadQrWifiPrivate::PayloadQrWifiPrivate(Payload *parent)
    : PayloadPrivate(PayloadType::PAYLOAD_TYPE_GENERIC_STRING, parent)
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
    //TODO: set
    //copy->m_string = m_string;

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
