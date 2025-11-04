#ifndef QBARCODE_BACKEND_TYPESQRENCODE_H
#define QBARCODE_BACKEND_TYPESQRENCODE_H

#include "qbarcode/qbartypes.h"

#include "qrencode.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar::libqrencode
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

} // namespace qbar

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_BACKEND_TYPESQRENCODE_H
