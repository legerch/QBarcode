#ifndef QBARCODE_BARCODE_H
#define QBARCODE_BARCODE_H

#include "qbarcode/payloads/payload.h"
#include <memory>

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
    BarType getType() const;
    const Payload* getPayload() const;

    const MatrixData& getMatrixData() const;

public:
    template<typename T>
    const T* getPayloadAs() const;

protected:
    explicit Barcode(std::unique_ptr<BarcodePrivate> impl);

protected:
    std::unique_ptr<BarcodePrivate> d_ptr;
    Q_DECLARE_PRIVATE(Barcode)
};

/*****************************/
/* Template methods          */
/*****************************/

template<typename T>
inline const T* Barcode::getPayloadAs() const
{
    return dynamic_cast<const T*>(getPayload());
}

/*****************************/
/* Qt specific methods       */
/*****************************/

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
