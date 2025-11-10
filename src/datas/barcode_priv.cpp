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

BarError BarcodePrivate::compute()
{
    /* Verify that payload is valid */
    if(!m_payload->isValid()){
        const BarError idErr = m_payload->getLastError();
        qCritical("Unable to compute barcode, invalid payload [id-err: %d, string: '%s']", QBAR_E2I(idErr), qUtf8Printable(m_payload->getString()));
        return idErr;
    }

    /* Generate data matrix */
    return generateMatrix();
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
