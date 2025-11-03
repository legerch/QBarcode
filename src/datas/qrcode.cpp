#include "qbarcode/datas/qrcode.h"

#include "backend/typesqrencode.h"
#include "datas/barcode_priv.h"

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
/* Functions definitions     */
/*      Private Class        */
/*****************************/

class QrCodePrivate : public BarcodePrivate
{
    Q_DECLARE_PUBLIC(QrCode)
    QBAR_DISABLE_COPY_MOVE(QrCodePrivate)

public:
    explicit QrCodePrivate(QrCode *parent);
    virtual ~QrCodePrivate();

protected:
    void setLevelEcc(QrLevelEcc idLevel);
    void setVersion(int version);

protected:
    virtual BarError generateMatrix() override;

protected:
    QrLevelEcc m_idLvlEcc;
    int m_version;
};

/*****************************/
/* Functions implementation  */
/*      Private Class        */
/*****************************/

QrCodePrivate::QrCodePrivate(QrCode *parent)
    : BarcodePrivate(BarType::QBAR_TYPE_QRCODE, parent),
    m_idLvlEcc(QrLevelEcc::QR_ECC_LOW), m_version(1)
{
    /* Nothing to do */
}

QrCodePrivate::~QrCodePrivate()
{
    /* Nothing to do */
}

void QrCodePrivate::setLevelEcc(QrLevelEcc idLevel)
{
    m_idLvlEcc = idLevel;
}

void QrCodePrivate::setVersion(int version)
{
    /* Verify that version is valid */
    if(version < QrCode::VERSION_MIN || version > QrCode::VERSION_MAX){
        qWarning("Unable to set QrCode version [version: %d]", version);
        return;
    }

    /* Set version */
    m_version = version;
}

BarError QrCodePrivate::generateMatrix()
{
    /* Prepare needed datas */
    const QByteArray data = m_payload->getData();
    const QRecLevel idLevel = libqrencode::convertLevelEccToApi(m_idLvlEcc);
    const unsigned char *rawData = reinterpret_cast<const unsigned char *>(data.constData());
    constexpr int qrVersion = 0; // Use 0 to let library choose minimal version posssible considering payload and level of ECC.

    /* Generate QrCode */
    QRcode *qr = QRcode_encodeData(data.size(), rawData, qrVersion, idLevel);
    if(!qr){
        qCritical("Unable to generate QrCode [payload: '%s']", qUtf8Printable(m_payload->getString()));
        return BarError::QBAR_ERR_UNKNOWN;
    }

    /* Set QrCode properties */
    // Version
    setVersion(qr->version);

    // Matrix data
    m_matrix.resize(qr->width, qr->width);

    for(int y = 0; y < qr->width; ++y){
        for(int x = 0; x < qr->width; ++x){
            m_matrix(y, x) = (qr->data[y * qr->width + x] & 0x1) ? 1 : 0;   // Less significant bit represent module black or white. See more at: https://fukuchi.org/works/qrencode/manual/structQRcode.html
        }
    }

    /* Clean used ressources */
    QRcode_free(qr);
    return BarError::QBAR_ERR_NO_ERROR;
}

/*****************************/
/* Functions implementation  */
/*      Public Class         */
/*****************************/

QrCode::QrCode()
    : Barcode(std::make_unique<QrCodePrivate>(this))
{
    /* Nothing to do */
}

QrCode::QrCode(QrCode &&other) noexcept = default;
QrCode &QrCode::operator=(QrCode &&) noexcept = default;

QrCode::~QrCode()
{
    /* Nothing to do */
}

QrLevelEcc QrCode::getIdLevelEcc() const
{
    Q_D(const QrCode);
    return d->m_idLvlEcc;
}

int QrCode::getVersion() const
{
    Q_D(const QrCode);
    return d->m_version;
}

std::optional<QrCode> QrCode::create(const Payload &payload, QrLevelEcc idLevel)
{
    /* Set QrCode properties */
    QrCode qrCode;
    QrCodePrivate *impl = qrCode.d_func();

    impl->setLevelEcc(idLevel);
    impl->setPayload(payload);

    /* Generate it */
    const BarError idErr = impl->compute();
    if(idErr != BarError::QBAR_ERR_NO_ERROR){
        return std::nullopt;
    }

    return qrCode;
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
