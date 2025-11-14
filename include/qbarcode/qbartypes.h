#ifndef QBARCODE_QWLANTYPES_H
#define QBARCODE_QWLANTYPES_H

#include "qbar_global.h"
#include "tools/array2d.h"

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
     * \brief Contains barcode matrix data
     * \details
     * Allow to store matrix modules of a barcode
     *
     * \sa Barcode::getMatrixData()
     */
    using MatrixData = Array2D<uint8_t>;

/*****************************/
/* Library enums             */
/*****************************/

    /*!
     * \brief List of all barcode related errors
     *
     * \sa barErrorToString()
     */
    enum class BarError
    {
        QBAR_ERR_NO_ERROR = 0,  /**< No error, operation succeed */
        QBAR_ERR_UNKNOWN,       /**< Unknown error */

        QBAR_ERR_ITEM_INVALID   /**< Operation cannot be performed due to an invalid item */
    };
    Q_ENUM_NS(BarError)

    QBAR_EXPORT QString barErrorToString(BarError idErr);

    /*!
     * \brief List of all supported barcode types
     *
     * \sa barTypeToString()
     */
    enum class BarType
    {
        QBAR_TYPE_UNKNOWN = 0,  /**< Unknown/unsupported barcode type */

        QBAR_TYPE_QRCODE,       /**< QrCode type */

        QBAR_TYPE_NB            /**< Number of supporter barcode types */
    };
    Q_ENUM_NS(BarType)

    QBAR_EXPORT QString barTypeToString(BarType idType);

    /*!
     * \brief List of all types of payload
     *
     * \sa payloadTypeToString()
     */
    enum class PayloadType
    {
        PAYLOAD_TYPE_GENERIC_STRING = 0,    /**< Payload containing a string */

        PAYLOAD_TYPE_QR_URL,                /**< Payload containing QrCode formatted URL datas */
        PAYLOAD_TYPE_QR_WIFI,               /**< Payload containing QrCode formatted WIFI datas */

        PAYLOAD_TYPE_NB                     /**< Number of supported payloads */
    };
    Q_ENUM_NS(PayloadType)

    QBAR_EXPORT QString payloadTypeToString(PayloadType idType);

    /*!
     * \brief Qrcode level of <b>errors correction capability (ECC)</b>.
     * \details
     * Higher levels of error correction sacrifice data capacity,
     * but allow a larger portion of the QR code to be damaged or
     * unreadable.
     *
     * \sa qrLevelEccToString()
     */
    enum class QrLevelEcc
    {
        QR_ECC_LOW = 0,   /**< 7% of data bytes can be restored. */
        QR_ECC_MEDIUM,    /**< 15% of data bytes can be restored. */
        QR_ECC_QUARTILE,  /**< 25% of data bytes can be restored. */
        QR_ECC_HIGH,      /**< 30% of data bytes can be restored. */
    };
    Q_ENUM_NS(QrLevelEcc)

    QBAR_EXPORT QString qrLevelEccToString(QrLevelEcc idLevel);

/*****************************/
/* Library methods           */
/*****************************/

    QBAR_EXPORT QVersionNumber getLibraryVersion();

/*****************************/
/* Qt related methods        */
/*****************************/

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)

inline uint qHash(qbar::BarError key, uint seed = 0)
{
    return ::qHash(static_cast<std::underlying_type<qbar::BarError>::type>(key), seed);
}

inline uint qHash(qbar::BarType key, uint seed = 0)
{
    return ::qHash(static_cast<std::underlying_type<qbar::BarType>::type>(key), seed);
}

inline uint qHash(qbar::PayloadType key, uint seed = 0)
{
    return ::qHash(static_cast<std::underlying_type<qbar::PayloadType>::type>(key), seed);
}

inline uint qHash(qbar::QrLevelEcc key, uint seed = 0)
{
    return ::qHash(static_cast<std::underlying_type<qbar::QrLevelEcc>::type>(key), seed);
}

#endif

/*****************************/
/* End namespaces            */
/*****************************/

} // namespace qbar

/*****************************/
/* Qt specific meta-system   */
/*****************************/

#endif // QBARCODE_QWLANTYPES_H
