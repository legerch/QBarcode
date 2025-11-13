#include "qbarcode/datas/barcode.h"

#include "datas/barcode_priv.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::Barcode
 *
 * \brief Represent a barcode entity
 * \details
 * This class allow to share common properties/methods accross
 * all kinds of barcodes types. \n
 * A barcode entity is considered as \b immutable, to set
 * it, it will be necessary to generate a new Barcode via their
 * \c create() method. \n
 * Barcode only store data, it known nothing of the rendering process.
 * Once a barcode entity is created, it can be renderer via Renderer derived
 * classes.
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
/*      Public Class         */
/*****************************/

Barcode::Barcode(Barcode &&other) noexcept = default;
Barcode& Barcode::operator=(Barcode &&other) noexcept = default;

Barcode::Barcode(std::unique_ptr<BarcodePrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

Barcode::~Barcode()
{
    /* Nothing to do */
}

/*!
 * \brief Allow to verify if a barcode is valid
 * \details
 * A barcode is considered valid if:
 * - Current type is known and supported
 * - A matrix is properly set.
 *
 * \return
 * Returns \c true if valid.
 */
bool Barcode::isValid() const
{
    /* Verify supported type */
    if(d_ptr->m_idType == BarType::QBAR_TYPE_UNKNOWN){
        return false;
    }

    return d_ptr->m_matrix.getNbElements() > 0;
}

/*!
 * \brief Get barcode type
 * \details
 * Useful to properly cast a \c Barcode instance
 * to its "real" type.
 *
 * \return
 * Returns type of the barcode.
 */
BarType Barcode::getType() const
{
    return d_ptr->m_idType;
}

/*!
 * \brief Get payload data of barcode
 * \return
 * Returns pointer to payload data. \n
 * Can be \c NULL if barcode is invalid.
 *
 * \sa isValid()
 */
const Payload* Barcode::getPayload() const
{
    return d_ptr->m_payload.get();
}

/*!
 * \brief Get matrix size
 * \return
 * Returns matrix size in number of modules.
 */
QSize Barcode::getSize() const
{
    return d_ptr->m_matrix.getSize();
}

/*!
 * \brief Get matrix data of a barcode
 * \details
 * Matrix data can be useful if directly managing "raw"
 * datas, mainly used for \c Renderer derived classes.
 *
 * \return
 * Returns constant reference to matrix of barcode.
 */
const MatrixData &Barcode::getMatrixData() const
{
    return d_ptr->m_matrix;
}

/*****************************/
/* Qt specific methods       */
/*****************************/

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
