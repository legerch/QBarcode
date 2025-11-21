#ifndef QBARCODE_BACKEND_EANUTILS_H
#define QBARCODE_BACKEND_EANUTILS_H

#include "qbarcode/qbartypes.h"

#include <QObject>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar::utils::ean
{
    Q_NAMESPACE

    BarError encodeData(const QString &digits, int nbDigits, QByteArray &data);
    int calcCheckDigit(const QString &digits);

/*****************************/
/* Qt specific methods       */
/*****************************/

/*****************************/
/* Alias for related types   */
/*****************************/

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar::utils::ean

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_BACKEND_EANUTILS_H
