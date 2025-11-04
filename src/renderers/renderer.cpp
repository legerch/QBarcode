#include "qbarcode/renderers/renderer.h"

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
