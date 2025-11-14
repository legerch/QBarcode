#include "qbarcode/payloads/payloadqrurl.h"

#include "payloads/payload_priv.h"

#include <QDebug>

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::PayloadQrUrl
 *
 * \brief Store QrCode URL data
 * \details
 * URL data will be properly encoded (percent
 * encoding for special characters and UTF-8 management).
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

/*!
 * \brief Create an empty payload URL.
 * \details
 * This payload will be invalid.
 *
 * \sa isValid()
 * \sa setUrl()
 */
PayloadQrUrl::PayloadQrUrl()
    : Payload(std::make_unique<PayloadQrUrlPrivate>(this))
{
    /* Nothing to do */
}

/*!
 * \brief Allow to initialize a payload URL.
 *
 * \param[in] URL
 * Payload URL to use.
 *
 * \sa isValid()
 * \sa setUrl()
 */
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

/*!
 * \brief Retrieve payload URL.
 *
 * \return
 * Returns current URL of payload.
 *
 * \sa setUrl()
 */
QUrl PayloadQrUrl::getUrl() const
{
    Q_D(const PayloadQrUrl);
    return d->m_url;
}

/*!
 * \brief Allow to set payload URL.
 *
 * \param[in] URL
 * Payload URL to use.
 *
 * \sa getUrl()
 */
void PayloadQrUrl::setUrl(const QUrl &url)
{
    Q_D(PayloadQrUrl);

    d->m_url = url;
    d->updateData();
}

/*****************************/
/* Qt specific methods       */
/*****************************/

QDebug operator<<(QDebug debug, const PayloadQrUrl &payload)
{
    QDebugStateSaver saver(debug);

    const Payload &base = payload;

    debug.nospace() << "PayloadQrUrl("
                    << "base: " << base << ", "
                    << "url: " << payload.getUrl() << ")";
    return debug;
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
