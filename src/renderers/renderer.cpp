#include "qbarcode/renderers/renderer.h"

#include "renderer_priv.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*!
 * \class qbar::Renderer
 *
 * \brief Allow to render a barcode
 * \details
 * This class allow to share common properties/methods accross
 * all renderer types. \n
 * A render entity represent how a barcode should "look", so only
 * one renderer is generally used but can render multiples barcodes. \n
 * Each types of barcode can have their specific appearance customization,
 * so each type will have a dedicated renderer.
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

/*!
 * \brief Retrieve requested size
 * \return
 * Returns barcode requested size in pixels.
 *
 * \sa setSizeRequested()
 * \sa getMargins(), setMargins()
 */
QSize Renderer::getSizeRequested() const
{
    return d_ptr->m_sizeReq;
}

/*!
 * \brief Retrieve margins
 * \return
 * Returns barcode margins in pixels to use.
 *
 * \sa setMargins()
 * \sa getSizeRequested(), setSizeRequested()
 */
QMargins Renderer::getMargins() const
{
    return d_ptr->m_margins;
}

/*!
 * \brief Retrieve color background
 * \return
 * Returns barcode background color to use.
 *
 * \sa setColorBackground()
 * \sa getColorForeground(), setColorForeground()
 */
QColor Renderer::getColorBackground() const
{
    return d_ptr->m_colorBg;
}

/*!
 * \brief Retrieve color foreground
 * \return
 * Returns barcode foreground color to use.
 *
 * \sa setColorForeground()
 * \sa getColorBackground(), setColorBackground()
 */
QColor Renderer::getColorForeground() const
{
    return d_ptr->m_colorFg;
}

/*!
 * \brief Allow to set requested size
 * \details
 * "Requested size" means that we will \b try to
 * render barcode at this requested size. \n
 * But that is not always possible since it will depends of
 * multiple factors:
 * - Barcode matrix size
 * - Barcode ratio
 * - Margins to use
 *
 * \param[in] size
 * Requested size in pixels.
 *
 * \sa getSizeRequested()
 * \sa setMargins(), getMargins()
 */
void Renderer::setSizeRequested(const QSize &size)
{
    d_ptr->m_sizeReq = size;
}

/*!
 * \brief Allow to set margins to use
 *
 * \param[in] margins
 * Margins to use in pixels.
 *
 * \sa getMargins()
 * \sa setSizeRequested(), getSizeRequested()
 */
void Renderer::setMargins(const QMargins &margins)
{
    d_ptr->m_margins = margins;
}

/*!
 * \brief Allow to set background color
 *
 * \param[in] color
 * Background color to use.
 *
 * \sa getColorBackground()
 * \sa setColorForeground(), getColorForeground()
 */
void Renderer::setColorBackground(const QColor &color)
{
    d_ptr->m_colorBg = color;
}

/*!
 * \brief Allow to set foreground color
 *
 * \param[in] color
 * foreground color to use.
 *
 * \sa getColorForeground()
 * \sa setColorBackground(), getColorBackground()
 */
void Renderer::setColorForeground(const QColor &color)
{
    d_ptr->m_colorFg = color;
}

/*!
 * \brief Use to render a barcode to an image
 *
 * \param[in] barcode
 * Barcode to render.
 *
 * \return
 * Returns image rendered of the barcode. \n
 * It can be invalid, verify it via \c isNull()
 * before using it.
 */
QImage Renderer::toImage(const Barcode &barcode)
{
    /* Verify barcode validity */
    if(!barcode.isValid()){
        qCritical("Rendering barcode to image failed due to barcode being invalid");
        return QImage();
    }

    /* Render to image */
    return d_ptr->renderToImage(barcode);
}

/*****************************/
/* Qt specific methods       */
/*****************************/

QDebug operator<<(QDebug debug, const Renderer &renderer)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Renderer("
                    << "size-requested: " << renderer.getSizeRequested() << ", "
                    << "margins: " << renderer.getMargins() << ", "
                    << "color-bg: " << renderer.getColorBackground() << ", "
                    << "color-fg: " << renderer.getColorForeground() << ")";
    return debug;
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar

/*****************************/
/* End file                  */
/*****************************/
