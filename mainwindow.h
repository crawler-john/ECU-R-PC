#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "communication.h"
#include <QTableWidget>

typedef struct
{
    char ID[13];
    unsigned short Grid_Frequency;
    unsigned short Temperature;
    unsigned short Inverter_Power;
    unsigned short Grid_Voltage;
    unsigned short Inverter_Power_B;
    unsigned short Grid_Voltage_B;

} YC600_RealData_t;

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


    void addTableData(QTableWidget *table, QList<YC600_RealData_t *> &List);
    void on_btn_getRealData_clicked();

private:
    Ui::MainWindow *ui;
    Communication *ECU_Client;
    char ECUID[13];
    QList<YC600_RealData_t *> YC600_RealData_List;
};

#endif // MAINWINDOW_H
