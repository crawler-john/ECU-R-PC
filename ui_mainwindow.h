/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Aug 15 09:26:11 2017
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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
    QLabel *label_6;
    QLineEdit *lineEdit_IPAddress;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_28;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_26;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
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
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_SSID;
    QLineEdit *lineEdit_Passwd;
    QPushButton *btn_configWIFI;
    QGroupBox *groupBox_6;
    QPushButton *btn_checkWifiStatus;
    QCheckBox *checkBox;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(781, 468);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 771, 411));
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
        groupBox_2->setGeometry(QRect(0, 70, 261, 311));
        btn_baseInfo = new QPushButton(groupBox_2);
        btn_baseInfo->setObjectName(QString::fromUtf8("btn_baseInfo"));
        btn_baseInfo->setGeometry(QRect(10, 20, 81, 23));
        gridLayoutWidget = new QWidget(groupBox_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 241, 251));
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

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(270, 0, 241, 61));
        btn_getTime = new QPushButton(groupBox_3);
        btn_getTime->setObjectName(QString::fromUtf8("btn_getTime"));
        btn_getTime->setGeometry(QRect(150, 10, 81, 23));
        btn_setTime = new QPushButton(groupBox_3);
        btn_setTime->setObjectName(QString::fromUtf8("btn_setTime"));
        btn_setTime->setGeometry(QRect(150, 36, 81, 23));
        dateTimeEdit = new QDateTimeEdit(groupBox_3);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(10, 21, 131, 21));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(270, 110, 241, 181));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 54, 21));
        comboBox = new QComboBox(groupBox_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 20, 69, 22));
        btn_setNetwork = new QPushButton(groupBox_4);
        btn_setNetwork->setObjectName(QString::fromUtf8("btn_setNetwork"));
        btn_setNetwork->setGeometry(QRect(140, 20, 91, 23));
        gridLayoutWidget_2 = new QWidget(groupBox_4);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 50, 231, 126));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_IPAddress = new QLineEdit(gridLayoutWidget_2);
        lineEdit_IPAddress->setObjectName(QString::fromUtf8("lineEdit_IPAddress"));

        gridLayout_2->addWidget(lineEdit_IPAddress, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 3, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 4, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_2->addWidget(label_22, 0, 2, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 0, 4, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_2->addWidget(label_28, 1, 2, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_2->addWidget(label_31, 2, 2, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_2->addWidget(label_32, 3, 2, 1, 1);

        label_33 = new QLabel(gridLayoutWidget_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_2->addWidget(label_33, 4, 2, 1, 1);

        label_34 = new QLabel(gridLayoutWidget_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_2->addWidget(label_34, 1, 4, 1, 1);

        label_35 = new QLabel(gridLayoutWidget_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_2->addWidget(label_35, 2, 4, 1, 1);

        label_36 = new QLabel(gridLayoutWidget_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_2->addWidget(label_36, 3, 4, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_2);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_2->addWidget(label_37, 4, 4, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_2);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_2->addWidget(label_38, 1, 6, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_2->addWidget(label_26, 0, 6, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_2);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_2->addWidget(label_39, 2, 6, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_2->addWidget(label_40, 3, 6, 1, 1);

        label_41 = new QLabel(gridLayoutWidget_2);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_2->addWidget(label_41, 4, 6, 1, 1);

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

        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(270, 290, 241, 91));
        gridLayoutWidget_3 = new QWidget(groupBox_5);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 141, 61));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(gridLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 1, 0, 1, 1);

        lineEdit_SSID = new QLineEdit(gridLayoutWidget_3);
        lineEdit_SSID->setObjectName(QString::fromUtf8("lineEdit_SSID"));

        gridLayout_3->addWidget(lineEdit_SSID, 0, 1, 1, 1);

        lineEdit_Passwd = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Passwd->setObjectName(QString::fromUtf8("lineEdit_Passwd"));

        gridLayout_3->addWidget(lineEdit_Passwd, 1, 1, 1, 1);

        btn_configWIFI = new QPushButton(groupBox_5);
        btn_configWIFI->setObjectName(QString::fromUtf8("btn_configWIFI"));
        btn_configWIFI->setGeometry(QRect(160, 30, 71, 41));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(520, 240, 241, 51));
        btn_checkWifiStatus = new QPushButton(groupBox_6);
        btn_checkWifiStatus->setObjectName(QString::fromUtf8("btn_checkWifiStatus"));
        btn_checkWifiStatus->setGeometry(QRect(10, 20, 91, 23));
        checkBox = new QCheckBox(groupBox_6);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(120, 20, 91, 21));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(520, 0, 241, 231));
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
        groupBox_8->setGeometry(QRect(520, 300, 241, 81));
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
        groupBox_12->setGeometry(QRect(270, 60, 241, 41));
        btn_getTime_ECU = new QPushButton(groupBox_12);
        btn_getTime_ECU->setObjectName(QString::fromUtf8("btn_getTime_ECU"));
        btn_getTime_ECU->setGeometry(QRect(150, 15, 81, 23));
        dateTimeEdit_ECU = new QDateTimeEdit(groupBox_12);
        dateTimeEdit_ECU->setObjectName(QString::fromUtf8("dateTimeEdit_ECU"));
        dateTimeEdit_ECU->setGeometry(QRect(10, 16, 131, 21));
        tabWidget->addTab(tab, QString());
        Tab_2 = new QWidget();
        Tab_2->setObjectName(QString::fromUtf8("Tab_2"));
        groupBox_9 = new QGroupBox(Tab_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(0, 0, 761, 381));
        tableWidget_RealData = new QTableWidget(groupBox_9);
        if (tableWidget_RealData->columnCount() < 7)
            tableWidget_RealData->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_RealData->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_RealData->setObjectName(QString::fromUtf8("tableWidget_RealData"));
        tableWidget_RealData->setGeometry(QRect(10, 40, 741, 331));
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
        groupBox_10->setGeometry(QRect(0, 0, 251, 381));
        btn_getPower = new QPushButton(groupBox_10);
        btn_getPower->setObjectName(QString::fromUtf8("btn_getPower"));
        btn_getPower->setGeometry(QRect(120, 50, 75, 21));
        tableWidget_Power = new QTableWidget(groupBox_10);
        if (tableWidget_Power->columnCount() < 2)
            tableWidget_Power->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Power->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Power->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        tableWidget_Power->setObjectName(QString::fromUtf8("tableWidget_Power"));
        tableWidget_Power->setGeometry(QRect(10, 80, 221, 291));
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
        groupBox_11->setGeometry(QRect(260, 0, 331, 381));
        tableWidget_Energy = new QTableWidget(groupBox_11);
        if (tableWidget_Energy->columnCount() < 2)
            tableWidget_Energy->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Energy->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Energy->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        tableWidget_Energy->setObjectName(QString::fromUtf8("tableWidget_Energy"));
        tableWidget_Energy->setGeometry(QRect(20, 50, 271, 321));
        btn_getEnergy = new QPushButton(groupBox_11);
        btn_getEnergy->setObjectName(QString::fromUtf8("btn_getEnergy"));
        btn_getEnergy->setGeometry(QRect(210, 20, 101, 21));
        label_45 = new QLabel(groupBox_11);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(20, 20, 71, 16));
        comboBox_2 = new QComboBox(groupBox_11);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 21, 111, 21));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 23));
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
        btn_setNetwork->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256\346\234\211\347\272\277\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "IP:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\346\216\251\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\347\275\221\345\205\263\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "DNS1\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "DNS2\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\346\227\240\347\272\277\347\275\221\347\273\234\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_SSID->setText(QApplication::translate("MainWindow", "yuneng_ecu_test", 0, QApplication::UnicodeUTF8));
        lineEdit_Passwd->setText(QApplication::translate("MainWindow", "123456789", 0, QApplication::UnicodeUTF8));
        btn_configWIFI->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256\346\227\240\347\272\277\n"
"\347\275\221\347\273\234\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\346\227\240\347\272\277\347\275\221\347\273\234\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        btn_checkWifiStatus->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\227\240\347\272\277\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\344\270\273\350\246\201\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_RealData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_RealData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\347\224\265\347\275\221\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_RealData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\234\272\345\206\205\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_RealData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "A\350\267\257\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_RealData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "A\350\267\257\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_RealData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "B\350\267\257\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_RealData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "B\350\267\257\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        btn_getRealData->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\217\221\347\224\265\351\207\217\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_all->setText(QString());
        label_42->setText(QApplication::translate("MainWindow", "\346\200\273\345\217\260\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_time->setText(QString());
        label_43->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Tab_2), QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\345\212\237\347\216\207\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        btn_getPower->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\212\237\347\216\207\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Power->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Power->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        btn_getDate->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Energy->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Energy->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\345\217\221\347\224\265\351\207\217", 0, QApplication::UnicodeUTF8));
        btn_getEnergy->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\217\221\347\224\265\351\207\217\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\227\266\351\227\264\346\256\265\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1.\346\234\200\350\277\221\344\270\200\345\221\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2.\346\234\200\350\277\221\344\270\200\346\234\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3.\346\234\200\350\277\221\344\270\200\345\271\264", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\345\212\237\347\216\207\343\200\201\345\217\221\347\224\265\351\207\217\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
