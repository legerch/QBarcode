#ifndef QBARCODE_QRCODE_H
#define QBARCODE_QRCODE_H

#include "qbarcode/datas/barcode.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class QrCodePrivate;
class QBAR_EXPORT QrCode : public Barcode
{
    QBAR_DISABLE_COPY(QrCode)

public:
    QrCode();
    QrCode(QrCode &&other) noexcept;

    virtual ~QrCode();

public:
    QrCode &operator=(QrCode &&) noexcept;

private:
    Q_DECLARE_PRIVATE(QrCode)
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

#endif // QBARCODE_QRCODE_H
