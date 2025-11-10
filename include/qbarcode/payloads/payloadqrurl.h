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
class PayloadQrUrl : public Payload
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
    void setUrl(const QUrl &url);

private:
    Q_DECLARE_PRIVATE(PayloadQrUrl)
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

#endif // QBARCODE_PAYLOADQRURL_H
