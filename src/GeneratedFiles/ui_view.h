/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created: Mon Oct 22 13:12:54 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QTabWidget *mainTabWidget;
    QWidget *tcTab;
    QWidget *gridLayoutWidget;
    QGridLayout *tcMainGridLayout;
    QLineEdit *dirLineEdit;
    QPushButton *dirBrowse;
    QLabel *dirLabel;
    QLabel *tcModelLabel;
    QLineEdit *tcModelLineEdit;
    QPushButton *tcModelBrowse;
    QLineEdit *predLocLineEdit;
    QPushButton *predLocBrowse;
    QLabel *predLocLabel;
    QHBoxLayout *mainButtonsLayout;
    QPushButton *trainButton;
    QPushButton *classifyDirectoryButton;
    QPushButton *estimateQualityButton;
    QLabel *precisionLabel;
    QLabel *precisionValue;
    QLabel *recallLabel;
    QLabel *recallValue;
    QLabel *fScoreLabel;
    QLabel *fScoreValue;
    QSpacerItem *prfHorizontalSpacer2;
    QSpacerItem *horizontalSpacer;
    QLabel *trueLocLabel;
    QLineEdit *trueLocLineEdit;
    QPushButton *trueLocBrowse;
    QSpacerItem *prfHorizontalSpacer1;
    QWidget *siTab;
    QWidget *gridLayoutWidget_5;
    QGridLayout *siMainGridLayout;
    QLabel *imageForScanLabel;
    QLineEdit *imageForScanLineEdit;
    QPushButton *imageForScanBrowse;
    QLineEdit *siModelLineEdit;
    QLabel *siModelLabel;
    QPushButton *siModelBrowse;
    QPushButton *scanImageButton;
    QScrollArea *siScrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(500, 375);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(View->sizePolicy().hasHeightForWidth());
        View->setSizePolicy(sizePolicy);
        mainTabWidget = new QTabWidget(View);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        mainTabWidget->setGeometry(QRect(10, 9, 485, 360));
        tcTab = new QWidget();
        tcTab->setObjectName(QString::fromUtf8("tcTab"));
        gridLayoutWidget = new QWidget(tcTab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 461, 321));
        tcMainGridLayout = new QGridLayout(gridLayoutWidget);
        tcMainGridLayout->setObjectName(QString::fromUtf8("tcMainGridLayout"));
        tcMainGridLayout->setContentsMargins(0, 0, 0, 0);
        dirLineEdit = new QLineEdit(gridLayoutWidget);
        dirLineEdit->setObjectName(QString::fromUtf8("dirLineEdit"));

        tcMainGridLayout->addWidget(dirLineEdit, 3, 0, 1, 7);

        dirBrowse = new QPushButton(gridLayoutWidget);
        dirBrowse->setObjectName(QString::fromUtf8("dirBrowse"));

        tcMainGridLayout->addWidget(dirBrowse, 3, 7, 1, 1);

        dirLabel = new QLabel(gridLayoutWidget);
        dirLabel->setObjectName(QString::fromUtf8("dirLabel"));

        tcMainGridLayout->addWidget(dirLabel, 2, 0, 1, 7);

        tcModelLabel = new QLabel(gridLayoutWidget);
        tcModelLabel->setObjectName(QString::fromUtf8("tcModelLabel"));

        tcMainGridLayout->addWidget(tcModelLabel, 0, 0, 1, 7);

        tcModelLineEdit = new QLineEdit(gridLayoutWidget);
        tcModelLineEdit->setObjectName(QString::fromUtf8("tcModelLineEdit"));

        tcMainGridLayout->addWidget(tcModelLineEdit, 1, 0, 1, 7);

        tcModelBrowse = new QPushButton(gridLayoutWidget);
        tcModelBrowse->setObjectName(QString::fromUtf8("tcModelBrowse"));

        tcMainGridLayout->addWidget(tcModelBrowse, 1, 7, 1, 1);

        predLocLineEdit = new QLineEdit(gridLayoutWidget);
        predLocLineEdit->setObjectName(QString::fromUtf8("predLocLineEdit"));

        tcMainGridLayout->addWidget(predLocLineEdit, 7, 0, 1, 7);

        predLocBrowse = new QPushButton(gridLayoutWidget);
        predLocBrowse->setObjectName(QString::fromUtf8("predLocBrowse"));

        tcMainGridLayout->addWidget(predLocBrowse, 7, 7, 1, 1);

        predLocLabel = new QLabel(gridLayoutWidget);
        predLocLabel->setObjectName(QString::fromUtf8("predLocLabel"));

        tcMainGridLayout->addWidget(predLocLabel, 6, 0, 1, 7);

        mainButtonsLayout = new QHBoxLayout();
        mainButtonsLayout->setObjectName(QString::fromUtf8("mainButtonsLayout"));
        trainButton = new QPushButton(gridLayoutWidget);
        trainButton->setObjectName(QString::fromUtf8("trainButton"));
        trainButton->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(trainButton->sizePolicy().hasHeightForWidth());
        trainButton->setSizePolicy(sizePolicy1);

        mainButtonsLayout->addWidget(trainButton);

        classifyDirectoryButton = new QPushButton(gridLayoutWidget);
        classifyDirectoryButton->setObjectName(QString::fromUtf8("classifyDirectoryButton"));
        sizePolicy1.setHeightForWidth(classifyDirectoryButton->sizePolicy().hasHeightForWidth());
        classifyDirectoryButton->setSizePolicy(sizePolicy1);

        mainButtonsLayout->addWidget(classifyDirectoryButton);

        estimateQualityButton = new QPushButton(gridLayoutWidget);
        estimateQualityButton->setObjectName(QString::fromUtf8("estimateQualityButton"));
        sizePolicy1.setHeightForWidth(estimateQualityButton->sizePolicy().hasHeightForWidth());
        estimateQualityButton->setSizePolicy(sizePolicy1);

        mainButtonsLayout->addWidget(estimateQualityButton);


        tcMainGridLayout->addLayout(mainButtonsLayout, 11, 0, 1, 8);

        precisionLabel = new QLabel(gridLayoutWidget);
        precisionLabel->setObjectName(QString::fromUtf8("precisionLabel"));

        tcMainGridLayout->addWidget(precisionLabel, 12, 0, 1, 1);

        precisionValue = new QLabel(gridLayoutWidget);
        precisionValue->setObjectName(QString::fromUtf8("precisionValue"));
        precisionValue->setEnabled(false);

        tcMainGridLayout->addWidget(precisionValue, 12, 1, 1, 1);

        recallLabel = new QLabel(gridLayoutWidget);
        recallLabel->setObjectName(QString::fromUtf8("recallLabel"));

        tcMainGridLayout->addWidget(recallLabel, 12, 3, 1, 1);

        recallValue = new QLabel(gridLayoutWidget);
        recallValue->setObjectName(QString::fromUtf8("recallValue"));
        recallValue->setEnabled(false);

        tcMainGridLayout->addWidget(recallValue, 12, 4, 1, 1);

        fScoreLabel = new QLabel(gridLayoutWidget);
        fScoreLabel->setObjectName(QString::fromUtf8("fScoreLabel"));

        tcMainGridLayout->addWidget(fScoreLabel, 12, 6, 1, 1);

        fScoreValue = new QLabel(gridLayoutWidget);
        fScoreValue->setObjectName(QString::fromUtf8("fScoreValue"));
        fScoreValue->setEnabled(false);

        tcMainGridLayout->addWidget(fScoreValue, 12, 7, 1, 1);

        prfHorizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        tcMainGridLayout->addItem(prfHorizontalSpacer2, 12, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tcMainGridLayout->addItem(horizontalSpacer, 10, 0, 1, 8);

        trueLocLabel = new QLabel(gridLayoutWidget);
        trueLocLabel->setObjectName(QString::fromUtf8("trueLocLabel"));

        tcMainGridLayout->addWidget(trueLocLabel, 4, 0, 1, 7);

        trueLocLineEdit = new QLineEdit(gridLayoutWidget);
        trueLocLineEdit->setObjectName(QString::fromUtf8("trueLocLineEdit"));

        tcMainGridLayout->addWidget(trueLocLineEdit, 5, 0, 1, 7);

        trueLocBrowse = new QPushButton(gridLayoutWidget);
        trueLocBrowse->setObjectName(QString::fromUtf8("trueLocBrowse"));

        tcMainGridLayout->addWidget(trueLocBrowse, 5, 7, 1, 1);

        prfHorizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        tcMainGridLayout->addItem(prfHorizontalSpacer1, 12, 2, 1, 1);

        mainTabWidget->addTab(tcTab, QString());
        siTab = new QWidget();
        siTab->setObjectName(QString::fromUtf8("siTab"));
        gridLayoutWidget_5 = new QWidget(siTab);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 10, 461, 321));
        siMainGridLayout = new QGridLayout(gridLayoutWidget_5);
        siMainGridLayout->setObjectName(QString::fromUtf8("siMainGridLayout"));
        siMainGridLayout->setContentsMargins(0, 0, 0, 0);
        imageForScanLabel = new QLabel(gridLayoutWidget_5);
        imageForScanLabel->setObjectName(QString::fromUtf8("imageForScanLabel"));

        siMainGridLayout->addWidget(imageForScanLabel, 2, 0, 1, 1);

        imageForScanLineEdit = new QLineEdit(gridLayoutWidget_5);
        imageForScanLineEdit->setObjectName(QString::fromUtf8("imageForScanLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageForScanLineEdit->sizePolicy().hasHeightForWidth());
        imageForScanLineEdit->setSizePolicy(sizePolicy2);

        siMainGridLayout->addWidget(imageForScanLineEdit, 3, 0, 1, 1);

        imageForScanBrowse = new QPushButton(gridLayoutWidget_5);
        imageForScanBrowse->setObjectName(QString::fromUtf8("imageForScanBrowse"));

        siMainGridLayout->addWidget(imageForScanBrowse, 3, 1, 1, 1);

        siModelLineEdit = new QLineEdit(gridLayoutWidget_5);
        siModelLineEdit->setObjectName(QString::fromUtf8("siModelLineEdit"));

        siMainGridLayout->addWidget(siModelLineEdit, 1, 0, 1, 1);

        siModelLabel = new QLabel(gridLayoutWidget_5);
        siModelLabel->setObjectName(QString::fromUtf8("siModelLabel"));

        siMainGridLayout->addWidget(siModelLabel, 0, 0, 1, 1);

        siModelBrowse = new QPushButton(gridLayoutWidget_5);
        siModelBrowse->setObjectName(QString::fromUtf8("siModelBrowse"));

        siMainGridLayout->addWidget(siModelBrowse, 1, 1, 1, 1);

        scanImageButton = new QPushButton(gridLayoutWidget_5);
        scanImageButton->setObjectName(QString::fromUtf8("scanImageButton"));
        sizePolicy.setHeightForWidth(scanImageButton->sizePolicy().hasHeightForWidth());
        scanImageButton->setSizePolicy(sizePolicy);

        siMainGridLayout->addWidget(scanImageButton, 0, 2, 4, 1);

        siScrollArea = new QScrollArea(gridLayoutWidget_5);
        siScrollArea->setObjectName(QString::fromUtf8("siScrollArea"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(siScrollArea->sizePolicy().hasHeightForWidth());
        siScrollArea->setSizePolicy(sizePolicy3);
        siScrollArea->setMinimumSize(QSize(0, 220));
        siScrollArea->setFrameShape(QFrame::StyledPanel);
        siScrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 459, 199));
        siScrollArea->setWidget(scrollAreaWidgetContents);

        siMainGridLayout->addWidget(siScrollArea, 4, 0, 1, 3);

        mainTabWidget->addTab(siTab, QString());

        retranslateUi(View);
        QObject::connect(predLocBrowse, SIGNAL(clicked()), View, SLOT(chooseUserLocationFileButton()));
        QObject::connect(dirBrowse, SIGNAL(clicked()), View, SLOT(chooseDirButton()));
        QObject::connect(trueLocBrowse, SIGNAL(clicked()), View, SLOT(chooseTrueLocationFileButton()));
        QObject::connect(classifyDirectoryButton, SIGNAL(clicked()), View, SLOT(classifyDirectoryButton()));
        QObject::connect(estimateQualityButton, SIGNAL(clicked()), View, SLOT(estimateQualityButton()));
        QObject::connect(scanImageButton, SIGNAL(clicked()), View, SLOT(scanImageButton()));
        QObject::connect(imageForScanBrowse, SIGNAL(clicked()), View, SLOT(chooseImageForScan()));
        QObject::connect(tcModelBrowse, SIGNAL(clicked()), View, SLOT(chooseTCModelFileButton()));
        QObject::connect(siModelBrowse, SIGNAL(clicked()), View, SLOT(chooseSIModelFileButton()));
        QObject::connect(trainButton, SIGNAL(clicked()), View, SLOT(trainButton()));

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QWidget *View)
    {
        View->setWindowTitle(QApplication::translate("View", "Pedestrian Detector", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mainTabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        mainTabWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        mainTabWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        mainTabWidget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        mainTabWidget->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        dirBrowse->setText(QApplication::translate("View", "Browse...", 0, QApplication::UnicodeUTF8));
        dirLabel->setText(QApplication::translate("View", "Directory for train/classify:", 0, QApplication::UnicodeUTF8));
        tcModelLabel->setText(QApplication::translate("View", "Model file for save/load:", 0, QApplication::UnicodeUTF8));
        tcModelBrowse->setText(QApplication::translate("View", "Browse...", 0, QApplication::UnicodeUTF8));
        predLocBrowse->setText(QApplication::translate("View", "Browse...", 0, QApplication::UnicodeUTF8));
        predLocLabel->setText(QApplication::translate("View", "File with predicted pedestrian locations for save/load:", 0, QApplication::UnicodeUTF8));
        trainButton->setText(QApplication::translate("View", "Train", 0, QApplication::UnicodeUTF8));
        classifyDirectoryButton->setText(QApplication::translate("View", "Classify Directory", 0, QApplication::UnicodeUTF8));
        estimateQualityButton->setText(QApplication::translate("View", "Estimate Quality", 0, QApplication::UnicodeUTF8));
        precisionLabel->setText(QApplication::translate("View", "Precision:", 0, QApplication::UnicodeUTF8));
        precisionValue->setText(QApplication::translate("View", "0.0", 0, QApplication::UnicodeUTF8));
        recallLabel->setText(QApplication::translate("View", "Recall:", 0, QApplication::UnicodeUTF8));
        recallValue->setText(QApplication::translate("View", "0.0", 0, QApplication::UnicodeUTF8));
        fScoreLabel->setText(QApplication::translate("View", "F-score:", 0, QApplication::UnicodeUTF8));
        fScoreValue->setText(QApplication::translate("View", "0.0", 0, QApplication::UnicodeUTF8));
        trueLocLabel->setText(QApplication::translate("View", "File with true pedestrian locations:", 0, QApplication::UnicodeUTF8));
        trueLocBrowse->setText(QApplication::translate("View", "Browse...", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tcTab), QApplication::translate("View", "Train/Classify", 0, QApplication::UnicodeUTF8));
        imageForScanLabel->setText(QApplication::translate("View", "Image for scan:", 0, QApplication::UnicodeUTF8));
        imageForScanBrowse->setText(QApplication::translate("View", "Browse...", 0, QApplication::UnicodeUTF8));
        siModelLabel->setText(QApplication::translate("View", "Model file:", 0, QApplication::UnicodeUTF8));
        siModelBrowse->setText(QApplication::translate("View", "Browse...", 0, QApplication::UnicodeUTF8));
        scanImageButton->setText(QApplication::translate("View", "Scan Image", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(siTab), QApplication::translate("View", "Scan Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
