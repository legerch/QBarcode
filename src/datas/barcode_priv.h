#ifndef QBARCODEBARCODE_PRIV_H
#define QBARCODEBARCODE_PRIV_H

#include "qbarcode/datas/barcode.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class BarcodePrivate
{
    Q_DECLARE_PUBLIC(Barcode)
    QBAR_DISABLE_COPY_MOVE(BarcodePrivate)

public:
    explicit BarcodePrivate(Barcode *parent);
    virtual ~BarcodePrivate();

protected:
    Barcode *q_ptr = nullptr;
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

#endif // QBARCODEBARCODE_PRIV_H
