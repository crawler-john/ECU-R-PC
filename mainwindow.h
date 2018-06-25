#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "communication.h"
#include <QTableWidget>
#include "commudp.h"


#define MAX_PV_NUM 	6
#define MAX_AC_NUM	3

typedef struct
{
    char ID[13];
    unsigned char flag;
    unsigned char inverter_type;
    unsigned short Grid_Frequency;
    unsigned short Temperature;
    unsigned short Inverter_Power;
    unsigned short Grid_Voltage;
    unsigned short Inverter_Power_B;
    unsigned short Grid_Voltage_B;
    unsigned short Inverter_Power_C;
    unsigned short Grid_Voltage_C;
    unsigned short Inverter_Power_D;
} YC600_RealData_t;

typedef struct
{
    char ID[32];
    unsigned char commStatus;
    char factor[10];
    char type[10];
    float PV_Voltage[MAX_PV_NUM];                       //直流电压		最多4路
    float PV_Current[MAX_PV_NUM];                       //直流电流		最多4路
    float PV_Power[MAX_PV_NUM];                         //直流电流		最多4路
    float AC_Voltage[MAX_AC_NUM];                       //交流电压		3相电压
    float AC_Current[MAX_AC_NUM];                       //交流电流		3相电压
    float Grid_Frequency[MAX_AC_NUM];                      //电网频率
    float Temperature;                           //机内温度
    int Reactive_Power;                        //无功功率
    int Active_Power;                          //有功功率
    float Power_Factor;                        //功率因数
    float Daily_Energy;                        //日发电量
    float Life_Energy;                         //历史发电量
    float Current_Energy;                      //本轮发电量	//日发电量计算
} ThirdData_t;



typedef struct
{
    char ID[13];
    unsigned short shortAddr;
} ShortAddr_t;

typedef struct
{
    char ID[13];
    unsigned char function;
} RSDStatus_t;

typedef struct
{
    char ID[13];
    char turnonoff[2];
} TurnOnOff_t;

typedef struct
{
    char ID[13];
    char GFDI[2];
} GFDI_t;

typedef struct
{
    char ID[13];
    int limitedpower;
    int limitedresult;
} MaxPower_t;

typedef struct
{
    char ID[13];
    int IRD;
    int IRDresult;
} IRD_t;

typedef struct
{
    char ID[13];
    char Time[10];
    char Event[65];
} AlarmEvent_t;

typedef struct
{
    char ID[32];
    int modbusAddr;
    char Factor[20];
    char Type[20];
    unsigned char BaudRate;
} ThirdID_t;

typedef struct
{
    char ID[13];
    unsigned char RSSI;
} RSSI_t;

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
    unsigned char model;
    unsigned char temperature;

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


typedef struct
{
    int ecn;
    char SSID[100];
    int RSSI;
    char MAC[20];
    int CHANNEL;
    int offset;
    int calibration;
} ESP07S_SSID_INFO;


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

    void on_btn_gethardware_clicked();


    void on_btn_config_IDWrite_clicked();

    void on_btn_mkfs_clicked();


    void on_btn_setID_clicked();

    void on_btn_getID_clicked();

    void on_btn_setMAC_clicked();

    void on_btn_getMAC_clicked();

    void on_btn_setArea_clicked();

    void on_btn_getArea_clicked();

    void on_btn_getTime_2_clicked();

    void on_btn_setTime_2_clicked();

    void on_btn_LED_clicked();

    void on_btn_Version_clicked();

    void on_btn_Clear_clicked();

    void on_btn_addInverter_clicked();

    void on_btn_query_result_clicked();

    void on_btn_query_protection_clicked();

    void on_btn_config_JSON_clicked();

    void on_btn_cmd101_clicked();

    void on_btn_connect_ESP07_clicked();

    void on_pushButton_ESP07_clicked();
    void addESP07SData(QTableWidget *table, QList<ESP07S_SSID_INFO *> &List);
    void on_btn_getWIFI_2_clicked();

    void on_btn_functionstatus_clicked();


    void on_btn_SetServer_clicked();

    void on_btn_setFunction_open_clicked();

    void on_btn_setFunction_close_clicked();

    void on_btn_getRSDStatus_clicked();
    void addTurnOnOffData(QTableWidget *table, QList<TurnOnOff_t *> &List);
    void addRSDStatusData(QTableWidget *table, QList<RSDStatus_t *> &List);
    void addRSSIData(QTableWidget *table, QList<RSSI_t *> &List);
    void on_btn_RSSI_clicked();

    void on_btn_ClearEnergy_clicked();

    void on_btn_InternalVersion_clicked();

    void on_btn_Flash_clicked();

    void on_btn_reboot_clicked();


    void on_btn_update_ver_clicked();

    void on_btn_update_ID_clicked();

    void on_btn_getSetTurnOnOff_clicked();

    void on_btn_SetTurnOnOff_clicked();

    void on_btn_SetTurnOnOff_Open_clicked();

    void on_btn_SetTurnOnOff_Close_clicked();

    void addGFDIData(QTableWidget *table, QList<GFDI_t *> &List);
    void on_btn_getClearGFDI_clicked();

    void on_btn_ClearGFDI_clicked();

    void on_btn_MaxPower_clicked();

    void on_btn_SetMaxPower_clicked();

    void on_btn_MaxPower_get_clicked();

    void addMaxPowerData(QTableWidget *table, QList<MaxPower_t *> &List);
    void on_btn_getMaxPower_clicked();

    void on_btn_IRD_get_clicked();

    void on_btn_IRD_clicked();

    void on_btn_SetIRD_clicked();

    void addIRDData(QTableWidget *table, QList<IRD_t *> &List);
    void on_btn_geIRD_clicked();

    void addAlarmEventData(QTableWidget *table, QList<AlarmEvent_t *> &List);
    void on_btn_alarmevent_clicked();

    void on_tableWidget_alarmEvent_itemClicked(QTableWidgetItem *item);

    void on_comboBox_factor_currentIndexChanged(int index);

    void on_btn_addThird_clicked();

    void on_btn_clearthirdID_clicked();
    void addThirdID(QTableWidget *table, QList<ThirdID_t *> &List);
    void on_btn_getthirdID_clicked();

    void on_btn_registerThirdID_clicked();
    void addThirdData(QTableWidget *table, QList<ThirdData_t *> &List);
    void on_btn_getThirdData_clicked();


    void on_btn_clearText_clicked();

    void on_btn_ZigBeeSend_clicked();

    void on_btn_trinasolarServer_clicked();
    unsigned short computeCRC(unsigned char* pByte, size_t nbBytes);
private slots:
//    void server_New_Connect();
    void newConnection();
       void ReceiveData();
//       void on_pushButton_2_clicked();


//       void on_pushButton_clicked();
       void on_btn_trinasolarServer_close_clicked();

       void on_btn_setServer_clicked();

       void on_btn_trinaReboot_clicked();

       void on_btn_trinagetinfo_clicked();

       void on_btn_trinaUpdate_clicked();

       void on_btn_trinaRSD_clicked();

       void on_btn_trinagetrelation_clicked();

       void on_comboBox_ServerItem_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Communication *ECU_Client;
    Communication *IDWrite_Client;
    Communication *JSON_Client;
    CommUDP *UDPClient1;
    CommUDP *UDPClient2;
    char ECUID[13];
    QList<YC600_RealData_t *> YC600_RealData_List;
    QList<ThirdData_t *> ThirdData_List;

    QList<ShortAddr_t *> ShortAddr_List;
    QList<RSDStatus_t *> RSDStatus_List;
    QList<TurnOnOff_t *> TurnOnOff_List;
    QList<GFDI_t *> GFDI_List;
    QList<MaxPower_t *> MaxPower_List;
    QList<IRD_t *> IRD_List;
    QList<AlarmEvent_t *> AlarmEvent_List;
    QList<ThirdID_t *> ThirdID_List;

    QList<RSSI_t *> RSSI_List;

    QList<OPT700_RS *> OPT700_RSList;
    QList<YC600_PowerData_t *> YC600_PowerData_List;
    QList<YC600_EnergyData_t *> YC600_EnergyData_List;
    QList<SSID_t *> SSID_List;
    QList<OPT700_RS_INFO *> OPT700_RS_INFOList;
    QList<ESP07S_SSID_INFO *> ESP07S_SSID_INFOList;
    QTcpServer *server;
    QTcpSocket *m_socket;
    char ECU_UID[25];
};

#endif // MAINWINDOW_H
