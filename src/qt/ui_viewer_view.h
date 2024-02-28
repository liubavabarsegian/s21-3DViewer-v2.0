/********************************************************************************
** Form generated from reading UI file 'viewer_view.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_VIEW_H
#define UI_VIEWER_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

#include "opengl.h"

QT_BEGIN_NAMESPACE

class Ui_ViewerView {
 public:
  QWidget *centralwidget;
  QLabel *label;
  QLineEdit *inputFile;
  QPushButton *openFileButton;
  QLabel *label_3;
  QTabWidget *tabWidget;
  QWidget *verticles;
  QLabel *label_7;
  QSlider *verticlesSlider;
  QRadioButton *noVerticles;
  QRadioButton *circleVerticles;
  QRadioButton *squareVerticles;
  QPushButton *verticlesColor;
  QWidget *edges;
  QLabel *label_4;
  QRadioButton *edgesSolid;
  QRadioButton *edgesDashed;
  QLabel *label_5;
  QSlider *edgesSize;
  QPushButton *edgesColor;
  QWidget *background;
  QPushButton *backgroundColor;
  QLabel *label_10;
  QLabel *label_11;
  QLabel *label_12;
  QLabel *label_13;
  QLabel *label_14;
  QLabel *label_15;
  QLabel *label_16;
  QLabel *label_17;
  QLabel *label_18;
  QLabel *label_19;
  QLabel *label_20;
  QLabel *label_21;
  QPushButton *inputFileButton;
  QPushButton *recordButton;
  QPushButton *saveButton;
  QLabel *filenameLabel;
  QLabel *verticlesLabel;
  QLabel *edgesLabel;
  QPushButton *x_dec;
  QPushButton *x_inc;
  QPushButton *y_dec;
  QPushButton *y_inc;
  QPushButton *z_dec;
  QPushButton *z_inc;
  QPushButton *z_dec_2;
  QPushButton *z_inc_2;
  QPushButton *x_inc_2;
  QPushButton *x_dec_2;
  QPushButton *y_dec_2;
  QPushButton *y_inc_2;
  QPushButton *scaleInc;
  QPushButton *scaleDec;
  QRadioButton *centralRadio;
  QRadioButton *parallelRadio;
  s21::OpenGL *viewerWidget;
  QMenuBar *menubar;
  QStatusBar *statusbar;
  QButtonGroup *buttonGroup;
  QButtonGroup *buttonGroup_2;

  void setupUi(QMainWindow *ViewerView) {
    if (ViewerView->objectName().isEmpty())
      ViewerView->setObjectName("ViewerView");
    ViewerView->resize(1300, 917);
#if QT_CONFIG(tooltip)
    ViewerView->setToolTip(QString::fromUtf8(""));
#endif  // QT_CONFIG(tooltip)
    ViewerView->setStyleSheet(
        QString::fromUtf8("background-color: rgb(12, 11, 60);\n"
                          ""));
    centralwidget = new QWidget(ViewerView);
    centralwidget->setObjectName("centralwidget");
    label = new QLabel(centralwidget);
    label->setObjectName("label");
    label->setGeometry(QRect(40, 40, 171, 31));
    QFont font;
    font.setFamilies({QString::fromUtf8("PT Mono")});
    font.setPointSize(23);
    font.setBold(false);
    font.setItalic(false);
    font.setUnderline(false);
    font.setStrikeOut(false);
    label->setFont(font);
    label->setStyleSheet(QString::fromUtf8("color: white"));
    inputFile = new QLineEdit(centralwidget);
    inputFile->setObjectName("inputFile");
    inputFile->setGeometry(QRect(970, 80, 241, 31));
    QFont font1;
    font1.setFamilies({QString::fromUtf8("PT Mono")});
    inputFile->setFont(font1);
    inputFile->setStyleSheet(
        QString::fromUtf8("background-color:  rgb(153, 193, 241);\n"
                          "color: rgb(22, 7, 83);\n"
                          "border-radius: 10px;\n"
                          ""));
    inputFile->setReadOnly(true);
    openFileButton = new QPushButton(centralwidget);
    openFileButton->setObjectName("openFileButton");
    openFileButton->setGeometry(QRect(970, 120, 301, 41));
    QFont font2;
    font2.setFamilies({QString::fromUtf8("PT Mono")});
    font2.setPointSize(14);
    font2.setBold(true);
    font2.setItalic(true);
    openFileButton->setFont(font2);
    openFileButton->setStyleSheet(
        QString::fromUtf8("color: rgb(0, 15, 88);\n"
                          "background-color: rgb(153, 193, 241);\n"
                          "border-radius: 20px;"));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(970, 190, 141, 17));
    QFont font3;
    font3.setFamilies({QString::fromUtf8("PT Mono")});
    font3.setPointSize(13);
    label_3->setFont(font3);
    label_3->setStyleSheet(QString::fromUtf8("color: white"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName("tabWidget");
    tabWidget->setEnabled(true);
    tabWidget->setGeometry(QRect(980, 230, 291, 181));
    QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding,
                           QSizePolicy::Policy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
    tabWidget->setSizePolicy(sizePolicy);
    tabWidget->setMaximumSize(QSize(291, 16777215));
    tabWidget->setFont(font1);
    verticles = new QWidget();
    verticles->setObjectName("verticles");
    verticles->setStyleSheet(QString::fromUtf8(""));
    label_7 = new QLabel(verticles);
    label_7->setObjectName("label_7");
    label_7->setGeometry(QRect(20, 110, 31, 17));
    label_7->setFont(font1);
    label_7->setStyleSheet(QString::fromUtf8("color: white"));
    verticlesSlider = new QSlider(verticles);
    verticlesSlider->setObjectName("verticlesSlider");
    verticlesSlider->setGeometry(QRect(70, 110, 91, 16));
    verticlesSlider->setFont(font1);
    verticlesSlider->setMinimum(40);
    verticlesSlider->setMaximum(150);
    verticlesSlider->setOrientation(Qt::Horizontal);
    noVerticles = new QRadioButton(verticles);
    noVerticles->setObjectName("noVerticles");
    noVerticles->setGeometry(QRect(10, 30, 61, 23));
    noVerticles->setFont(font1);
    noVerticles->setStyleSheet(QString::fromUtf8("color: white;"));
    circleVerticles = new QRadioButton(verticles);
    circleVerticles->setObjectName("circleVerticles");
    circleVerticles->setGeometry(QRect(100, 30, 71, 23));
    circleVerticles->setFont(font1);
    circleVerticles->setStyleSheet(QString::fromUtf8("color: white;"));
    squareVerticles = new QRadioButton(verticles);
    squareVerticles->setObjectName("squareVerticles");
    squareVerticles->setGeometry(QRect(190, 30, 91, 23));
    squareVerticles->setFont(font1);
    squareVerticles->setStyleSheet(QString::fromUtf8("color: white;"));
    verticlesColor = new QPushButton(verticles);
    verticlesColor->setObjectName("verticlesColor");
    verticlesColor->setGeometry(QRect(190, 90, 91, 31));
    verticlesColor->setFont(font1);
    verticlesColor->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    tabWidget->addTab(verticles, QString());
    edges = new QWidget();
    edges->setObjectName("edges");
    label_4 = new QLabel(edges);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(70, 20, 111, 21));
    label_4->setStyleSheet(QString::fromUtf8("color: white;"));
    label_4->setScaledContents(false);
    label_4->setAlignment(Qt::AlignCenter);
    label_4->setOpenExternalLinks(false);
    edgesSolid = new QRadioButton(edges);
    buttonGroup = new QButtonGroup(ViewerView);
    buttonGroup->setObjectName("buttonGroup");
    buttonGroup->addButton(edgesSolid);
    edgesSolid->setObjectName("edgesSolid");
    edgesSolid->setGeometry(QRect(0, 60, 112, 23));
    edgesSolid->setStyleSheet(QString::fromUtf8("color: white;"));
    edgesDashed = new QRadioButton(edges);
    buttonGroup->addButton(edgesDashed);
    edgesDashed->setObjectName("edgesDashed");
    edgesDashed->setGeometry(QRect(170, 60, 112, 23));
    edgesDashed->setStyleSheet(QString::fromUtf8("color: white;"));
    label_5 = new QLabel(edges);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(0, 110, 31, 17));
    label_5->setStyleSheet(QString::fromUtf8("color: white"));
    edgesSize = new QSlider(edges);
    edgesSize->setObjectName("edgesSize");
    edgesSize->setGeometry(QRect(50, 110, 91, 16));
    edgesSize->setMinimum(1);
    edgesSize->setMaximum(50);
    edgesSize->setOrientation(Qt::Horizontal);
    edgesColor = new QPushButton(edges);
    edgesColor->setObjectName("edgesColor");
    edgesColor->setGeometry(QRect(170, 100, 101, 31));
    edgesColor->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    tabWidget->addTab(edges, QString());
    background = new QWidget();
    background->setObjectName("background");
    backgroundColor = new QPushButton(background);
    backgroundColor->setObjectName("backgroundColor");
    backgroundColor->setGeometry(QRect(40, 50, 211, 41));
    QFont font4;
    font4.setPointSize(14);
    backgroundColor->setFont(font4);
    backgroundColor->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    tabWidget->addTab(background, QString());
    label_10 = new QLabel(centralwidget);
    label_10->setObjectName("label_10");
    label_10->setGeometry(QRect(980, 420, 67, 17));
    label_10->setFont(font1);
    label_10->setStyleSheet(QString::fromUtf8("color: white;"));
    label_11 = new QLabel(centralwidget);
    label_11->setObjectName("label_11");
    label_11->setGeometry(QRect(980, 530, 42, 17));
    QFont font5;
    font5.setFamilies({QString::fromUtf8("PT Mono")});
    font5.setPointSize(14);
    label_11->setFont(font5);
    label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
    label_12 = new QLabel(centralwidget);
    label_12->setObjectName("label_12");
    label_12->setGeometry(QRect(1060, 490, 21, 16));
    label_12->setFont(font1);
    label_12->setStyleSheet(QString::fromUtf8("color: white;"));
    label_13 = new QLabel(centralwidget);
    label_13->setObjectName("label_13");
    label_13->setGeometry(QRect(1060, 520, 21, 16));
    label_13->setFont(font1);
    label_13->setStyleSheet(QString::fromUtf8("color: white;"));
    label_14 = new QLabel(centralwidget);
    label_14->setObjectName("label_14");
    label_14->setGeometry(QRect(1060, 550, 21, 16));
    label_14->setFont(font1);
    label_14->setStyleSheet(QString::fromUtf8("color: white;"));
    label_15 = new QLabel(centralwidget);
    label_15->setObjectName("label_15");
    label_15->setGeometry(QRect(1060, 700, 21, 16));
    label_15->setFont(font1);
    label_15->setStyleSheet(QString::fromUtf8("color: white;"));
    label_16 = new QLabel(centralwidget);
    label_16->setObjectName("label_16");
    label_16->setGeometry(QRect(1060, 670, 21, 16));
    label_16->setFont(font1);
    label_16->setStyleSheet(QString::fromUtf8("color: white;"));
    label_17 = new QLabel(centralwidget);
    label_17->setObjectName("label_17");
    label_17->setGeometry(QRect(970, 670, 81, 16));
    label_17->setFont(font3);
    label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
    label_18 = new QLabel(centralwidget);
    label_18->setObjectName("label_18");
    label_18->setGeometry(QRect(1060, 640, 21, 16));
    label_18->setFont(font1);
    label_18->setStyleSheet(QString::fromUtf8("color: white;"));
    label_19 = new QLabel(centralwidget);
    label_19->setObjectName("label_19");
    label_19->setGeometry(QRect(70, 760, 81, 21));
    QFont font6;
    font6.setFamilies({QString::fromUtf8("PT Mono")});
    font6.setPointSize(15);
    label_19->setFont(font6);
    label_19->setStyleSheet(QString::fromUtf8("color: white;"));
    label_20 = new QLabel(centralwidget);
    label_20->setObjectName("label_20");
    label_20->setGeometry(QRect(240, 760, 81, 21));
    label_20->setFont(font6);
    label_20->setStyleSheet(QString::fromUtf8("color: white;"));
    label_21 = new QLabel(centralwidget);
    label_21->setObjectName("label_21");
    label_21->setGeometry(QRect(400, 760, 67, 21));
    label_21->setFont(font6);
    label_21->setStyleSheet(QString::fromUtf8("color: white;"));
    inputFileButton = new QPushButton(centralwidget);
    inputFileButton->setObjectName("inputFileButton");
    inputFileButton->setGeometry(QRect(1220, 70, 71, 41));
    inputFileButton->setFont(font1);
    inputFileButton->setStyleSheet(QString::fromUtf8(""));
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/imgs/folder.png"), QSize(), QIcon::Normal,
                 QIcon::Off);
    inputFileButton->setIcon(icon);
    inputFileButton->setIconSize(QSize(50, 50));
    recordButton = new QPushButton(centralwidget);
    recordButton->setObjectName("recordButton");
    recordButton->setGeometry(QRect(560, 750, 61, 51));
    recordButton->setFont(font1);
    recordButton->setStyleSheet(QString::fromUtf8(""));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/imgs/camera.png"), QSize(),
                  QIcon::Normal, QIcon::Off);
    recordButton->setIcon(icon1);
    recordButton->setIconSize(QSize(50, 50));
    saveButton = new QPushButton(centralwidget);
    saveButton->setObjectName("saveButton");
    saveButton->setGeometry(QRect(650, 760, 91, 41));
    saveButton->setFont(font1);
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/imgs/save.png"), QSize(), QIcon::Normal,
                  QIcon::Off);
    saveButton->setIcon(icon2);
    saveButton->setIconSize(QSize(50, 50));
    filenameLabel = new QLabel(centralwidget);
    filenameLabel->setObjectName("filenameLabel");
    filenameLabel->setGeometry(QRect(70, 800, 131, 21));
    filenameLabel->setFont(font5);
    filenameLabel->setStyleSheet(QString::fromUtf8("color: white;"));
    verticlesLabel = new QLabel(centralwidget);
    verticlesLabel->setObjectName("verticlesLabel");
    verticlesLabel->setGeometry(QRect(240, 800, 111, 21));
    verticlesLabel->setFont(font5);
    verticlesLabel->setStyleSheet(QString::fromUtf8("color: white;"));
    edgesLabel = new QLabel(centralwidget);
    edgesLabel->setObjectName("edgesLabel");
    edgesLabel->setGeometry(QRect(400, 800, 91, 21));
    edgesLabel->setFont(font5);
    edgesLabel->setStyleSheet(QString::fromUtf8("color: white;"));
    x_dec = new QPushButton(centralwidget);
    x_dec->setObjectName("x_dec");
    x_dec->setGeometry(QRect(1090, 480, 81, 31));
    x_dec->setFont(font1);
    x_dec->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    x_inc = new QPushButton(centralwidget);
    x_inc->setObjectName("x_inc");
    x_inc->setGeometry(QRect(1180, 480, 81, 31));
    x_inc->setFont(font1);
    x_inc->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    y_dec = new QPushButton(centralwidget);
    y_dec->setObjectName("y_dec");
    y_dec->setGeometry(QRect(1090, 520, 81, 31));
    y_dec->setFont(font1);
    y_dec->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    y_inc = new QPushButton(centralwidget);
    y_inc->setObjectName("y_inc");
    y_inc->setGeometry(QRect(1180, 520, 81, 31));
    y_inc->setFont(font1);
    y_inc->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    z_dec = new QPushButton(centralwidget);
    z_dec->setObjectName("z_dec");
    z_dec->setGeometry(QRect(1090, 560, 81, 31));
    z_dec->setFont(font1);
    z_dec->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    z_inc = new QPushButton(centralwidget);
    z_inc->setObjectName("z_inc");
    z_inc->setGeometry(QRect(1180, 560, 81, 31));
    z_inc->setFont(font1);
    z_inc->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    z_dec_2 = new QPushButton(centralwidget);
    z_dec_2->setObjectName("z_dec_2");
    z_dec_2->setGeometry(QRect(1090, 700, 81, 31));
    z_dec_2->setFont(font1);
    z_dec_2->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    z_inc_2 = new QPushButton(centralwidget);
    z_inc_2->setObjectName("z_inc_2");
    z_inc_2->setGeometry(QRect(1180, 700, 81, 31));
    z_inc_2->setFont(font1);
    z_inc_2->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    x_inc_2 = new QPushButton(centralwidget);
    x_inc_2->setObjectName("x_inc_2");
    x_inc_2->setGeometry(QRect(1180, 620, 81, 31));
    x_inc_2->setFont(font1);
    x_inc_2->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    x_dec_2 = new QPushButton(centralwidget);
    x_dec_2->setObjectName("x_dec_2");
    x_dec_2->setGeometry(QRect(1090, 620, 81, 31));
    x_dec_2->setFont(font1);
    x_dec_2->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    y_dec_2 = new QPushButton(centralwidget);
    y_dec_2->setObjectName("y_dec_2");
    y_dec_2->setGeometry(QRect(1090, 660, 81, 31));
    y_dec_2->setFont(font1);
    y_dec_2->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    y_inc_2 = new QPushButton(centralwidget);
    y_inc_2->setObjectName("y_inc_2");
    y_inc_2->setGeometry(QRect(1180, 660, 81, 31));
    y_inc_2->setFont(font1);
    y_inc_2->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);"));
    scaleInc = new QPushButton(centralwidget);
    scaleInc->setObjectName("scaleInc");
    scaleInc->setGeometry(QRect(1180, 410, 81, 31));
    scaleInc->setFont(font1);
    scaleInc->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);\n"
                          "border-radius: 20px;"));
    scaleDec = new QPushButton(centralwidget);
    scaleDec->setObjectName("scaleDec");
    scaleDec->setGeometry(QRect(1090, 410, 81, 31));
    scaleDec->setFont(font1);
    scaleDec->setStyleSheet(
        QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
                          "color: rgb(0, 15, 88);\n"
                          "border-radius: 20px;"));
    centralRadio = new QRadioButton(centralwidget);
    buttonGroup_2 = new QButtonGroup(ViewerView);
    buttonGroup_2->setObjectName("buttonGroup_2");
    buttonGroup_2->addButton(centralRadio);
    centralRadio->setObjectName("centralRadio");
    centralRadio->setGeometry(QRect(1140, 170, 111, 21));
    centralRadio->setFont(font1);
    centralRadio->setStyleSheet(QString::fromUtf8("color: white;"));
    parallelRadio = new QRadioButton(centralwidget);
    buttonGroup_2->addButton(parallelRadio);
    parallelRadio->setObjectName("parallelRadio");
    parallelRadio->setGeometry(QRect(1140, 200, 112, 23));
    parallelRadio->setFont(font1);
    parallelRadio->setStyleSheet(QString::fromUtf8("color: white;"));
    viewerWidget = new s21::OpenGL(centralwidget);
    viewerWidget->setObjectName("viewerWidget");
    viewerWidget->setGeometry(QRect(30, 100, 901, 601));
    viewerWidget->setFont(font1);
    ViewerView->setCentralWidget(centralwidget);
    inputFileButton->raise();
    label->raise();
    inputFile->raise();
    openFileButton->raise();
    label_3->raise();
    tabWidget->raise();
    label_10->raise();
    label_11->raise();
    label_12->raise();
    label_13->raise();
    label_14->raise();
    label_15->raise();
    label_16->raise();
    label_17->raise();
    label_18->raise();
    label_19->raise();
    label_20->raise();
    label_21->raise();
    recordButton->raise();
    saveButton->raise();
    filenameLabel->raise();
    verticlesLabel->raise();
    edgesLabel->raise();
    x_dec->raise();
    x_inc->raise();
    y_dec->raise();
    y_inc->raise();
    z_dec->raise();
    z_inc->raise();
    z_dec_2->raise();
    z_inc_2->raise();
    x_inc_2->raise();
    x_dec_2->raise();
    y_dec_2->raise();
    y_inc_2->raise();
    scaleInc->raise();
    scaleDec->raise();
    centralRadio->raise();
    parallelRadio->raise();
    viewerWidget->raise();
    menubar = new QMenuBar(ViewerView);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 1300, 37));
    ViewerView->setMenuBar(menubar);
    statusbar = new QStatusBar(ViewerView);
    statusbar->setObjectName("statusbar");
    ViewerView->setStatusBar(statusbar);

    retranslateUi(ViewerView);

    tabWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(ViewerView);
  }  // setupUi

  void retranslateUi(QMainWindow *ViewerView) {
    ViewerView->setWindowTitle(
        QCoreApplication::translate("ViewerView", "MainWindow", nullptr));
    label->setText(
        QCoreApplication::translate("ViewerView", "3D VIEWER", nullptr));
    openFileButton->setText(
        QCoreApplication::translate("ViewerView", "DRAW MODEL", nullptr));
    label_3->setText(QCoreApplication::translate(
        "ViewerView", "Type of projection", nullptr));
    label_7->setText(
        QCoreApplication::translate("ViewerView", "Size", nullptr));
    noVerticles->setText(
        QCoreApplication::translate("ViewerView", "none", nullptr));
    circleVerticles->setText(
        QCoreApplication::translate("ViewerView", "circle", nullptr));
    squareVerticles->setText(
        QCoreApplication::translate("ViewerView", "square", nullptr));
    verticlesColor->setText(
        QCoreApplication::translate("ViewerView", "Pick color", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(verticles),
        QCoreApplication::translate("ViewerView", " Verticles ", nullptr));
    label_4->setText(
        QCoreApplication::translate("ViewerView", "Type", nullptr));
    edgesSolid->setText(
        QCoreApplication::translate("ViewerView", "solid", nullptr));
    edgesDashed->setText(
        QCoreApplication::translate("ViewerView", "dashed", nullptr));
    label_5->setText(
        QCoreApplication::translate("ViewerView", "Size", nullptr));
    edgesColor->setText(
        QCoreApplication::translate("ViewerView", "Pick color", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(edges),
        QCoreApplication::translate("ViewerView", "    Edges    ", nullptr));
    backgroundColor->setText(QCoreApplication::translate(
        "ViewerView", "Pick background color", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(background),
        QCoreApplication::translate("ViewerView", "Background", nullptr));
    label_10->setText(
        QCoreApplication::translate("ViewerView", "Scale", nullptr));
    label_11->setText(
        QCoreApplication::translate("ViewerView", "Rotate", nullptr));
    label_12->setText(QCoreApplication::translate("ViewerView", "X", nullptr));
    label_13->setText(QCoreApplication::translate("ViewerView", "Y", nullptr));
    label_14->setText(QCoreApplication::translate("ViewerView", "Z", nullptr));
    label_15->setText(QCoreApplication::translate("ViewerView", "Z", nullptr));
    label_16->setText(QCoreApplication::translate("ViewerView", "Y", nullptr));
    label_17->setText(
        QCoreApplication::translate("ViewerView", "Translate", nullptr));
    label_18->setText(QCoreApplication::translate("ViewerView", "X", nullptr));
    label_19->setText(
        QCoreApplication::translate("ViewerView", "filename", nullptr));
    label_20->setText(
        QCoreApplication::translate("ViewerView", "verticles", nullptr));
    label_21->setText(
        QCoreApplication::translate("ViewerView", "edges", nullptr));
    inputFileButton->setText(QString());
    recordButton->setText(QString());
    saveButton->setText(QString());
    filenameLabel->setText(QString());
    verticlesLabel->setText(QString());
    edgesLabel->setText(QString());
    x_dec->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    x_inc->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    y_dec->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    y_inc->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    z_dec->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    z_inc->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    z_dec_2->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    z_inc_2->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    x_inc_2->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    x_dec_2->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    y_dec_2->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    y_inc_2->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    scaleInc->setText(QCoreApplication::translate("ViewerView", "+", nullptr));
    scaleDec->setText(QCoreApplication::translate("ViewerView", "-", nullptr));
    centralRadio->setText(
        QCoreApplication::translate("ViewerView", "Central", nullptr));
    parallelRadio->setText(
        QCoreApplication::translate("ViewerView", "Parallel", nullptr));
  }  // retranslateUi
};

namespace Ui {
class ViewerView : public Ui_ViewerView {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_VIEWER_VIEW_H
