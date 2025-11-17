#include "qrcodeutils.h"

#include <QHash>

/*****************************/
/* Macro definitions         */
/*****************************/

/*****************************/
/* Namespace documentations  */
/*****************************/

/*!
 * \namespace qbar::utils
 * \brief Namespace used to manage
 * all barcode utilities.
 */

/*!
 * \namespace qbar::utils::qrc
 * \brief Namespace used to manage all QrCode
 * utilities including backend library.
 * \details
 * Backend used for QrCode generation is \b libqrencode. \n
 * For more details, see:
 * - https://fukuchi.org/works/qrencode/manual/
 */

/*****************************/
/* Class documentations      */
/*****************************/

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Start namespace           */
/*****************************/

namespace qbar::utils::qrc
{


/*!
 * \brief Use to convert <b>Error Correction
 * Capability</b> level from this library API
 * to \em libqrencode API equivalent.
 *
 * \param[in] idLevel
 * Level ID to convert. \n
 * If invalid level ID, return highest supported level.
 *
 * \note
 * https://fukuchi.org/works/qrencode/manual/qrencode_8h.html#a35d70229ba985c61bbdab27b0f65740e
 *
 * \return
 * Returns \em libqrencode equivalent level.
 */
QRecLevel convertLevelEccToApi(QrLevelEcc idLevel)
{
    static const QHash<QrLevelEcc, QRecLevel> MAP_API_LVL =
    {
        {QrLevelEcc::QR_ECC_LOW,        QR_ECLEVEL_L},
        {QrLevelEcc::QR_ECC_MEDIUM,     QR_ECLEVEL_M},
        {QrLevelEcc::QR_ECC_QUARTILE,   QR_ECLEVEL_Q},
        {QrLevelEcc::QR_ECC_HIGH,       QR_ECLEVEL_H},
    };

    return MAP_API_LVL.value(idLevel, QR_ECLEVEL_H);
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar::utils::qrc

/*****************************/
/* End file                  */
/*****************************/
