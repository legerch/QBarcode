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

void Renderer::setSizeRequested(const QSize &size)
{
    d_ptr->m_sizeReq = size;
}

void Renderer::setMargins(const QMargins &margins)
{
    d_ptr->m_margins = margins;
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
