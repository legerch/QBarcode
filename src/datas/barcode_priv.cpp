#include "barcode_priv.h"

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

BarcodePrivate::BarcodePrivate(BarType idType, Barcode *parent)
    : m_idType(idType), q_ptr(parent)
{
    /* Nothing to do */
}

BarcodePrivate::~BarcodePrivate()
{
    /* Nothing to do */
}

void BarcodePrivate::setPayload(const Payload &payload)
{
    m_payload = std::make_unique<Payload>(payload);
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
