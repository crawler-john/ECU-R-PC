/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 19 15:40:32 2018
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
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
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
    QGroupBox *groupBox_32;
    QPushButton *btn_connect_ESP07;
    QLabel *label_52;
    QLineEdit *lineEdit_SSID2;
    QLabel *label_53;
    QLineEdit *lineEdit_PassWD2;
    QGroupBox *groupBox_33;
    QPushButton *pushButton_ESP07;
    QLabel *label_LinkStatus_ESP07;
    QLabel *label_51;
    QGroupBox *groupBox_34;
    QPushButton *btn_getWIFI_2;
    QTableWidget *tableWidget_SSID_ESP07S;
    QWidget *tab_10;
    QGroupBox *groupBox_35;
    QGroupBox *groupBox_27;
    QPushButton *btn_setFunction;
    QComboBox *comboBox_SetFunction;
    QLabel *label_60;
    QPlainTextEdit *plainTextEdit_RSDID;
    QPushButton *btn_setFunction_open;
    QPushButton *btn_setFunction_close;
    QPushButton *btn_getRSDStatus;
    QTableWidget *tableWidget_RSDStatus;
    QGroupBox *groupBox_36;
    QPushButton *btn_functionstatus;
    QLabel *label_34;
    QLabel *RSDstatus;
    QGroupBox *groupBox_37;
    QPushButton *btn_SetServer;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_54;
    QComboBox *comboBox_ServerItem;
    QLabel *label_55;
    QLineEdit *lineEdit_Domain;
    QLabel *label_56;
    QLabel *label_57;
    QLineEdit *lineEdit_Port1;
    QLabel *label_58;
    QLineEdit *lineEdit_Port2;
    QLabel *label_59;
    QLineEdit *lineEdit_Port3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_Ip_1;
    QLabel *l_21;
    QLineEdit *lineEdit_Ip_2;
    QLabel *l_22;
    QLineEdit *lineEdit_Ip_3;
    QLabel *l_23;
    QLineEdit *lineEdit_Ip_4;
    QGroupBox *groupBox_38;
    QPushButton *btn_RSSI;
    QTableWidget *tableWidget_RSSI;
    QGroupBox *groupBox_39;
    QPushButton *btn_ClearEnergy;
    QWidget *tab_11;
    QGroupBox *groupBox_43;
    QGroupBox *groupBox_44;
    QPushButton *btn_SetTurnOnOff;
    QComboBox *comboBox_SetTurnOnOff;
    QLabel *label_70;
    QPlainTextEdit *plainTextEdit_SetTurnOnOff;
    QPushButton *btn_SetTurnOnOff_Open;
    QPushButton *btn_SetTurnOnOff_Close;
    QPushButton *btn_getSetTurnOnOff;
    QTableWidget *tableWidget_SetTurnOnOff;
    QGroupBox *groupBox_45;
    QLabel *label_72;
    QPlainTextEdit *plainTextEdit_ClearGFDI;
    QPushButton *btn_ClearGFDI;
    QPushButton *btn_getClearGFDI;
    QTableWidget *tableWidget_ClearGFDI;
    QGroupBox *groupBox_46;
    QPushButton *btn_MaxPower;
    QLabel *label_75;
    QPlainTextEdit *plainTextEdit_SeMaxPower;
    QPushButton *btn_SetMaxPower;
    QPushButton *btn_getMaxPower;
    QTableWidget *tableWidget_MaxPower;
    QLineEdit *lineEdit_MaxPower;
    QLineEdit *lineEdit_MaxPower_2;
    QPushButton *btn_MaxPower_get;
    QWidget *tab_12;
    QGroupBox *groupBox_47;
    QGroupBox *groupBox_50;
    QPushButton *btn_IRD;
    QLabel *label_77;
    QPlainTextEdit *plainTextEdit_IRD;
    QPushButton *btn_SetIRD;
    QPushButton *btn_geIRD;
    QTableWidget *tableWidget_IRD;
    QPushButton *btn_IRD_get;
    QComboBox *comboBox_IRDALL;
    QComboBox *comboBox_IRD;
    QGroupBox *groupBox_20;
    QDateEdit *dateEdit_alarm;
    QLabel *label_61;
    QLabel *label_71;
    QSpinBox *spinBox_alarm;
    QTableWidget *tableWidget_alarmEvent;
    QPushButton *btn_alarmevent;
    QTextBrowser *textBrowser_alarmEvent;
    QWidget *tab_3;
    QGroupBox *groupBox_6;
    QComboBox *comboBox_UID;
    QLabel *label_73;
    QLabel *label_74;
    QDateEdit *dateEdit_2;
    QTableWidget *tableWidget_Info;
    QPushButton *btn_getInfo;
    QPushButton *btn_getDate_2;
    QWidget *tab_6;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QGroupBox *groupBox_18;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_IP_IDWrite;
    QLineEdit *lineEdit_Port_IDWrite;
    QPushButton *btn_config_IDWrite;
    QGroupBox *groupBox_21;
    QPushButton *btn_mkfs;
    QLabel *label_24;
    QLabel *label_mkfs;
    QGroupBox *groupBox_19;
    QPushButton *btn_setID;
    QPushButton *btn_getID;
    QLineEdit *lineEdit_ID_2;
    QLabel *label_ID_2;
    QLabel *label_26;
    QGroupBox *groupBox_22;
    QLineEdit *lineEdit_MAC;
    QLabel *label_MAC;
    QPushButton *btn_setMAC;
    QPushButton *btn_getMAC;
    QLabel *label_28;
    QGroupBox *groupBox_23;
    QPushButton *btn_setArea;
    QPushButton *btn_getArea;
    QLabel *label_Area;
    QLabel *label_35;
    QComboBox *comboBox_Area;
    QLabel *label_36;
    QGroupBox *groupBox_24;
    QPushButton *btn_getTime_2;
    QPushButton *btn_setTime_2;
    QComboBox *comboBox_TimeZone;
    QLabel *label_37;
    QLabel *label_Time;
    QLabel *label_38;
    QGroupBox *groupBox_25;
    QPushButton *btn_LED;
    QGroupBox *groupBox_26;
    QPushButton *btn_Version;
    QLabel *label_39;
    QLabel *label_version;
    QPushButton *btn_InternalVersion;
    QLabel *label_62;
    QLabel *label_InternalVersion;
    QGroupBox *groupBox_28;
    QPushButton *btn_addInverter;
    QLineEdit *lineEdit_INVERTER;
    QPushButton *btn_query_result;
    QPushButton *btn_query_protection;
    QLabel *label_inverter;
    QLabel *label_41;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QGroupBox *groupBox_29;
    QPushButton *btn_Clear;
    QLabel *label_40;
    QLabel *label_Clear;
    QGroupBox *groupBox_40;
    QPushButton *btn_Flash;
    QLabel *label_63;
    QLabel *label_Flash;
    QGroupBox *groupBox_41;
    QPushButton *btn_reboot;
    QLabel *label_64;
    QLabel *label_reboot;
    QGroupBox *groupBox_42;
    QLabel *label_65;
    QLineEdit *lineEdit_UpdateIP;
    QLabel *label_66;
    QLineEdit *lineEdit_UpdatePort;
    QLabel *label_67;
    QLineEdit *lineEdit_UpdateUser;
    QLineEdit *lineEdit_UpdatePasswd;
    QLabel *label_68;
    QPushButton *btn_update_ver;
    QPushButton *btn_update_ID;
    QLabel *label_update;
    QLabel *label_69;
    QWidget *tab_8;
    QTabWidget *tabWidget_4;
    QWidget *tab_9;
    QGroupBox *groupBox_30;
    QLabel *label_46;
    QLabel *label_47;
    QLineEdit *lineEdit_IP_JSON;
    QLineEdit *lineEdit_Port_JSON;
    QPushButton *btn_config_JSON;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_31;
    QPushButton *btn_cmd101;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(810, 521);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(4, -1, 801, 471));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget = new QTabWidget(tab_5);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(3, 0, 821, 451));
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
        groupBox_7->setGeometry(QRect(550, 0, 241, 301));
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
        plainTextEdit_ID->setGeometry(QRect(10, 110, 221, 181));
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
        groupBox_5->setGeometry(QRect(550, 300, 241, 121));
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
        groupBox_17->setGeometry(QRect(270, 0, 261, 71));
        btn_gethardware = new QPushButton(groupBox_17);
        btn_gethardware->setObjectName(QString::fromUtf8("btn_gethardware"));
        btn_gethardware->setGeometry(QRect(4, 14, 91, 21));
        label_12 = new QLabel(groupBox_17);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 41, 81, 21));
        label_wifiType = new QLabel(groupBox_17);
        label_wifiType->setObjectName(QString::fromUtf8("label_wifiType"));
        label_wifiType->setGeometry(QRect(110, 41, 131, 21));
        groupBox_32 = new QGroupBox(tab_4);
        groupBox_32->setObjectName(QString::fromUtf8("groupBox_32"));
        groupBox_32->setGeometry(QRect(530, 0, 241, 71));
        btn_connect_ESP07 = new QPushButton(groupBox_32);
        btn_connect_ESP07->setObjectName(QString::fromUtf8("btn_connect_ESP07"));
        btn_connect_ESP07->setGeometry(QRect(160, 27, 51, 23));
        label_52 = new QLabel(groupBox_32);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(10, 21, 31, 16));
        lineEdit_SSID2 = new QLineEdit(groupBox_32);
        lineEdit_SSID2->setObjectName(QString::fromUtf8("lineEdit_SSID2"));
        lineEdit_SSID2->setGeometry(QRect(40, 18, 113, 20));
        label_53 = new QLabel(groupBox_32);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 48, 31, 16));
        lineEdit_PassWD2 = new QLineEdit(groupBox_32);
        lineEdit_PassWD2->setObjectName(QString::fromUtf8("lineEdit_PassWD2"));
        lineEdit_PassWD2->setGeometry(QRect(40, 44, 113, 20));
        groupBox_33 = new QGroupBox(tab_4);
        groupBox_33->setObjectName(QString::fromUtf8("groupBox_33"));
        groupBox_33->setGeometry(QRect(270, 75, 501, 51));
        pushButton_ESP07 = new QPushButton(groupBox_33);
        pushButton_ESP07->setObjectName(QString::fromUtf8("pushButton_ESP07"));
        pushButton_ESP07->setGeometry(QRect(4, 18, 131, 23));
        label_LinkStatus_ESP07 = new QLabel(groupBox_33);
        label_LinkStatus_ESP07->setObjectName(QString::fromUtf8("label_LinkStatus_ESP07"));
        label_LinkStatus_ESP07->setGeometry(QRect(201, 14, 301, 31));
        label_51 = new QLabel(groupBox_33);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(150, 20, 61, 21));
        groupBox_34 = new QGroupBox(tab_4);
        groupBox_34->setObjectName(QString::fromUtf8("groupBox_34"));
        groupBox_34->setGeometry(QRect(260, 130, 511, 281));
        btn_getWIFI_2 = new QPushButton(groupBox_34);
        btn_getWIFI_2->setObjectName(QString::fromUtf8("btn_getWIFI_2"));
        btn_getWIFI_2->setGeometry(QRect(10, 20, 75, 23));
        tableWidget_SSID_ESP07S = new QTableWidget(groupBox_34);
        if (tableWidget_SSID_ESP07S->columnCount() < 7)
            tableWidget_SSID_ESP07S->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_SSID_ESP07S->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableWidget_SSID_ESP07S->setObjectName(QString::fromUtf8("tableWidget_SSID_ESP07S"));
        tableWidget_SSID_ESP07S->setGeometry(QRect(10, 50, 491, 221));
        tabWidget->addTab(tab_4, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        groupBox_35 = new QGroupBox(tab_10);
        groupBox_35->setObjectName(QString::fromUtf8("groupBox_35"));
        groupBox_35->setGeometry(QRect(0, 0, 791, 411));
        groupBox_27 = new QGroupBox(groupBox_35);
        groupBox_27->setObjectName(QString::fromUtf8("groupBox_27"));
        groupBox_27->setGeometry(QRect(10, 20, 241, 381));
        btn_setFunction = new QPushButton(groupBox_27);
        btn_setFunction->setObjectName(QString::fromUtf8("btn_setFunction"));
        btn_setFunction->setGeometry(QRect(110, 20, 81, 23));
        comboBox_SetFunction = new QComboBox(groupBox_27);
        comboBox_SetFunction->setObjectName(QString::fromUtf8("comboBox_SetFunction"));
        comboBox_SetFunction->setGeometry(QRect(20, 20, 69, 22));
        label_60 = new QLabel(groupBox_27);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(10, 50, 111, 20));
        plainTextEdit_RSDID = new QPlainTextEdit(groupBox_27);
        plainTextEdit_RSDID->setObjectName(QString::fromUtf8("plainTextEdit_RSDID"));
        plainTextEdit_RSDID->setGeometry(QRect(10, 80, 151, 81));
        btn_setFunction_open = new QPushButton(groupBox_27);
        btn_setFunction_open->setObjectName(QString::fromUtf8("btn_setFunction_open"));
        btn_setFunction_open->setGeometry(QRect(170, 90, 61, 23));
        btn_setFunction_close = new QPushButton(groupBox_27);
        btn_setFunction_close->setObjectName(QString::fromUtf8("btn_setFunction_close"));
        btn_setFunction_close->setGeometry(QRect(170, 130, 61, 23));
        btn_getRSDStatus = new QPushButton(groupBox_27);
        btn_getRSDStatus->setObjectName(QString::fromUtf8("btn_getRSDStatus"));
        btn_getRSDStatus->setGeometry(QRect(10, 170, 75, 21));
        tableWidget_RSDStatus = new QTableWidget(groupBox_27);
        if (tableWidget_RSDStatus->columnCount() < 2)
            tableWidget_RSDStatus->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_RSDStatus->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_RSDStatus->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        tableWidget_RSDStatus->setObjectName(QString::fromUtf8("tableWidget_RSDStatus"));
        tableWidget_RSDStatus->setGeometry(QRect(10, 200, 221, 161));
        groupBox_36 = new QGroupBox(groupBox_35);
        groupBox_36->setObjectName(QString::fromUtf8("groupBox_36"));
        groupBox_36->setGeometry(QRect(250, 20, 211, 211));
        btn_functionstatus = new QPushButton(groupBox_36);
        btn_functionstatus->setObjectName(QString::fromUtf8("btn_functionstatus"));
        btn_functionstatus->setGeometry(QRect(10, 20, 101, 23));
        label_34 = new QLabel(groupBox_36);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 50, 91, 20));
        RSDstatus = new QLabel(groupBox_36);
        RSDstatus->setObjectName(QString::fromUtf8("RSDstatus"));
        RSDstatus->setGeometry(QRect(110, 50, 91, 21));
        groupBox_37 = new QGroupBox(groupBox_35);
        groupBox_37->setObjectName(QString::fromUtf8("groupBox_37"));
        groupBox_37->setGeometry(QRect(470, 20, 301, 211));
        btn_SetServer = new QPushButton(groupBox_37);
        btn_SetServer->setObjectName(QString::fromUtf8("btn_SetServer"));
        btn_SetServer->setGeometry(QRect(170, 180, 75, 23));
        gridLayoutWidget_3 = new QWidget(groupBox_37);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(7, 20, 280, 154));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_54 = new QLabel(gridLayoutWidget_3);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        gridLayout_3->addWidget(label_54, 0, 0, 1, 1);

        comboBox_ServerItem = new QComboBox(gridLayoutWidget_3);
        comboBox_ServerItem->setObjectName(QString::fromUtf8("comboBox_ServerItem"));

        gridLayout_3->addWidget(comboBox_ServerItem, 0, 1, 1, 1);

        label_55 = new QLabel(gridLayoutWidget_3);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        gridLayout_3->addWidget(label_55, 1, 0, 1, 1);

        lineEdit_Domain = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Domain->setObjectName(QString::fromUtf8("lineEdit_Domain"));

        gridLayout_3->addWidget(lineEdit_Domain, 1, 1, 1, 1);

        label_56 = new QLabel(gridLayoutWidget_3);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_3->addWidget(label_56, 2, 0, 1, 1);

        label_57 = new QLabel(gridLayoutWidget_3);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        gridLayout_3->addWidget(label_57, 3, 0, 1, 1);

        lineEdit_Port1 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Port1->setObjectName(QString::fromUtf8("lineEdit_Port1"));

        gridLayout_3->addWidget(lineEdit_Port1, 3, 1, 1, 1);

        label_58 = new QLabel(gridLayoutWidget_3);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_3->addWidget(label_58, 4, 0, 1, 1);

        lineEdit_Port2 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Port2->setObjectName(QString::fromUtf8("lineEdit_Port2"));

        gridLayout_3->addWidget(lineEdit_Port2, 4, 1, 1, 1);

        label_59 = new QLabel(gridLayoutWidget_3);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_3->addWidget(label_59, 5, 0, 1, 1);

        lineEdit_Port3 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Port3->setObjectName(QString::fromUtf8("lineEdit_Port3"));

        gridLayout_3->addWidget(lineEdit_Port3, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_Ip_1 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Ip_1->setObjectName(QString::fromUtf8("lineEdit_Ip_1"));

        horizontalLayout->addWidget(lineEdit_Ip_1);

        l_21 = new QLabel(gridLayoutWidget_3);
        l_21->setObjectName(QString::fromUtf8("l_21"));

        horizontalLayout->addWidget(l_21);

        lineEdit_Ip_2 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Ip_2->setObjectName(QString::fromUtf8("lineEdit_Ip_2"));

        horizontalLayout->addWidget(lineEdit_Ip_2);

        l_22 = new QLabel(gridLayoutWidget_3);
        l_22->setObjectName(QString::fromUtf8("l_22"));

        horizontalLayout->addWidget(l_22);

        lineEdit_Ip_3 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Ip_3->setObjectName(QString::fromUtf8("lineEdit_Ip_3"));

        horizontalLayout->addWidget(lineEdit_Ip_3);

        l_23 = new QLabel(gridLayoutWidget_3);
        l_23->setObjectName(QString::fromUtf8("l_23"));

        horizontalLayout->addWidget(l_23);

        lineEdit_Ip_4 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_Ip_4->setObjectName(QString::fromUtf8("lineEdit_Ip_4"));

        horizontalLayout->addWidget(lineEdit_Ip_4);


        gridLayout_3->addLayout(horizontalLayout, 2, 1, 1, 1);

        groupBox_38 = new QGroupBox(groupBox_35);
        groupBox_38->setObjectName(QString::fromUtf8("groupBox_38"));
        groupBox_38->setGeometry(QRect(250, 240, 261, 161));
        btn_RSSI = new QPushButton(groupBox_38);
        btn_RSSI->setObjectName(QString::fromUtf8("btn_RSSI"));
        btn_RSSI->setGeometry(QRect(10, 20, 101, 23));
        tableWidget_RSSI = new QTableWidget(groupBox_38);
        if (tableWidget_RSSI->columnCount() < 2)
            tableWidget_RSSI->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_RSSI->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_RSSI->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        tableWidget_RSSI->setObjectName(QString::fromUtf8("tableWidget_RSSI"));
        tableWidget_RSSI->setGeometry(QRect(10, 50, 221, 101));
        groupBox_39 = new QGroupBox(groupBox_35);
        groupBox_39->setObjectName(QString::fromUtf8("groupBox_39"));
        groupBox_39->setGeometry(QRect(520, 240, 251, 151));
        btn_ClearEnergy = new QPushButton(groupBox_39);
        btn_ClearEnergy->setObjectName(QString::fromUtf8("btn_ClearEnergy"));
        btn_ClearEnergy->setGeometry(QRect(10, 20, 101, 23));
        tabWidget->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        groupBox_43 = new QGroupBox(tab_11);
        groupBox_43->setObjectName(QString::fromUtf8("groupBox_43"));
        groupBox_43->setGeometry(QRect(0, 0, 791, 411));
        groupBox_44 = new QGroupBox(groupBox_43);
        groupBox_44->setObjectName(QString::fromUtf8("groupBox_44"));
        groupBox_44->setGeometry(QRect(10, 20, 241, 381));
        btn_SetTurnOnOff = new QPushButton(groupBox_44);
        btn_SetTurnOnOff->setObjectName(QString::fromUtf8("btn_SetTurnOnOff"));
        btn_SetTurnOnOff->setGeometry(QRect(140, 20, 81, 23));
        comboBox_SetTurnOnOff = new QComboBox(groupBox_44);
        comboBox_SetTurnOnOff->setObjectName(QString::fromUtf8("comboBox_SetTurnOnOff"));
        comboBox_SetTurnOnOff->setGeometry(QRect(20, 20, 101, 22));
        label_70 = new QLabel(groupBox_44);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(10, 50, 111, 20));
        plainTextEdit_SetTurnOnOff = new QPlainTextEdit(groupBox_44);
        plainTextEdit_SetTurnOnOff->setObjectName(QString::fromUtf8("plainTextEdit_SetTurnOnOff"));
        plainTextEdit_SetTurnOnOff->setGeometry(QRect(10, 80, 151, 81));
        btn_SetTurnOnOff_Open = new QPushButton(groupBox_44);
        btn_SetTurnOnOff_Open->setObjectName(QString::fromUtf8("btn_SetTurnOnOff_Open"));
        btn_SetTurnOnOff_Open->setGeometry(QRect(170, 90, 61, 23));
        btn_SetTurnOnOff_Close = new QPushButton(groupBox_44);
        btn_SetTurnOnOff_Close->setObjectName(QString::fromUtf8("btn_SetTurnOnOff_Close"));
        btn_SetTurnOnOff_Close->setGeometry(QRect(170, 130, 61, 23));
        btn_getSetTurnOnOff = new QPushButton(groupBox_44);
        btn_getSetTurnOnOff->setObjectName(QString::fromUtf8("btn_getSetTurnOnOff"));
        btn_getSetTurnOnOff->setGeometry(QRect(10, 170, 111, 21));
        tableWidget_SetTurnOnOff = new QTableWidget(groupBox_44);
        if (tableWidget_SetTurnOnOff->columnCount() < 2)
            tableWidget_SetTurnOnOff->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_SetTurnOnOff->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_SetTurnOnOff->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        tableWidget_SetTurnOnOff->setObjectName(QString::fromUtf8("tableWidget_SetTurnOnOff"));
        tableWidget_SetTurnOnOff->setGeometry(QRect(10, 200, 221, 161));
        groupBox_45 = new QGroupBox(groupBox_43);
        groupBox_45->setObjectName(QString::fromUtf8("groupBox_45"));
        groupBox_45->setGeometry(QRect(250, 20, 241, 381));
        label_72 = new QLabel(groupBox_45);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setGeometry(QRect(10, 10, 111, 20));
        plainTextEdit_ClearGFDI = new QPlainTextEdit(groupBox_45);
        plainTextEdit_ClearGFDI->setObjectName(QString::fromUtf8("plainTextEdit_ClearGFDI"));
        plainTextEdit_ClearGFDI->setGeometry(QRect(10, 40, 151, 81));
        btn_ClearGFDI = new QPushButton(groupBox_45);
        btn_ClearGFDI->setObjectName(QString::fromUtf8("btn_ClearGFDI"));
        btn_ClearGFDI->setGeometry(QRect(170, 50, 61, 23));
        btn_getClearGFDI = new QPushButton(groupBox_45);
        btn_getClearGFDI->setObjectName(QString::fromUtf8("btn_getClearGFDI"));
        btn_getClearGFDI->setGeometry(QRect(10, 130, 111, 21));
        tableWidget_ClearGFDI = new QTableWidget(groupBox_45);
        if (tableWidget_ClearGFDI->columnCount() < 2)
            tableWidget_ClearGFDI->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_ClearGFDI->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_ClearGFDI->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        tableWidget_ClearGFDI->setObjectName(QString::fromUtf8("tableWidget_ClearGFDI"));
        tableWidget_ClearGFDI->setGeometry(QRect(10, 160, 221, 161));
        groupBox_46 = new QGroupBox(groupBox_43);
        groupBox_46->setObjectName(QString::fromUtf8("groupBox_46"));
        groupBox_46->setGeometry(QRect(500, 20, 281, 381));
        btn_MaxPower = new QPushButton(groupBox_46);
        btn_MaxPower->setObjectName(QString::fromUtf8("btn_MaxPower"));
        btn_MaxPower->setGeometry(QRect(140, 50, 101, 23));
        label_75 = new QLabel(groupBox_46);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setGeometry(QRect(10, 80, 111, 20));
        plainTextEdit_SeMaxPower = new QPlainTextEdit(groupBox_46);
        plainTextEdit_SeMaxPower->setObjectName(QString::fromUtf8("plainTextEdit_SeMaxPower"));
        plainTextEdit_SeMaxPower->setGeometry(QRect(10, 110, 151, 81));
        btn_SetMaxPower = new QPushButton(groupBox_46);
        btn_SetMaxPower->setObjectName(QString::fromUtf8("btn_SetMaxPower"));
        btn_SetMaxPower->setGeometry(QRect(170, 160, 81, 23));
        btn_getMaxPower = new QPushButton(groupBox_46);
        btn_getMaxPower->setObjectName(QString::fromUtf8("btn_getMaxPower"));
        btn_getMaxPower->setGeometry(QRect(10, 200, 111, 21));
        tableWidget_MaxPower = new QTableWidget(groupBox_46);
        if (tableWidget_MaxPower->columnCount() < 3)
            tableWidget_MaxPower->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_MaxPower->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_MaxPower->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_MaxPower->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        tableWidget_MaxPower->setObjectName(QString::fromUtf8("tableWidget_MaxPower"));
        tableWidget_MaxPower->setGeometry(QRect(10, 230, 261, 141));
        lineEdit_MaxPower = new QLineEdit(groupBox_46);
        lineEdit_MaxPower->setObjectName(QString::fromUtf8("lineEdit_MaxPower"));
        lineEdit_MaxPower->setGeometry(QRect(10, 50, 121, 21));
        lineEdit_MaxPower_2 = new QLineEdit(groupBox_46);
        lineEdit_MaxPower_2->setObjectName(QString::fromUtf8("lineEdit_MaxPower_2"));
        lineEdit_MaxPower_2->setGeometry(QRect(170, 130, 81, 21));
        btn_MaxPower_get = new QPushButton(groupBox_46);
        btn_MaxPower_get->setObjectName(QString::fromUtf8("btn_MaxPower_get"));
        btn_MaxPower_get->setGeometry(QRect(10, 20, 81, 23));
        tabWidget->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        groupBox_47 = new QGroupBox(tab_12);
        groupBox_47->setObjectName(QString::fromUtf8("groupBox_47"));
        groupBox_47->setGeometry(QRect(0, 0, 791, 411));
        groupBox_50 = new QGroupBox(groupBox_47);
        groupBox_50->setObjectName(QString::fromUtf8("groupBox_50"));
        groupBox_50->setGeometry(QRect(10, 20, 281, 381));
        btn_IRD = new QPushButton(groupBox_50);
        btn_IRD->setObjectName(QString::fromUtf8("btn_IRD"));
        btn_IRD->setGeometry(QRect(140, 50, 101, 23));
        label_77 = new QLabel(groupBox_50);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setGeometry(QRect(10, 80, 111, 20));
        plainTextEdit_IRD = new QPlainTextEdit(groupBox_50);
        plainTextEdit_IRD->setObjectName(QString::fromUtf8("plainTextEdit_IRD"));
        plainTextEdit_IRD->setGeometry(QRect(10, 110, 151, 81));
        btn_SetIRD = new QPushButton(groupBox_50);
        btn_SetIRD->setObjectName(QString::fromUtf8("btn_SetIRD"));
        btn_SetIRD->setGeometry(QRect(170, 160, 81, 23));
        btn_geIRD = new QPushButton(groupBox_50);
        btn_geIRD->setObjectName(QString::fromUtf8("btn_geIRD"));
        btn_geIRD->setGeometry(QRect(10, 200, 111, 21));
        tableWidget_IRD = new QTableWidget(groupBox_50);
        if (tableWidget_IRD->columnCount() < 3)
            tableWidget_IRD->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_IRD->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_IRD->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_IRD->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        tableWidget_IRD->setObjectName(QString::fromUtf8("tableWidget_IRD"));
        tableWidget_IRD->setGeometry(QRect(10, 230, 261, 141));
        btn_IRD_get = new QPushButton(groupBox_50);
        btn_IRD_get->setObjectName(QString::fromUtf8("btn_IRD_get"));
        btn_IRD_get->setGeometry(QRect(10, 20, 81, 23));
        comboBox_IRDALL = new QComboBox(groupBox_50);
        comboBox_IRDALL->setObjectName(QString::fromUtf8("comboBox_IRDALL"));
        comboBox_IRDALL->setGeometry(QRect(10, 50, 111, 22));
        comboBox_IRD = new QComboBox(groupBox_50);
        comboBox_IRD->setObjectName(QString::fromUtf8("comboBox_IRD"));
        comboBox_IRD->setGeometry(QRect(170, 130, 101, 22));
        groupBox_20 = new QGroupBox(groupBox_47);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        groupBox_20->setGeometry(QRect(300, 20, 481, 381));
        dateEdit_alarm = new QDateEdit(groupBox_20);
        dateEdit_alarm->setObjectName(QString::fromUtf8("dateEdit_alarm"));
        dateEdit_alarm->setGeometry(QRect(50, 28, 110, 22));
        label_61 = new QLabel(groupBox_20);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(10, 30, 31, 16));
        label_71 = new QLabel(groupBox_20);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setGeometry(QRect(180, 30, 41, 16));
        spinBox_alarm = new QSpinBox(groupBox_20);
        spinBox_alarm->setObjectName(QString::fromUtf8("spinBox_alarm"));
        spinBox_alarm->setGeometry(QRect(230, 28, 42, 22));
        tableWidget_alarmEvent = new QTableWidget(groupBox_20);
        if (tableWidget_alarmEvent->columnCount() < 3)
            tableWidget_alarmEvent->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_alarmEvent->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_alarmEvent->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_alarmEvent->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        tableWidget_alarmEvent->setObjectName(QString::fromUtf8("tableWidget_alarmEvent"));
        tableWidget_alarmEvent->setGeometry(QRect(10, 53, 461, 191));
        btn_alarmevent = new QPushButton(groupBox_20);
        btn_alarmevent->setObjectName(QString::fromUtf8("btn_alarmevent"));
        btn_alarmevent->setGeometry(QRect(290, 29, 101, 23));
        textBrowser_alarmEvent = new QTextBrowser(groupBox_20);
        textBrowser_alarmEvent->setObjectName(QString::fromUtf8("textBrowser_alarmEvent"));
        textBrowser_alarmEvent->setGeometry(QRect(10, 251, 461, 91));
        tabWidget->addTab(tab_12, QString());
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
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(5, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_Info->setHorizontalHeaderItem(6, __qtablewidgetitem38);
        tableWidget_Info->setObjectName(QString::fromUtf8("tableWidget_Info"));
        tableWidget_Info->setGeometry(QRect(10, 50, 771, 361));
        btn_getInfo = new QPushButton(groupBox_6);
        btn_getInfo->setObjectName(QString::fromUtf8("btn_getInfo"));
        btn_getInfo->setGeometry(QRect(630, 20, 91, 21));
        btn_getDate_2 = new QPushButton(groupBox_6);
        btn_getDate_2->setObjectName(QString::fromUtf8("btn_getDate_2"));
        btn_getDate_2->setGeometry(QRect(510, 20, 91, 23));
        tabWidget->addTab(tab_3, QString());
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_3 = new QTabWidget(tab_6);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(4, 0, 791, 441));
        tabWidget_3->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{\n"
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
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        groupBox_18 = new QGroupBox(tab_7);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(0, 0, 271, 71));
        label_13 = new QLabel(groupBox_18);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 16, 41, 21));
        label_14 = new QLabel(groupBox_18);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 40, 41, 21));
        lineEdit_IP_IDWrite = new QLineEdit(groupBox_18);
        lineEdit_IP_IDWrite->setObjectName(QString::fromUtf8("lineEdit_IP_IDWrite"));
        lineEdit_IP_IDWrite->setGeometry(QRect(50, 16, 91, 20));
        lineEdit_Port_IDWrite = new QLineEdit(groupBox_18);
        lineEdit_Port_IDWrite->setObjectName(QString::fromUtf8("lineEdit_Port_IDWrite"));
        lineEdit_Port_IDWrite->setGeometry(QRect(50, 41, 91, 20));
        btn_config_IDWrite = new QPushButton(groupBox_18);
        btn_config_IDWrite->setObjectName(QString::fromUtf8("btn_config_IDWrite"));
        btn_config_IDWrite->setGeometry(QRect(150, 15, 121, 41));
        groupBox_21 = new QGroupBox(tab_7);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        groupBox_21->setGeometry(QRect(0, 70, 271, 51));
        btn_mkfs = new QPushButton(groupBox_21);
        btn_mkfs->setObjectName(QString::fromUtf8("btn_mkfs"));
        btn_mkfs->setGeometry(QRect(10, 20, 101, 23));
        label_24 = new QLabel(groupBox_21);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(120, 20, 31, 21));
        label_mkfs = new QLabel(groupBox_21);
        label_mkfs->setObjectName(QString::fromUtf8("label_mkfs"));
        label_mkfs->setGeometry(QRect(160, 20, 91, 21));
        groupBox_19 = new QGroupBox(tab_7);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(0, 120, 271, 81));
        btn_setID = new QPushButton(groupBox_19);
        btn_setID->setObjectName(QString::fromUtf8("btn_setID"));
        btn_setID->setGeometry(QRect(10, 20, 101, 23));
        btn_getID = new QPushButton(groupBox_19);
        btn_getID->setObjectName(QString::fromUtf8("btn_getID"));
        btn_getID->setGeometry(QRect(10, 50, 101, 23));
        lineEdit_ID_2 = new QLineEdit(groupBox_19);
        lineEdit_ID_2->setObjectName(QString::fromUtf8("lineEdit_ID_2"));
        lineEdit_ID_2->setGeometry(QRect(120, 20, 81, 21));
        label_ID_2 = new QLabel(groupBox_19);
        label_ID_2->setObjectName(QString::fromUtf8("label_ID_2"));
        label_ID_2->setGeometry(QRect(170, 50, 91, 21));
        label_26 = new QLabel(groupBox_19);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(120, 50, 31, 21));
        groupBox_22 = new QGroupBox(tab_7);
        groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
        groupBox_22->setGeometry(QRect(0, 200, 271, 71));
        lineEdit_MAC = new QLineEdit(groupBox_22);
        lineEdit_MAC->setObjectName(QString::fromUtf8("lineEdit_MAC"));
        lineEdit_MAC->setGeometry(QRect(90, 14, 111, 21));
        label_MAC = new QLabel(groupBox_22);
        label_MAC->setObjectName(QString::fromUtf8("label_MAC"));
        label_MAC->setGeometry(QRect(120, 44, 141, 21));
        btn_setMAC = new QPushButton(groupBox_22);
        btn_setMAC->setObjectName(QString::fromUtf8("btn_setMAC"));
        btn_setMAC->setGeometry(QRect(10, 14, 71, 23));
        btn_getMAC = new QPushButton(groupBox_22);
        btn_getMAC->setObjectName(QString::fromUtf8("btn_getMAC"));
        btn_getMAC->setGeometry(QRect(10, 44, 71, 23));
        label_28 = new QLabel(groupBox_22);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(88, 44, 31, 21));
        groupBox_23 = new QGroupBox(tab_7);
        groupBox_23->setObjectName(QString::fromUtf8("groupBox_23"));
        groupBox_23->setGeometry(QRect(280, 0, 261, 81));
        btn_setArea = new QPushButton(groupBox_23);
        btn_setArea->setObjectName(QString::fromUtf8("btn_setArea"));
        btn_setArea->setGeometry(QRect(10, 20, 101, 23));
        btn_getArea = new QPushButton(groupBox_23);
        btn_getArea->setObjectName(QString::fromUtf8("btn_getArea"));
        btn_getArea->setGeometry(QRect(10, 50, 101, 23));
        label_Area = new QLabel(groupBox_23);
        label_Area->setObjectName(QString::fromUtf8("label_Area"));
        label_Area->setGeometry(QRect(160, 50, 91, 21));
        label_35 = new QLabel(groupBox_23);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(120, 50, 31, 21));
        comboBox_Area = new QComboBox(groupBox_23);
        comboBox_Area->setObjectName(QString::fromUtf8("comboBox_Area"));
        comboBox_Area->setGeometry(QRect(170, 20, 61, 22));
        label_36 = new QLabel(groupBox_23);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(120, 20, 31, 21));
        groupBox_24 = new QGroupBox(tab_7);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        groupBox_24->setGeometry(QRect(0, 270, 271, 81));
        btn_getTime_2 = new QPushButton(groupBox_24);
        btn_getTime_2->setObjectName(QString::fromUtf8("btn_getTime_2"));
        btn_getTime_2->setGeometry(QRect(10, 50, 101, 23));
        btn_setTime_2 = new QPushButton(groupBox_24);
        btn_setTime_2->setObjectName(QString::fromUtf8("btn_setTime_2"));
        btn_setTime_2->setGeometry(QRect(10, 20, 101, 23));
        comboBox_TimeZone = new QComboBox(groupBox_24);
        comboBox_TimeZone->setObjectName(QString::fromUtf8("comboBox_TimeZone"));
        comboBox_TimeZone->setGeometry(QRect(160, 20, 61, 22));
        label_37 = new QLabel(groupBox_24);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(120, 20, 31, 21));
        label_Time = new QLabel(groupBox_24);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setGeometry(QRect(160, 50, 91, 21));
        label_38 = new QLabel(groupBox_24);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(120, 50, 31, 21));
        groupBox_25 = new QGroupBox(tab_7);
        groupBox_25->setObjectName(QString::fromUtf8("groupBox_25"));
        groupBox_25->setGeometry(QRect(280, 80, 261, 51));
        btn_LED = new QPushButton(groupBox_25);
        btn_LED->setObjectName(QString::fromUtf8("btn_LED"));
        btn_LED->setGeometry(QRect(10, 20, 101, 23));
        groupBox_26 = new QGroupBox(tab_7);
        groupBox_26->setObjectName(QString::fromUtf8("groupBox_26"));
        groupBox_26->setGeometry(QRect(280, 130, 261, 81));
        btn_Version = new QPushButton(groupBox_26);
        btn_Version->setObjectName(QString::fromUtf8("btn_Version"));
        btn_Version->setGeometry(QRect(10, 20, 101, 23));
        label_39 = new QLabel(groupBox_26);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(120, 20, 31, 21));
        label_version = new QLabel(groupBox_26);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setGeometry(QRect(160, 20, 91, 21));
        btn_InternalVersion = new QPushButton(groupBox_26);
        btn_InternalVersion->setObjectName(QString::fromUtf8("btn_InternalVersion"));
        btn_InternalVersion->setGeometry(QRect(10, 50, 101, 23));
        label_62 = new QLabel(groupBox_26);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(120, 50, 31, 21));
        label_InternalVersion = new QLabel(groupBox_26);
        label_InternalVersion->setObjectName(QString::fromUtf8("label_InternalVersion"));
        label_InternalVersion->setGeometry(QRect(160, 50, 91, 21));
        groupBox_28 = new QGroupBox(tab_7);
        groupBox_28->setObjectName(QString::fromUtf8("groupBox_28"));
        groupBox_28->setGeometry(QRect(540, 0, 241, 351));
        btn_addInverter = new QPushButton(groupBox_28);
        btn_addInverter->setObjectName(QString::fromUtf8("btn_addInverter"));
        btn_addInverter->setGeometry(QRect(10, 20, 91, 23));
        lineEdit_INVERTER = new QLineEdit(groupBox_28);
        lineEdit_INVERTER->setObjectName(QString::fromUtf8("lineEdit_INVERTER"));
        lineEdit_INVERTER->setGeometry(QRect(110, 20, 111, 21));
        btn_query_result = new QPushButton(groupBox_28);
        btn_query_result->setObjectName(QString::fromUtf8("btn_query_result"));
        btn_query_result->setGeometry(QRect(10, 80, 91, 23));
        btn_query_protection = new QPushButton(groupBox_28);
        btn_query_protection->setObjectName(QString::fromUtf8("btn_query_protection"));
        btn_query_protection->setGeometry(QRect(10, 210, 91, 23));
        label_inverter = new QLabel(groupBox_28);
        label_inverter->setObjectName(QString::fromUtf8("label_inverter"));
        label_inverter->setGeometry(QRect(80, 50, 141, 21));
        label_41 = new QLabel(groupBox_28);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(50, 50, 31, 21));
        textBrowser = new QTextBrowser(groupBox_28);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(5, 110, 231, 91));
        textBrowser_2 = new QTextBrowser(groupBox_28);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(5, 240, 231, 91));
        groupBox_29 = new QGroupBox(tab_7);
        groupBox_29->setObjectName(QString::fromUtf8("groupBox_29"));
        groupBox_29->setGeometry(QRect(280, 210, 261, 51));
        btn_Clear = new QPushButton(groupBox_29);
        btn_Clear->setObjectName(QString::fromUtf8("btn_Clear"));
        btn_Clear->setGeometry(QRect(10, 20, 101, 23));
        label_40 = new QLabel(groupBox_29);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(120, 20, 31, 21));
        label_Clear = new QLabel(groupBox_29);
        label_Clear->setObjectName(QString::fromUtf8("label_Clear"));
        label_Clear->setGeometry(QRect(160, 20, 91, 21));
        groupBox_40 = new QGroupBox(tab_7);
        groupBox_40->setObjectName(QString::fromUtf8("groupBox_40"));
        groupBox_40->setGeometry(QRect(280, 260, 261, 51));
        btn_Flash = new QPushButton(groupBox_40);
        btn_Flash->setObjectName(QString::fromUtf8("btn_Flash"));
        btn_Flash->setGeometry(QRect(10, 20, 101, 23));
        label_63 = new QLabel(groupBox_40);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(120, 20, 31, 21));
        label_Flash = new QLabel(groupBox_40);
        label_Flash->setObjectName(QString::fromUtf8("label_Flash"));
        label_Flash->setGeometry(QRect(160, 20, 91, 21));
        groupBox_41 = new QGroupBox(tab_7);
        groupBox_41->setObjectName(QString::fromUtf8("groupBox_41"));
        groupBox_41->setGeometry(QRect(280, 310, 261, 41));
        btn_reboot = new QPushButton(groupBox_41);
        btn_reboot->setObjectName(QString::fromUtf8("btn_reboot"));
        btn_reboot->setGeometry(QRect(10, 15, 101, 23));
        label_64 = new QLabel(groupBox_41);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(120, 15, 31, 21));
        label_reboot = new QLabel(groupBox_41);
        label_reboot->setObjectName(QString::fromUtf8("label_reboot"));
        label_reboot->setGeometry(QRect(160, 15, 91, 21));
        groupBox_42 = new QGroupBox(tab_7);
        groupBox_42->setObjectName(QString::fromUtf8("groupBox_42"));
        groupBox_42->setGeometry(QRect(0, 350, 781, 51));
        label_65 = new QLabel(groupBox_42);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(12, 22, 21, 16));
        lineEdit_UpdateIP = new QLineEdit(groupBox_42);
        lineEdit_UpdateIP->setObjectName(QString::fromUtf8("lineEdit_UpdateIP"));
        lineEdit_UpdateIP->setGeometry(QRect(40, 20, 91, 20));
        label_66 = new QLabel(groupBox_42);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setGeometry(QRect(140, 20, 41, 21));
        lineEdit_UpdatePort = new QLineEdit(groupBox_42);
        lineEdit_UpdatePort->setObjectName(QString::fromUtf8("lineEdit_UpdatePort"));
        lineEdit_UpdatePort->setGeometry(QRect(170, 21, 41, 20));
        label_67 = new QLabel(groupBox_42);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(220, 19, 41, 21));
        lineEdit_UpdateUser = new QLineEdit(groupBox_42);
        lineEdit_UpdateUser->setObjectName(QString::fromUtf8("lineEdit_UpdateUser"));
        lineEdit_UpdateUser->setGeometry(QRect(267, 20, 71, 20));
        lineEdit_UpdatePasswd = new QLineEdit(groupBox_42);
        lineEdit_UpdatePasswd->setObjectName(QString::fromUtf8("lineEdit_UpdatePasswd"));
        lineEdit_UpdatePasswd->setGeometry(QRect(370, 20, 61, 20));
        label_68 = new QLabel(groupBox_42);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setGeometry(QRect(340, 20, 31, 21));
        btn_update_ver = new QPushButton(groupBox_42);
        btn_update_ver->setObjectName(QString::fromUtf8("btn_update_ver"));
        btn_update_ver->setGeometry(QRect(440, 18, 101, 23));
        btn_update_ID = new QPushButton(groupBox_42);
        btn_update_ID->setObjectName(QString::fromUtf8("btn_update_ID"));
        btn_update_ID->setGeometry(QRect(543, 17, 71, 23));
        label_update = new QLabel(groupBox_42);
        label_update->setObjectName(QString::fromUtf8("label_update"));
        label_update->setGeometry(QRect(660, 20, 101, 21));
        label_69 = new QLabel(groupBox_42);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setGeometry(QRect(620, 20, 31, 21));
        tabWidget_3->addTab(tab_7, QString());
        tabWidget_2->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tabWidget_4 = new QTabWidget(tab_8);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(4, 0, 791, 441));
        tabWidget_4->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{\n"
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
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        groupBox_30 = new QGroupBox(tab_9);
        groupBox_30->setObjectName(QString::fromUtf8("groupBox_30"));
        groupBox_30->setGeometry(QRect(0, 0, 261, 71));
        label_46 = new QLabel(groupBox_30);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(10, 16, 41, 21));
        label_47 = new QLabel(groupBox_30);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(10, 40, 41, 21));
        lineEdit_IP_JSON = new QLineEdit(groupBox_30);
        lineEdit_IP_JSON->setObjectName(QString::fromUtf8("lineEdit_IP_JSON"));
        lineEdit_IP_JSON->setGeometry(QRect(50, 16, 91, 20));
        lineEdit_Port_JSON = new QLineEdit(groupBox_30);
        lineEdit_Port_JSON->setObjectName(QString::fromUtf8("lineEdit_Port_JSON"));
        lineEdit_Port_JSON->setGeometry(QRect(50, 41, 91, 20));
        btn_config_JSON = new QPushButton(groupBox_30);
        btn_config_JSON->setObjectName(QString::fromUtf8("btn_config_JSON"));
        btn_config_JSON->setGeometry(QRect(150, 20, 101, 31));
        plainTextEdit = new QPlainTextEdit(tab_9);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(290, 10, 421, 401));
        groupBox_31 = new QGroupBox(tab_9);
        groupBox_31->setObjectName(QString::fromUtf8("groupBox_31"));
        groupBox_31->setGeometry(QRect(0, 80, 251, 61));
        btn_cmd101 = new QPushButton(groupBox_31);
        btn_cmd101->setObjectName(QString::fromUtf8("btn_cmd101"));
        btn_cmd101->setGeometry(QRect(10, 20, 75, 23));
        tabWidget_4->addTab(tab_9, QString());
        tabWidget_2->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 810, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_4->setCurrentIndex(0);


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
        groupBox_13->setTitle(QApplication::translate("MainWindow", "\346\234\211\344\272\272\346\250\241\345\235\227\350\216\267\345\217\226\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
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
        groupBox_14->setTitle(QApplication::translate("MainWindow", "\346\234\211\344\272\272\346\250\241\345\235\227\350\216\267\345\217\226WIFI\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
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
        groupBox_32->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\350\277\236\346\216\245\347\203\255\347\202\271ESP07S", 0, QApplication::UnicodeUTF8));
        btn_connect_ESP07->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        lineEdit_SSID2->setText(QApplication::translate("MainWindow", "yuneng_ecu_test", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        lineEdit_PassWD2->setText(QApplication::translate("MainWindow", "123456789", 0, QApplication::UnicodeUTF8));
        groupBox_33->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\277\236\346\216\245\347\203\255\347\202\271ESP07S", 0, QApplication::UnicodeUTF8));
        pushButton_ESP07->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226WIFI\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_LinkStatus_ESP07->setText(QString());
        label_51->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        groupBox_34->setTitle(QApplication::translate("MainWindow", "EPS07S\346\250\241\345\235\227\350\216\267\345\217\226\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        btn_getWIFI_2->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226WIFI\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_SSID_ESP07S->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "ECN", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_SSID_ESP07S->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_SSID_ESP07S->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "RSSI", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_SSID_ESP07S->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "MAC", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_SSID_ESP07S->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "CH", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_SSID_ESP07S->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "freq offset", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_SSID_ESP07S->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "freq calibration", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\237\255\345\234\260\345\235\200\343\200\201ESP07S", 0, QApplication::UnicodeUTF8));
        groupBox_35->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\222\214\346\237\245\350\257\242\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        groupBox_27->setTitle(QApplication::translate("MainWindow", "06 \350\256\276\347\275\256RSD\345\212\237\350\203\275\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        btn_setFunction->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        comboBox_SetFunction->clear();
        comboBox_SetFunction->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "00\357\274\232\345\205\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "01\357\274\232\345\274\200", 0, QApplication::UnicodeUTF8)
        );
        label_60->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\346\263\250\345\206\214\347\232\204ID\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        plainTextEdit_RSDID->setPlainText(QString());
        btn_setFunction_open->setText(QApplication::translate("MainWindow", "\345\210\227\350\241\250\345\274\200", 0, QApplication::UnicodeUTF8));
        btn_setFunction_close->setText(QApplication::translate("MainWindow", "\345\210\227\350\241\250\345\205\263", 0, QApplication::UnicodeUTF8));
        btn_getRSDStatus->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213RSD\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_RSDStatus->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_RSDStatus->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\345\212\237\350\203\275\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        groupBox_36->setTitle(QApplication::translate("MainWindow", "23 \346\237\245\350\257\242\345\212\237\350\203\275\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        btn_functionstatus->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\212\237\350\203\275\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "RSD\345\212\237\350\203\275\345\274\200\345\205\263\357\274\232", 0, QApplication::UnicodeUTF8));
        RSDstatus->setText(QString());
        groupBox_37->setTitle(QApplication::translate("MainWindow", "24 \346\237\245\347\234\213\345\222\214\350\256\276\347\275\256\347\233\270\345\205\263\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        btn_SetServer->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256/\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\211\351\241\271\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_ServerItem->clear();
        comboBox_ServerItem->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "01\357\274\232\346\237\245\347\234\213\345\215\207\347\272\247\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "02\357\274\232\346\237\245\347\234\213\346\225\260\346\215\256\344\270\212\344\274\240\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "03\357\274\232\346\237\245\347\234\213\350\277\234\347\250\213\346\216\247\345\210\266\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "04\357\274\232\350\256\276\347\275\256\345\215\207\347\272\247\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "05\357\274\232\350\256\276\347\275\256\346\225\260\346\215\256\344\270\212\344\274\240\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "06\357\274\232\350\256\276\347\275\256\350\277\234\347\250\213\346\216\247\345\210\266\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8)
        );
        label_55->setText(QApplication::translate("MainWindow", "\345\237\237\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("MainWindow", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("MainWindow", "Port1\357\274\232", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("MainWindow", "Port2\357\274\232", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("MainWindow", "Port3\357\274\232", 0, QApplication::UnicodeUTF8));
        l_21->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_22->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        l_23->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        groupBox_38->setTitle(QApplication::translate("MainWindow", "30 \344\277\241\345\217\267\345\274\272\345\272\246", 0, QApplication::UnicodeUTF8));
        btn_RSSI->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\212\237\350\203\275\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_RSSI->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_RSSI->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\344\277\241\345\217\267\345\274\272\345\272\246", 0, QApplication::UnicodeUTF8));
        groupBox_39->setTitle(QApplication::translate("MainWindow", "31 \346\270\205\351\231\244\345\216\206\345\217\262\345\217\221\347\224\265\351\207\217", 0, QApplication::UnicodeUTF8));
        btn_ClearEnergy->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\216\206\345\217\262\345\217\221\347\224\265\351\207\217", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\217\212\346\237\245\350\257\2421", 0, QApplication::UnicodeUTF8));
        groupBox_43->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\222\214\346\237\245\350\257\242\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        groupBox_44->setTitle(QApplication::translate("MainWindow", "26 \345\274\200\345\205\263\346\234\272\350\256\276\347\275\256\344\270\216\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btn_SetTurnOnOff->setText(QApplication::translate("MainWindow", "\345\271\277\346\222\255\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        comboBox_SetTurnOnOff->clear();
        comboBox_SetTurnOnOff->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "00\357\274\232\345\271\277\346\222\255\345\274\200\346\234\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "01\357\274\232\345\271\277\346\222\255\345\205\263\346\234\272", 0, QApplication::UnicodeUTF8)
        );
        label_70->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\350\256\276\347\275\256\347\232\204ID\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        plainTextEdit_SetTurnOnOff->setPlainText(QString());
        btn_SetTurnOnOff_Open->setText(QApplication::translate("MainWindow", "\345\210\227\350\241\250\345\274\200", 0, QApplication::UnicodeUTF8));
        btn_SetTurnOnOff_Close->setText(QApplication::translate("MainWindow", "\345\210\227\350\241\250\345\205\263", 0, QApplication::UnicodeUTF8));
        btn_getSetTurnOnOff->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\274\200\345\205\263\346\234\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_SetTurnOnOff->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_SetTurnOnOff->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\263\346\234\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        groupBox_45->setTitle(QApplication::translate("MainWindow", "27 \346\270\205\351\231\244GFDI\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_72->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\350\256\276\347\275\256\347\232\204ID\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        plainTextEdit_ClearGFDI->setPlainText(QString());
        btn_ClearGFDI->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244GFDI", 0, QApplication::UnicodeUTF8));
        btn_getClearGFDI->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213GFDI\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_ClearGFDI->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_ClearGFDI->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "GFDI\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        groupBox_46->setTitle(QApplication::translate("MainWindow", "25 \350\257\273\345\217\226\345\222\214\350\256\276\347\275\256\346\234\200\345\244\247\344\277\235\346\212\244\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        btn_MaxPower->setText(QApplication::translate("MainWindow", "\345\271\277\346\222\255\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\350\256\276\347\275\256\347\232\204ID\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        plainTextEdit_SeMaxPower->setPlainText(QString());
        btn_SetMaxPower->setText(QApplication::translate("MainWindow", "\345\215\225\346\222\255\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_getMaxPower->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\234\200\345\244\247\345\212\237\347\216\207\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_MaxPower->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_MaxPower->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_MaxPower->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\345\256\236\351\231\205\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        lineEdit_MaxPower->setText(QApplication::translate("MainWindow", "256", 0, QApplication::UnicodeUTF8));
        lineEdit_MaxPower_2->setText(QApplication::translate("MainWindow", "255", 0, QApplication::UnicodeUTF8));
        btn_MaxPower_get->setText(QApplication::translate("MainWindow", "\344\270\213\345\217\221\350\257\273\345\217\226\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\217\212\346\237\245\350\257\2422", 0, QApplication::UnicodeUTF8));
        groupBox_47->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\222\214\346\237\245\350\257\242\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        groupBox_50->setTitle(QApplication::translate("MainWindow", "28 \350\257\273\345\217\226\345\222\214\350\256\276\347\275\256IRD", 0, QApplication::UnicodeUTF8));
        btn_IRD->setText(QApplication::translate("MainWindow", "\345\271\277\346\222\255\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_77->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\350\256\276\347\275\256\347\232\204ID\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        plainTextEdit_IRD->setPlainText(QString());
        btn_SetIRD->setText(QApplication::translate("MainWindow", "\345\215\225\346\222\255\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_geIRD->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213IRD\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_IRD->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_IRD->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232IRD", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_IRD->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\345\256\236\351\231\205IRD", 0, QApplication::UnicodeUTF8));
        btn_IRD_get->setText(QApplication::translate("MainWindow", "\344\270\213\345\217\221\350\257\273\345\217\226\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        comboBox_IRDALL->clear();
        comboBox_IRDALL->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1:\345\205\263\351\227\255IRD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2:\345\274\200\345\220\257IRD\345\270\246\351\224\201\345\255\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3:\345\274\200\345\220\257IRD\344\270\215\345\270\246\351\224\201\345\255\230", 0, QApplication::UnicodeUTF8)
        );
        comboBox_IRD->clear();
        comboBox_IRD->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1:\345\205\263\351\227\255IRD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2:\345\274\200\345\220\257IRD\345\270\246\351\224\201\345\255\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3:\345\274\200\345\220\257IRD\344\270\215\345\270\246\351\224\201\345\255\230", 0, QApplication::UnicodeUTF8)
        );
        groupBox_20->setTitle(QApplication::translate("MainWindow", "32 \345\221\212\350\255\246\344\272\213\344\273\266", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_71->setText(QApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_alarmEvent->horizontalHeaderItem(0);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_alarmEvent->horizontalHeaderItem(1);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_alarmEvent->horizontalHeaderItem(2);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\345\221\212\350\255\246\344\272\213\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_alarmevent->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\221\212\350\255\246\344\272\213\344\273\266", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\217\212\346\237\245\350\257\2423", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "17 \345\215\225\345\217\260\347\233\270\345\205\263\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        label_73->setText(QApplication::translate("MainWindow", "\351\234\200\350\246\201\350\216\267\345\217\226\347\232\204ID\345\217\267", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_Info->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_Info->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "PV1\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_Info->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "PV1\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_Info->horizontalHeaderItem(3);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "PV1\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_Info->horizontalHeaderItem(4);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "PV2\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_Info->horizontalHeaderItem(5);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "PV2\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_Info->horizontalHeaderItem(6);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "PV2\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        btn_getInfo->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\215\225\345\217\260\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        btn_getDate_2->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\345\215\225\345\217\260RSD\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "WIFI\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        groupBox_18->setTitle(QApplication::translate("MainWindow", "\351\200\232\344\277\241\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_IP_IDWrite->setText(QApplication::translate("MainWindow", "192.168.131.228", 0, QApplication::UnicodeUTF8));
        lineEdit_Port_IDWrite->setText(QApplication::translate("MainWindow", "4540", 0, QApplication::UnicodeUTF8));
        btn_config_IDWrite->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        groupBox_21->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\263\273\347\273\237\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        btn_mkfs->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\263\273\347\273\237\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_mkfs->setText(QString());
        groupBox_19->setTitle(QApplication::translate("MainWindow", "ID\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        btn_setID->setText(QApplication::translate("MainWindow", "ID\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        btn_getID->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226ID", 0, QApplication::UnicodeUTF8));
        lineEdit_ID_2->setText(QApplication::translate("MainWindow", "216000000000", 0, QApplication::UnicodeUTF8));
        label_ID_2->setText(QString());
        label_26->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_22->setTitle(QApplication::translate("MainWindow", "MAC\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        lineEdit_MAC->setText(QApplication::translate("MainWindow", "80971B000000", 0, QApplication::UnicodeUTF8));
        label_MAC->setText(QString());
        btn_setMAC->setText(QApplication::translate("MainWindow", "MAC\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        btn_getMAC->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226MAC", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_23->setTitle(QApplication::translate("MainWindow", "Area\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        btn_setArea->setText(QApplication::translate("MainWindow", "Area\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        btn_getArea->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226Area", 0, QApplication::UnicodeUTF8));
        label_Area->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_Area->clear();
        comboBox_Area->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "NA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SAA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "MX", 0, QApplication::UnicodeUTF8)
        );
        label_36->setText(QApplication::translate("MainWindow", "\345\214\272\345\237\237\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_24->setTitle(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        btn_getTime_2->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        btn_setTime_2->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "\346\227\266\345\214\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_Time->setText(QString());
        label_38->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_25->setTitle(QApplication::translate("MainWindow", "LED\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_LED->setText(QApplication::translate("MainWindow", "LED\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        groupBox_26->setTitle(QApplication::translate("MainWindow", "\347\211\210\346\234\254\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        btn_Version->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_version->setText(QString());
        btn_InternalVersion->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\347\211\210\346\234\254\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_InternalVersion->setText(QString());
        groupBox_28->setTitle(QApplication::translate("MainWindow", "ID\346\267\273\345\212\240\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_addInverter->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\200\206\345\217\230\345\231\250ID", 0, QApplication::UnicodeUTF8));
        lineEdit_INVERTER->setText(QApplication::translate("MainWindow", "501003220001", 0, QApplication::UnicodeUTF8));
        btn_query_result->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        btn_query_protection->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\344\277\235\346\212\244\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_inverter->setText(QString());
        label_41->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_29->setTitle(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\265\213\350\257\225\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        btn_Clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\265\213\350\257\225\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_Clear->setText(QString());
        groupBox_40->setTitle(QApplication::translate("MainWindow", "Flash\347\251\272\351\227\264", 0, QApplication::UnicodeUTF8));
        btn_Flash->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213Flash\347\251\272\351\227\264", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_Flash->setText(QString());
        groupBox_41->setTitle(QApplication::translate("MainWindow", "\351\207\215\345\220\257", 0, QApplication::UnicodeUTF8));
        btn_reboot->setText(QApplication::translate("MainWindow", "\351\207\215\345\220\257", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_reboot->setText(QString());
        groupBox_42->setTitle(QApplication::translate("MainWindow", "\346\234\254\345\234\260\345\215\207\347\272\247", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("MainWindow", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_UpdateIP->setText(QApplication::translate("MainWindow", "192.168.131.1", 0, QApplication::UnicodeUTF8));
        label_66->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_UpdatePort->setText(QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8));
        label_67->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_UpdateUser->setText(QApplication::translate("MainWindow", "dsf", 0, QApplication::UnicodeUTF8));
        lineEdit_UpdatePasswd->setText(QApplication::translate("MainWindow", "dsf031411", 0, QApplication::UnicodeUTF8));
        label_68->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        btn_update_ver->setText(QApplication::translate("MainWindow", "\346\214\211\347\205\247\347\211\210\346\234\254\345\217\267\345\215\207\347\272\247", 0, QApplication::UnicodeUTF8));
        btn_update_ID->setText(QApplication::translate("MainWindow", "\346\214\211\347\205\247ID\345\215\207\347\272\247", 0, QApplication::UnicodeUTF8));
        label_update->setText(QString());
        label_69->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "\345\237\272\347\241\200\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "IDWrite\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        groupBox_30->setTitle(QApplication::translate("MainWindow", "\351\200\232\344\277\241\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("MainWindow", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_IP_JSON->setText(QApplication::translate("MainWindow", "192.168.131.228", 0, QApplication::UnicodeUTF8));
        lineEdit_Port_JSON->setText(QApplication::translate("MainWindow", "4570", 0, QApplication::UnicodeUTF8));
        btn_config_JSON->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        groupBox_31->setTitle(QApplication::translate("MainWindow", "\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        btn_cmd101->setText(QApplication::translate("MainWindow", "CMD\357\274\232101", 0, QApplication::UnicodeUTF8));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QApplication::translate("MainWindow", "\345\237\272\347\241\200\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "JSON\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
