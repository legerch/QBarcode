#include "qbarcode/payloads/payloadbase.h"

#include "payloads/payloadbase_priv.h"

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

PayloadBase::PayloadBase(PayloadBase &&other) noexcept = default;
PayloadBase& PayloadBase::operator=(PayloadBase &&other) noexcept = default;

PayloadBase::PayloadBase(std::unique_ptr<PayloadBasePrivate> impl)
    : d_ptr(std::move(impl))
{
    /* Nothing to do */
}

PayloadBase::~PayloadBase()
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
