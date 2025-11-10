#include "renderer_priv.h"

#include <QDebug>

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
/*****************************/

RendererPrivate::RendererPrivate(Renderer *parent) :
    m_colorBg(Qt::white), m_colorFg(Qt::black),
    q_ptr(parent)
{
    /* Nothing to do */
}

RendererPrivate::~RendererPrivate()
{
    /* Nothing to do */
}

bool RendererPrivate::computeSize(const Barcode &barcode)
{
    /* Verify that size can be calculated */
    const int marginsWidth = m_margins.left() + m_margins.right();
    const int marginsHeight = m_margins.top() + m_margins.bottom();

    if(m_sizeReq.width() <= marginsWidth || m_sizeReq.height() <= marginsHeight){
        qCritical() << "Computing size failed due to requested size being too small for margins [size-requested: "
                    << m_sizeReq
                    << ", margins: "
                    << m_margins
                    << "]";
        return false;
    }

    const QSize sizeDrawable = m_sizeReq - QSize(marginsWidth, marginsHeight);

    /* Retrieve needed datas */
    const QSize matrixSize = barcode.getSize();
    const QSizeF matrixRatio = barcode.getRatio();

    int barcodeW = sizeDrawable.width();
    int barcodeH = sizeDrawable.height();

    /* Calculate aspect ratio */
    const double aspect = matrixRatio.width() / matrixRatio.height();
    if(aspect > 1.0){   // barcode is wider than tall
        barcodeH = barcodeW / aspect;
    }else{              // barcode is taller than wide (or equal)
        barcodeW = barcodeH * aspect;
    }

    /* Calculate module size */
    const int pxHz = barcodeW / matrixSize.width();     // Pixels per module horizontally
    const int pxVt = barcodeH / matrixSize.height();    // Pixels per module vertically
    const int moduleSize = std::min(pxHz, pxVt);
    if(moduleSize <= 0){
        qCritical() << "Computing size failed due to requested size being too small, module size would be too small [size-requested: "
                    << m_sizeReq
                    << ", margins: "
                    << m_margins
                    << ", module-size: "
                    << moduleSize
                    << "]";
        return false;
    }

    /* Calculate final output size */
    m_sizeOut.setWidth(moduleSize * matrixSize.width() + marginsWidth);
    m_sizeOut.setHeight(moduleSize * matrixSize.height() + marginsHeight);

    m_sizeModule = moduleSize;

    return true;
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
