#include "eanutils.h"

/*****************************/
/* Macro definitions         */
/*****************************/

/*****************************/
/* Namespace documentations  */
/*****************************/

/*!
 * \namespace qbar::utils::ean
 * \brief Namespace used to manage
 * all EAN utilities.
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

namespace qbar::utils::ean
{

/*****************************/
/* Functions definitions     */
/*****************************/

/*!
 * \brief Use to encode EAN datas.
 *
 * \param[in] digits
 * Data digits to use. \n
 * All characters must be digits. \n
 * If lenght is different than \c nbDigits
 * argument, error \c BarError::QBAR_ERR_ITEM_INVALID
 * will be returned.
 * \param[in] nbDigits
 * Number of digits input to use.
 * \param[out] data
 * Encoded datas. \n
 * Nothing is set in case of errors.
 *
 * \return
 * Return \c BarError::QBAR_ERR_NO_ERROR if succeed.
 */
BarError encodeData(const QString &digits, int nbDigits, QByteArray &data)
{
    /* Verify that digit string is valid */
    if(digits.size() != nbDigits){
        return BarError::QBAR_ERR_ITEM_INVALID;
    }

    /* Create payload data */
    const int checkDigit = calcCheckDigit(digits);
    const QString strData = digits + QString::number(checkDigit);

    /* Return encoded datas */
    data = strData.toUtf8();
    return BarError::QBAR_ERR_NO_ERROR;
}

/*!
 * \brief Calculate check digit of EAN based barcode
 * \details
 * Last digits checksums is calculated by using the formula: \n
 * 1. Odd = Sum of the numbers of odd positions
 * 2. Even = Sum of the numbers of even positions
 * 3. Sum = (Odd * 3) + Even    // Use weight of 3 for odd positions, 1 for even positions
 * 4. Key = ( 10 - [ Sum modulo 10 ] )
 *
 * Weight alternate with \c 1 and \c 3, starting from the rightmost digit.
 * So positions are read from right to left, by using index \c 1 to
 * start <b>(not 0)</b>. \n
 * EAN-13 used the same algorithm that ISBN-13, for more details,
 * please refer to:\n
 * - https://barcode-coder.com/en/ean-13-specification-102.html
 * - https://en.wikipedia.org/wiki/ISBN#ISBN-13_check_digit_calculation
 *
 * \param[in] digits
 * Digits to use.
 *
 * \return
 * Returns calculated check digit.
 *
 * \sa encodeData()
 */
int calcCheckDigit(const QString &digits)
{
    int sum = 0;
    int position = 1;

    /* Perform the sum */
    for(auto it = digits.crbegin(); it != digits.crend(); ++it){
        const int number = it->digitValue();

        // Current position is odd
        if(position % 2 != 0){
            sum += number * 3;
        }else{
            sum += number;
        }

        ++position;
    }

    /* Calculate check digit */
    return (10 - (sum % 10)) % 10;
}

/*****************************/
/* End namespace             */
/*****************************/

} // namespace qbar::utils::ean

/*****************************/
/* End file                  */
/*****************************/
