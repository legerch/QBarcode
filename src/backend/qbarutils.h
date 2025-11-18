#ifndef QBARCODE_BACKEND_QBARUTILS_H
#define QBARCODE_BACKEND_QBARUTILS_H

#include <QObject>
#include <QString>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar::utils
{
    Q_NAMESPACE

    bool stringIsDigits(const QString &string);
    QString stringDigitsOnly(const QString &string);
    QString stringRemoveSpaces(const QString &string);

/*****************************/
/* Qt specific methods       */
/*****************************/

/*****************************/
/* Alias for related types   */
/*****************************/

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar::utils

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_BACKEND_QBARUTILS_H
