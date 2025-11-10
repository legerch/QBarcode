#ifndef QBARCODE_RENDERER_H
#define QBARCODE_RENDERER_H

#include "qbarcode/datas/barcode.h"

#include <QImage>

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class RendererPrivate;
class QBAR_EXPORT Renderer
{
    QBAR_DISABLE_COPY(Renderer)

public:
    Renderer(Renderer &&other) noexcept;
    Renderer &operator=(Renderer &&) noexcept;

    virtual ~Renderer();

public:
    QSize getSizeRequested() const;
    QMargins getMargins() const;
    QColor getColorBackground() const;
    QColor getColorForeground() const;

public:
    void setSizeRequested(const QSize &size);
    void setMargins(const QMargins &margins);
    void setColorBackground(const QColor &color);
    void setColorForeground(const QColor &color);

public:
    QImage toImage(const Barcode &barcode);

protected:
    explicit Renderer(std::unique_ptr<RendererPrivate> impl);

protected:
    std::unique_ptr<RendererPrivate> d_ptr;
    Q_DECLARE_PRIVATE(Renderer)
};

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

#endif // QBARCODE_RENDERER_H
