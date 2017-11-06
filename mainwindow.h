#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "communication.h"
#include <QTableWidget>
#include "commudp.h"

typedef struct
{
    char ID[13];
    unsigned char flag;
    unsigned short Grid_Frequency;
    unsigned short Temperature;
    unsigned short Inverter_Power;
    unsigned short Grid_Voltage;
    unsigned short Inverter_Power_B;
    unsigned short Grid_Voltage_B;

} YC600_RealData_t;

typedef struct
{
    char ID[13];
    unsigned short shortAddr;
} ShortAddr_t;


typedef struct
{
    char ID[13];
    unsigned char Equipment_Status;
    unsigned char Mos_Status;
    unsigned char Function_Status;
    unsigned char PV1_Protect;
    unsigned char PV2_Protect;
    unsigned long Heart_Rate;
    unsigned short Off_Times;
    unsigned char Shutdown_Num;
    unsigned short PV1;
    unsigned short PV2;
    unsigned short PI;
    unsigned short PI2;
    unsigned short Power1;
    unsigned short Power2;
    unsigned short Output_PV;
    unsigned short PI_Output;
    unsigned short Power_Output;
    unsigned char RSSI;
    unsigned int PV1_ENERGY;    //10 -6次方度
    unsigned int PV2_ENERGY;    //10 -6次方度
    unsigned int PV_Output_ENERGY;    //10 -6次方度
    unsigned char MOS_CLOSE_NUM;
    unsigned short version;

} OPT700_RS;



typedef struct
{
    char time[6];
    int power;
} YC600_PowerData_t;

typedef struct
{
    char date[11];
    double energy;
} YC600_EnergyData_t;

typedef struct
{
    char SSID[50];
    int  signalStrength;
} SSID_t;


typedef struct
{
    char time[6];
    unsigned short PV1;
    unsigned char PI1;
    unsigned short Power1;
    unsigned short PV2;
    unsigned char PI2;
    unsigned short Power2;
} OPT700_RS_INFO;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    //IP界面设置
    void IPInterfaceSataus(bool status);

    void on_btn_config_clicked();

    void on_btn_baseInfo_clicked();

    void on_btn_getTime_clicked();

    void on_btn_setTime_clicked();

    void on_btn_setNetwork_clicked();

    void on_btn_setPasswd_clicked();

    void on_btn_addID_clicked();

    void on_btn_SetID_clicked();

    void on_btn_ECUImport_clicked();

    void on_comboBox_activated(int index);

    void on_btn_getRealData_clicked();

    void on_btn_getDate_clicked();

    void on_btn_getPower_clicked();
    void addShortAddrData(QTableWidget *table, QList<ShortAddr_t *> &List);

    void on_btn_getEnergy_clicked();
    void set_tableWidget_RealData_View(int item);
    void clr_tableWidget_RealData_Item();
    void addTableData(QTableWidget *table, QList<OPT700_RS *> &List);
    void addRealData(QTableWidget *table, QList<YC600_RealData_t *> &List);

    void addPowerData(QTableWidget *table, QList<YC600_PowerData_t *> &List);
    void addEnergyData(QTableWidget *table, QList<YC600_EnergyData_t *> &List);
    void addSSIDData(QTableWidget *table, QList<SSID_t *> &List);
    void on_btn_getTime_ECU_clicked();

    void on_btn_getWIFI_clicked();

    void on_pushButton_clicked();


    void on_tableWidget_SSID_itemClicked(QTableWidgetItem *item);

    void on_btn_connect_clicked();

    void on_pushButton_2_clicked();

    void on_btn_getNetwork_clicked();

    void on_btn_SetChannel_clicked();

    void on_btn_setFunction_clicked();
    void addINFOTableData(QTableWidget *table, QList<OPT700_RS_INFO *> &List);
    void on_btn_getDate_2_clicked();

    void on_btn_getInfo_clicked();

    void on_btn_getshortAddr_clicked();

private:
    Ui::MainWindow *ui;
    Communication *ECU_Client;
    CommUDP *UDPClient1;
    CommUDP *UDPClient2;
    char ECUID[13];
    QList<YC600_RealData_t *> YC600_RealData_List;
    QList<ShortAddr_t *> ShortAddr_List;
    QList<OPT700_RS *> OPT700_RSList;
    QList<YC600_PowerData_t *> YC600_PowerData_List;
    QList<YC600_EnergyData_t *> YC600_EnergyData_List;
    QList<SSID_t *> SSID_List;
    QList<OPT700_RS_INFO *> OPT700_RS_INFOList;
};

#endif // MAINWINDOW_H
