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

    /*!
     * \brief List of all supported barcode types
     *
     * \sa barTypeToString()
     */
    enum class BarType
    {
        QBAR_TYPE_UNKNOWN = 0,  /**< Unknown/unsupported barcode type */

        QBAR_TYPE_QRCODE        /**< QrCode type */
    };
    Q_ENUM_NS(BarType)

    QBAR_EXPORT QString barTypeToString(BarType idType);

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
