#include "qbarcode/renderers/rendererqrcode.h"

#include "renderers/renderer_priv.h"

#include <QPainter>

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::RendererQrCode
 *
 * \brief Represent a QrCode renderer
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
/* Functions definitions     */
/*      Private Class        */
/*****************************/

class RendererQrCodePrivate : public RendererPrivate
{
    Q_DECLARE_PUBLIC(RendererQrCode)
    QBAR_DISABLE_COPY_MOVE(RendererQrCodePrivate)

public:
    explicit RendererQrCodePrivate(RendererQrCode *parent);
    virtual ~RendererQrCodePrivate();

protected:
    virtual QImage renderToImage(const Barcode &barcode) override;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

RendererQrCodePrivate::RendererQrCodePrivate(RendererQrCode *parent)
    : RendererPrivate(parent)
{
    /* Nothing to do */
}

RendererQrCodePrivate::~RendererQrCodePrivate()
{
    /* Nothing to do */
}

QImage RendererQrCodePrivate::renderToImage(const Barcode &barcode)
{
    /* Compute size */
    bool succeed = computeSize(barcode);
    if(!succeed){
        return QImage();
    }

    /* Initialize image */
    QImage img(m_sizeOut, QImage::Format_RGB32);
    img.fill(m_colorBg);

    /* Prepare painter to use */
    QPainter painter(&img);
    painter.setBrush(m_colorFg);
    painter.setPen(Qt::NoPen); // Do not draw boundary lines. See https://doc.qt.io/qt-6/qt.html#PenStyle-enum

    /* Draw modules */
    const MatrixData &matrixData = barcode.getMatrixData();

    const int nbRows = matrixData.getRows();
    const int nbCols = matrixData.getCols();
    const int sizeMod = m_sizeModule;

    for(int y = 0; y < nbRows; ++y){
        for(int x = 0; x < nbCols; ++x){
            if(matrixData(y, x) == 1){
                const QRect mod(
                    m_margins.left() + x * sizeMod,
                    m_margins.top() + y * sizeMod,
                    sizeMod, sizeMod
                    );

                painter.drawRect(mod);
            }
        }
    }

    return img;
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

RendererQrCode::RendererQrCode()
    : Renderer(std::make_unique<RendererQrCodePrivate>(this))
{
    /* Nothing to do */
}

RendererQrCode::RendererQrCode(RendererQrCode &&other) noexcept = default;
RendererQrCode &RendererQrCode::operator=(RendererQrCode &&) noexcept = default;

RendererQrCode::~RendererQrCode()
{
    /* Nothing to do */
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
