#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent): QWidget(parent), ui(new Ui::View)
{
    ui->setupUi(this);
    setFixedSize(size());
    ui->tcModelLineEdit->setText("X:/mashgraph/detector/Debug/model.txt");
    ui->dirLineEdit->setText("X:/mashgraph/detector_files/test-public");
    ui->trueLocLineEdit->setText("X:/mashgraph/detector_files/test-public/test-processed.idl");
    ui->predLocLineEdit->setText("X:/mashgraph/detector/Debug/predicted.txt");
    ui->siModelLineEdit->setText("X:/mashgraph/detector/Debug/model.txt");
    ui->imageForScanLineEdit->setText("X:/mashgraph/detector_files/test-public/0000.png");

    imageLabel = new QLabel();
    ui->siScrollArea->setWidget(imageLabel);

    warningDialog = new QMessageBox();
    warningDialog->setWindowTitle("Warning!");
    warningDialog->setIcon(QMessageBox::Warning);

    m_precision = 0.0;
    m_recall = 0.0;
    m_fScore = 0.0;
}

View::~View()
{
    delete ui;
    delete imageLabel;
    delete warningDialog;
}

void View::setViewPrecision(double value)
{
    m_precision = value;
}

void View::setViewRecall(double value)
{
    m_recall = value;
}

void View::setViewFScore(double value)
{
    m_fScore = value;
}

void View::setViewScannedImage(const QImage &image)
{
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->adjustSize();
}

void View::showWarning(const QString &warningMsg)
{
    warningDialog->setText(warningMsg);
    warningDialog->show();
}

void View::chooseDirButton()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Choose directory"), QDir::currentPath());
    if (!dirName.isNull())
        ui->dirLineEdit->setText(dirName + "\\");
}

void View::chooseTrueLocationFileButton()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose annotation file"), QDir::currentPath());
    if (!fileName.isNull())
        ui->trueLocLineEdit->setText(fileName);
}

void View::chooseUserLocationFileButton()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose annotation file"), QDir::currentPath());
    if (!fileName.isNull())
        ui->predLocLineEdit->setText(fileName);
}

void View::chooseTCModelFileButton()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose model file"), QDir::currentPath());
    if (!fileName.isNull())
        ui->tcModelLineEdit->setText(fileName);
}

void View::chooseSIModelFileButton()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose model file"), QDir::currentPath());
    if (!fileName.isNull())
        ui->siModelLineEdit->setText(fileName);
}

void View::chooseImageForScan()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose image file"), QDir::currentPath());
    if (!fileName.isNull())
        ui->imageForScanLineEdit->setText(fileName);
}

void View::trainButton()
{
    if (ui->dirLineEdit->text().isEmpty() ||
        ui->tcModelLineEdit->text().isEmpty())
        showWarning("Please, fill all necessary fields");
    else
    {
        setCurrDir(ui->dirLineEdit->text());
        setModelFileName(ui->tcModelLineEdit->text());

        train();
        saveModel();
    }
}

void View::classifyDirectoryButton()
{
    if (ui->dirLineEdit->text().isEmpty() ||
        ui->predLocLineEdit->text().isEmpty() ||
        ui->tcModelLineEdit->text().isEmpty())
        showWarning("Please, fill all necessary fields");
    else
    {
        setCurrDir(ui->dirLineEdit->text());
        setUserLocationFileName(ui->predLocLineEdit->text());
        setModelFileName(ui->tcModelLineEdit->text());

        loadModel();
        classifyDirectory();
    }
}

void View::estimateQualityButton()
{
    if (ui->trueLocLineEdit->text().isEmpty() ||
        ui->predLocLineEdit->text().isEmpty())
        showWarning("Please, fill all necessary fields");
    else
    {
        setTrueLocationFileName(ui->trueLocLineEdit->text());
        setUserLocationFileName(ui->predLocLineEdit->text());

        estimateQuality();

        ui->precisionValue->setEnabled(true);
        ui->precisionValue->setText(QString::number(m_precision));
        ui->recallValue->setEnabled(true);
        ui->recallValue->setText(QString::number(m_recall));
        ui->fScoreValue->setEnabled(true);
        ui->fScoreValue->setText(QString::number(m_fScore));
    }
}

void View::scanImageButton()
{
    if (ui->siModelLineEdit->text().isEmpty() ||
        ui->imageForScanLineEdit->text().isEmpty())
        showWarning("Please, fill all necessary fields");
    else
    {
        setModelFileName(ui->siModelLineEdit->text());

        loadModel();
        scanImage(ui->imageForScanLineEdit->text());
    }
}
