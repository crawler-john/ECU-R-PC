#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "communication.h"

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
    void on_btn_config_clicked();

    void on_btn_baseInfo_clicked();


    void on_btn_getTime_clicked();

    void on_btn_setTime_clicked();

    void on_btn_setNetwork_clicked();

private:
    Ui::MainWindow *ui;
    Communication *ECU_Client;
    char ECUID[13];
    //QList<OPT700_RS *> OPT700_RSList;
};

#endif // MAINWINDOW_H
