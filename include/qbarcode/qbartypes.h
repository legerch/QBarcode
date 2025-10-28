#ifndef QBARCODE_QWLANTYPES_H
#define QBARCODE_QWLANTYPES_H

#include "qbar_global.h"

#include <QObject>
#include <QVersionNumber>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{
    Q_NAMESPACE_EXPORT(QBAR_EXPORT)

/*****************************/
/* Library types             */
/*****************************/

/*****************************/
/* Library methods           */
/*****************************/

    QBAR_EXPORT QVersionNumber getLibraryVersion();

/*****************************/
/* Qt related methods        */
/*****************************/

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)

// QHash inline enums

#endif

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_QWLANTYPES_H