#ifndef QBARCODE_PAYLOADBASE_PRIV_H
#define QBARCODE_PAYLOADBASE_PRIV_H

#include "qbarcode/payloads/payloadbase.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadBasePrivate
{
public:
    Q_DECLARE_PUBLIC(PayloadBase)
    QBAR_DISABLE_COPY_MOVE(PayloadBasePrivate)

public:
    explicit PayloadBasePrivate(PayloadBase *parent);
    virtual ~PayloadBasePrivate();

protected:
    PayloadBase *q_ptr = nullptr;
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

#endif // QBARCODE_PAYLOADBASE_PRIV_H
