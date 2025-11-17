#ifndef QBARCODE_BACKEND_QRCODEUTILS_H
#define QBARCODE_BACKEND_QRCODEUTILS_H

#include "qbarcode/qbartypes.h"

#include "qrencode.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar::utils::qrc
{
    Q_NAMESPACE

    QRecLevel convertLevelEccToApi(QrLevelEcc idLevel);

/*****************************/
/* Qt specific methods       */
/*****************************/

/*****************************/
/* Alias for related types   */
/*****************************/

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar::utils::qrc

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_BACKEND_QRCODEUTILS_H
