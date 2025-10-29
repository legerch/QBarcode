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

Barcode::Barcode()
    : d_ptr(std::make_unique<BarcodePrivate>(this))
{
    /* Nothing to do */
}

Barcode::Barcode(Barcode &&other) noexcept = default;

Barcode::Barcode(std::unique_ptr<BarcodePrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

Barcode::~Barcode()
{
    /* Nothing to do */
}

Barcode& Barcode::operator=(Barcode &&other) noexcept = default;

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
