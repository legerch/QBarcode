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
