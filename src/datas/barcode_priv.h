#ifndef QBARCODE_BARCODE_PRIV_H
#define QBARCODE_BARCODE_PRIV_H

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
    explicit BarcodePrivate(BarType idType, Barcode *parent);
    virtual ~BarcodePrivate();

protected:
    void setPayload(const Payload &payload);

protected:
    BarType m_idType;
    std::unique_ptr<Payload> m_payload;
    MatrixData m_matrix;

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

#endif // QBARCODE_BARCODE_PRIV_H
