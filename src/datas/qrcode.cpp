#include "qbarcode/datas/qrcode.h"

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
/* Functions definitions     */
/*      Private Class        */
/*****************************/

class QrCodePrivate : public BarcodePrivate
{
    Q_DECLARE_PUBLIC(QrCode)
    QBAR_DISABLE_COPY_MOVE(QrCodePrivate)

public:
    explicit QrCodePrivate(QrCode *parent);
    virtual ~QrCodePrivate();
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
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
/* Functions implementation  */
/*      Public Class         */
/*****************************/

QrCode::QrCode()
    : Barcode(std::make_unique<QrCodePrivate>(this))
{
    /* Nothing to do */
}

QrCode::QrCode(QrCode &&other) noexcept = default;
QrCode &QrCode::operator=(QrCode &&) noexcept = default;

QrCode::~QrCode()
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
