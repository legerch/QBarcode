#ifndef QBARCODE_PAYLOAD_H
#define QBARCODE_PAYLOAD_H

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

class PayloadPrivate;
class QBAR_EXPORT Payload
{
    QBAR_DISABLE_COPY(Payload)

public:
    Payload(Payload &&other) noexcept;
    Payload &operator=(Payload &&) noexcept;

    virtual ~Payload();

protected:
    explicit Payload(std::unique_ptr<PayloadPrivate> impl);

public:
    bool isValid() const;
    PayloadType getType() const;

    QByteArray getData() const;
    QString getString() const;

public:
    void clear();

protected:
    std::unique_ptr<PayloadPrivate> d_ptr;
    Q_DECLARE_PRIVATE(Payload)
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

#endif // QBARCODE_PAYLOAD_H
