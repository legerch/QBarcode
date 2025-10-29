#include "qbarcode/datas/qrcode.h"

#include "datas/qrcode_priv.h"

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

QrCode::QrCode()
    : Barcode(std::make_unique<QrCodePrivate>(this))
{
    /* Nothing to do */
}

QrCode::QrCode(QrCode &&other) noexcept = default;

QrCode::~QrCode()
{
    /* Nothing to do */
}

QrCode &QrCode::operator=(QrCode &&) noexcept = default;

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
