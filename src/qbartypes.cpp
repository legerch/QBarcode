#include "qbarcode/qbartypes.h"

#include <QHash>

/*****************************/
/* Namespace documentations  */
/*****************************/

/*!
 * \namespace qbar
 * \brief Namespace used for \b QWlanManager library
 *
 * \sa getLibraryVersion()
 */

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Start namespace           */
/*****************************/

namespace qbar
{

/*****************************/
/* Functions implementation  */
/*****************************/

/*!
 * \brief Use to convert barcode types to string.
 *
 * \param[in] idType
 * Type ID to convert. \n
 * If unknown, string "unknown" will be returned.
 *
 * \return
 * Returns string equivalent.
 */
QString barTypeToString(BarType idType)
{
    static const QHash<BarType, QString> MAP_STR_TYPE =
    {
        {BarType::QBAR_TYPE_QRCODE, "QrCode"},
    };

    return MAP_STR_TYPE.value(idType, "Unknown");
}

/*!
 * \brief Used to retrieve \b QBarcode library
 * version.
 *
 * \return
 * Returns semantic version of the library.
 */
QVersionNumber getLibraryVersion()
{
    return QVersionNumber(QBAR_VERSION_MAJOR, QBAR_VERSION_MINOR, QBAR_VERSION_PATCH);
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
