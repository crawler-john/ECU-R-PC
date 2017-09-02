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

    //IPΩÁ√Ê…Ë÷√
    void IPInterfaceSataus(bool status);

    void on_btn_config_clicked();

    void on_btn_baseInfo_clicked();

    void on_btn_getTime_clicked();

    void on_btn_setTime_clicked();

    void on_btn_setNetwork_clicked();

    void on_btn_setPasswd_clicked();

    void on_btn_checkWifiStatus_clicked();

    void on_btn_configWIFI_clicked();

    void on_btn_addID_clicked();

    void on_btn_SetID_clicked();

    void on_btn_ECUImport_clicked();

    void on_comboBox_activated(int index);

    void on_btn_getRealData_clicked();

    void on_btn_getDate_clicked();

    void on_btn_getPower_clicked();

    void on_btn_getEnergy_clicked();

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

private:
    Ui::MainWindow *ui;
    Communication *ECU_Client;
    CommUDP *UDPClient1;
    CommUDP *UDPClient2;
    char ECUID[13];
    QList<YC600_RealData_t *> YC600_RealData_List;
    QList<YC600_PowerData_t *> YC600_PowerData_List;
    QList<YC600_EnergyData_t *> YC600_EnergyData_List;
    QList<SSID_t *> SSID_List;
};

#endif // MAINWINDOW_H
