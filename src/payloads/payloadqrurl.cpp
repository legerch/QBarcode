#include "qbarcode/payloads/payloadqrurl.h"

#include "payloads/payload_priv.h"

#include <QDebug>

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

class PayloadQrUrlPrivate : public PayloadPrivate
{
    Q_DECLARE_PUBLIC(PayloadQrUrl)
    QBAR_DISABLE_COPY_MOVE(PayloadQrUrlPrivate)

public:
    explicit PayloadQrUrlPrivate(Payload *parent);
    virtual ~PayloadQrUrlPrivate();

public:
    virtual std::unique_ptr<PayloadPrivate> clone(Payload *parent) const override;

protected:
    virtual BarError convert() override;

protected:
    QUrl m_url;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

PayloadQrUrlPrivate::PayloadQrUrlPrivate(Payload *parent)
    : PayloadPrivate(PayloadType::PAYLOAD_TYPE_QR_URL, parent)
{
    /* Nothing to do */
}

PayloadQrUrlPrivate::~PayloadQrUrlPrivate()
{
    /* Nothing to do */
}

std::unique_ptr<PayloadPrivate> PayloadQrUrlPrivate::clone(Payload *parent) const
{
    /* Perform base copy */
    auto copy = std::make_unique<PayloadQrUrlPrivate>(parent);
    copyBaseTo(copy.get());

    /* Copy child members */
    copy->m_url = m_url;

    return copy;
}

BarError PayloadQrUrlPrivate::convert()
{
    /* Verify that URL is valid */
    if(!m_url.isValid() || m_url.isRelative()){
        return BarError::QBAR_ERR_ITEM_INVALID;
    }

    /* Perform UTF-8 conversion */
    m_data = m_url.toEncoded();
    return BarError::QBAR_ERR_NO_ERROR;
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

PayloadQrUrl::PayloadQrUrl()
    : Payload(std::make_unique<PayloadQrUrlPrivate>(this))
{
    /* Nothing to do */
}

PayloadQrUrl::PayloadQrUrl(const QUrl &url)
    : PayloadQrUrl()
{
    setUrl(url);
}

PayloadQrUrl::PayloadQrUrl(const PayloadQrUrl &other)
    : PayloadQrUrl()
{
    *this = other;
}

PayloadQrUrl &PayloadQrUrl::operator=(const PayloadQrUrl &other)
{
    if(this != &other){
        d_ptr = other.d_ptr->clone(this);
    }

    return *this;
}

PayloadQrUrl::PayloadQrUrl(PayloadQrUrl &&other) noexcept = default;
PayloadQrUrl &PayloadQrUrl::operator=(PayloadQrUrl &&) noexcept = default;

PayloadQrUrl::~PayloadQrUrl()
{
    /* Nothing to do */
}

void PayloadQrUrl::setUrl(const QUrl &url)
{
    Q_D(PayloadQrUrl);

    d->m_url = url;
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
