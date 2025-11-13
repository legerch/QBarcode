#include "qbarcode/payloads/payload.h"

#include "payloads/payload_priv.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::Payload
 *
 * \brief Store data of a Barcode
 * \details
 * This class allow to share common properties/methods accross
 * all kinds of payload types. \n
 * This is this class that is responsible to properly \b encode
 * datas.
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

/*!
 * \brief Allow to verify if a payload is valid
 * \details
 * A payload is considered valid if:
 * - It contains data
 * - Encoding operation succeed.
 *
 * \return
 * Returns \c true if valid.
 */
bool Payload::isValid() const
{
    if(d_ptr->m_lastErr != BarError::QBAR_ERR_NO_ERROR){
        return false;
    }

    return !d_ptr->m_data.isEmpty();
}

/*!
 * \brief Get payload type
 * \details
 * Useful to properly cast a \c Payload
 * instance to its "real" type.
 *
 * \return
 * Returns type of the payload.
 */
PayloadType Payload::getType() const
{
    return d_ptr->m_idType;
}

/*!
 * \brief Retrieve encoded data as bytes array.
 * \return
 * Returns bytes array data.
 *
 * \sa getString()
 */
QByteArray Payload::getData() const
{
    return d_ptr->m_data;
}

/*!
 * \brief Retrieve encoded data as string.
 * \return
 * Returns UTF-8 string data.
 *
 * \sa getData()
 */
QString Payload::getString() const
{
    return QString::fromUtf8(getData());
}

/*!
 * \brief Retrieve last error
 * \details
 * Can be useful if after setting a payload, it
 * becomes invalid, this method allow to retrieve
 * the associated error.
 *
 * \return
 * Returns latest error.
 */
BarError Payload::getLastError() const
{
    return d_ptr->m_lastErr;
}

/*!
 * \brief Clear payload content.
 * \details
 * Payload data content will be cleared,
 * latest error will be preserved.
 *
 * \sa getData(), getLastError()
 */
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
