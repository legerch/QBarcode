#include "qbarcode/renderers/renderer.h"

#include "renderer_priv.h"

#include <QPainter>

/*****************************/
/* Class documentations      */
/*****************************/

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

Renderer::Renderer()
    : d_ptr(std::make_unique<RendererPrivate>(this))
{
    /* Nothing to do */
}

Renderer::Renderer(Renderer &&other) noexcept = default;
Renderer& Renderer::operator=(Renderer &&other) noexcept = default;

Renderer::~Renderer()
{
    /* Nothing to do */
}

QSize Renderer::getSizeRequested() const
{
    return d_ptr->m_sizeReq;
}

QMargins Renderer::getMargins() const
{
    return d_ptr->m_margins;
}

QColor Renderer::getColorBackground() const
{
    return d_ptr->m_colorBg;
}

QColor Renderer::getColorForeground() const
{
    return d_ptr->m_colorFg;
}

void Renderer::setSizeRequested(const QSize &size)
{
    d_ptr->m_sizeReq = size;
}

void Renderer::setMargins(const QMargins &margins)
{
    d_ptr->m_margins = margins;
}

void Renderer::setColorBackground(const QColor &color)
{
    d_ptr->m_colorBg = color;
}

void Renderer::setColorForeground(const QColor &color)
{
    d_ptr->m_colorFg = color;
}

QImage Renderer::toImage(const Barcode &barcode)
{
    /* Compute size */
    bool succeed = d_ptr->computeSize(barcode);
    if(!succeed){
        return QImage();
    }

    /* Initialize image */
    QImage img(d_ptr->m_sizeOut, QImage::Format_ARGB32);
    img.fill(Qt::white);

    /* Prepare painter to use */
    QPainter painter(&img);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen); // Do not draw boundary lines. See https://doc.qt.io/qt-6/qt.html#PenStyle-enum

    /* Draw modules */
    const MatrixData &matrixData = barcode.getMatrixData();

    const int nbRows = matrixData.getRows();
    const int nbCols = matrixData.getCols();
    const int sizeMod = d_ptr->m_sizeModule;

    for(int y = 0; y < nbRows; ++y){
        for(int x = 0; x < nbCols; ++x){
            if(matrixData(y, x) == 1){
                const QRect mod(
                    d_ptr->m_margins.left() + x * sizeMod,
                    d_ptr->m_margins.top() + y * sizeMod,
                    sizeMod, sizeMod
                );

                painter.drawRect(mod);
            }
        }
    }

    return img;
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
