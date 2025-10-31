#include "qbarcode/payloads/payloadbase.h"

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
/* Functions implementation  */
/*      Public Class         */
/*****************************/

PayloadBase::PayloadBase(PayloadBase &&other) noexcept = default;
PayloadBase& PayloadBase::operator=(PayloadBase &&other) noexcept = default;

PayloadBase::PayloadBase(std::unique_ptr<PayloadBasePrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

PayloadBase::~PayloadBase()
{
    /* Nothing to do */
}

bool PayloadBase::isValid() const
{
    if(d_ptr->m_lastErr != BarError::QBAR_ERR_NO_ERROR){
        return false;
    }

    return !d_ptr->m_data.isEmpty();
}

PayloadType PayloadBase::getType() const
{
    return d_ptr->m_idType;
}

QByteArray PayloadBase::getData() const
{
    return d_ptr->m_data;
}

QString PayloadBase::getString() const
{
    return QString::fromUtf8(getData());
}

void PayloadBase::clear()
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
