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

bool Barcode::isValid() const
{
    /* Verify supported type */
    if(d_ptr->m_idType == BarType::QBAR_TYPE_UNKNOWN){
        return false;
    }

    return d_ptr->m_matrix.getNbElements() > 0;
}

BarType Barcode::getType() const
{
    return d_ptr->m_idType;
}

const Payload* Barcode::getPayload() const
{
    return d_ptr->m_payload.get();
}

QSize Barcode::getSize() const
{
    return d_ptr->m_matrix.getSize();
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
