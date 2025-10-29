#ifndef QBARCODE_PAYLOADBASE_H
#define QBARCODE_PAYLOADBASE_H

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

class PayloadBasePrivate;
class QBAR_EXPORT PayloadBase
{
    QBAR_DISABLE_COPY(PayloadBase)

public:
    PayloadBase(PayloadBase &&other) noexcept;
    PayloadBase &operator=(PayloadBase &&) noexcept;

    virtual ~PayloadBase();

protected:
    explicit PayloadBase(std::unique_ptr<PayloadBasePrivate> impl);

protected:
    std::unique_ptr<PayloadBasePrivate> d_ptr;
    Q_DECLARE_PRIVATE(PayloadBase)
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

#endif // QBARCODE_PAYLOADBASE_H
