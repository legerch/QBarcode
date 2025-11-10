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
    QrCode &operator=(QrCode &&) noexcept;

    virtual ~QrCode();

public:
    QrLevelEcc getIdLevelEcc() const;
    int getVersion() const;

public:
    virtual QSizeF getRatio() const override;

private:
    Q_DECLARE_PRIVATE(QrCode)

public:
    static constexpr int VERSION_MIN = 1;
    static constexpr int VERSION_MAX = 40;

public:
    static QrCode create(const Payload &payload, QrLevelEcc idLevel);
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
