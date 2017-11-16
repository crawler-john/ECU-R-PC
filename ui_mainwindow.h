/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Nov 16 14:36:47 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_IP;
    QLineEdit *lineEdit_Port;
    QPushButton *btn_config;
    QGroupBox *groupBox_2;
    QPushButton *btn_baseInfo;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_ECUID;
    QLabel *label_4;
    QLabel *label_ECUModel;
    QLabel *label_7;
    QLabel *label_LifttimeEnergy;
    QLabel *label_8;
    QLabel *label_LastSystemPower;
    QLabel *label_17;
    QLabel *label_GenerationCurrentDay;
    QLabel *label_20;
    QLabel *label_LastToEMA;
    QLabel *label_21;
    QLabel *label_NumberInverters;
    QLabel *label_23;
    QLabel *label_LastNumberInverters;
    QLabel *label_25;
    QLabel *label_Version;
    QLabel *label_27;
    QLabel *label_TimeZone;
    QLabel *label_30;
    QLabel *label_29;
    QLabel *label_MacAddress;
    QLabel *label_WifiMac;
    QLabel *label_31;
    QLabel *label_level;
    QLabel *label_32;
    QLabel *label_channel;
    QLabel *label_33;
    QLabel *label_rsdType;
    QGroupBox *groupBox_3;
    QPushButton *btn_getTime;
    QPushButton *btn_setTime;
    QDateTimeEdit *dateTimeEdit;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QComboBox *comboBox;
    QPushButton *btn_setNetwork;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *l_1;
    QLineEdit *lineEdit_IPAddress;
    QLabel *l_2;
    QLabel *l_3;
    QLabel *l_4;
    QLabel *l_5;
    QLabel *l_6;
    QLabel *l_11;
    QLabel *l_7;
    QLabel *l_8;
    QLabel *l_9;
    QLabel *l_10;
    QLabel *l_12;
    QLabel *l_13;
    QLabel *l_14;
    QLabel *l_15;
    QLabel *l_17;
    QLabel *l_16;
    QLabel *l_18;
    QLabel *l_19;
    QLabel *l_20;
    QLineEdit *lineEdit_IPAddress2;
    QLineEdit *lineEdit_IPAddress3;
    QLineEdit *lineEdit_IPAddress4;
    QLineEdit *lineEdit_Mask;
    QLineEdit *lineEdit_Mask2;
    QLineEdit *lineEdit_Mask3;
    QLineEdit *lineEdit_Mask4;
    QLineEdit *lineEdit_gate;
    QLineEdit *lineEdit_gate2;
    QLineEdit *lineEdit_gate3;
    QLineEdit *lineEdit_gate4;
    QLineEdit *lineEdit_DNS1;
    QLineEdit *lineEdit_DNS12;
    QLineEdit *lineEdit_DNS13;
    QLineEdit *lineEdit_DNS14;
    QLineEdit *lineEdit_DNS2;
    QLineEdit *lineEdit_DNS22;
    QLineEdit *lineEdit_DNS23;
    QLineEdit *lineEdit_DNS24;
    QPushButton *btn_getNetwork;
    QGroupBox *groupBox_7;
    QLineEdit *lineEdit_ID;
    QLabel *label_15;
    QPushButton *btn_addID;
    QLabel *label_16;
    QPlainTextEdit *plainTextEdit_ID;
    QPushButton *btn_SetID;
    QPushButton *btn_ECUImport;
    QGroupBox *groupBox_8;
    QLineEdit *lineEdit_oldPasswd;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *btn_setPasswd;
    QLineEdit *lineEdit_newPasswd;
    QGroupBox *groupBox_12;
    QPushButton *btn_getTime_ECU;
    QDateTimeEdit *dateTimeEdit_ECU;
    QGroupBox *groupBox_5;
    QComboBox *comboBox_SetChannel;
    QLabel *label_9;
    QPushButton *btn_SetChannel;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_CurrentChannel;
    QLabel *label_Stren;
    QLabel *label_22;
    QComboBox *comboBox_OldChannel;
    QGroupBox *groupBox_27;
    QPushButton *btn_setFunction;
    QComboBox *comboBox_SetFunction;
    QGroupBox *groupBox_15;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_flashsize;
    QWidget *Tab_2;
    QGroupBox *groupBox_9;
    QTableWidget *tableWidget_RealData;
    QPushButton *btn_getRealData;
    QLabel *label_all;
    QLabel *label_42;
    QLabel *label_time;
    QLabel *label_43;
    QWidget *tab_2;
    QGroupBox *groupBox_10;
    QPushButton *btn_getPower;
    QTableWidget *tableWidget_Power;
    QLabel *label_44;
    QDateEdit *dateEdit;
    QPushButton *btn_getDate;
    QGroupBox *groupBox_11;
    QTableWidget *tableWidget_Energy;
    QPushButton *btn_getEnergy;
    QLabel *label_45;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_13;
    QPushButton *btn_getWIFI;
    QTableWidget *tableWidget_SSID;
    QLabel *label_49;
    QLabel *label_50;
    QPushButton *btn_connect;
    QLineEdit *lineEdit_SSID_2;
    QLineEdit *lineEdit_PassWD;
    QGroupBox *groupBox_14;
    QPushButton *pushButton;
    QLabel *label_LinkStatus;
    QLabel *label_48;
    QWidget *tab_4;
    QGroupBox *groupBox_16;
    QTableWidget *tableWidget_shortAddr;
    QPushButton *btn_getshortAddr;
    QProgressBar *progressBar;
    QLabel *label_6;
    QGroupBox *groupBox_17;
    QPushButton *btn_gethardware;
    QLabel *label_12;
    QLabel *label_wifiType;
    QWidget *tab_3;
    QGroupBox *groupBox_6;
    QComboBox *comboBox_UID;
    QLabel *label_73;
    QLabel *label_74;
    QDateEdit *dateEdit_2;
    QTableWidget *tableWidget_Info;
    QPushButton *btn_getInfo;
    QPushButton *btn_getDate_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 506);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 451));
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{\n"
"	background-image:url(img/mainwindow.jpg);\n"
"}\n"
"QGroupBox::title {\n"
"	color:#ff0000\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"background: rgb(237,216,255);\n"
"alternate-background-color:rgb(48,51,55);\n"
"selection-background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(237,216,255),stop:1 rgb(237,211,255));\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, 		stop:0 rgb(237,216,255),\n"
"	stop:1 rgb(237,211,255));\n"
"color: rgb(0,0,0);\n"
"padding-left: 4px;\n"
"border: 1px solid #383838;\n"
"}\n"
"QScrollBar:vertical \n"
"{\n"
"border: 0px solid grey;\n"
"background: transparent;\n"
"width: 15px;\n"
"margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical \n"
"{\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));\n"
"min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical \n"
"{\n"
"border: 0px solid grey;\n"
"background: rgb(66,66,66);\n"
"height: 20px;\n"
""
                        "subcontrol-position: bottom;\n"
"subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical \n"
"{\n"
"border: 0px solid grey;\n"
"background: rgb(56,56,56);\n"
"height: 20px;\n"
"subcontrol-position: top;\n"
"subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical \n"
"{\n"
"border: 0px solid grey;\n"
"width: 3px;\n"
"height: 3px;\n"
"background: rgb(46,46,46);\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"background: none;\n"
"}\n"
"\n"
"QPushButton{\n"
"color:#0000ff;\n"
"border:26px;\n"
"solid #FFFFFF;\n"
"border: 1px solid green;\n"
"border-radius:10px;\n"
"}\n"
"QPushButton:hover{\n"
"color:#FF0000;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 261, 71));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 16, 41, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 41, 21));
        lineEdit_IP = new QLineEdit(groupBox);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));
        lineEdit_IP->setGeometry(QRect(50, 16, 91, 20));
        lineEdit_Port = new QLineEdit(groupBox);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));
        lineEdit_Port->setGeometry(QRect(50, 41, 91, 20));
        btn_config = new QPushButton(groupBox);
        btn_config->setObjectName(QString::fromUtf8("btn_config"));
        btn_config->setGeometry(QRect(150, 15, 101, 31));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 70, 261, 351));
        btn_baseInfo = new QPushButton(groupBox_2);
        btn_baseInfo->setObjectName(QString::fromUtf8("btn_baseInfo"));
        btn_baseInfo->setGeometry(QRect(10, 20, 81, 23));
        gridLayoutWidget = new QWidget(groupBox_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 241, 302));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_ECUID = new QLineEdit(gridLayoutWidget);
        lineEdit_ECUID->setObjectName(QString::fromUtf8("lineEdit_ECUID"));

        gridLayout->addWidget(lineEdit_ECUID, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_ECUModel = new QLabel(gridLayoutWidget);
        label_ECUModel->setObjectName(QString::fromUtf8("label_ECUModel"));

        gridLayout->addWidget(label_ECUModel, 1, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_LifttimeEnergy = new QLabel(gridLayoutWidget);
        label_LifttimeEnergy->setObjectName(QString::fromUtf8("label_LifttimeEnergy"));

        gridLayout->addWidget(label_LifttimeEnergy, 2, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_LastSystemPower = new QLabel(gridLayoutWidget);
        label_LastSystemPower->setObjectName(QString::fromUtf8("label_LastSystemPower"));

        gridLayout->addWidget(label_LastSystemPower, 3, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 4, 0, 1, 1);

        label_GenerationCurrentDay = new QLabel(gridLayoutWidget);
        label_GenerationCurrentDay->setObjectName(QString::fromUtf8("label_GenerationCurrentDay"));

        gridLayout->addWidget(label_GenerationCurrentDay, 4, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 5, 0, 1, 1);

        label_LastToEMA = new QLabel(gridLayoutWidget);
        label_LastToEMA->setObjectName(QString::fromUtf8("label_LastToEMA"));

        gridLayout->addWidget(label_LastToEMA, 5, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 6, 0, 1, 1);

        label_NumberInverters = new QLabel(gridLayoutWidget);
        label_NumberInverters->setObjectName(QString::fromUtf8("label_NumberInverters"));

        gridLayout->addWidget(label_NumberInverters, 6, 1, 1, 1);

        label_23 = new QLabel(gridLayoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout->addWidget(label_23, 7, 0, 1, 1);

        label_LastNumberInverters = new QLabel(gridLayoutWidget);
        label_LastNumberInverters->setObjectName(QString::fromUtf8("label_LastNumberInverters"));

        gridLayout->addWidget(label_LastNumberInverters, 7, 1, 1, 1);

        label_25 = new QLabel(gridLayoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout->addWidget(label_25, 8, 0, 1, 1);

        label_Version = new QLabel(gridLayoutWidget);
        label_Version->setObjectName(QString::fromUtf8("label_Version"));

        gridLayout->addWidget(label_Version, 8, 1, 1, 1);

        label_27 = new QLabel(gridLayoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout->addWidget(label_27, 9, 0, 1, 1);

        label_TimeZone = new QLabel(gridLayoutWidget);
        label_TimeZone->setObjectName(QString::fromUtf8("label_TimeZone"));

        gridLayout->addWidget(label_TimeZone, 9, 1, 1, 1);

        label_30 = new QLabel(gridLayoutWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout->addWidget(label_30, 11, 0, 1, 1);

        label_29 = new QLabel(gridLayoutWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout->addWidget(label_29, 10, 0, 1, 1);

        label_MacAddress = new QLabel(gridLayoutWidget);
        label_MacAddress->setObjectName(QString::fromUtf8("label_MacAddress"));

        gridLayout->addWidget(label_MacAddress, 10, 1, 1, 1);

        label_WifiMac = new QLabel(gridLayoutWidget);
        label_WifiMac->setObjectName(QString::fromUtf8("label_WifiMac"));

        gridLayout->addWidget(label_WifiMac, 11, 1, 1, 1);

        label_31 = new QLabel(gridLayoutWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout->addWidget(label_31, 12, 0, 1, 1);

        label_level = new QLabel(gridLayoutWidget);
        label_level->setObjectName(QString::fromUtf8("label_level"));

        gridLayout->addWidget(label_level, 12, 1, 1, 1);

        label_32 = new QLabel(gridLayoutWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout->addWidget(label_32, 13, 0, 1, 1);

        label_channel = new QLabel(gridLayoutWidget);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));

        gridLayout->addWidget(label_channel, 13, 1, 1, 1);

        label_33 = new QLabel(gridLayoutWidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout->addWidget(label_33, 14, 0, 1, 1);

        label_rsdType = new QLabel(gridLayoutWidget);
        label_rsdType->setObjectName(QString::fromUtf8("label_rsdType"));

        gridLayout->addWidget(label_rsdType, 14, 1, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(270, 0, 271, 61));
        btn_getTime = new QPushButton(groupBox_3);
        btn_getTime->setObjectName(QString::fromUtf8("btn_getTime"));
        btn_getTime->setGeometry(QRect(170, 10, 81, 23));
        btn_setTime = new QPushButton(groupBox_3);
        btn_setTime->setObjectName(QString::fromUtf8("btn_setTime"));
        btn_setTime->setGeometry(QRect(170, 36, 81, 23));
        dateTimeEdit = new QDateTimeEdit(groupBox_3);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(10, 21, 141, 21));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(270, 100, 271, 181));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 54, 16));
        comboBox = new QComboBox(groupBox_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(51, 16, 69, 21));
        btn_setNetwork = new QPushButton(groupBox_4);
        btn_setNetwork->setObjectName(QString::fromUtf8("btn_setNetwork"));
        btn_setNetwork->setGeometry(QRect(126, 15, 51, 23));
        gridLayoutWidget_2 = new QWidget(groupBox_4);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 50, 254, 126));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        l_1 = new QLabel(gridLayoutWidget_2);
        l_1->setObjectName(QString::fromUtf8("l_1"));

        gridLayout_2->addWidget(l_1, 0, 0, 1, 1);

        lineEdit_IPAddress = new QLineEdit(gridLayoutWidget_2);
        lineEdit_IPAddress->setObjectName(QString::fromUtf8("lineEdit_IPAddress"));

        gridLayout_2->addWidget(lineEdit_IPAddress, 0, 1, 1, 1);

        l_2 = new QLabel(gridLayoutWidget_2);
        l_2->setObjectName(QString::fromUtf8("l_2"));

        gridLayout_2->addWidget(l_2, 1, 0, 1, 1);

        l_3 = new QLabel(gridLayoutWidget_2);
        l_3->setObjectName(QString::fromUtf8("l_3"));

        gridLayout_2->addWidget(l_3, 2, 0, 1, 1);

        l_4 = new QLabel(gridLayoutWidget_2);
        l_4->setObjectName(QString::fromUtf8("l_4"));

        gridLayout_2->addWidget(l_4, 3, 0, 1, 1);

        l_5 = new QLabel(gridLayoutWidget_2);
        l_5->setObjectName(QString::fromUtf8("l_5"));

        gridLayout_2->addWidget(l_5, 4, 0, 1, 1);

        l_6 = new QLabel(gridLayoutWidget_2);
        l_6->setObjectName(QString::fromUtf8("l_6"));

        gridLayout_2->addWidget(l_6, 0, 2, 1, 1);

        l_11 = new QLabel(gridLayoutWidget_2);
        l_11->setObjectName(QString::fromUtf8("l_11"));

        gridLayout_2->addWidget(l_11, 0, 4, 1, 1);

        l_7 = new QLabel(gridLayoutWidget_2);
        l_7->setObjectName(QString::fromUtf8("l_7"));

        gridLayout_2->addWidget(l_7, 1, 2, 1, 1);

        l_8 = new QLabel(gridLayoutWidget_2);
        l_8->setObjectName(QString::fromUtf8("l_8"));

        gridLayout_2->addWidget(l_8, 2, 2, 1, 1);

        l_9 = new QLabel(gridLayoutWidget_2);
        l_9->setObjectName(QString::fromUtf8("l_9"));

        gridLayout_2->addWidget(l_9, 3, 2, 1, 1);

        l_10 = new QLabel(gridLayoutWidget_2);
        l_10->setObjectName(QString::fromUtf8("l_10"));

        gridLayout_2->addWidget(l_10, 4, 2, 1, 1);

        l_12 = new QLabel(gridLayoutWidget_2);
        l_12->setObjectName(QString::fromUtf8("l_12"));

        gridLayout_2->addWidget(l_12, 1, 4, 1, 1);

        l_13 = new QLabel(gridLayoutWidget_2);
        l_13->setObjectName(QString::fromUtf8("l_13"));

        gridLayout_2->addWidget(l_13, 2, 4, 1, 1);

        l_14 = new QLabel(gridLayoutWidget_2);
        l_14->setObjectName(QString::fromUtf8("l_14"));

        gridLayout_2->addWidget(l_14, 3, 4, 1, 1);

        l_15 = new QLabel(gridLayoutWidget_2);
        l_15->setObjectName(QString::fromUtf8("l_15"));

        gridLayout_2->addWidget(l_15, 4, 4, 1, 1);

        l_17 = new QLabel(gridLayoutWidget_2);
        l_17->setObjectName(QString::fromUtf8("l_17"));

        gridLayout_2->addWidget(l_17, 1, 6, 1, 1);

        l_16 = new QLabel(gridLayoutWidget_2);
        l_16->setObjectName(QString::fromUtf8("l_16"));

        gridLayout_2->addWidget(l_16, 0, 6, 1, 1);

        l_18 = new QLabel(gridLayoutWidget_2);
        l_18->setObjectName(QString::fromUtf8("l_18"));

        gridLayout_2->addWidget(l_18, 2, 6, 1, 1);

        l_19 = new QLabel(gridLayoutWidget_2);
        l_19->setObjectName(QString::fromUtf8("l_19"));

        gridLayout_2->addWidget(l_19, 3, 6, 1, 1);

        l_20 = new QLabel(gridLayoutWidget_2);
        l_20->setObjectName(QString::fromUtf8("l_20"));

        gridLayout_2->addWidget(l_20, 4, 6, 1, 1);

        lineEdit_IPAddress2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_IPAddress2->setObjectName(QString::fromUtf8("lineEdit_IPAddress2"));

        gridLayout_2->addWidget(lineEdit_IPAddress2, 0, 3, 1, 1);

        lineEdit_IPAddress3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_IPAddress3->setObjectName(QString::fromUtf8("lineEdit_IPAddress3"));

        gridLayout_2->addWidget(lineEdit_IPAddress3, 0, 5, 1, 1);

        lineEdit_IPAddress4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_IPAddress4->setObjectName(QString::fromUtf8("lineEdit_IPAddress4"));

        gridLayout_2->addWidget(lineEdit_IPAddress4, 0, 7, 1, 1);

        lineEdit_Mask = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Mask->setObjectName(QString::fromUtf8("lineEdit_Mask"));

        gridLayout_2->addWidget(lineEdit_Mask, 1, 1, 1, 1);

        lineEdit_Mask2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Mask2->setObjectName(QString::fromUtf8("lineEdit_Mask2"));

        gridLayout_2->addWidget(lineEdit_Mask2, 1, 3, 1, 1);

        lineEdit_Mask3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Mask3->setObjectName(QString::fromUtf8("lineEdit_Mask3"));

        gridLayout_2->addWidget(lineEdit_Mask3, 1, 5, 1, 1);

        lineEdit_Mask4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Mask4->setObjectName(QString::fromUtf8("lineEdit_Mask4"));

        gridLayout_2->addWidget(lineEdit_Mask4, 1, 7, 1, 1);

        lineEdit_gate = new QLineEdit(gridLayoutWidget_2);
        lineEdit_gate->setObjectName(QString::fromUtf8("lineEdit_gate"));

        gridLayout_2->addWidget(lineEdit_gate, 2, 1, 1, 1);

        lineEdit_gate2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_gate2->setObjectName(QString::fromUtf8("lineEdit_gate2"));

        gridLayout_2->addWidget(lineEdit_gate2, 2, 3, 1, 1);

        lineEdit_gate3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_gate3->setObjectName(QString::fromUtf8("lineEdit_gate3"));

        gridLayout_2->addWidget(lineEdit_gate3, 2, 5, 1, 1);

        lineEdit_gate4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_gate4->setObjectName(QString::fromUtf8("lineEdit_gate4"));

        gridLayout_2->addWidget(lineEdit_gate4, 2, 7, 1, 1);

        lineEdit_DNS1 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS1->setObjectName(QString::fromUtf8("lineEdit_DNS1"));

        gridLayout_2->addWidget(lineEdit_DNS1, 3, 1, 1, 1);

        lineEdit_DNS12 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS12->setObjectName(QString::fromUtf8("lineEdit_DNS12"));

        gridLayout_2->addWidget(lineEdit_DNS12, 3, 3, 1, 1);

        lineEdit_DNS13 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS13->setObjectName(QString::fromUtf8("lineEdit_DNS13"));

        gridLayout_2->addWidget(lineEdit_DNS13, 3, 5, 1, 1);

        lineEdit_DNS14 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS14->setObjectName(QString::fromUtf8("lineEdit_DNS14"));

        gridLayout_2->addWidget(lineEdit_DNS14, 3, 7, 1, 1);

        lineEdit_DNS2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS2->setObjectName(QString::fromUtf8("lineEdit_DNS2"));

        gridLayout_2->addWidget(lineEdit_DNS2, 4, 1, 1, 1);

        lineEdit_DNS22 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS22->setObjectName(QString::fromUtf8("lineEdit_DNS22"));

        gridLayout_2->addWidget(lineEdit_DNS22, 4, 3, 1, 1);

        lineEdit_DNS23 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS23->setObjectName(QString::fromUtf8("lineEdit_DNS23"));

        gridLayout_2->addWidget(lineEdit_DNS23, 4, 5, 1, 1);

        lineEdit_DNS24 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_DNS24->setObjectName(QString::fromUtf8("lineEdit_DNS24"));

        gridLayout_2->addWidget(lineEdit_DNS24, 4, 7, 1, 1);

        btn_getNetwork = new QPushButton(groupBox_4);
        btn_getNetwork->setObjectName(QString::fromUtf8("btn_getNetwork"));
        btn_getNetwork->setGeometry(QRect(182, 15, 51, 23));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(550, 0, 241, 231));
        lineEdit_ID = new QLineEdit(groupBox_7);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(80, 20, 131, 20));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 20, 81, 21));
        btn_addID = new QPushButton(groupBox_7);
        btn_addID->setObjectName(QString::fromUtf8("btn_addID"));
        btn_addID->setGeometry(QRect(20, 50, 41, 23));
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 80, 111, 20));
        plainTextEdit_ID = new QPlainTextEdit(groupBox_7);
        plainTextEdit_ID->setObjectName(QString::fromUtf8("plainTextEdit_ID"));
        plainTextEdit_ID->setGeometry(QRect(10, 110, 221, 111));
        btn_SetID = new QPushButton(groupBox_7);
        btn_SetID->setObjectName(QString::fromUtf8("btn_SetID"));
        btn_SetID->setGeometry(QRect(70, 50, 71, 23));
        btn_ECUImport = new QPushButton(groupBox_7);
        btn_ECUImport->setObjectName(QString::fromUtf8("btn_ECUImport"));
        btn_ECUImport->setGeometry(QRect(150, 50, 75, 23));
        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(280, 290, 261, 71));
        lineEdit_oldPasswd = new QLineEdit(groupBox_8);
        lineEdit_oldPasswd->setObjectName(QString::fromUtf8("lineEdit_oldPasswd"));
        lineEdit_oldPasswd->setGeometry(QRect(60, 19, 101, 20));
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 50, 54, 12));
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 19, 54, 21));
        btn_setPasswd = new QPushButton(groupBox_8);
        btn_setPasswd->setObjectName(QString::fromUtf8("btn_setPasswd"));
        btn_setPasswd->setGeometry(QRect(170, 30, 61, 23));
        lineEdit_newPasswd = new QLineEdit(groupBox_8);
        lineEdit_newPasswd->setObjectName(QString::fromUtf8("lineEdit_newPasswd"));
        lineEdit_newPasswd->setGeometry(QRect(60, 45, 101, 20));
        groupBox_12 = new QGroupBox(tab);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(270, 60, 271, 41));
        btn_getTime_ECU = new QPushButton(groupBox_12);
        btn_getTime_ECU->setObjectName(QString::fromUtf8("btn_getTime_ECU"));
        btn_getTime_ECU->setGeometry(QRect(170, 11, 81, 23));
        dateTimeEdit_ECU = new QDateTimeEdit(groupBox_12);
        dateTimeEdit_ECU->setObjectName(QString::fromUtf8("dateTimeEdit_ECU"));
        dateTimeEdit_ECU->setGeometry(QRect(10, 12, 141, 21));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(550, 230, 241, 121));
        comboBox_SetChannel = new QComboBox(groupBox_5);
        comboBox_SetChannel->setObjectName(QString::fromUtf8("comboBox_SetChannel"));
        comboBox_SetChannel->setGeometry(QRect(70, 49, 69, 22));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 50, 54, 21));
        btn_SetChannel = new QPushButton(groupBox_5);
        btn_SetChannel->setObjectName(QString::fromUtf8("btn_SetChannel"));
        btn_SetChannel->setGeometry(QRect(150, 40, 75, 23));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 87, 54, 21));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(110, 87, 54, 21));
        label_CurrentChannel = new QLabel(groupBox_5);
        label_CurrentChannel->setObjectName(QString::fromUtf8("label_CurrentChannel"));
        label_CurrentChannel->setGeometry(QRect(70, 87, 31, 21));
        label_Stren = new QLabel(groupBox_5);
        label_Stren->setObjectName(QString::fromUtf8("label_Stren"));
        label_Stren->setGeometry(QRect(180, 87, 41, 21));
        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 21, 54, 21));
        comboBox_OldChannel = new QComboBox(groupBox_5);
        comboBox_OldChannel->setObjectName(QString::fromUtf8("comboBox_OldChannel"));
        comboBox_OldChannel->setGeometry(QRect(70, 20, 69, 22));
        groupBox_27 = new QGroupBox(tab);
        groupBox_27->setObjectName(QString::fromUtf8("groupBox_27"));
        groupBox_27->setGeometry(QRect(550, 360, 241, 61));
        btn_setFunction = new QPushButton(groupBox_27);
        btn_setFunction->setObjectName(QString::fromUtf8("btn_setFunction"));
        btn_setFunction->setGeometry(QRect(110, 20, 81, 23));
        comboBox_SetFunction = new QComboBox(groupBox_27);
        comboBox_SetFunction->setObjectName(QString::fromUtf8("comboBox_SetFunction"));
        comboBox_SetFunction->setGeometry(QRect(20, 20, 69, 22));
        groupBox_15 = new QGroupBox(tab);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(280, 360, 261, 61));
        pushButton_2 = new QPushButton(groupBox_15);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 81, 23));
        lineEdit_flashsize = new QLineEdit(groupBox_15);
        lineEdit_flashsize->setObjectName(QString::fromUtf8("lineEdit_flashsize"));
        lineEdit_flashsize->setGeometry(QRect(120, 20, 113, 20));
        tabWidget->addTab(tab, QString());
        Tab_2 = new QWidget();
        Tab_2->setObjectName(QString::fromUtf8("Tab_2"));
        groupBox_9 = new QGroupBox(Tab_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(0, 0, 791, 381));
        tableWidget_RealData = new QTableWidget(groupBox_9);
        tableWidget_RealData->setObjectName(QString::fromUtf8("tableWidget_RealData"));
        tableWidget_RealData->setGeometry(QRect(10, 40, 771, 331));
        btn_getRealData = new QPushButton(groupBox_9);
        btn_getRealData->setObjectName(QString::fromUtf8("btn_getRealData"));
        btn_getRealData->setGeometry(QRect(15, 19, 91, 21));
        label_all = new QLabel(groupBox_9);
        label_all->setObjectName(QString::fromUtf8("label_all"));
        label_all->setGeometry(QRect(220, 15, 54, 20));
        label_all->setStyleSheet(QString::fromUtf8("color:#ff0000"));
        label_42 = new QLabel(groupBox_9);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(170, 15, 54, 20));
        label_time = new QLabel(groupBox_9);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(350, 15, 141, 20));
        label_time->setStyleSheet(QString::fromUtf8("color:#ff0000"));
        label_43 = new QLabel(groupBox_9);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(300, 15, 54, 20));
        tabWidget->addTab(Tab_2, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_10 = new QGroupBox(tab_2);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(0, 0, 231, 381));
        btn_getPower = new QPushButton(groupBox_10);
        btn_getPower->setObjectName(QString::fromUtf8("btn_getPower"));
        btn_getPower->setGeometry(QRect(120, 50, 75, 21));
        tableWidget_Power = new QTableWidget(groupBox_10);
        if (tableWidget_Power->columnCount() < 2)
            tableWidget_Power->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Power->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Power->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_Power->setObjectName(QString::fromUtf8("tableWidget_Power"));
        tableWidget_Power->setGeometry(QRect(10, 80, 211, 291));
        label_44 = new QLabel(groupBox_10);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(14, 16, 31, 21));
        dateEdit = new QDateEdit(groupBox_10);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(50, 17, 151, 21));
        btn_getDate = new QPushButton(groupBox_10);
        btn_getDate->setObjectName(QString::fromUtf8("btn_getDate"));
        btn_getDate->setGeometry(QRect(20, 49, 91, 23));
        groupBox_11 = new QGroupBox(tab_2);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(230, 0, 241, 381));
        tableWidget_Energy = new QTableWidget(groupBox_11);
        if (tableWidget_Energy->columnCount() < 2)
            tableWidget_Energy->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Energy->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Energy->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_Energy->setObjectName(QString::fromUtf8("tableWidget_Energy"));
        tableWidget_Energy->setGeometry(QRect(10, 90, 221, 281));
        btn_getEnergy = new QPushButton(groupBox_11);
        btn_getEnergy->setObjectName(QString::fromUtf8("btn_getEnergy"));
        btn_getEnergy->setGeometry(QRect(20, 50, 61, 31));
        label_45 = new QLabel(groupBox_11);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(20, 20, 71, 16));
        comboBox_2 = new QComboBox(groupBox_11);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 21, 111, 21));
        groupBox_13 = new QGroupBox(tab_2);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(470, 0, 291, 211));
        btn_getWIFI = new QPushButton(groupBox_13);
        btn_getWIFI->setObjectName(QString::fromUtf8("btn_getWIFI"));
        btn_getWIFI->setGeometry(QRect(10, 20, 75, 23));
        tableWidget_SSID = new QTableWidget(groupBox_13);
        if (tableWidget_SSID->columnCount() < 2)
            tableWidget_SSID->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_SSID->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_SSID->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        tableWidget_SSID->setObjectName(QString::fromUtf8("tableWidget_SSID"));
        tableWidget_SSID->setGeometry(QRect(10, 50, 261, 91));
        label_49 = new QLabel(groupBox_13);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 150, 31, 16));
        label_50 = new QLabel(groupBox_13);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(10, 180, 31, 16));
        btn_connect = new QPushButton(groupBox_13);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));
        btn_connect->setGeometry(QRect(190, 170, 51, 23));
        lineEdit_SSID_2 = new QLineEdit(groupBox_13);
        lineEdit_SSID_2->setObjectName(QString::fromUtf8("lineEdit_SSID_2"));
        lineEdit_SSID_2->setGeometry(QRect(40, 147, 113, 20));
        lineEdit_PassWD = new QLineEdit(groupBox_13);
        lineEdit_PassWD->setObjectName(QString::fromUtf8("lineEdit_PassWD"));
        lineEdit_PassWD->setGeometry(QRect(40, 176, 113, 20));
        groupBox_14 = new QGroupBox(tab_2);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(470, 210, 291, 101));
        pushButton = new QPushButton(groupBox_14);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 131, 23));
        label_LinkStatus = new QLabel(groupBox_14);
        label_LinkStatus->setObjectName(QString::fromUtf8("label_LinkStatus"));
        label_LinkStatus->setGeometry(QRect(40, 45, 241, 51));
        label_48 = new QLabel(groupBox_14);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(10, 40, 31, 41));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox_16 = new QGroupBox(tab_4);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(10, 0, 251, 411));
        tableWidget_shortAddr = new QTableWidget(groupBox_16);
        if (tableWidget_shortAddr->columnCount() < 2)
            tableWidget_shortAddr->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_shortAddr->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_shortAddr->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_shortAddr->setObjectName(QString::fromUtf8("tableWidget_shortAddr"));
        tableWidget_shortAddr->setGeometry(QRect(10, 80, 231, 321));
        btn_getshortAddr = new QPushButton(groupBox_16);
        btn_getshortAddr->setObjectName(QString::fromUtf8("btn_getshortAddr"));
        btn_getshortAddr->setGeometry(QRect(15, 19, 91, 21));
        progressBar = new QProgressBar(groupBox_16);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(90, 46, 151, 23));
        progressBar->setValue(24);
        label_6 = new QLabel(groupBox_16);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 50, 51, 16));
        groupBox_17 = new QGroupBox(tab_4);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(270, 0, 261, 171));
        btn_gethardware = new QPushButton(groupBox_17);
        btn_gethardware->setObjectName(QString::fromUtf8("btn_gethardware"));
        btn_gethardware->setGeometry(QRect(20, 20, 91, 21));
        label_12 = new QLabel(groupBox_17);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 60, 81, 21));
        label_wifiType = new QLabel(groupBox_17);
        label_wifiType->setObjectName(QString::fromUtf8("label_wifiType"));
        label_wifiType->setGeometry(QRect(110, 60, 131, 21));
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 0, 791, 411));
        comboBox_UID = new QComboBox(groupBox_6);
        comboBox_UID->setObjectName(QString::fromUtf8("comboBox_UID"));
        comboBox_UID->setGeometry(QRect(90, 20, 191, 21));
        label_73 = new QLabel(groupBox_6);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setGeometry(QRect(10, 22, 71, 16));
        label_74 = new QLabel(groupBox_6);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setGeometry(QRect(294, 19, 31, 21));
        dateEdit_2 = new QDateEdit(groupBox_6);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(330, 20, 151, 21));
        tableWidget_Info = new QTableWidget(groupBox_6);
        if (tableWidget_Info->columnCount() < 7)
            tableWidget_Info->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableWidget_Info->setObjectName(QString::fromUtf8("tableWidget_Info"));
        tableWidget_Info->setGeometry(QRect(10, 50, 771, 361));
        btn_getInfo = new QPushButton(groupBox_6);
        btn_getInfo->setObjectName(QString::fromUtf8("btn_getInfo"));
        btn_getInfo->setGeometry(QRect(630, 20, 91, 21));
        btn_getDate_2 = new QPushButton(groupBox_6);
        btn_getDate_2->setObjectName(QString::fromUtf8("btn_getDate_2"));
        btn_getDate_2->setGeometry(QRect(510, 20, 91, 23));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 807, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\351\200\232\344\277\241\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_IP->setText(QApplication::translate("MainWindow", "10.10.100.254", 0, QApplication::UnicodeUTF8));
        lineEdit_Port->setText(QApplication::translate("MainWindow", "8899", 0, QApplication::UnicodeUTF8));
        btn_config->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        btn_baseInfo->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "ECU ID\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_ECUID->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "ECU \346\234\272\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_ECUModel->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\345\217\221\347\224\265\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_LifttimeEnergy->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\263\273\347\273\237\345\212\237\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_LastSystemPower->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "\345\275\223\345\244\251\345\217\221\347\224\265\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_GenerationCurrentDay->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "\346\234\200\345\220\216\350\201\224\347\275\221\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_LastToEMA->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\351\200\206\345\217\230\345\231\250\346\200\273\345\217\260\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_NumberInverters->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\277\236\346\216\245\345\217\260\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_LastNumberInverters->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_Version->setText(QString());
        label_27->setText(QApplication::translate("MainWindow", "\346\227\266\345\214\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_TimeZone->setText(QString());
        label_30->setText(QApplication::translate("MainWindow", "\346\227\240\347\272\277MAC\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "\346\234\211\347\272\277MAC\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        label_MacAddress->setText(QString());
        label_WifiMac->setText(QString());
        label_31->setText(QApplication::translate("MainWindow", "\344\277\241\345\217\267\345\274\272\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_level->setText(QString());
        label_32->setText(QApplication::translate("MainWindow", "\344\277\241\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        label_channel->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "RSD\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_rsdType->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\227\266\351\227\264\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_getTime->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\234\254\346\234\272\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        btn_setTime->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\234\211\347\272\277\347\275\221\347\273\234\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "IP\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\212\250\346\200\201IP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\235\231\346\200\201IP", 0, QApplication::UnicodeUTF8)
        );
        btn_setNetwork->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        l_1->setText(QApplication::translate("MainWindow", "IP:", 0, QApplication::UnicodeUTF8));
        l_2->setText(QApplication::translate("MainWindow", "\346\216\251\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        l_3->setText(QApplication::translate("MainWindow", "\347\275\221\345\205\263\357\274\232", 0, QApplication::UnicodeUTF8));
        l_4->setText(QApplication::translate("MainWindow", "DNS1\357\274\232", 0, QApplication::UnicodeUTF8));
        l_5->setText(QApplication::translate("MainWindow", "DNS2\357\274\232", 0, QApplication::UnicodeUTF8));
        l_6->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_11->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_7->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_8->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_9->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_10->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_12->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_13->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_14->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_15->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_17->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_16->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_18->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_19->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_20->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        btn_getNetwork->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\351\200\206\345\217\230\345\231\250ID\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        lineEdit_ID->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "\351\234\200\346\267\273\345\212\240\347\232\204ID:", 0, QApplication::UnicodeUTF8));
        btn_addID->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\346\263\250\345\206\214\347\232\204ID\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        plainTextEdit_ID->setPlainText(QString());
        btn_SetID->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\273\204\347\275\221", 0, QApplication::UnicodeUTF8));
        btn_ECUImport->setText(QApplication::translate("MainWindow", "ECU\345\257\274\345\205\245ID", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "ECU AP\345\257\206\347\240\201\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "\345\216\237\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        btn_setPasswd->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "\346\227\266\351\227\264\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        btn_getTime_ECU->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226ECU\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "04 \344\277\241\351\201\223\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        comboBox_SetChannel->clear();
        comboBox_SetChannel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1A", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("MainWindow", "\346\226\260\344\277\241\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        btn_SetChannel->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\277\241\351\201\223", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\277\241\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\344\277\241\345\217\267\345\274\272\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_CurrentChannel->setText(QString());
        label_Stren->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "\345\216\237\344\277\241\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_OldChannel->clear();
        comboBox_OldChannel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "00unknown", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1A", 0, QApplication::UnicodeUTF8)
        );
        groupBox_27->setTitle(QApplication::translate("MainWindow", "06 RSD\345\212\237\350\203\275\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        btn_setFunction->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        comboBox_SetFunction->clear();
        comboBox_SetFunction->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "00\357\274\232\345\205\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "01\357\274\232\345\274\200", 0, QApplication::UnicodeUTF8)
        );
        groupBox_15->setTitle(QApplication::translate("MainWindow", "Flash\345\211\251\344\275\231\347\251\272\351\227\264", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226Flash\347\251\272\351\227\264", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\344\270\273\350\246\201\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        btn_getRealData->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\217\221\347\224\265\351\207\217\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_all->setText(QString());
        label_42->setText(QApplication::translate("MainWindow", "\346\200\273\345\217\260\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_time->setText(QString());
        label_43->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Tab_2), QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\345\212\237\347\216\207\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        btn_getPower->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\212\237\347\216\207\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Power->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Power->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        btn_getDate->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Energy->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Energy->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217", 0, QApplication::UnicodeUTF8));
        btn_getEnergy->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\217\221\347\224\265\n"
"\351\207\217\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\227\266\351\227\264\346\256\265\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1.\346\234\200\350\277\221\344\270\200\345\221\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2.\346\234\200\350\277\221\344\270\200\346\234\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3.\346\234\200\350\277\221\344\270\200\345\271\264", 0, QApplication::UnicodeUTF8)
        );
        groupBox_13->setTitle(QApplication::translate("MainWindow", "\350\216\267\345\217\226\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        btn_getWIFI->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226WIFI\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_SSID->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_SSID->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\344\277\241\345\217\267\345\274\272\345\272\246", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        btn_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        lineEdit_SSID_2->setText(QApplication::translate("MainWindow", "yuneng_ecu_test", 0, QApplication::UnicodeUTF8));
        lineEdit_PassWD->setText(QApplication::translate("MainWindow", "123456789", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "\350\216\267\345\217\226WIFI\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226WIFI\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_LinkStatus->setText(QString());
        label_48->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\n"
"\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\345\212\237\347\216\207\343\200\201\345\217\221\347\224\265\351\207\217\346\233\262\347\272\277\343\200\201\346\227\240\347\272\277\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        groupBox_16->setTitle(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\237\255\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_shortAddr->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_shortAddr->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\347\237\255\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        btn_getshortAddr->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\237\255\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\277\233\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_17->setTitle(QApplication::translate("MainWindow", "\350\216\267\345\217\226ECU\347\241\254\344\273\266\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        btn_gethardware->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\241\254\344\273\266\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "WIFI\346\250\241\345\235\227\345\236\213\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_wifiType->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\237\255\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "17 \345\215\225\345\217\260\347\233\270\345\205\263\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        label_73->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\350\216\267\345\217\226\347\232\204ID\345\217\267", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Info->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Info->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "PV1\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Info->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "PV1\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Info->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "PV1\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Info->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "PV2\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Info->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "PV2\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Info->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "PV2\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        btn_getInfo->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\215\225\345\217\260\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        btn_getDate_2->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\345\215\225\345\217\260RSD\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
