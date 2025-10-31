#include "qbarcode/payloads/payload.h"

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
/* Functions implementation  */
/*      Public Class         */
/*****************************/

Payload::Payload(const Payload &other)
{
    d_ptr = other.d_ptr->clone(this);
}

Payload &Payload::operator=(const Payload &other)
{
    if(this != &other){
        d_ptr = other.d_ptr->clone(this);
    }

    return *this;
}

Payload::Payload(Payload &&other) noexcept = default;
Payload& Payload::operator=(Payload &&other) noexcept = default;

Payload::Payload(std::unique_ptr<PayloadPrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

Payload::~Payload()
{
    /* Nothing to do */
}

bool Payload::isValid() const
{
    if(d_ptr->m_lastErr != BarError::QBAR_ERR_NO_ERROR){
        return false;
    }

    return !d_ptr->m_data.isEmpty();
}

PayloadType Payload::getType() const
{
    return d_ptr->m_idType;
}

QByteArray Payload::getData() const
{
    return d_ptr->m_data;
}

QString Payload::getString() const
{
    return QString::fromUtf8(getData());
}

void Payload::clear()
{
    d_ptr->m_data.clear();
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
