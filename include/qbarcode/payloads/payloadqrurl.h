#ifndef QBARCODE_PAYLOADQRURL_H
#define QBARCODE_PAYLOADQRURL_H

#include "qbarcode/payloads/payload.h"

#include <QUrl>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class PayloadQrUrlPrivate;
class QBAR_EXPORT PayloadQrUrl : public Payload
{
public:
    PayloadQrUrl();
    PayloadQrUrl(const QUrl &url);

    PayloadQrUrl(const PayloadQrUrl &other);
    PayloadQrUrl &operator=(const PayloadQrUrl &other);

    PayloadQrUrl(PayloadQrUrl &&other) noexcept;
    PayloadQrUrl &operator=(PayloadQrUrl &&) noexcept;

    virtual ~PayloadQrUrl();

public:
    QUrl getUrl() const;

public:
    void setUrl(const QUrl &url);

private:
    Q_DECLARE_PRIVATE(PayloadQrUrl)
};

/*****************************/
/* Qt specific methods       */
/*****************************/

QBAR_EXPORT QDebug operator<<(QDebug debug, const PayloadQrUrl &payload);

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

Q_DECLARE_METATYPE(qbar::PayloadQrUrl)

#endif // QBARCODE_PAYLOADQRURL_H
