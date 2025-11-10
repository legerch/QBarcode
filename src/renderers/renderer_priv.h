#ifndef QBARCODE_RENDERERPRIVATE_H
#define QBARCODE_RENDERERPRIVATE_H

#include "qbarcode/renderers/renderer.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class RendererPrivate
{
    Q_DECLARE_PUBLIC(Renderer)
    QBAR_DISABLE_COPY_MOVE(RendererPrivate)

public:
    explicit RendererPrivate(Renderer *parent);
    virtual ~RendererPrivate();

public:
    bool computeSize(const Barcode &barcode);

public:
    QSize m_sizeReq;
    QMargins m_margins;

    QColor m_colorBg;
    QColor m_colorFg;

    QSize m_sizeOut;
    int m_sizeModule;

    Renderer *q_ptr = nullptr;
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

#endif // QBARCODE_RENDERERPRIVATE_H
