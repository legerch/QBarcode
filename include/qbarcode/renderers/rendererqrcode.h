#ifndef QBARCODE_RENDERERQRCODE_H
#define QBARCODE_RENDERERQRCODE_H

#include "qbarcode/renderers/renderer.h"

/*****************************/
/* Namespace instructions    */
/*****************************/

namespace qbar
{

/*****************************/
/* Class definitions         */
/*****************************/

class RendererQrCodePrivate;
class QBAR_EXPORT RendererQrCode : public Renderer
{
    QBAR_DISABLE_COPY(RendererQrCode)

public:
    RendererQrCode();
    RendererQrCode(RendererQrCode &&other) noexcept;
    RendererQrCode &operator=(RendererQrCode &&) noexcept;

    virtual ~RendererQrCode();

private:
    Q_DECLARE_PRIVATE(RendererQrCode)
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

#endif // QBARCODE_RENDERERQRCODE_H
