#include "qbarutils.h"

/*****************************/
/* Macro definitions         */
/*****************************/

/*****************************/
/* Namespace documentations  */
/*****************************/

/*!
 * \namespace qbar::utils
 * \brief Namespace used to manage
 * all barcode utilities.
 */

/*****************************/
/* Class documentations      */
/*****************************/

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Start namespace           */
/*****************************/

namespace qbar::utils
{

/*****************************/
/* Functions definitions     */
/*****************************/

/*!
 * \brief Use to verify if a string contains only digits
 *
 * \param[in] string
 * String to check. \n
 * If empty, \c false will be returned.
 *
 * \return
 * Returns \c true if the string contains only
 * digits characters.
 *
 * \sa stringDigitsOnly()
 */
bool stringIsDigits(const QString &string)
{
    /* Verify that string is valid */
    if(string.isEmpty()){
        return false;
    }

    /* Verify that each character is a digit */
    return std::all_of(string.cbegin(), string.cend(), [](QChar c){
        return c.isDigit();
    });
}

/*!
 * \brief Return digits characters only of
 * a string
 *
 * \param[in] string
 * String to use.
 *
 * \return
 * Returns string containing only digits
 * characters
 *
 * \sa stringIsDigits()
 */
QString stringDigitsOnly(const QString &string)
{
    QString newStr;

    for(QChar c : string){
        if(c.isDigit()){
            newStr.append(c);
        }
    }

    return newStr;
}

/*!
 * \brief Remove all space characters from
 * a string
 * \details
 * A space means any character for which
 * \c QChar::isSpace() returns \c true.
 *
 * \param[in] string
 * String to check.
 *
 * \return
 * Returns string that has whitespaces removed.
 *
 * \sa QString::simplified()
 */
QString stringRemoveSpaces(const QString &string)
{
    QString newStr;

    for(QChar c : string){
        if(!c.isSpace()){
            newStr.append(c);
        }
    }

    return newStr;
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar::utils

/*****************************/
/* End file                  */
/*****************************/
