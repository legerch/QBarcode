#ifndef QBARCODE_BARCODE_H
#define QBARCODE_BARCODE_H

#include "qbarcode/qbar_global.h"
#include <memory>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class BarcodePrivate;
class QBAR_EXPORT Barcode
{
    QBAR_DISABLE_COPY(Barcode)

public:
    Barcode();
    Barcode(Barcode &&other) noexcept;

    virtual ~Barcode();

protected:
    explicit Barcode(BarcodePrivate *impl);

public:
    Barcode &operator=(Barcode &&) noexcept;

protected:
    std::unique_ptr<BarcodePrivate> d_ptr;
    Q_DECLARE_PRIVATE(Barcode)
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

#endif // QBARCODE_BARCODE_H
