#ifndef QBAR_TESTS_HELPERS_TESTSUTILS_H
#define QBAR_TESTS_HELPERS_TESTSUTILS_H

#include "qbarcode/payloads/payloadqrwifi.h"

#include <QFileInfo>

using IdWifiSec = qbar::PayloadQrWifi::SecurityType;

class TestsUtils
{
public:
    static QFileInfo getPathRsc(const QString &filename);
    static QFileInfo getPathRscCustom(const QFileInfo &fileInfo, const QString &customName);

    static qbar::PayloadQrWifi createPayloadWifi(IdWifiSec idSec, const QString &ssid, const QString &passwd, bool isHidden);
};

#endif // QBAR_TESTS_HELPERS_TESTSUTILS_H
