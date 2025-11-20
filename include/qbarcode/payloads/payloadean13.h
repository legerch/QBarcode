#ifndef QBARCODE_PAYLOADEAN13_H
#define QBARCODE_PAYLOADEAN13_H

#include "qbarcode/payloads/payload.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadEan13Private;
class QBAR_EXPORT PayloadEan13 : public Payload
{
public:
    PayloadEan13();
    PayloadEan13(const QString &digits);

    PayloadEan13(const PayloadEan13 &other);
    PayloadEan13 &operator=(const PayloadEan13 &other);

    PayloadEan13(PayloadEan13 &&other) noexcept;
    PayloadEan13 &operator=(PayloadEan13 &&) noexcept;

    virtual ~PayloadEan13();

public:
    QString getDigits() const;

public:
    void setDigits(const QString &digits);

private:
    Q_DECLARE_PRIVATE(PayloadEan13)
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

Q_DECLARE_METATYPE(qbar::PayloadEan13)

#endif // QBARCODE_PAYLOADEAN13_H
