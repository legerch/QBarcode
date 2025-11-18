#include "testsutils.h"



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

QFileInfo TestsUtils::getPathRsc(const QString &filename)
{
    return QFileInfo(QBAR_TESTS_DIR_EXTERNAL_RSC + filename);
}

QFileInfo TestsUtils::getPathRscCustom(const QFileInfo &fileInfo, const QString &customName)
{
    const QString path = fileInfo.absolutePath();
    const QString suffix = fileInfo.suffix();

    const QString newFile = QString("%1/%2.%3").arg(path, customName, suffix);
    return QFileInfo(newFile);
}

qbar::PayloadQrWifi TestsUtils::createPayloadWifi(IdWifiSec idSec, const QString &ssid, const QString &passwd, bool isHidden)
{
    qbar::PayloadQrWifi payload;

    payload.setSecurityType(idSec);
    payload.setSsid(ssid);
    payload.setPassword(passwd);
    payload.setIsHidden(isHidden);

    return payload;
}

/*****************************/
/* End namespace             */
/*****************************/

/*****************************/
/* End file                  */
/*****************************/
