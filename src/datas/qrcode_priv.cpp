#include "qrcode_priv.h"

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

QrCodePrivate::QrCodePrivate(QrCode *parent)
    : BarcodePrivate(BarType::QBAR_TYPE_QRCODE, parent)
{
    /* Nothing to do */
}

QrCodePrivate::~QrCodePrivate()
{
    /* Nothing to do */
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
