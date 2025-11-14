#ifndef QBARCODE_BARCODE_H
#define QBARCODE_BARCODE_H

#include "qbarcode/payloads/payload.h"

#include <memory>

#include <QSize>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class BarcodePrivate;
class QBAR_EXPORT Barcode
{
    QBAR_DISABLE_COPY(Barcode)

public:
    Barcode(Barcode &&other) noexcept;
    Barcode &operator=(Barcode &&) noexcept;

    virtual ~Barcode();

public:
    bool isValid() const;

    BarType getType() const;
    const Payload* getPayload() const;

    QSize getSize() const;
    const MatrixData& getMatrixData() const;

public:
    /*!
     * \brief Retrieve ratio of a barcode
     * \details
     * Allow to manage different format of barcode, to know
     * if they are taller of wider.
     *
     * \return
     * Returns associated ratio.
     */
    virtual QSizeF getRatio() const = 0;

public:
    template<typename T>
    const T* getPayloadAs() const;

/*! \cond INTERNAL */

protected:
    explicit Barcode(std::unique_ptr<BarcodePrivate> impl);

protected:
    std::unique_ptr<BarcodePrivate> d_ptr;
    Q_DECLARE_PRIVATE(Barcode)

/*! \endcond */

};

/*****************************/
/* Template methods          */
/*****************************/

/*!
 * \brief Allow to directly cast payload to expected type
 * \return
 * Returns casted payload pointer. \n
 * Can be \c NULL if barcode is \em invalid or
 * if casting cannot be done.
 */
template<typename T>
inline const T* Barcode::getPayloadAs() const
{
    return dynamic_cast<const T*>(getPayload());
}

/*****************************/
/* Qt specific methods       */
/*****************************/

QBAR_EXPORT QDebug operator<<(QDebug debug, const Barcode &barcode);

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

#endif // QBARCODE_BARCODE_H
