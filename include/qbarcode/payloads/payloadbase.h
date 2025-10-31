#ifndef QBARCODE_PAYLOADBASE_H
#define QBARCODE_PAYLOADBASE_H

#include "qbarcode/qbartypes.h"
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

public:
    bool isValid() const;
    PayloadType getType() const;

    QByteArray getData() const;
    QString getString() const;

public:
    void clear();

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
