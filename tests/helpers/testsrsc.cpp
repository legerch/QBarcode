#include "testsrsc.h"

/*****************************/
/* Macro definitions         */
/*****************************/
#if !defined(QBAR_TESTS_DIR_EXTERNAL_RSC)
#error "Macro 'QBAR_TESTS_DIR_EXTERNAL_RSC' is not defined, please set up !"
#endif

/*****************************/
/* Start namespace           */
/*****************************/

/*****************************/
/* Constants defintitions    */
/*****************************/

/*****************************/
/* Functions implementations */
/*****************************/

std::string TestsRsc::getPathExternalRsc(const std::string &filename)
{
    return QBAR_TESTS_DIR_EXTERNAL_RSC + filename;
}

/*****************************/
/* End namespace             */
/*****************************/

/*****************************/
/* End file                  */
/*****************************/