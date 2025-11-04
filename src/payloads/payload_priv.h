#ifndef QBARCODE_PAYLOAD_PRIV_H
#define QBARCODE_PAYLOAD_PRIV_H

#include "qbarcode/payloads/payload.h"

#include <QByteArray>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadPrivate
{
public:
    Q_DECLARE_PUBLIC(Payload)
    QBAR_DISABLE_COPY_MOVE(PayloadPrivate)

public:
    explicit PayloadPrivate(PayloadType idType, Payload *parent);
    virtual ~PayloadPrivate();

public:
    void updateData();

protected:
    void copyBaseTo(PayloadPrivate *other) const;

public:
    virtual std::unique_ptr<PayloadPrivate> clone(Payload *parent) const = 0;

protected:
    virtual BarError convert() = 0;

protected:
    PayloadType m_idType;
    QByteArray m_data;
    BarError m_lastErr;

    Payload *q_ptr = nullptr;
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

#endif // QBARCODE_PAYLOAD_PRIV_H
