#include "qbarcode/datas/barcode.h"

#include "datas/barcode_priv.h"

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

Barcode::Barcode(Barcode &&other) noexcept = default;
Barcode& Barcode::operator=(Barcode &&other) noexcept = default;

Barcode::Barcode(std::unique_ptr<BarcodePrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

Barcode::~Barcode()
{
    /* Nothing to do */
}

BarType Barcode::getType() const
{
    return d_ptr->m_idType;
}

const Payload* Barcode::getPayload() const
{
    return d_ptr->m_payload.get();
}

const MatrixData &Barcode::getMatrixData() const
{
    return d_ptr->m_matrix;
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
