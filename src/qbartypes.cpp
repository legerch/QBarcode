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