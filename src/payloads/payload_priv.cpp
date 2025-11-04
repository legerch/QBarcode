#include "payload_priv.h"

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
/*****************************/

PayloadPrivate::PayloadPrivate(PayloadType idType, Payload *parent)
    : m_idType(idType), m_lastErr(BarError::QBAR_ERR_NO_ERROR), q_ptr(parent)
{
    /* Nothing to do */
}

PayloadPrivate::~PayloadPrivate()
{
    /* Nothing to do */
}

void PayloadPrivate::updateData()
{
    m_lastErr = convert();
    if(m_lastErr != BarError::QBAR_ERR_NO_ERROR){
        q_ptr->clear();
    }
}

void PayloadPrivate::copyBaseTo(PayloadPrivate *other) const
{
    other->m_idType = m_idType;
    other->m_data = m_data;
    other->m_lastErr = m_lastErr;
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
