#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug.h"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_6->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->lineEdit_IPAddress->hide();
    ui->lineEdit_Mask->hide();
    ui->lineEdit_gate->hide();
    ui->lineEdit_DNS1->hide();
    ui->lineEdit_DNS2->hide();
    ECU_Client = new Communication("10.10.100.254",8899);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ECU_Client;
    ECU_Client = NULL;
}

void MainWindow::on_btn_config_clicked()
{
    if(ECU_Client != NULL)
    {
        delete ECU_Client;
        ECU_Client = NULL;
    }

    ECU_Client = new Communication(ui->lineEdit_IP->text(),ui->lineEdit_Port->text().toUShort());
    statusBar()->showMessage(tr("Configure IP And Port Successful ..."), 1000);
}


void MainWindow::on_btn_baseInfo_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char ECU_Model[3] = {'\0'};
    double Lifttime_Energy;
    unsigned int Last_System_Power;
    double Generation_Current_Day;
    char Last_To_EMA[15] = {'\0'};
    unsigned short Number_Inverters;
    unsigned short Last_Number_Inverters;
    int version_length = 0;
    char Version[100];
    int Time_length = 0;
    char Time_Zone[100];
    char MAC[18] = {'\0'};
    char WIFI_MAC[18] = {'\0'};

    char Sendbuff[20] = "APS1100160001END";
    char Recvbuff[4096] = {'\0'};
    memset(Recvbuff,0x00,4096);
    flag = ECU_Client->ECU_Communication(Sendbuff,16,Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        //保存ECUID
        memcpy(ECUID,&Recvbuff[13],12);
        ECUID[12]  = '\0';
        ui->lineEdit_ECUID->setText(ECUID);
        memcpy(ECU_Model,&Recvbuff[25],2);
        ECU_Model[2] = '\0';
        ui->label_ECUModel->setText(ECU_Model);
        //系统发电量
        Lifttime_Energy = ((double)(Recvbuff[27]*(256*256*256) + Recvbuff[28]*(256*256) + Recvbuff[29]*256 + Recvbuff[30]))/10;
        qDebug("%d\n",(Recvbuff[27]*(256*256*256) + Recvbuff[28]*(256*256) + Recvbuff[29]*256 + Recvbuff[30]));
        ui->label_LifttimeEnergy->setText(QString::number(Lifttime_Energy));

        //当前系统功率
        Last_System_Power = (Recvbuff[31]*(256*256*256) + Recvbuff[32]*(256*256) + Recvbuff[33]*256 + Recvbuff[34]);
        ui->label_LastSystemPower->setText(QString::number(Last_System_Power));
        //当天发电量
        Generation_Current_Day = ((double)(Recvbuff[35]*(256*256*256) + Recvbuff[36]*(256*256) + Recvbuff[37]*256 + Recvbuff[38]))/100;
        ui->label_GenerationCurrentDay->setText(QString::number(Generation_Current_Day));

        //最后一次连接EMA时间
        sprintf(Last_To_EMA,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[39]&0x000000ff,Recvbuff[40]&0x000000ff,Recvbuff[41]&0x000000ff,Recvbuff[42]&0x000000ff,Recvbuff[43]&0x000000ff,Recvbuff[44]&0x000000ff,Recvbuff[45]&0x000000ff);
        ui->label_LastToEMA->setText(QString(Last_To_EMA));

        //逆变器总台数
        Number_Inverters = (Recvbuff[46]*256 + Recvbuff[47]);
        ui->label_NumberInverters->setText(QString::number(Number_Inverters));

        //当前逆变器连接台数
        Last_Number_Inverters = (Recvbuff[48]*256 + Recvbuff[49]);
        ui->label_LastNumberInverters->setText(QString::number(Last_Number_Inverters));

        //软件版本
        version_length = (Recvbuff[50]-'0')*100 + (Recvbuff[51]-'0')*10 + (Recvbuff[52]-'0');
        memcpy(Version,&Recvbuff[53],version_length);
        Version[version_length] = '\0';
        ui->label_Version->setText(Version);

        //时区
        Time_length = (Recvbuff[53+version_length]-'0')*100 + (Recvbuff[54+version_length]-'0')*10 + (Recvbuff[55+version_length]-'0');
        memcpy(Time_Zone,&Recvbuff[56+version_length],Time_length);
        Time_Zone[Time_length] = '\0';
        ui->label_TimeZone->setText(Time_Zone);
        //MAC地址
        sprintf(MAC,"%02x-%02x-%02x-%02x-%02x-%02x",Recvbuff[56+version_length+Time_length]&0x000000ff,Recvbuff[57+version_length+Time_length]&0x000000ff,Recvbuff[58+version_length+Time_length]&0x000000ff,Recvbuff[59+version_length+Time_length]&0x000000ff,Recvbuff[60+version_length+Time_length]&0x000000ff,Recvbuff[61+version_length+Time_length]&0x000000ff);
        ui->label_MacAddress->setText(MAC);
        //WIFI MAC地址
        sprintf(WIFI_MAC,"%02x-%02x-%02x-%02x-%02x-%02x",Recvbuff[62+version_length+Time_length]&0x000000ff,Recvbuff[63+version_length+Time_length]&0x000000ff,Recvbuff[64+version_length+Time_length]&0x000000ff,Recvbuff[65+version_length+Time_length]&0x000000ff,Recvbuff[66+version_length+Time_length]&0x000000ff,Recvbuff[67+version_length+Time_length]&0x000000ff);
        ui->label_WifiMac->setText(WIFI_MAC);
        statusBar()->showMessage(tr("Add Device Success ..."), 2000);
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_getTime_clicked()
{
    //获取当前的时间
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void MainWindow::on_btn_setTime_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[100];
    char Recvbuff[4096] = {'\0'};
    char DateTime[15] = {'\0'};
    memset(Recvbuff,0x00,4096);
    int year = ui->dateTimeEdit->dateTime().date().year();
    int month = ui->dateTimeEdit->dateTime().date().month();
    int day = ui->dateTimeEdit->dateTime().date().day();
    int hour = ui->dateTimeEdit->dateTime().time().hour();
    int minute = ui->dateTimeEdit->dateTime().time().minute();
    int second = ui->dateTimeEdit->dateTime().time().second();
    //设置ECU-R的时间
    sprintf(DateTime,"%04d%02d%02d%02d%02d%02d",year,month,day,hour,minute,second);
    DateTime[14] = '\0';
    sprintf(Sendbuff,"APS1100450006%sEND%sEND",ECUID,DateTime);
    qDebug("%s",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,45,Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            statusBar()->showMessage(tr("Set Time Success ..."), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Time Failed ..."), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }

}

void MainWindow::on_btn_setNetwork_clicked()
{
    /*
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[100];
    char Recvbuff[4096] = {'\0'};

    memset(Recvbuff,0x00,4096);

    //设置ECU-R的有线网
    sprintf(DateTime,"%04d%02d%02d%02d%02d%02d",year,month,day,hour,minute,second);
    DateTime[14] = '\0';
    sprintf(Sendbuff,"APS1100450006%sEND%sEND",ECUID,DateTime);
    qDebug("%s",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,45,Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            statusBar()->showMessage(tr("Set Time Success ..."), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Time Failed ..."), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
    */
}

void MainWindow::on_btn_addID_clicked()
{
    QString addID = ui->lineEdit_ID->text();

    if(12 == addID.length())
    {
        ui->plainTextEdit_ID->appendPlainText(addID);
        statusBar()->showMessage(tr("Add ID Success ..."), 1000);
    }else
    {
        statusBar()->showMessage(tr("ID Length Mismatching ..."), 1000);
    }
}

void MainWindow::on_btn_setPasswd_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[300];
    char Recvbuff[200] = {'\0'};
    int OldLen = 0;
    int NewLen = 0;
    char OldPasswd[100];
    char NewPasswd[100];
    char length[5] = {'\0'};

    OldLen = ui->lineEdit_oldPasswd->text().length();
    NewLen = ui->lineEdit_newPasswd->text().length();
    if(OldLen < 8 || NewLen < 8)
    {
        statusBar()->showMessage(tr("size too short ..."), 2000);
        qDebug("字节长度太短\n");
        return;
    }
    memcpy(OldPasswd, ui->lineEdit_oldPasswd->text().toLatin1().data(),OldLen);
    memcpy(NewPasswd, ui->lineEdit_newPasswd->text().toLatin1().data(),NewLen);
    OldPasswd[OldLen] = '\0';
    NewPasswd[NewLen] = '\0';

    sprintf(Sendbuff,"APS1100000005%sEND%02d%s%02d%sEND",ECUID,OldLen,OldPasswd,NewLen,NewPasswd);
    sprintf(length,"%04d",QString(Sendbuff).length());
    memcpy(&Sendbuff[5],length,4);
    memset(Recvbuff,0x00,200);
    qDebug("%s\n",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,QString(Sendbuff).length(),Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(Recvbuff[12] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Password Success ..."), 2000);
            qDebug("设置WIFI密码成功！");
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_checkWifiStatus_clicked()
{

}

void MainWindow::on_btn_configWIFI_clicked()
{

}

void MainWindow::on_btn_SetID_clicked()
{

}

void MainWindow::on_btn_ECUImport_clicked()
{

}

void MainWindow::on_comboBox_activated(int index)
{
    if(index == 0)
    {
        ui->label_6->hide();
        ui->label_9->hide();
        ui->label_10->hide();
        ui->label_11->hide();
        ui->label_12->hide();
        ui->lineEdit_IPAddress->hide();
        ui->lineEdit_Mask->hide();
        ui->lineEdit_gate->hide();
        ui->lineEdit_DNS1->hide();
        ui->lineEdit_DNS2->hide();
    }else if(index == 1)
    {
        ui->label_6->show();
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
        ui->lineEdit_IPAddress->show();
        ui->lineEdit_Mask->show();
        ui->lineEdit_gate->show();
        ui->lineEdit_DNS1->show();
        ui->lineEdit_DNS2->show();
    }
}
