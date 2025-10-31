#include "payloadbase_priv.h"

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

PayloadBasePrivate::PayloadBasePrivate(PayloadType idType, PayloadBase *parent)
    : m_idType(idType), m_lastErr(BarError::QBAR_ERR_NO_ERROR), q_ptr(parent)
{
    /* Nothing to do */
}

PayloadBasePrivate::~PayloadBasePrivate()
{
    /* Nothing to do */
}

void PayloadBasePrivate::updateData()
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
