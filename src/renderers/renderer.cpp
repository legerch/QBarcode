#include "qbarcode/renderers/renderer.h"

#include "renderer_priv.h"

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

Renderer::Renderer(Renderer &&other) noexcept = default;
Renderer& Renderer::operator=(Renderer &&other) noexcept = default;

Renderer::Renderer(std::unique_ptr<RendererPrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

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
    return d_ptr->renderToImage(barcode);
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
