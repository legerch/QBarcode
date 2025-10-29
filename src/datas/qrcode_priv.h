#ifndef QBARCODE_QRCODE_PRIV_H
#define QBARCODE_QRCODE_PRIV_H

#include "datas/barcode_priv.h"
#include "qbarcode/datas/qrcode.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
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
/* Qt specific methods       */
/*****************************/

/*****************************/
/* Alias for related types   */
/*****************************/

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_QRCODE_PRIV_H
