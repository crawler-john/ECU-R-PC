#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug.h"
#include "QDateTime"
#include <unistd.h>
#include <QString>
#include<QTcpServer>
#include<QTcpSocket>
#include<QMessageBox>
#include<QDataStream>
#include<QString>
#include<QByteArray>

#define MAJOR_VERSION   1
#define MINOR_VERSION   0

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sprintf(ECUID,"000000000000");
    ECUID[12]  = '\0';
    m_socket = NULL;
    server = NULL;
    ui->setupUi(this);
    memset(ECU_UID,'0',25);
    IPInterfaceSataus(false);
    setWindowTitle(tr("ECU-R Test V%1.%2").arg(MAJOR_VERSION).arg(MINOR_VERSION));
    setFixedSize(801,510);
    UDPClient1 = new CommUDP("10.10.100.254",49000);
    UDPClient2 = new CommUDP("10.10.100.254",48899);
    ECU_Client = new Communication("10.10.100.254",8899);
    IDWrite_Client = new Communication("192.168.131.228",4540);
    JSON_Client = new Communication("192.168.131.228",4570);
    ui->tableWidget_SSID->setColumnWidth(0,150);
    ui->tableWidget_SSID->setColumnWidth(1,60);
    //    ui->progressBar->setValue(0);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(0,40);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(1,150);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(2,40);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(3,130);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(4,40);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(5,100);
    ui->tableWidget_SSID_ESP07S->setColumnWidth(6,100);

    ui->tableWidget_MaxPower->setColumnWidth(0,100);
    ui->tableWidget_MaxPower->setColumnWidth(1,70);
    ui->tableWidget_MaxPower->setColumnWidth(2,70);
    ui->tableWidget_IRD->setColumnWidth(0,100);
    ui->tableWidget_IRD->setColumnWidth(1,70);
    ui->tableWidget_IRD->setColumnWidth(2,70);

    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_alarm->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    ui->tableWidget_alarmEvent->setColumnWidth(1,100);
    ui->tableWidget_alarmEvent->setColumnWidth(2,70);
    ui->tableWidget_alarmEvent->setColumnWidth(2,300);
    ui->spinBox_third->setRange(0,256);
    ui->spinBox_third->setValue(1);
    ui->label_trina->hide();
    ui->comboBox_trina->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ECU_Client;
    ECU_Client = NULL;
    delete IDWrite_Client;
    IDWrite_Client = NULL;
}

void MainWindow::IPInterfaceSataus(bool status)
{
    if(status == true)
    {
        ui->l_1->show();
        ui->l_2->show();
        ui->l_3->show();
        ui->l_4->show();
        ui->l_5->show();

        ui->l_6->show();
        ui->l_7->show();
        ui->l_8->show();
        ui->l_9->show();
        ui->l_10->show();

        ui->l_11->show();
        ui->l_12->show();
        ui->l_13->show();
        ui->l_14->show();
        ui->l_15->show();

        ui->l_16->show();
        ui->l_17->show();
        ui->l_18->show();
        ui->l_19->show();
        ui->l_20->show();


        ui->lineEdit_IPAddress->show();
        ui->lineEdit_Mask->show();
        ui->lineEdit_gate->show();
        ui->lineEdit_DNS1->show();
        ui->lineEdit_DNS2->show();

        ui->lineEdit_IPAddress2->show();
        ui->lineEdit_Mask2->show();
        ui->lineEdit_gate2->show();
        ui->lineEdit_DNS12->show();
        ui->lineEdit_DNS22->show();

        ui->lineEdit_IPAddress3->show();
        ui->lineEdit_Mask3->show();
        ui->lineEdit_gate3->show();
        ui->lineEdit_DNS13->show();
        ui->lineEdit_DNS23->show();

        ui->lineEdit_IPAddress4->show();
        ui->lineEdit_Mask4->show();
        ui->lineEdit_gate4->show();
        ui->lineEdit_DNS14->show();
        ui->lineEdit_DNS24->show();
    }else
    {
        ui->l_1->hide();
        ui->l_2->hide();
        ui->l_3->hide();
        ui->l_4->hide();
        ui->l_5->hide();

        ui->l_6->hide();
        ui->l_7->hide();
        ui->l_8->hide();
        ui->l_9->hide();
        ui->l_10->hide();

        ui->l_11->hide();
        ui->l_12->hide();
        ui->l_13->hide();
        ui->l_14->hide();
        ui->l_15->hide();

        ui->l_16->hide();
        ui->l_17->hide();
        ui->l_18->hide();
        ui->l_19->hide();
        ui->l_20->hide();


        ui->lineEdit_IPAddress->hide();
        ui->lineEdit_Mask->hide();
        ui->lineEdit_gate->hide();
        ui->lineEdit_DNS1->hide();
        ui->lineEdit_DNS2->hide();

        ui->lineEdit_IPAddress2->hide();
        ui->lineEdit_Mask2->hide();
        ui->lineEdit_gate2->hide();
        ui->lineEdit_DNS12->hide();
        ui->lineEdit_DNS22->hide();

        ui->lineEdit_IPAddress3->hide();
        ui->lineEdit_Mask3->hide();
        ui->lineEdit_gate3->hide();
        ui->lineEdit_DNS13->hide();
        ui->lineEdit_DNS23->hide();

        ui->lineEdit_IPAddress4->hide();
        ui->lineEdit_Mask4->hide();
        ui->lineEdit_gate4->hide();
        ui->lineEdit_DNS14->hide();
        ui->lineEdit_DNS24->hide();
    }
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
    int commtime = 0;
    char Sendbuff[20] = "APS1100160001END";
    char Recvbuff[4096] = {'\0'};
    char channel[3];
    char level[4];
    char rsdType[2];
    memset(Recvbuff,0x00,4096);
    flag = ECU_Client->ECU_Communication(Sendbuff,16,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[25],"02",2))   //ECU-R-RS
        {
            //保存ECUID
            memcpy(ECUID,&Recvbuff[13],12);
            ECUID[12]  = '\0';
            ui->lineEdit_ECUID->setText(ECUID);
            memcpy(ECU_Model,&Recvbuff[25],2);
            ECU_Model[2] = '\0';
            ui->label_ECUModel->setText(ECU_Model);
            //系统发电量
            Lifttime_Energy = ((double)((Recvbuff[27]&0x000000ff)*(256*256*256) + (Recvbuff[28]&0x000000ff)*(256*256) + (Recvbuff[29]&0x000000ff)*256 + (Recvbuff[30]&0x000000ff)))/10;
            ui->label_LifttimeEnergy->setText(QString::number(Lifttime_Energy));

            //当前系统功率
            Last_System_Power = ((Recvbuff[31]&0x000000ff)*(256*256*256) + (Recvbuff[32]&0x000000ff)*(256*256) + (Recvbuff[33]&0x000000ff)*256 + (Recvbuff[34]&0x000000ff));
            ui->label_LastSystemPower->setText(QString::number(Last_System_Power));
            //当天发电量
            Generation_Current_Day = ((double)((Recvbuff[35]&0x000000ff)*(256*256*256) + (Recvbuff[36]&0x000000ff)*(256*256) + (Recvbuff[37]&0x000000ff)*256 + (Recvbuff[38]&0x000000ff)))/100;
            //qDebug("%x %x %x %x\n",Recvbuff[35],Recvbuff[36],Recvbuff[37],Recvbuff[38]);
            ui->label_GenerationCurrentDay->setText(QString::number(Generation_Current_Day));

            //逆变器总台数
            Number_Inverters = ((Recvbuff[39]&0x000000ff)*256 + (Recvbuff[40]&0x000000ff));
            ui->label_NumberInverters->setText(QString::number(Number_Inverters));

            //当前逆变器连接台数
            Last_Number_Inverters = ((Recvbuff[41]&0x000000ff)*256 + (Recvbuff[42]&0x000000ff));
            ui->label_LastNumberInverters->setText(QString::number(Last_Number_Inverters));

            memcpy(level,&Recvbuff[43],3);
            level[3] = '\0';
            ui->label_level->setText(level);
            memcpy(channel,&Recvbuff[46],2);
            channel[2] = '\0';
            ui->label_channel->setText(channel);

            rsdType[0] = Recvbuff[48];
            rsdType[1] = '\0';
            ui->label_rsdType->setText(rsdType);


            //软件版本
            version_length = ((Recvbuff[49]&0x000000ff)-'0')*100 + ((Recvbuff[50]&0x000000ff)-'0')*10 + ((Recvbuff[51]&0x000000ff)-'0');
            memcpy(Version,&Recvbuff[52],version_length);
            Version[version_length] = '\0';
            ui->label_Version->setText(Version);

            ui->label_LastToEMA->clear();
            ui->label_TimeZone->clear();

            ui->label_MacAddress->clear();
            ui->label_WifiMac->clear();
        }
        if(!memcmp(&Recvbuff[25],"01",2))       //ECU-R
        {
            //保存ECUID
            memcpy(ECUID,&Recvbuff[13],12);
            ECUID[12]  = '\0';
            ui->lineEdit_ECUID->setText(ECUID);
            memcpy(ECU_Model,&Recvbuff[25],2);
            ECU_Model[2] = '\0';
            ui->label_ECUModel->setText(ECU_Model);
            //系统发电量
            Lifttime_Energy = ((double)((Recvbuff[27]&0x000000ff)*(256*256*256) + (Recvbuff[28]&0x000000ff)*(256*256) + (Recvbuff[29]&0x000000ff)*256 + (Recvbuff[30]&0x000000ff)))/10;
            ui->label_LifttimeEnergy->setText(QString::number(Lifttime_Energy));

            //当前系统功率
            Last_System_Power = ((Recvbuff[31]&0x000000ff)*(256*256*256) + (Recvbuff[32]&0x000000ff)*(256*256) + (Recvbuff[33]&0x000000ff)*256 + (Recvbuff[34]&0x000000ff));
            ui->label_LastSystemPower->setText(QString::number(Last_System_Power));
            //当天发电量
            Generation_Current_Day = ((double)((Recvbuff[35]&0x000000ff)*(256*256*256) + (Recvbuff[36]&0x000000ff)*(256*256) + (Recvbuff[37]&0x000000ff)*256 + (Recvbuff[38]&0x000000ff)))/100;
            //qDebug("%x %x %x %x\n",Recvbuff[35],Recvbuff[36],Recvbuff[37],Recvbuff[38]);
            ui->label_GenerationCurrentDay->setText(QString::number(Generation_Current_Day));

            //最后一次连接EMA时间
            sprintf(Last_To_EMA,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[39]&0x000000ff,Recvbuff[40]&0x000000ff,Recvbuff[41]&0x000000ff,Recvbuff[42]&0x000000ff,Recvbuff[43]&0x000000ff,Recvbuff[44]&0x000000ff,Recvbuff[45]&0x000000ff);
            ui->label_LastToEMA->setText(QString(Last_To_EMA));

            //逆变器总台数
            Number_Inverters = ((Recvbuff[46]&0x000000ff)*256 + (Recvbuff[47]&0x000000ff));
            ui->label_NumberInverters->setText(QString::number(Number_Inverters));

            //当前逆变器连接台数
            Last_Number_Inverters = ((Recvbuff[48]&0x000000ff)*256 + (Recvbuff[49]&0x000000ff));
            ui->label_LastNumberInverters->setText(QString::number(Last_Number_Inverters));

            memcpy(channel,&Recvbuff[50],2);
            channel[2] = '\0';
            ui->label_channel->setText(channel);
            //软件版本
            version_length = ((Recvbuff[52]&0x000000ff)-'0')*100 + ((Recvbuff[53]&0x000000ff)-'0')*10 + ((Recvbuff[54]&0x000000ff)-'0');
            memcpy(Version,&Recvbuff[55],version_length);
            Version[version_length] = '\0';
            ui->label_Version->setText(Version);

            //时区
            Time_length = (Recvbuff[55+version_length]-'0')*100 + (Recvbuff[56+version_length]-'0')*10 + (Recvbuff[57+version_length]-'0');
            memcpy(Time_Zone,&Recvbuff[58+version_length],Time_length);
            Time_Zone[Time_length] = '\0';
            ui->label_TimeZone->setText(Time_Zone);
            //MAC地址
            sprintf(MAC,"%02x-%02x-%02x-%02x-%02x-%02x",Recvbuff[58+version_length+Time_length]&0x000000ff,Recvbuff[59+version_length+Time_length]&0x000000ff,Recvbuff[60+version_length+Time_length]&0x000000ff,Recvbuff[61+version_length+Time_length]&0x000000ff,Recvbuff[62+version_length+Time_length]&0x000000ff,Recvbuff[63+version_length+Time_length]&0x000000ff);
            ui->label_MacAddress->setText(MAC);
            //WIFI MAC地址
            sprintf(WIFI_MAC,"%02x-%02x-%02x-%02x-%02x-%02x",Recvbuff[64+version_length+Time_length]&0x000000ff,Recvbuff[65+version_length+Time_length]&0x000000ff,Recvbuff[66+version_length+Time_length]&0x000000ff,Recvbuff[67+version_length+Time_length]&0x000000ff,Recvbuff[68+version_length+Time_length]&0x000000ff,Recvbuff[69+version_length+Time_length]&0x000000ff);
            ui->label_WifiMac->setText(WIFI_MAC);
            ui->label_level->clear();
            ui->label_rsdType->clear();
        }

        statusBar()->showMessage(tr("Add Device Success ... time:%1").arg(commtime), 2000);
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ... time:%1").arg(commtime), 2000);
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
    int commtime = 0;
    //设置ECU-R的时间
    sprintf(DateTime,"%04d%02d%02d%02d%02d%02d",year,month,day,hour,minute,second);
    DateTime[14] = '\0';
    sprintf(Sendbuff,"APS1100450006%sEND%sEND",ECUID,DateTime);
    flag = ECU_Client->ECU_Communication(Sendbuff,45,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            statusBar()->showMessage(tr("Set Time Success ... time:%1").arg(commtime), 1000);
        }else if(!memcmp(&Recvbuff[13],"01",2))
        {
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Time Failed ... time:%1").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }

}

void MainWindow::on_btn_setNetwork_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[4096] = {'\0'};
    int select_item = 0;
    memset(Recvbuff,0x00,4096);

    select_item = ui->comboBox->currentIndex();
    //先判断是静态  还是动态
    if(select_item == 0)
    {   //动态获取IP
        sprintf((char *)Sendbuff,"APS1100530007%sEND0000000000000000000000END",ECUID);
    }else if(select_item == 1)
    {   //静态获取IP
        sprintf((char *)Sendbuff,"APS1100530007%sEND0100000000000000000000END",ECUID);
        Sendbuff[30] = (unsigned char )ui->lineEdit_IPAddress->text().toInt(); //IP 1
        Sendbuff[31] = (unsigned char )ui->lineEdit_IPAddress2->text().toInt(); //IP 2
        Sendbuff[32] = (unsigned char )ui->lineEdit_IPAddress3->text().toInt(); //IP 3
        Sendbuff[33] = (unsigned char )ui->lineEdit_IPAddress4->text().toInt(); //IP 4

        Sendbuff[34] = (unsigned char )ui->lineEdit_Mask->text().toInt(); //MASK 1
        Sendbuff[35] = (unsigned char )ui->lineEdit_Mask2->text().toInt(); //MASK 2
        Sendbuff[36] = (unsigned char )ui->lineEdit_Mask3->text().toInt(); //MASK 3
        Sendbuff[37] = (unsigned char )ui->lineEdit_Mask4->text().toInt(); //MASK 4

        Sendbuff[38] = (unsigned char )ui->lineEdit_gate->text().toInt(); //GATE 1
        Sendbuff[39] = (unsigned char )ui->lineEdit_gate2->text().toInt(); //GATE 2
        Sendbuff[40] = (unsigned char )ui->lineEdit_gate3->text().toInt(); //GATE 3
        Sendbuff[41] = (unsigned char )ui->lineEdit_gate4->text().toInt(); //GATE 4

        Sendbuff[42] = (unsigned char )ui->lineEdit_DNS1->text().toInt(); //DNS1 1
        Sendbuff[43] = (unsigned char )ui->lineEdit_DNS12->text().toInt(); //DNS1 2
        Sendbuff[44] = (unsigned char )ui->lineEdit_DNS13->text().toInt(); //DNS1 3
        Sendbuff[45] = (unsigned char )ui->lineEdit_DNS14->text().toInt(); //DNS1 4

        Sendbuff[46] = (unsigned char )ui->lineEdit_DNS2->text().toInt(); //DNS2 1
        Sendbuff[47] = (unsigned char )ui->lineEdit_DNS22->text().toInt(); //DNS2 2
        Sendbuff[48] = (unsigned char )ui->lineEdit_DNS23->text().toInt(); //DNS2 3
        Sendbuff[49] = (unsigned char )ui->lineEdit_DNS24->text().toInt(); //DNS2 4

        //qDebug("ip:%d.%d.%d.%d\n",Sendbuff[30],Sendbuff[31],Sendbuff[32],Sendbuff[33]);
        //qDebug("mask:%d.%d.%d.%d\n",Sendbuff[34],Sendbuff[35],Sendbuff[36],Sendbuff[37]);
        //qDebug("gate:%d.%d.%d.%d\n",Sendbuff[38],Sendbuff[39],Sendbuff[40],Sendbuff[41]);
        //qDebug("dns1:%d.%d.%d.%d\n",Sendbuff[42],Sendbuff[43],Sendbuff[44],Sendbuff[45]);
        //qDebug("dns2:%d.%d.%d.%d\n",Sendbuff[46],Sendbuff[47],Sendbuff[48],Sendbuff[49]);

    }
    int commtime = 0;
    flag = ECU_Client->ECU_Communication((char *)Sendbuff,53,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            statusBar()->showMessage(tr("Set Network Success ... time:%1").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }

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
        return;
    }
    memcpy(OldPasswd, ui->lineEdit_oldPasswd->text().toLatin1().data(),OldLen);
    memcpy(NewPasswd, ui->lineEdit_newPasswd->text().toLatin1().data(),NewLen);
    OldPasswd[OldLen] = '\0';
    NewPasswd[NewLen] = '\0';

    sprintf(Sendbuff,"APS1100000010%sEND%02d%s%02d%sEND",ECUID,OldLen,OldPasswd,NewLen,NewPasswd);
    sprintf(length,"%04d",QString(Sendbuff).length());
    memcpy(&Sendbuff[5],length,4);
    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,QString(Sendbuff).length(),Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }else if(Recvbuff[14] == '2')
        {
            statusBar()->showMessage(tr("ECU Old Passwd Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Password Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_SetID_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[7];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_ID->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_ID->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,7);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');


        memcpy(&ID_BCD_List[index*6],ID_BCD,6);
    }

    sprintf(Sendbuff,"APS1100000005%sEND",ECUID);
    memcpy(&Sendbuff[28],ID_BCD_List,(OPTCount*6));
    Sendbuff[OPTCount*6+28] = 'E';
    Sendbuff[OPTCount*6+29] = 'N';
    Sendbuff[OPTCount*6+30] = 'D';

    sprintf(packlength,"%04d",(OPTCount*6+31));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*6+31),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set ID Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_ECUImport_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char ID[13] = {'\0'};
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int length = 0,index = 0;
    int optcount = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280011%sEND",ECUID);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    ui->plainTextEdit_ID->clear();
    if(flag == true)
    {

        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Import ID Success ... time:%1").arg(commtime), 2000);
            optcount = (recvLen-18)/6;
            length = 15;
            for(index = 0;index < optcount;index++)
            {
                sprintf(ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                //qDebug("%s\n",ID);
                ID[12] = '\0';
                ui->plainTextEdit_ID->appendPlainText(ID);
                length += 6;
            }
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_comboBox_activated(int index)
{
    if(index == 0)
    {
        IPInterfaceSataus(false);
    }else if(index == 1)
    {
        IPInterfaceSataus(true);
    }
}

void MainWindow::addRealData(QTableWidget *table, QList<YC600_RealData_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<YC600_RealData_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        QTableWidgetItem *item5 = new QTableWidgetItem();
        QTableWidgetItem *item6 = new QTableWidgetItem();
        QTableWidgetItem *item7 = new QTableWidgetItem();
        QTableWidgetItem *item8 = new QTableWidgetItem();
        QTableWidgetItem *item9 = new QTableWidgetItem();
        QTableWidgetItem *item10 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        if((*iter)->inverter_type == 0){
            item1->setText("UNKNOWN");
            item2->setText("-");
            item3->setText("-");
            item4->setText("-");
            item5->setText("-");
            item6->setText("-");
            item7->setText("-");
            item8->setText("-");
            item9->setText("-");
            item10->setText("-");
        }else if((*iter)->inverter_type == 1){
            item1->setText("YC600");
            if((*iter)->flag == 1)
            {
                item2->setText(QString::number((double)((*iter)->Grid_Frequency/10)));
                item3->setText(QString::number(((*iter)->Temperature - 100)));
                item4->setText(QString::number((*iter)->Inverter_Power));
                item5->setText(QString::number((*iter)->Grid_Voltage));
                item6->setText(QString::number((*iter)->Inverter_Power_B));
                item7->setText(QString::number((*iter)->Grid_Voltage_B));
                item8->setText("-");
                item9->setText("-");
                item10->setText("-");

                item->setBackgroundColor(QColor(0,238,0));
                item1->setBackgroundColor(QColor(0,238,0));
                item2->setBackgroundColor(QColor(0,238,0));
                item3->setBackgroundColor(QColor(0,238,0));
                item4->setBackgroundColor(QColor(0,238,0));
                item5->setBackgroundColor(QColor(0,238,0));
                item6->setBackgroundColor(QColor(0,238,0));
                item7->setBackgroundColor(QColor(0,238,0));
                item8->setBackgroundColor(QColor(0,238,0));
                item9->setBackgroundColor(QColor(0,238,0));
                item10->setBackgroundColor(QColor(0,238,0));

            }else if ((*iter)->flag == 0)
            {
                item2->setText("-");
                item3->setText("-");
                item4->setText("-");
                item5->setText("-");
                item6->setText("-");
                item7->setText("-");
                item8->setText("-");
                item9->setText("-");
                item10->setText("-");
            }
        }else if(((*iter)->inverter_type == 2)||((*iter)->inverter_type == 3)){
            if((*iter)->inverter_type == 2)
                item1->setText("YC1000");
            else if((*iter)->inverter_type == 3)
                item1->setText("QS1200");
            if((*iter)->flag == 1)
            {
                item2->setText(QString::number((double)((*iter)->Grid_Frequency/10)));
                item3->setText(QString::number(((*iter)->Temperature - 100)));
                item4->setText(QString::number((*iter)->Inverter_Power));
                item5->setText(QString::number((*iter)->Grid_Voltage));
                item6->setText(QString::number((*iter)->Inverter_Power_B));
                item7->setText(QString::number((*iter)->Grid_Voltage_B));
                item8->setText(QString::number((*iter)->Inverter_Power_C));
                item9->setText(QString::number((*iter)->Grid_Voltage_C));
                item10->setText(QString::number((*iter)->Inverter_Power_D));

                item->setBackgroundColor(QColor(0,238,0));
                item1->setBackgroundColor(QColor(0,238,0));
                item2->setBackgroundColor(QColor(0,238,0));
                item3->setBackgroundColor(QColor(0,238,0));
                item4->setBackgroundColor(QColor(0,238,0));
                item5->setBackgroundColor(QColor(0,238,0));
                item6->setBackgroundColor(QColor(0,238,0));
                item7->setBackgroundColor(QColor(0,238,0));
                item8->setBackgroundColor(QColor(0,238,0));
                item9->setBackgroundColor(QColor(0,238,0));
                item10->setBackgroundColor(QColor(0,238,0));

            }else if ((*iter)->flag == 0)
            {
                item2->setText("-");
                item3->setText("-");
                item4->setText("-");
                item5->setText("-");
                item6->setText("-");
                item7->setText("-");
                item8->setText("-");
                item9->setText("-");
                item10->setText("-");
            }
        }




        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
        table->setItem(row_count, 3, item3);
        table->setItem(row_count, 4, item4);
        table->setItem(row_count, 5, item5);
        table->setItem(row_count, 6, item6);
        table->setItem(row_count, 7, item7);
        table->setItem(row_count, 8, item8);
        table->setItem(row_count, 9, item9);
        table->setItem(row_count, 10, item10);

    }

}

void MainWindow::addPowerData(QTableWidget *table, QList<YC600_PowerData_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<YC600_PowerData_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->time);
        item1->setText(QString::number((*iter)->power));

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}

void MainWindow::addEnergyData(QTableWidget *table, QList<YC600_EnergyData_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<YC600_EnergyData_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->date);
        item1->setText(QString::number((double)(*iter)->energy));

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}
void MainWindow::addShortAddrData(QTableWidget *table, QList<ShortAddr_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<ShortAddr_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText(QString::number((unsigned short)(*iter)->shortAddr));

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}


void MainWindow::addTableData(QTableWidget *table, QList<OPT700_RS *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<OPT700_RS *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        QTableWidgetItem *item5 = new QTableWidgetItem();
        QTableWidgetItem *item6 = new QTableWidgetItem();
        QTableWidgetItem *item7 = new QTableWidgetItem();
        QTableWidgetItem *item8 = new QTableWidgetItem();
        QTableWidgetItem *item9 = new QTableWidgetItem();
        QTableWidgetItem *item10 = new QTableWidgetItem();
        QTableWidgetItem *item11 = new QTableWidgetItem();
        QTableWidgetItem *item12 = new QTableWidgetItem();
        QTableWidgetItem *item13 = new QTableWidgetItem();
        QTableWidgetItem *item14 = new QTableWidgetItem();
        QTableWidgetItem *item15 = new QTableWidgetItem();
        QTableWidgetItem *item16 = new QTableWidgetItem();
        QTableWidgetItem *item17 = new QTableWidgetItem();
        QTableWidgetItem *item18 = new QTableWidgetItem();
        QTableWidgetItem *item19 = new QTableWidgetItem();
        QTableWidgetItem *item20 = new QTableWidgetItem();
        QTableWidgetItem *item21 = new QTableWidgetItem();
        QTableWidgetItem *item22 = new QTableWidgetItem();
        QTableWidgetItem *item23 = new QTableWidgetItem();
        QTableWidgetItem *item24 = new QTableWidgetItem();
        QTableWidgetItem *item25 = new QTableWidgetItem();



        item->setText((*iter)->ID);
        item1->setText(QString::number((*iter)->Equipment_Status));
        item2->setText(QString::number((*iter)->Mos_Status));

        item3->setText(QString::number((*iter)->Function_Status));
        item4->setText(QString::number((*iter)->PV1_Protect));
        item5->setText(QString::number((*iter)->PV2_Protect));
        item6->setText(QString::number((*iter)->Heart_Rate));
        item7->setText(QString::number((*iter)->Off_Times));
        item8->setText(QString::number((*iter)->Shutdown_Num));
        item9->setText(QString::number((*iter)->PV1));
        item10->setText(QString::number((*iter)->PV2));
        item11->setText(QString::number((*iter)->PI));
        item12->setText(QString::number((*iter)->PI2));

        item13->setText(QString::number((*iter)->Power1));
        item14->setText(QString::number((*iter)->Power2));
        item15->setText(QString::number((*iter)->Output_PV));
        item16->setText(QString::number((*iter)->PI_Output));
        item17->setText(QString::number((*iter)->Power_Output));
        item18->setText(QString::number((*iter)->RSSI));

        item19->setText(QString::number((*iter)->PV1_ENERGY));
        item20->setText(QString::number((*iter)->PV2_ENERGY));
        item21->setText(QString::number((*iter)->PV_Output_ENERGY));
        item22->setText(QString::number((*iter)->MOS_CLOSE_NUM));
        item23->setText(QString::number((*iter)->version));
        item24->setText(QString::number((*iter)->model));
        item25->setText(QString::number((*iter)->temperature));

        if((*iter)->Mos_Status == 1)
        {
            item->setBackgroundColor(QColor(0,238,0));
            item1->setBackgroundColor(QColor(0,238,0));
            item2->setBackgroundColor(QColor(0,238,0));
            item3->setBackgroundColor(QColor(0,238,0));
            item4->setBackgroundColor(QColor(0,238,0));
            item5->setBackgroundColor(QColor(0,238,0));
            item6->setBackgroundColor(QColor(0,238,0));
            item7->setBackgroundColor(QColor(0,238,0));
            item8->setBackgroundColor(QColor(0,238,0));
            item9->setBackgroundColor(QColor(0,238,0));
            item10->setBackgroundColor(QColor(0,238,0));
            item11->setBackgroundColor(QColor(0,238,0));
            item12->setBackgroundColor(QColor(0,238,0));
            item13->setBackgroundColor(QColor(0,238,0));
            item14->setBackgroundColor(QColor(0,238,0));
            item15->setBackgroundColor(QColor(0,238,0));
            item16->setBackgroundColor(QColor(0,238,0));
            item17->setBackgroundColor(QColor(0,238,0));
            item18->setBackgroundColor(QColor(0,238,0));
            item19->setBackgroundColor(QColor(0,238,0));
            item20->setBackgroundColor(QColor(0,238,0));
            item21->setBackgroundColor(QColor(0,238,0));
            item22->setBackgroundColor(QColor(0,238,0));
            item23->setBackgroundColor(QColor(0,238,0));
            item24->setBackgroundColor(QColor(0,238,0));
            item25->setBackgroundColor(QColor(0,238,0));
        }

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
        table->setItem(row_count, 3, item3);
        table->setItem(row_count, 4, item4);
        table->setItem(row_count, 5, item5);
        table->setItem(row_count, 6, item6);
        table->setItem(row_count, 7, item7);
        table->setItem(row_count, 8, item8);
        table->setItem(row_count, 9, item9);
        table->setItem(row_count, 10, item10);
        table->setItem(row_count, 11, item11);
        table->setItem(row_count, 12, item12);
        table->setItem(row_count, 13, item13);
        table->setItem(row_count, 14, item14);
        table->setItem(row_count, 15, item15);
        table->setItem(row_count, 16, item16);
        table->setItem(row_count, 17, item17);
        table->setItem(row_count, 18, item18);
        table->setItem(row_count, 19, item19);
        table->setItem(row_count, 20, item20);
        table->setItem(row_count, 21, item21);
        table->setItem(row_count, 22, item22);
        table->setItem(row_count, 23, item23);
        table->setItem(row_count, 24, item24);
        table->setItem(row_count, 25, item25);
    }
}

void MainWindow::addSSIDData(QTableWidget *table, QList<SSID_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<SSID_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->SSID);
        item1->setText(QString::number((double)(*iter)->signalStrength));

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}




void MainWindow::on_btn_getRealData_clicked()
{
    unsigned char status;
    qint64 recvLen=0;
    int openCount = 0,closeCount = 0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    char dateTime[15] = {'\0'};
    int optcount = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100280002%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    YC600_RealData_List.clear();
    OPT700_RSList.clear();
    clr_tableWidget_RealData_Item();
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else if(Recvbuff[14] == '2')
        {
            statusBar()->showMessage(tr("ECU Have No Data ... time:%1").arg(commtime), 2000);
        }
        else
        {
            //分辨是YC600YC1000    还是 RSD
            if(!memcmp(&Recvbuff[15],"01",2))
            {   //YC600
                set_tableWidget_RealData_View(1);
                statusBar()->showMessage(tr("ECU Get Real Data Success ... time:%1").arg(commtime), 2000);

                optcount = (Recvbuff[17]& 0x000000ff)*256+(Recvbuff[18]& 0x000000ff);
                length = 26;
                for(index = 0;index < optcount;index++)
                {
                    YC600_RealData_t *YC600_RealData = new YC600_RealData_t;

                    sprintf(YC600_RealData->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length] & 0x000000ff),(Recvbuff[length+1] & 0x000000ff),(Recvbuff[length+2] & 0x000000ff),(Recvbuff[length+3] & 0x000000ff),(Recvbuff[length+4] & 0x000000ff),(Recvbuff[length+5] & 0x000000ff));
                    YC600_RealData->flag = (Recvbuff[length+6] & 0x000000ff);
                    YC600_RealData->inverter_type = ((Recvbuff[length+7]-'0') & 0x000000ff)*10 + ((Recvbuff[length+8]-'0') & 0x000000ff);
                    if(YC600_RealData->inverter_type == 0)
                    {
                        length += 9;
                    }else if(YC600_RealData->inverter_type == 1)
                    {
                        YC600_RealData->Grid_Frequency = (Recvbuff[length+9] & 0x000000ff)*256 + (Recvbuff[length+10] & 0x000000ff);
                        YC600_RealData->Temperature = (Recvbuff[length+11] & 0x000000ff)*256 + (Recvbuff[length+12] & 0x000000ff);
                        YC600_RealData->Inverter_Power = (Recvbuff[length+13] & 0x000000ff)*256 + (Recvbuff[length+14] & 0x000000ff);
                        YC600_RealData->Grid_Voltage = (Recvbuff[length+15] & 0x000000ff)*256 + (Recvbuff[length+16] & 0x000000ff);
                        YC600_RealData->Inverter_Power_B = (Recvbuff[length+17] & 0x000000ff)*256 + (Recvbuff[length+18] & 0x000000ff);
                        YC600_RealData->Grid_Voltage_B = (Recvbuff[length+19] & 0x000000ff)*256 + (Recvbuff[length+20] & 0x000000ff);
                        length += 21;
                    }else if(YC600_RealData->inverter_type == 2)
                    {
                        YC600_RealData->Grid_Frequency = (Recvbuff[length+9] & 0x000000ff)*256 + (Recvbuff[length+10] & 0x000000ff);
                        YC600_RealData->Temperature = (Recvbuff[length+11] & 0x000000ff)*256 + (Recvbuff[length+12] & 0x000000ff);
                        YC600_RealData->Inverter_Power = (Recvbuff[length+13] & 0x000000ff)*256 + (Recvbuff[length+14] & 0x000000ff);
                        YC600_RealData->Grid_Voltage = (Recvbuff[length+15] & 0x000000ff)*256 + (Recvbuff[length+16] & 0x000000ff);
                        YC600_RealData->Inverter_Power_B = (Recvbuff[length+17] & 0x000000ff)*256 + (Recvbuff[length+18] & 0x000000ff);
                        YC600_RealData->Grid_Voltage_B = (Recvbuff[length+19] & 0x000000ff)*256 + (Recvbuff[length+20] & 0x000000ff);
                        YC600_RealData->Inverter_Power_C = (Recvbuff[length+21] & 0x000000ff)*256 + (Recvbuff[length+22] & 0x000000ff);
                        YC600_RealData->Grid_Voltage_C = (Recvbuff[length+23] & 0x000000ff)*256 + (Recvbuff[length+24] & 0x000000ff);
                        YC600_RealData->Inverter_Power_D = (Recvbuff[length+25] & 0x000000ff)*256 + (Recvbuff[length+26] & 0x000000ff);
                        length += 27;
                    }
                    else if(YC600_RealData->inverter_type == 3)
                    {
                        YC600_RealData->Grid_Frequency = (Recvbuff[length+9] & 0x000000ff)*256 + (Recvbuff[length+10] & 0x000000ff);
                        YC600_RealData->Temperature = (Recvbuff[length+11] & 0x000000ff)*256 + (Recvbuff[length+12] & 0x000000ff);
                        YC600_RealData->Inverter_Power = (Recvbuff[length+13] & 0x000000ff)*256 + (Recvbuff[length+14] & 0x000000ff);
                        YC600_RealData->Grid_Voltage = (Recvbuff[length+15] & 0x000000ff)*256 + (Recvbuff[length+16] & 0x000000ff);
                        YC600_RealData->Inverter_Power_B = (Recvbuff[length+17] & 0x000000ff)*256 + (Recvbuff[length+18] & 0x000000ff);
                        YC600_RealData->Grid_Voltage_B =YC600_RealData->Grid_Voltage;
                        YC600_RealData->Inverter_Power_C = (Recvbuff[length+19] & 0x000000ff)*256 + (Recvbuff[length+20] & 0x000000ff);
                        YC600_RealData->Grid_Voltage_C =YC600_RealData->Grid_Voltage;
                        YC600_RealData->Inverter_Power_D = (Recvbuff[length+21] & 0x000000ff)*256 + (Recvbuff[length+22] & 0x000000ff);
                        length += 23;
                    }
                    YC600_RealData_List.push_back(YC600_RealData);

                }
                addRealData(ui->tableWidget_RealData,YC600_RealData_List);
                sprintf(dateTime,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[19],Recvbuff[20],Recvbuff[21],Recvbuff[22],Recvbuff[23],Recvbuff[24],Recvbuff[25]);
                ui->label_all->setText(QString::number(optcount));
                ui->label_time->setText(dateTime);
                QList<YC600_RealData_t *>::Iterator iter = YC600_RealData_List.begin();
                for ( ; iter != YC600_RealData_List.end(); iter++)  {
                    delete (*iter);
                }

            }else if(!memcmp(&Recvbuff[15],"02",2))
            {   //RSD
                set_tableWidget_RealData_View(2);

                optcount = Recvbuff[17]*256 + Recvbuff[18];
                qDebug("optcount:%d\n",optcount);
                length = 26;

                for(index = 0;index < optcount;index++)
                {
                    OPT700_RS *opt700_rs = new OPT700_RS;

                    sprintf(opt700_rs->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length] & 0x000000ff),(Recvbuff[length+1] & 0x000000ff),(Recvbuff[length+2] & 0x000000ff),(Recvbuff[length+3] & 0x000000ff),(Recvbuff[length+4] & 0x000000ff),(Recvbuff[length+5] & 0x000000ff));
                    ui->comboBox_UID->insertItem(index,opt700_rs->ID);
                    opt700_rs->ID[12] = '\0';
                    opt700_rs->Equipment_Status = Recvbuff[length + 6];

                    status = Recvbuff[length+7] & 0x000000ff;

                    opt700_rs->Mos_Status = status & (int)1;
                    opt700_rs->Function_Status = ((status & (int)(1<<1)) >> 1);
                    opt700_rs->PV1_Protect = ((status&(int)(1<<2)) >> 2);
                    opt700_rs->PV2_Protect = ((status&(int)(1<<3)) >> 3);

                    opt700_rs->Heart_Rate = (Recvbuff[length+8] & 0x000000ff)*256+(Recvbuff[length+9] & 0x000000ff);
                    opt700_rs->Off_Times = (Recvbuff[length+10] & 0x000000ff)*256+(Recvbuff[length+11] & 0x000000ff);
                    opt700_rs->Shutdown_Num = (Recvbuff[length+12] & 0x000000ff);
                    opt700_rs->PV1 = (Recvbuff[length+13] & 0x000000ff)*256+(Recvbuff[length+14] & 0x000000ff);
                    opt700_rs->PV2 = (Recvbuff[length+15] & 0x000000ff)*256+(Recvbuff[length+16] & 0x000000ff);
                    opt700_rs->PI = (Recvbuff[length+17] & 0x000000ff)*256 +  (Recvbuff[length+18] & 0x000000ff);
                    opt700_rs->PI2 = (Recvbuff[length+19] & 0x000000ff)*256 +  (Recvbuff[length+20] & 0x000000ff);

                    opt700_rs->Power1 = (Recvbuff[length+21] & 0x000000ff)*256+(Recvbuff[length+22] & 0x000000ff);
                    opt700_rs->Power2 = (Recvbuff[length+23] & 0x000000ff)*256+(Recvbuff[length+24] & 0x000000ff);
                    opt700_rs->Output_PV = (Recvbuff[length+25] & 0x000000ff)*256+(Recvbuff[length+26] & 0x000000ff);
                    opt700_rs->PI_Output = (Recvbuff[length+27] & 0x000000ff)*256+(Recvbuff[length+28] & 0x000000ff);
                    opt700_rs->Power_Output = (Recvbuff[length+29] & 0x000000ff)*256+(Recvbuff[length+30] & 0x000000ff);


                    opt700_rs->RSSI = (Recvbuff[length+31]  & 0x000000ff);

                    opt700_rs->PV1_ENERGY =  (Recvbuff[length+32] & 0x000000ff)*256*256*256+(Recvbuff[length+33] & 0x000000ff)*256*256 + (Recvbuff[length+34] & 0x000000ff)*256+(Recvbuff[length+35] & 0x000000ff);
                    opt700_rs->PV2_ENERGY = (Recvbuff[length+36] & 0x000000ff)*256*256*256+(Recvbuff[length+37] & 0x000000ff)*256*256 + (Recvbuff[length+38] & 0x000000ff)*256+(Recvbuff[length+39] & 0x000000ff);
                    opt700_rs->PV_Output_ENERGY = (Recvbuff[length+40] & 0x000000ff)*256*256*256+(Recvbuff[length+41] & 0x000000ff)*256*256 + (Recvbuff[length+42] & 0x000000ff)*256+(Recvbuff[length+43] & 0x000000ff);

                    opt700_rs->MOS_CLOSE_NUM = (Recvbuff[length+44] & 0x000000ff);
                    opt700_rs->version = (Recvbuff[length+45] & 0x000000ff)*256+(Recvbuff[length+46] & 0x000000ff);
                    opt700_rs->model = (Recvbuff[length+47] & 0x000000ff);
                    opt700_rs->temperature = (Recvbuff[length+48] & 0x000000ff);
                    OPT700_RSList.push_back(opt700_rs);

                    length += 57;

                    if(opt700_rs->Mos_Status == 1)
                    {
                        openCount++;
                    }else
                    {
                        closeCount++;
                    }
                }

                statusBar()->showMessage(tr("Get System Info Success ... time:%1 ms").arg(commtime), 2000);
                ui->label_all->setText(QString::number(optcount));
                sprintf(dateTime,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[19],Recvbuff[20],Recvbuff[21],Recvbuff[22],Recvbuff[23],Recvbuff[24],Recvbuff[25]);
                ui->label_time->setText(dateTime);
                addTableData(ui->tableWidget_RealData,OPT700_RSList);
                QList<OPT700_RS *>::Iterator iter = OPT700_RSList.begin();
                for ( ; iter != OPT700_RSList.end(); iter++)  {
                    delete (*iter);
                }

            }






        }


    }else
    {
        ui->tableWidget_RealData->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_RealData->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_getDate_clicked()
{
    //获取当前的时间
    ui->dateEdit->setDate(QDate::currentDate());
}

void MainWindow::on_btn_getPower_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    int year = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int day = ui->dateEdit->date().day();
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100390003%sEND%02d%02d%02dEND",ECUID,year,month,day);

    flag = ECU_Client->ECU_Communication(Sendbuff,39,Recvbuff,&recvLen,2000,&commtime);
    YC600_PowerData_List.clear();

    if(flag == true)
    {
        ui->tableWidget_Power->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Power->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Power Data Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-18)/4;
            length = 15;
            for(index = 0;index < num;index++)
            {
                YC600_PowerData_t *YC600_PowerData = new YC600_PowerData_t;
                sprintf(YC600_PowerData->time,"%02x:%02x",Recvbuff[length],Recvbuff[length+1]);
                YC600_PowerData->time[5] = '\0';
                YC600_PowerData->power = (Recvbuff[length+2] & 0x000000ff)*256 + (Recvbuff[length+3] & 0x000000ff);

                YC600_PowerData_List.push_back(YC600_PowerData);
                length += 4;

            }
            addPowerData(ui->tableWidget_Power,YC600_PowerData_List);

            QList<YC600_PowerData_t *>::Iterator iter = YC600_PowerData_List.begin();
            for ( ; iter != YC600_PowerData_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_Power->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Power->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }

}

void MainWindow::on_btn_getEnergy_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    int select_item = ui->comboBox_2->currentIndex();
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100330004%sEND%02dEND",ECUID,select_item);
    //qDebug("send:%s\n",Sendbuff);

    flag = ECU_Client->ECU_Communication(Sendbuff,33,Recvbuff,&recvLen,2000,&commtime);
    YC600_EnergyData_List.clear();

    if(flag == true)
    {
        ui->tableWidget_Energy->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Energy->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Energy Data Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-20)/6;
            length = 17;
            for(index = 0;index < num;index++)
            {
                YC600_EnergyData_t *YC600_EnergyData = new YC600_EnergyData_t;

                sprintf(YC600_EnergyData->date,"%02x%02x-%02x-%02x",Recvbuff[length],Recvbuff[length+1],Recvbuff[length+2],Recvbuff[length+3]);
                YC600_EnergyData->energy = ((double)((Recvbuff[length+4] & 0x000000ff)*256 + (Recvbuff[length+5] & 0x000000ff))/100);
                YC600_EnergyData_List.push_back(YC600_EnergyData);
                length += 6;
            }
            addEnergyData(ui->tableWidget_Energy,YC600_EnergyData_List);

            QList<YC600_EnergyData_t *>::Iterator iter = YC600_EnergyData_List.begin();
            for ( ; iter != YC600_EnergyData_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_Energy->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Energy->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }

}

void MainWindow::set_tableWidget_RealData_View(int item)
{
    int i = 0,columnNum=0;
    ui->tableWidget_RealData->clear();
    ui->tableWidget_RealData->setRowCount(0);
    //清空Table中内容
    ui->tableWidget_RealData->clearContents();

    if(item == 1)
    {
        columnNum = ui->tableWidget_RealData->columnCount();
        for(i=0;i<columnNum;i++)
        {
            delete 	ui->tableWidget_RealData->horizontalHeaderItem(i);
        }

        ui->tableWidget_RealData->setColumnCount(11);

        ui->tableWidget_RealData->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("ID")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Type")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("frequency")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("temperature")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("A power")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(5,new QTableWidgetItem(tr("A voltage")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(6,new QTableWidgetItem(tr("B power")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(7,new QTableWidgetItem(tr("B voltage")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(8,new QTableWidgetItem(tr("C power")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(9,new QTableWidgetItem(tr("C voltage")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(10,new QTableWidgetItem(tr("D power")));
        ui->tableWidget_RealData->setColumnWidth(0,100);
        ui->tableWidget_RealData->setColumnWidth(1,50);
        ui->tableWidget_RealData->setColumnWidth(2,60);
        ui->tableWidget_RealData->setColumnWidth(3,72);
        ui->tableWidget_RealData->setColumnWidth(4,55);
        ui->tableWidget_RealData->setColumnWidth(5,60);
        ui->tableWidget_RealData->setColumnWidth(6,60);
        ui->tableWidget_RealData->setColumnWidth(7,60);
        ui->tableWidget_RealData->setColumnWidth(8,60);
        ui->tableWidget_RealData->setColumnWidth(9,60);
        ui->tableWidget_RealData->setColumnWidth(10,60);


    }else if(item == 2)
    {
        columnNum = ui->tableWidget_RealData->columnCount();
        for(i=0;i<columnNum;i++)
        {
            if(ui->tableWidget_RealData->horizontalHeaderItem(i))
                delete 	ui->tableWidget_RealData->horizontalHeaderItem(i);
        }

        ui->tableWidget_RealData->setColumnCount(26);


        ui->tableWidget_RealData->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("ID")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("status")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("OnOff")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("function")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("PV1 status")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(5,new QTableWidgetItem(tr("PV2 status")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(6,new QTableWidgetItem(tr("heart Time")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(7,new QTableWidgetItem(tr("off Time")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(8,new QTableWidgetItem(tr("today Close Time ")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(9,new QTableWidgetItem(tr("PV1")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(10,new QTableWidgetItem(tr("PV2")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(11,new QTableWidgetItem(tr("PI1")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(12,new QTableWidgetItem(tr("PI2")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(13,new QTableWidgetItem(tr("Power1")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(14,new QTableWidgetItem(tr("Power2")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(15,new QTableWidgetItem(tr("PV Out")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(16,new QTableWidgetItem(tr("PI Out")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(17,new QTableWidgetItem(tr("Power Out")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(18,new QTableWidgetItem(tr("RSSI")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(19,new QTableWidgetItem(tr("PV1 Energy")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(20,new QTableWidgetItem(tr("PV2 Energy")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(21,new QTableWidgetItem(tr("PV Out Energy")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(22,new QTableWidgetItem(tr("MOS Close Num")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(23,new QTableWidgetItem(tr("Version")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(24,new QTableWidgetItem(tr("Model")));
        ui->tableWidget_RealData->setHorizontalHeaderItem(25,new QTableWidgetItem(tr("Temperature")));

        ui->tableWidget_RealData->setColumnWidth(0,100);
        ui->tableWidget_RealData->setColumnWidth(1,40);
        ui->tableWidget_RealData->setColumnWidth(2,50);
        ui->tableWidget_RealData->setColumnWidth(3,60);
        ui->tableWidget_RealData->setColumnWidth(4,70);
        ui->tableWidget_RealData->setColumnWidth(5,70);
        ui->tableWidget_RealData->setColumnWidth(6,70);
        ui->tableWidget_RealData->setColumnWidth(7,60);
        ui->tableWidget_RealData->setColumnWidth(8,100);
        ui->tableWidget_RealData->setColumnWidth(9,30);
        ui->tableWidget_RealData->setColumnWidth(10,30);
        ui->tableWidget_RealData->setColumnWidth(11,30);
        ui->tableWidget_RealData->setColumnWidth(12,30);
        ui->tableWidget_RealData->setColumnWidth(13,40);
        ui->tableWidget_RealData->setColumnWidth(14,40);
        ui->tableWidget_RealData->setColumnWidth(15,40);
        ui->tableWidget_RealData->setColumnWidth(16,40);
        ui->tableWidget_RealData->setColumnWidth(17,40);
        ui->tableWidget_RealData->setColumnWidth(18,60);
        ui->tableWidget_RealData->setColumnWidth(19,60);
        ui->tableWidget_RealData->setColumnWidth(20,60);
        ui->tableWidget_RealData->setColumnWidth(21,80);
        ui->tableWidget_RealData->setColumnWidth(22,80);
        ui->tableWidget_RealData->setColumnWidth(23,50);
        ui->tableWidget_RealData->setColumnWidth(24,50);
        ui->tableWidget_RealData->setColumnWidth(25,100);
    }

}

void MainWindow::clr_tableWidget_RealData_Item()
{
    int i = 0,columnNum=0,j = 0,rowNum = 0;
    columnNum = ui->tableWidget_RealData->columnCount();
    rowNum = ui->tableWidget_RealData->rowCount();
    qDebug("%d %d",columnNum,rowNum);
    for(i = 0;i<columnNum;i++)
    {
        for(j = 0;j<rowNum;j++)
        {
            if(ui->tableWidget_RealData->item(j,i))
                delete ui->tableWidget_RealData->item(j,i);
        }
    }
}

void MainWindow::on_btn_getTime_ECU_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Time[15] = {'\0'};
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280012%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    //ui->plainTextEdit_ID->clear();
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {

            statusBar()->showMessage(tr("ECU Get Time Success ... time:%1").arg(commtime), 2000);
            memcpy(&Time,&Recvbuff[15],14);
            Time[14] = '\0';
            QDate date;
            QTime time;
            QString a = QString(Time).mid(0,8);
            QString b = QString(Time).mid(8,6);
            date = QDate::fromString(a,"yyyyMMdd");
            time = QTime::fromString(b,"hhmmss");
            ui->dateTimeEdit_ECU->setDateTime(QDateTime(date,time));
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}



void MainWindow::on_btn_getWIFI_clicked()
{
    char send[100] = {'\0'};
    char recv[4096] = {'\0'};
    bool flag = false;
    qint64 recvlen,length,num,index,j,SSIDLen;

    send[0] = 0xFF;
    send[1] = 0x00;
    send[2] = 0x01;
    send[3] = 0x01;
    send[4] = 0x02;
    UDPClient1->ECU_Connect();
    flag =UDPClient1->ECU_CommUDP(send, 5, recv, &recvlen, 5000);
    SSID_List.clear();
    if(flag == true)
    {    ui->tableWidget_SSID->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_SSID->clearContents();
        num = recv[4];
        //qDebug("num:%d\n",num);
        length = 5;
        //qDebug("SSID %s\n",&recv[5]);

        for(index = 0;index < num;index++)
        {
            SSID_t *SSID = new SSID_t;
            for(j = length;j<recvlen;j++)
            {
                if(recv[j] == 0x00)
                {
                    SSIDLen = j - length;
                    //qDebug("SSID len:%d\n",SSIDLen);
                    break;
                }
            }
            memcpy(SSID->SSID,&recv[length],SSIDLen);
            SSID->SSID[SSIDLen] = '\0';
            //qDebug("SSID:%s\n",SSID->SSID);
            SSID->signalStrength = recv[length+SSIDLen+1];
            //qDebug("SSID:%d\n",SSID->signalStrength);
            //qDebug("%x %x\n",recv[length+SSIDLen+2],recv[length+SSIDLen+3]);
            SSID_List.push_back(SSID);
            length += SSIDLen+4;
        }
        addSSIDData(ui->tableWidget_SSID,SSID_List);

        QList<SSID_t *>::Iterator iter = SSID_List.begin();
        for ( ; iter != SSID_List.end(); iter++)  {
            delete (*iter);
        }

    }else
    {
        ui->tableWidget_Energy->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Energy->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
    UDPClient1->ECU_Abrot();
}

void MainWindow::on_pushButton_clicked()
{
    char send[100] = "HF-A11ASSISTHREAD";
    char recv[4096] = {'\0'};
    bool flag = false;
    qint64 sendlen,recvlen;
    UDPClient2->ECU_Connect();
    flag = UDPClient2->ECU_CommUDP(send, 17, recv, &recvlen, 2000);
    if(flag == true)
    {
        //qDebug("%s\n",recv);
        UDPClient2->ECU_SendUDP("+ok", 3);
        memset(recv,'\0',4096);
        flag = UDPClient2->ECU_CommUDP("AT+WSLK\n", 9, recv, &recvlen, 3000);
        if(flag == true)
        {
            //qDebug("%s\n",recv);
            ui->label_LinkStatus->setText(QString(&recv[4]));
        }

        UDPClient2->ECU_SendUDP("AT+Q\n", 5);
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
    UDPClient2->ECU_Abrot();

}


void MainWindow::on_tableWidget_SSID_itemClicked(QTableWidgetItem *item)
{
    QString SSID;
    SSID = ui->tableWidget_SSID->item(item->row(),0)->text();
    qDebug("%s\n",SSID.toLatin1().data());
    ui->lineEdit_SSID_2->clear();
    ui->lineEdit_SSID_2->setText(SSID.toLatin1().data());
    ui->lineEdit_PassWD->clear();
    if(!SSID.compare("yuneng_ecu_test"))
    {
        ui->lineEdit_PassWD->setText("123456789");
    }else if(!SSID.compare("yuneng_wifi"))
    {
        ui->lineEdit_PassWD->setText("yunengaps2014");
    }else if(!SSID.compare("yuneng_ecu"))
    {
        ui->lineEdit_PassWD->setText("yunengaps2014");
    }else if(!SSID.compare("TP-LINK_CS"))
    {
        ui->lineEdit_PassWD->setText("yunengaps");
    }else if(!SSID.compare("HUAWEI-6MTDB2"))
    {
        ui->lineEdit_PassWD->setText("shiyanshi2016");
    }


}

void MainWindow::on_btn_connect_clicked()
{
    char send[300] = {'\0'};
    char SSID[100] = {'\0'};
    char PassWD[100] = {'\0'};
    char recv[4096] = {'\0'};
    bool flag = false;
    qint64 recvlen,SSIDLen,PassWDLen,length = 0,i = 0,sum = 0;

    SSIDLen = ui->lineEdit_SSID_2->text().length();
    PassWDLen = ui->lineEdit_PassWD->text().length();
    memcpy(SSID,ui->lineEdit_SSID_2->text().toLatin1().data(),SSIDLen);
    SSID[SSIDLen] = '\0';
    memcpy(PassWD,ui->lineEdit_PassWD->text().toLatin1().data(),PassWDLen);
    PassWD[PassWDLen] = '\0';
    send[length++] = 0xFF;
    send[length++] = 0x00;
    send[length++] = 0x01;
    send[length++] = 0x02;
    send[length++] = 0x00;
    memcpy(&send[length],SSID,SSIDLen);
    length += SSIDLen;
    send[length++] = 0x0D;
    send[length++] = 0x0A;
    memcpy(&send[length],PassWD,PassWDLen);
    length += PassWDLen;
    send[1] = (length-3)/256;
    send[2] = (length-3)%256;

    for(i = 1;i<length;i++)
    {
        sum+=send[i];
    }
    send[length++] = sum;
    UDPClient1->ECU_Connect();

    for(i = 1;i<length;i++)
    {
        qDebug("%x ",send[i]);
    }

    flag = UDPClient1->ECU_CommUDP(send, length, recv, &recvlen, 3000);
    if(flag == true)
    {
        if(recv[4] == 0x00)
        {
            statusBar()->showMessage(tr("DON'T Search WIFI SSID ..."), 2000);
        }else
        {
            if(recv[5] == 0x00)
            {
                statusBar()->showMessage(tr("DON'T Password Mismatching ..."), 2000);
            }else
            {
                statusBar()->showMessage(tr("Set Success ..."), 2000);
            }
        }

    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }

    UDPClient1->ECU_Abrot();
}

void MainWindow::on_pushButton_2_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280013%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            unsigned int FlashSize = 0;
            statusBar()->showMessage(tr("ECU Get Flash Size Success ... time:%1").arg(commtime), 2000);

            FlashSize = (Recvbuff[15]&0x000000ff)*16777216+(Recvbuff[16]&0x000000ff)*65536+(Recvbuff[17]&0x000000ff)*256+(Recvbuff[18]&0x000000ff);
            ui->lineEdit_flashsize->setText(QString::number(FlashSize));
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_getNetwork_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);

    sprintf((char *)Sendbuff,"APS1100280014%sEND",ECUID);


    flag = ECU_Client->ECU_Communication((char *)Sendbuff,28,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            if(Recvbuff[16] == '0')
            {
                ui->comboBox->setCurrentIndex(0);
                IPInterfaceSataus(false);
            }else
            {
                ui->comboBox->setCurrentIndex(1);
                IPInterfaceSataus(true);
            }

            ui->lineEdit_IPAddress->setText(QString::number(Recvbuff[17])); //IP 1
            ui->lineEdit_IPAddress2->setText(QString::number(Recvbuff[18])); //IP 2
            ui->lineEdit_IPAddress3->setText(QString::number(Recvbuff[19])); //IP 3
            ui->lineEdit_IPAddress4->setText(QString::number(Recvbuff[20])); //IP 4

            ui->lineEdit_Mask->setText(QString::number(Recvbuff[21])); //MASK 1
            ui->lineEdit_Mask2->setText(QString::number(Recvbuff[22])); //MASK 2
            ui->lineEdit_Mask3->setText(QString::number(Recvbuff[23])); //MASK 3
            ui->lineEdit_Mask4->setText(QString::number(Recvbuff[24])); //MASK 4

            ui->lineEdit_gate->setText(QString::number(Recvbuff[25])); //GATE 1
            ui->lineEdit_gate2->setText(QString::number(Recvbuff[26])); //GATE 2
            ui->lineEdit_gate3->setText(QString::number(Recvbuff[27])); //GATE 3
            ui->lineEdit_gate4->setText(QString::number(Recvbuff[28])); //GATE 4

            ui->lineEdit_DNS1->setText(QString::number(Recvbuff[29])); //DNS1 1
            ui->lineEdit_DNS12->setText(QString::number(Recvbuff[30])); //DNS1 2
            ui->lineEdit_DNS13->setText(QString::number(Recvbuff[31])); //DNS1 3
            ui->lineEdit_DNS14->setText(QString::number(Recvbuff[32])); //DNS1 4

            ui->lineEdit_DNS2->setText(QString::number(Recvbuff[33])); //DNS2 1
            ui->lineEdit_DNS22->setText(QString::number(Recvbuff[34])); //DNS2 2
            ui->lineEdit_DNS23->setText(QString::number(Recvbuff[35])); //DNS2 3
            ui->lineEdit_DNS24->setText(QString::number(Recvbuff[36])); //DNS2 4


            statusBar()->showMessage(tr("Get Network Success ... time:%1").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::on_btn_SetChannel_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    char Sendbuff[50];
    char Recvbuff[200] = {'\0'};
    char SIGNAL_LEVEL[4];
    char SIGNAL_CHANNEL[3];
    char oldChannel[3];
    char setChannel[3];
    memcpy(oldChannel,ui->comboBox_OldChannel->currentText().toLatin1().data(),2);
    oldChannel[2] = '\0';
    memcpy(setChannel,ui->comboBox_SetChannel->currentText().toLatin1().data(),2);
    setChannel[2] = '\0';

    qDebug("%s  %s\n",oldChannel,setChannel);
    sprintf(Sendbuff,"APS1100350015%sEND%s%sEND\n",ECUID,oldChannel,setChannel);
    qDebug("%s\n",Sendbuff);
    memset(Recvbuff,0x00,200);
    flag = ECU_Client->ECU_Communication(Sendbuff,35,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1 ms").arg(commtime), 2000);
        }
        else
        {
            memcpy(SIGNAL_CHANNEL,&Recvbuff[15],2);
            SIGNAL_CHANNEL[2]  = '\0';
            ui->label_CurrentChannel->setText(SIGNAL_CHANNEL);

            memcpy(SIGNAL_LEVEL,&Recvbuff[17],3);
            SIGNAL_LEVEL[3]  = '\0';
            ui->label_Stren->setText(SIGNAL_LEVEL);
            statusBar()->showMessage(tr("Set Channel Success ... time:%1 ms").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }

}

void MainWindow::on_btn_setFunction_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[8192] = {'\0'};
    int select_item = 0;
    memset(Recvbuff,0x00,8192);

    select_item = ui->comboBox_SetFunction->currentIndex();
    //先判断是关闭  还是开启
    if(select_item == 0)
    {   //关闭RSD功能
        sprintf((char *)Sendbuff,"APS1100290016%s0END",ECUID);
    }else if(select_item == 1)
    {   //开启RSD功能
        sprintf((char *)Sendbuff,"APS1100290016%s1END",ECUID);
    }

    flag = ECU_Client->ECU_Communication((char *)Sendbuff,29,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            statusBar()->showMessage(tr("Set RSD Function Success ... time:%1 ms").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set RSD Function Failed ... time:%1 ms").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::addINFOTableData(QTableWidget *table, QList<OPT700_RS_INFO *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<OPT700_RS_INFO *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        QTableWidgetItem *item5 = new QTableWidgetItem();
        QTableWidgetItem *item6 = new QTableWidgetItem();


        item->setText((*iter)->time);
        item1->setText(QString::number((*iter)->PV1));
        item2->setText(QString::number((*iter)->PI1));

        item3->setText(QString::number((*iter)->Power1));
        item4->setText(QString::number((*iter)->PV2));
        item5->setText(QString::number((*iter)->PI2));
        item6->setText(QString::number((*iter)->Power2));


        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));
        item2->setBackgroundColor(QColor(0,238,0));
        item3->setBackgroundColor(QColor(0,238,0));
        item4->setBackgroundColor(QColor(0,238,0));
        item5->setBackgroundColor(QColor(0,238,0));
        item6->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
        table->setItem(row_count, 3, item3);
        table->setItem(row_count, 4, item4);
        table->setItem(row_count, 5, item5);
        table->setItem(row_count, 6, item6);
    }
}

void MainWindow::on_btn_getDate_2_clicked()
{
    //获取当前的时间
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void MainWindow::on_btn_getInfo_clicked()
{
    qint64 recvLen=0;
    char uid_str[13] = {'\0'};
    char uid[7] = {'\0'};
    bool flag = false;
    int commtime = 0;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int optcount = 0;
    int length = 0,index = 0;
    int year = ui->dateEdit_2->date().year();
    int month = ui->dateEdit_2->date().month();
    int day = ui->dateEdit_2->date().day();

    memset(Recvbuff,0x00,200);
    sprintf(Sendbuff,"APS1100450017%sEND%04d%02d%02d000000END",ECUID,year,month,day);
    memcpy(uid_str,ui->comboBox_UID->currentText().toLatin1().data(),12);
    uid[0] = (uid_str[0] - '0')*0x10 + (uid_str[1] - '0');
    uid[1] = (uid_str[2] - '0')*0x10 + (uid_str[3] - '0');
    uid[2] = (uid_str[4] - '0')*0x10 + (uid_str[5] - '0');
    uid[3] = (uid_str[6] - '0')*0x10 + (uid_str[7] - '0');
    uid[4] = (uid_str[8] - '0')*0x10 + (uid_str[9] - '0');
    uid[5] = (uid_str[10] - '0')*0x10 + (uid_str[11] - '0');
    memcpy(&Sendbuff[34],uid,6);

    flag = ECU_Client->ECU_Communication(Sendbuff,45,Recvbuff,&recvLen,15000,&commtime);
    OPT700_RS_INFOList.clear();

    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1 ms").arg(commtime), 2000);
        }else if(Recvbuff[14] == '2')
        {
            statusBar()->showMessage(tr("ECU Don't Have Data ... time:%1 ms").arg(commtime), 2000);
        }
        else
        {
            optcount = (recvLen - 32)/12;
            qDebug("optcount:%d\n",optcount);
            length = 29;

            for(index = 0;index < optcount;index++)
            {
                OPT700_RS_INFO *opt700_rs_info = new OPT700_RS_INFO;
                sprintf(opt700_rs_info->time,"%02x:%02x",Recvbuff[length],Recvbuff[length+1]);
                opt700_rs_info->PV1 = Recvbuff[length+2]*256+Recvbuff[length+3];
                opt700_rs_info->PI1 = Recvbuff[length+4];
                opt700_rs_info->Power1 = Recvbuff[length+5]*256+Recvbuff[length+6];
                opt700_rs_info->PV2 = Recvbuff[length+7]*256+Recvbuff[length+8];
                opt700_rs_info->PI2 = Recvbuff[length+9];
                opt700_rs_info->Power2 = Recvbuff[length+10]*256+Recvbuff[length+11];
                OPT700_RS_INFOList.push_back(opt700_rs_info);

                length += 12;
            }
            statusBar()->showMessage(tr("Get RSD Info Success ... time:%1 ms").arg(commtime), 2000);
            addINFOTableData(ui->tableWidget_Info,OPT700_RS_INFOList);
            QList<OPT700_RS_INFO *>::Iterator iter = OPT700_RS_INFOList.begin();
            for ( ; iter != OPT700_RS_INFOList.end(); iter++)  {
                delete (*iter);
            }
        }
    }else
    {
        ui->tableWidget_Info->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Info->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_getshortAddr_clicked()
{
    unsigned char status;
    unsigned char rateOfProgress = 0;
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100280018%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    ShortAddr_List.clear();
    if(flag == true)
    {
        ui->tableWidget_shortAddr->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_shortAddr->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get ShortAddr Data Success ... time:%1").arg(commtime), 2000);
            rateOfProgress = (Recvbuff[15] & 0x000000ff);
            num = (recvLen-20)/8;
            length = 16;
            for(index = 0;index < num;index++)
            {
                ShortAddr_t *shortAddr = new ShortAddr_t;
                sprintf(shortAddr->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                shortAddr->shortAddr = (((Recvbuff[length+6] & 0x000000ff)*256 + (Recvbuff[length+7] & 0x000000ff)));
                ShortAddr_List.push_back(shortAddr);
                length += 8;
            }
            ui->progressBar->setValue((int)rateOfProgress);
            addShortAddrData(ui->tableWidget_shortAddr,ShortAddr_List);

            QList<ShortAddr_t *>::Iterator iter = ShortAddr_List.begin();
            for ( ; iter != ShortAddr_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_Energy->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Energy->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_gethardware_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280008%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Hardware status Success ... time:%1").arg(commtime), 2000);
            if(!memcmp(&Recvbuff[15],"00",2))
            {
                ui->label_wifiType->setText("00:USR MODULE");
            }else if(!memcmp(&Recvbuff[15],"01",2))
            {
                ui->label_wifiType->setText("01:RAK475 MODULE");
            }else if(!memcmp(&Recvbuff[15],"02",2))
            {
                ui->label_wifiType->setText("02:ESP07S MODULE");
            }
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_config_IDWrite_clicked()
{
    if(IDWrite_Client != NULL)
    {
        delete IDWrite_Client;
        IDWrite_Client = NULL;
    }

    IDWrite_Client = new Communication(ui->lineEdit_IP_IDWrite->text(),ui->lineEdit_Port_IDWrite->text().toUShort());
    statusBar()->showMessage(tr("Configure IDWrite IP And Port Successful ..."), 1000);
}

void MainWindow::on_btn_mkfs_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);

    flag = IDWrite_Client->IDWrite_Communication("mkfs",4,Recvbuff,&recvLen,10000,&commtime);
    if(flag == true)
    {
        Recvbuff[recvLen-1] = '\0';
        ui->label_mkfs->setText(Recvbuff);
        statusBar()->showMessage(tr("mkfs Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_mkfs->setText("mkfs failed");
        statusBar()->showMessage(tr("mkfs failed ..."), 2000);
    }
}



void MainWindow::on_btn_setID_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    char ID[13] = {'\0'};
    memset(Recvbuff,0x00,4096);
    memcpy(ID,ui->lineEdit_ID_2->text().toLatin1(),12);
    sprintf(Sendbuff,"set_ecu_id %s",ID);
    flag = IDWrite_Client->IDWrite_Communication(Sendbuff,23,Recvbuff,&recvLen,20000,&commtime);
    if(flag == true)
    {
        ui->label_ID_2->setText(Recvbuff);
        statusBar()->showMessage(tr("Set ID Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_ID_2->setText("Set ID failed");
        statusBar()->showMessage(tr("Set ID failed ..."), 2000);
    }
}

void MainWindow::on_btn_getID_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("get_ecu_id",10,Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        ui->label_ID_2->setText(Recvbuff);
        statusBar()->showMessage(tr("Get ID Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_ID_2->setText("Get ID failed");
        statusBar()->showMessage(tr("Get ID failed ..."), 2000);
    }
}

void MainWindow::on_btn_setMAC_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    char MAC[13] = {'\0'};
    memset(Recvbuff,0x00,4096);
    memcpy(MAC,ui->lineEdit_MAC->text().toLatin1(),12);
    sprintf(Sendbuff,"set_eth0_mac %s",MAC);
    flag = IDWrite_Client->IDWrite_Communication(Sendbuff,25,Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        ui->label_MAC->setText(Recvbuff);
        statusBar()->showMessage(tr("Set MAC Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_MAC->setText("Set MAC failed");
        statusBar()->showMessage(tr("Set MAC failed ..."), 2000);
    }
}

void MainWindow::on_btn_getMAC_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("get_eth0_mac",12,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_MAC->setText(Recvbuff);
        statusBar()->showMessage(tr("Get MAC Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_MAC->setText("Get MAC failed");
        statusBar()->showMessage(tr("Get MAC failed ..."), 2000);
    }
}

void MainWindow::on_btn_setArea_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    char Area[13] = {'\0'};
    memset(Recvbuff,0x00,4096);
    memcpy(Area,ui->comboBox_Area->currentText().toLatin1(),ui->comboBox_Area->currentText().length());
    if(ui->comboBox_Area->currentIndex() == 0)
    {
        sprintf(Sendbuff,"set_area  ");
    }
    else
    {
        sprintf(Sendbuff,"set_area %s",Area);
    }

    flag = IDWrite_Client->IDWrite_Communication(Sendbuff,strlen(Sendbuff),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        ui->label_Area->setText(Recvbuff);
        statusBar()->showMessage(tr("Set AREA Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_Area->setText("Set AREA failed");
        statusBar()->showMessage(tr("Set AREA failed ..."), 2000);
    }
}

void MainWindow::on_btn_getArea_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("get_area",8,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_Area->setText(Recvbuff);
        statusBar()->showMessage(tr("Get AREA Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_Area->setText("Get AREA failed");
        statusBar()->showMessage(tr("Get AREA failed ..."), 2000);
    }
}

void MainWindow::on_btn_getTime_2_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("get_time",8,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_Time->setText(Recvbuff);
        statusBar()->showMessage(tr("Get Time Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_Time->setText("Get Time failed");
        statusBar()->showMessage(tr("Get Time failed ..."), 2000);
    }

}

void MainWindow::on_btn_setTime_2_clicked()
{
    char Time[15] = {'\0'};
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    memcpy(Time,QDateTime::currentDateTime().toString("yyyyMMddhhmmss").toLatin1(),14);
    sprintf(Sendbuff,"set_time %s",Time);
    flag = IDWrite_Client->IDWrite_Communication(Sendbuff,23,Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        ui->label_Time->setText(Recvbuff);
        statusBar()->showMessage(tr("Set Time Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_Time->setText("Set Time failed");
        statusBar()->showMessage(tr("Set Time failed ..."), 2000);
    }
}

void MainWindow::on_btn_LED_clicked()
{
    IDWrite_Client->ECU_Connect();
    IDWrite_Client->ECU_Write("test_led",8);
    IDWrite_Client->ECU_Disconnect();
}

void MainWindow::on_btn_Version_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("get_version",11,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_version->setText(Recvbuff);
        statusBar()->showMessage(tr("Get Version Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_version->setText("Get Version failed");
        statusBar()->showMessage(tr("Get Version failed ..."), 2000);
    }
}

void MainWindow::on_btn_Clear_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    char Recvbuff[4096] = {'\0'};
    IDWrite_Client->ECU_Connect();
    IDWrite_Client->ECU_Write("clear",5);
    flag = IDWrite_Client->ECU_Read(Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(Recvbuff,"0x10",4))
        {
            memset(Recvbuff,'\0',4096);
            recvLen = 0;
            commtime = 0;
            flag = IDWrite_Client->ECU_Read(Recvbuff,&recvLen,3000,&commtime);
            if(flag == true)
            {
                if(!memcmp(Recvbuff,"clearok",7))
                {
                    ui->label_Clear->setText(Recvbuff);
                    statusBar()->showMessage(tr("clear Success ... time:%1").arg(commtime), 2000);
                }
            }
        }
    }else
    {
        ui->label_Clear->setText("clear failed");
        statusBar()->showMessage(tr("clear failed ..."), 2000);
    }

    IDWrite_Client->ECU_Disconnect();
}

void MainWindow::on_btn_addInverter_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    char inverterID[200] = {'\0'};
    memset(Recvbuff,0x00,4096);
    memcpy(inverterID,ui->lineEdit_INVERTER->text().toLatin1(),ui->lineEdit_INVERTER->text().length());
    sprintf(Sendbuff,"set_inverter_id %s",inverterID);
    IDWrite_Client->ECU_Connect();
    IDWrite_Client->ECU_Write(Sendbuff,(16+ui->lineEdit_INVERTER->text().length()));
    flag = IDWrite_Client->ECU_Read(Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(Recvbuff,"0x12",4))
        {
            memset(Recvbuff,'\0',4096);
            recvLen = 0;
            commtime = 0;
            flag = IDWrite_Client->ECU_Read(Recvbuff,&recvLen,3000,&commtime);
            if(flag == true)
            {
                if(!memcmp(Recvbuff,"01",2))
                {
                    ui->label_inverter->setText(Recvbuff);
                    statusBar()->showMessage(tr("Add Inverter Success ... time:%1").arg(commtime), 2000);
                }
            }
        }
    }else
    {
        ui->label_inverter->setText("Add Inverter failed");
        statusBar()->showMessage(tr("Add Inverter failed ..."), 2000);
    }

    IDWrite_Client->ECU_Disconnect();
}

void MainWindow::on_btn_query_result_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[8192] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,8192);
    flag = IDWrite_Client->IDWrite_Communication("query_result",12,Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        ui->textBrowser->setText(Recvbuff);
        statusBar()->showMessage(tr("query result Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->textBrowser->setText("query result failed");
        statusBar()->showMessage(tr("query result failed ..."), 2000);
    }
}

void MainWindow::on_btn_query_protection_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("query_protection",16,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->textBrowser_2->setText(Recvbuff);
        statusBar()->showMessage(tr("query protection Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->textBrowser_2->setText("query protection failed");
        statusBar()->showMessage(tr("query protection failed ..."), 2000);
    }
}

void MainWindow::on_btn_config_JSON_clicked()
{
    if(JSON_Client != NULL)
    {
        delete JSON_Client;
        JSON_Client = NULL;
    }

    JSON_Client = new Communication(ui->lineEdit_IP_JSON->text(),ui->lineEdit_Port_JSON->text().toUShort());
    statusBar()->showMessage(tr("Configure JSON IP And Port Successful ..."), 1000);
}

void MainWindow::on_btn_cmd101_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[16384] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,16384);
    flag = JSON_Client->IDWrite_Communication("{\"cmd\":101}",11,Recvbuff,&recvLen,5000,&commtime);
    if(flag == true)
    {
        ui->plainTextEdit->setPlainText(Recvbuff);
        statusBar()->showMessage(tr("query JSON Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->plainTextEdit->setPlainText("query JSON failed");
        statusBar()->showMessage(tr("query JSON failed ..."), 2000);
    }
}

void MainWindow::on_btn_connect_ESP07_clicked()
{

    qint64 SSIDLen,PassWDLen = 0;
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    char length[5] = {'\0'};
    char SSID_esp07[100] = {'\0'};
    char PassWD[100] = {'\0'};

    sprintf(Sendbuff,"APS1100000021%sEND04",ECUID);
    SSIDLen = ui->lineEdit_SSID2->text().length();
    sprintf(length,"%02d",SSIDLen);
    memcpy(&Sendbuff[strlen(Sendbuff)],length,2);

    memcpy(SSID_esp07,ui->lineEdit_SSID2->text().toLatin1().data(),SSIDLen);
    SSID_esp07[SSIDLen] = '\0';
    memcpy(&Sendbuff[strlen(Sendbuff)],SSID_esp07,SSIDLen);

    PassWDLen = ui->lineEdit_PassWD2->text().length();
    sprintf(length,"%02d",PassWDLen);
    memcpy(&Sendbuff[strlen(Sendbuff)],length,2);

    memcpy(PassWD,ui->lineEdit_PassWD2->text().toLatin1().data(),PassWDLen);
    PassWD[PassWDLen] = '\0';
    memcpy(&Sendbuff[strlen(Sendbuff)],PassWD,PassWDLen);

    memcpy(&Sendbuff[strlen(Sendbuff)],"END",3);
    sprintf(length,"%04d",QString(Sendbuff).length());
    memcpy(&Sendbuff[5],length,4);
    qDebug("%s",Sendbuff);

    flag = ECU_Client->ECU_Communication(Sendbuff,(37+SSIDLen+PassWDLen),Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU SET ESP07 WIFI Connect Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }


}
//APS1100620020001"yuneng_ecu_test","00:1d:0f:7f:f3:08",6,-31END
void MainWindow::on_pushButton_ESP07_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Time[15] = {'\0'};
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280020%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {

            statusBar()->showMessage(tr("ECU Get ESP07 WIFI Connect Success ... time:%1").arg(commtime), 2000);
            if(0 == Recvbuff[15])
            {
                ui->label_LinkStatus_ESP07->setText("Disconnect");
            }else
            {
                char info[100];
                Recvbuff[recvLen-4] = '\0';
                memcpy(info,&Recvbuff[16],recvLen-17);
                qDebug("%s",info);
                ui->label_LinkStatus_ESP07->setWordWrap ( true );
                ui->label_LinkStatus_ESP07->setText(info);
            }
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::addESP07SData(QTableWidget *table, QList<ESP07S_SSID_INFO *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();
    QList<ESP07S_SSID_INFO *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        QTableWidgetItem *item5 = new QTableWidgetItem();
        QTableWidgetItem *item6 = new QTableWidgetItem();


        item->setText(QString::number((*iter)->ecn));
        item1->setText(QString((*iter)->SSID));
        item2->setText(QString::number((*iter)->RSSI));
        item3->setText(QString((*iter)->MAC));
        item4->setText(QString::number((*iter)->CHANNEL));
        item5->setText(QString::number((*iter)->offset));
        item6->setText(QString::number((*iter)->calibration));


        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
        table->setItem(row_count, 3, item3);
        table->setItem(row_count, 4, item4);
        table->setItem(row_count, 5, item5);
        table->setItem(row_count, 6, item6);

    }

}

void MainWindow::on_btn_getWIFI_2_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280022%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,10000,&commtime);
    ESP07S_SSID_INFOList.clear();
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get ESP07 WIFI Connect Success ... time:%1").arg(commtime), 2000);
            if(0 == Recvbuff[15])
            {
                ui->label_LinkStatus_ESP07->setText("Disconnect");
            }else
            {
                char SSIDLIST[3000];
                int i = 0,j = 0;
                Recvbuff[recvLen-4] = '\0';
                memcpy(SSIDLIST,&Recvbuff[15],recvLen-17);
                //qDebug("%s",SSIDLIST);
                qDebug("11111111111111\n");
                for(i = 0;i<recvLen-4;i++)
                {
                    if(SSIDLIST[i] == '(')
                    {
                        for(j = i;j<recvLen-4;j++)
                        {
                            if(SSIDLIST[j] == ')')
                            {
                                char SSIDINFO[100];
                                QStringList SSIDlist;
                                memset(SSIDINFO,'\0',100);
                                memcpy(SSIDINFO,&SSIDLIST[i+1],(j-i));
                                SSIDINFO[j-i-1] = '\0';
                                QString SSIDListStr = SSIDINFO;
                                SSIDlist = SSIDListStr.replace("\"","").split(",");
                                qDebug("%s\n",SSIDINFO);
                                ESP07S_SSID_INFO *esp07s_ssid_info = new ESP07S_SSID_INFO;
                                esp07s_ssid_info->ecn = atoi(SSIDlist.value(0).toLatin1().data());
                                memset(esp07s_ssid_info->SSID,'\0',100);
                                memcpy(esp07s_ssid_info->SSID,SSIDlist.value(1).toLatin1().data(),SSIDlist.value(1).length());
                                esp07s_ssid_info->RSSI = atoi(SSIDlist.value(2).toLatin1().data());
                                memset(esp07s_ssid_info->MAC,'\0',20);
                                memcpy(esp07s_ssid_info->MAC,SSIDlist.value(3).toLatin1().data(),SSIDlist.value(3).length());
                                esp07s_ssid_info->CHANNEL = atoi(SSIDlist.value(4).toLatin1().data());
                                esp07s_ssid_info->offset = atoi(SSIDlist.value(5).toLatin1().data());
                                esp07s_ssid_info->calibration = atoi(SSIDlist.value(6).toLatin1().data());
                                ESP07S_SSID_INFOList.push_back(esp07s_ssid_info);
                                break;
                            }
                        }
                    }
                }
            }
        }
        addESP07SData(ui->tableWidget_SSID_ESP07S,ESP07S_SSID_INFOList);
        QList<ESP07S_SSID_INFO *>::Iterator iter = ESP07S_SSID_INFOList.begin();
        for ( ; iter != ESP07S_SSID_INFOList.end(); iter++)  {
            delete (*iter);
        }

    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_functionstatus_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Time[15] = {'\0'};
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280023%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {

            statusBar()->showMessage(tr("ECU Get Function Status Success ... time:%1").arg(commtime), 2000);
            if(Recvbuff[15] == '0')
            {
                ui->RSDstatus->setText("NO FUNCTION");
            }else if(Recvbuff[15] == '1')
            {
                ui->RSDstatus->setText("CLOSE");
            }else if(Recvbuff[15] == '2')
            {
                ui->RSDstatus->setText("OPEN");
            }else
            {
                ui->RSDstatus->setText("UNKNOWN");
            }
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}



void MainWindow::on_btn_SetServer_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;
    int index = 0;
    char Domain[100] = {'\0'};
    char Domain_Len_str[4] = {'\0'};
    int Domain_Len = 0;
    unsigned char IP[4] = {'\0'};
    unsigned short Port1 = 0;
    unsigned short Port2 = 0;
    unsigned short Port3 = 0;
    int sendlen = 0;

    memset(Recvbuff,0x00,4096);
    index = ui->comboBox_ServerItem->currentIndex()+1;
    Domain_Len = ui->lineEdit_Domain->text().length();

    memcpy(Domain,ui->lineEdit_Domain->text().toLatin1().data(),Domain_Len);
    Domain[Domain_Len] = '\0';
    IP[0] = (unsigned char )ui->lineEdit_Ip_1->text().toInt(); //IP 1
    IP[1] = (unsigned char )ui->lineEdit_Ip_2->text().toInt(); //IP 2
    IP[2] = (unsigned char )ui->lineEdit_Ip_3->text().toInt(); //IP 3
    IP[3] = (unsigned char )ui->lineEdit_Ip_4->text().toInt(); //IP 4
    Port1 = ui->lineEdit_Port1->text().toUShort();
    Port2 = ui->lineEdit_Port2->text().toUShort();
    Port3 = ui->lineEdit_Port3->text().toUShort();

    if((index == 1)||(index == 2)||(index == 3) || (index == 3) || (index == 7))
    {
        sprintf(Sendbuff,"APS1100300024%s%02dEND",ECUID,index);
        qDebug("%s",Sendbuff);
        sendlen = 30;
    }else if((index == 4)||(index == 5)||(index == 6))
    {
        sprintf(Sendbuff,"APS11%04d0024%s%02dEND%03d",(Domain_Len+46),ECUID,index,Domain_Len);
        memcpy(&Sendbuff[33],Domain,Domain_Len);
        Sendbuff[33+Domain_Len] = IP[0];
        Sendbuff[34+Domain_Len] = IP[1];
        Sendbuff[35+Domain_Len] = IP[2];
        Sendbuff[36+Domain_Len] = IP[3];
        Sendbuff[37+Domain_Len] = Port1/256;
        Sendbuff[38+Domain_Len] = Port1%256;
        Sendbuff[39+Domain_Len] = Port2/256;
        Sendbuff[40+Domain_Len] = Port2%256;
        Sendbuff[41+Domain_Len] = Port3/256;
        Sendbuff[42+Domain_Len] = Port3%256;
        Sendbuff[43+Domain_Len] = 'E';
        Sendbuff[44+Domain_Len] = 'N';
        Sendbuff[45+Domain_Len] = 'D';
        qDebug("%s",Sendbuff);
        sendlen = (Domain_Len+46);
    }else
    {
        sprintf(Sendbuff,"APS11%04d0024%s%02dEND%03d",(Domain_Len+46),ECUID,index,Domain_Len);
        memcpy(&Sendbuff[33],Domain,Domain_Len);
        Sendbuff[33+Domain_Len] = IP[0];
        Sendbuff[34+Domain_Len] = IP[1];
        Sendbuff[35+Domain_Len] = IP[2];
        Sendbuff[36+Domain_Len] = IP[3];
        Sendbuff[37+Domain_Len] = Port1/256;
        Sendbuff[38+Domain_Len] = Port1%256;
        Sendbuff[39+Domain_Len] = Port2/256;
        Sendbuff[40+Domain_Len] = Port2%256;
        Sendbuff[41+Domain_Len] = Port3/256;
        Sendbuff[42+Domain_Len] = Port3%256;
        if(ui->comboBox_trina->currentIndex() == 0)
        {
            Sendbuff[43+Domain_Len] = '0';
        }else
        {
            Sendbuff[43+Domain_Len] = '1';
        }
        Sendbuff[44+Domain_Len] = 'E';
        Sendbuff[45+Domain_Len] = 'N';
        Sendbuff[46+Domain_Len] = 'D';
        qDebug("%s",Sendbuff);
        sendlen = (Domain_Len+47);
    }

    flag = ECU_Client->ECU_Communication(Sendbuff,sendlen,Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            if((index == 1)||(index == 2)||(index == 3))
            {
                //Domain
                memcpy(Domain_Len_str,&Recvbuff[17],3);
                Domain_Len =atoi(Domain_Len_str);
                memcpy(Domain,&Recvbuff[20],Domain_Len);
                //IP
                IP[0] = Recvbuff[20+Domain_Len];
                IP[1] = Recvbuff[21+Domain_Len];
                IP[2] = Recvbuff[22+Domain_Len];
                IP[3] = Recvbuff[23+Domain_Len];
                //Port1
                Port1 = (Recvbuff[24+Domain_Len]& 0x000000ff)*256 + (Recvbuff[25+Domain_Len]& 0x000000ff);
                //Port2
                Port2 = (Recvbuff[26+Domain_Len]& 0x000000ff)*256 + (Recvbuff[27+Domain_Len]& 0x000000ff);
                //Port3
                Port3 = (Recvbuff[28+Domain_Len]& 0x000000ff)*256 + (Recvbuff[29+Domain_Len]& 0x000000ff);

                ui->lineEdit_Domain->setText(Domain);
                ui->lineEdit_Ip_1->setText(QString::number(IP[0]));
                ui->lineEdit_Ip_2->setText(QString::number(IP[1]));
                ui->lineEdit_Ip_3->setText(QString::number(IP[2]));
                ui->lineEdit_Ip_4->setText(QString::number(IP[3]));
                ui->lineEdit_Port1->setText(QString::number(Port1));
                ui->lineEdit_Port2->setText(QString::number(Port2));
                ui->lineEdit_Port3->setText(QString::number(Port3));
                statusBar()->showMessage(tr("ECU Get Server Info Success ... time:%1").arg(commtime), 2000);

            }else if(index == 7)
            {
                //Domain
                memcpy(Domain_Len_str,&Recvbuff[17],3);
                Domain_Len =atoi(Domain_Len_str);
                memcpy(Domain,&Recvbuff[20],Domain_Len);
                //IP
                IP[0] = Recvbuff[20+Domain_Len];
                IP[1] = Recvbuff[21+Domain_Len];
                IP[2] = Recvbuff[22+Domain_Len];
                IP[3] = Recvbuff[23+Domain_Len];
                //Port1
                Port1 = (Recvbuff[24+Domain_Len]& 0x000000ff)*256 + (Recvbuff[25+Domain_Len]& 0x000000ff);
                //Port2
                Port2 = (Recvbuff[26+Domain_Len]& 0x000000ff)*256 + (Recvbuff[27+Domain_Len]& 0x000000ff);
                //Port3
                Port3 = (Recvbuff[28+Domain_Len]& 0x000000ff)*256 + (Recvbuff[29+Domain_Len]& 0x000000ff);

                ui->lineEdit_Domain->setText(Domain);
                ui->lineEdit_Ip_1->setText(QString::number(IP[0]));
                ui->lineEdit_Ip_2->setText(QString::number(IP[1]));
                ui->lineEdit_Ip_3->setText(QString::number(IP[2]));
                ui->lineEdit_Ip_4->setText(QString::number(IP[3]));
                ui->lineEdit_Port1->setText(QString::number(Port1));
                ui->lineEdit_Port2->setText(QString::number(Port2));
                ui->lineEdit_Port3->setText(QString::number(Port3));
                if(Recvbuff[30+Domain_Len] == '1')
                {
                    ui->comboBox_trina->setCurrentIndex(1);
                }else
                {
                    ui->comboBox_trina->setCurrentIndex(0);
                }
                statusBar()->showMessage(tr("ECU Get Server Info Success ... time:%1").arg(commtime), 2000);

            }
            else
            {
                statusBar()->showMessage(tr("ECU Set Server Info Success ... time:%1").arg(commtime), 2000);
            }

        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }

}

void MainWindow::on_btn_setFunction_open_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[8];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_RSDID->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_RSDID->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,7);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = (0x01)&0x000000ff;

        memcpy(&ID_BCD_List[index*7],ID_BCD,7);
    }

    sprintf(Sendbuff,"APS1100000016%s2END",ECUID);
    memcpy(&Sendbuff[29],ID_BCD_List,(OPTCount*7));
    Sendbuff[OPTCount*7+29] = 'E';
    Sendbuff[OPTCount*7+30] = 'N';
    Sendbuff[OPTCount*7+31] = 'D';

    sprintf(packlength,"%04d",(OPTCount*7+32));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set RSD Open Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_setFunction_close_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[8];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_RSDID->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_RSDID->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,7);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = (0x00)&0x000000ff;

        memcpy(&ID_BCD_List[index*7],ID_BCD,7);
    }

    sprintf(Sendbuff,"APS1100000016%s2END",ECUID);
    memcpy(&Sendbuff[29],ID_BCD_List,(OPTCount*7));
    Sendbuff[OPTCount*7+29] = 'E';
    Sendbuff[OPTCount*7+30] = 'N';
    Sendbuff[OPTCount*7+31] = 'D';

    sprintf(packlength,"%04d",(OPTCount*7+32));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set RSD Close Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::addRSDStatusData(QTableWidget *table, QList<RSDStatus_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<RSDStatus_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText(QString::number((unsigned char)(*iter)->function));

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}

void MainWindow::on_btn_getRSDStatus_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100290016%s3END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,29,Recvbuff,&recvLen,2000,&commtime);
    RSDStatus_List.clear();
    if(flag == true)
    {
        ui->tableWidget_RSDStatus->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_RSDStatus->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get RSD Function Data Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-18)/7;
            length = 15;
            for(index = 0;index < num;index++)
            {
                RSDStatus_t *RSDStatus = new RSDStatus_t;
                sprintf(RSDStatus->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                RSDStatus->function = (Recvbuff[length+6] & 0x000000ff);
                RSDStatus_List.push_back(RSDStatus);
                length += 7;
            }
            addRSDStatusData(ui->tableWidget_RSDStatus,RSDStatus_List);

            QList<RSDStatus_t *>::Iterator iter = RSDStatus_List.begin();
            for ( ; iter != RSDStatus_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_RSDStatus->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_RSDStatus->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }

}

void MainWindow::addRSSIData(QTableWidget *table, QList<RSSI_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<RSSI_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText(QString::number((unsigned char)(*iter)->RSSI));

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}

void MainWindow::on_btn_RSSI_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100290030%s3END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,29,Recvbuff,&recvLen,2000,&commtime);
    RSSI_List.clear();
    if(flag == true)
    {
        ui->tableWidget_RSSI->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_RSSI->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get RSD Function Data Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-18)/7;
            length = 15;
            for(index = 0;index < num;index++)
            {
                RSSI_t *RSSI = new RSSI_t;
                sprintf(RSSI->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                RSSI->RSSI = (Recvbuff[length+6] & 0x000000ff);
                RSSI_List.push_back(RSSI);
                length += 7;
            }
            addRSSIData(ui->tableWidget_RSSI,RSSI_List);

            QList<RSSI_t *>::Iterator iter = RSSI_List.begin();
            for ( ; iter != RSSI_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_RSSI->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_RSSI->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_ClearEnergy_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100290031%s3END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,29,Recvbuff,&recvLen,2000,&commtime);

    if(flag == true)
    {

        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Clear Energy Data Success ... time:%1").arg(commtime), 2000);
        }


    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_InternalVersion_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("Internal_version",16,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_InternalVersion->setText(Recvbuff);
        statusBar()->showMessage(tr("Get Internal Version Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_InternalVersion->setText("Get Internal Version failed");
        statusBar()->showMessage(tr("Get Internal Version failed ..."), 2000);
    }
}

void MainWindow::on_btn_Flash_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("get_flash",9,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_Flash->setText(Recvbuff);
        statusBar()->showMessage(tr("Get Flash Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_Flash->setText("Get Flash failed");
        statusBar()->showMessage(tr("Get Flash failed ..."), 2000);
    }
}

void MainWindow::on_btn_reboot_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    int commtime = 0;

    memset(Recvbuff,0x00,4096);
    flag = IDWrite_Client->IDWrite_Communication("reboot",6,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        ui->label_reboot->setText(Recvbuff);
        statusBar()->showMessage(tr("Reboot Success ... time:%1").arg(commtime), 2000);
    }else
    {
        ui->label_reboot->setText("Reboot failed");
        statusBar()->showMessage(tr("Reboot failed ..."), 2000);
    }
}

void MainWindow::on_btn_update_ver_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    char Sendbuff[4096] = {'\0'};
    int commtime = 0;
    char IP[30] = {'\0'};
    char port[10] = {'\0'};
    char user[30] = {'\0'};
    char passwd[30] = {'\0'};
    memset(Recvbuff,0x00,4096);
    memcpy(IP,ui->lineEdit_UpdateIP->text().toLatin1(),ui->lineEdit_UpdateIP->text().length());
    memcpy(port,ui->lineEdit_UpdatePort->text().toLatin1(),ui->lineEdit_UpdatePort->text().length());
    memcpy(user,ui->lineEdit_UpdateUser->text().toLatin1(),ui->lineEdit_UpdateUser->text().length());
    memcpy(passwd,ui->lineEdit_UpdatePasswd->text().toLatin1(),ui->lineEdit_UpdatePasswd->text().length());
    sprintf(Sendbuff,"update VER %s %s %s %s",IP,port,user,passwd);
    flag = IDWrite_Client->IDWrite_Communication(Sendbuff,strlen(Sendbuff),Recvbuff,&recvLen,25000,&commtime);
    if(flag == true)
    {

        ui->label_update->setText(Recvbuff);
        statusBar()->showMessage(Recvbuff, 2000);
    }else
    {
        ui->label_reboot->setText("Update failed");
        statusBar()->showMessage(tr("Update failed ..."), 2000);
    }
}

void MainWindow::on_btn_update_ID_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Recvbuff[4096] = {'\0'};
    char Sendbuff[4096] = {'\0'};
    int commtime = 0;
    char IP[30] = {'\0'};
    char port[10] = {'\0'};
    char user[30] = {'\0'};
    char passwd[30] = {'\0'};
    memset(Recvbuff,0x00,4096);
    memcpy(IP,ui->lineEdit_UpdateIP->text().toLatin1(),ui->lineEdit_UpdateIP->text().length());
    memcpy(port,ui->lineEdit_UpdatePort->text().toLatin1(),ui->lineEdit_UpdatePort->text().length());
    memcpy(user,ui->lineEdit_UpdateUser->text().toLatin1(),ui->lineEdit_UpdateUser->text().length());
    memcpy(passwd,ui->lineEdit_UpdatePasswd->text().toLatin1(),ui->lineEdit_UpdatePasswd->text().length());
    sprintf(Sendbuff,"update ID %s %s %s %s",IP,port,user,passwd);
    flag = IDWrite_Client->IDWrite_Communication(Sendbuff,strlen(Sendbuff),Recvbuff,&recvLen,25000,&commtime);
    if(flag == true)
    {

        ui->label_update->setText(Recvbuff);
        statusBar()->showMessage(Recvbuff, 2000);
    }else
    {
        ui->label_reboot->setText("Update failed");
        statusBar()->showMessage(tr("Update failed ..."), 2000);
    }
}

void MainWindow::addTurnOnOffData(QTableWidget *table, QList<TurnOnOff_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<TurnOnOff_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText((*iter)->turnonoff);

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}

void MainWindow::on_btn_getSetTurnOnOff_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100300026%s01END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,30,Recvbuff,&recvLen,2000,&commtime);
    TurnOnOff_List.clear();
    if(flag == true)
    {
        ui->tableWidget_SetTurnOnOff->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_SetTurnOnOff->clearContents();
        if(Recvbuff[16] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get RSD Function Data Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-20)/7;
            length = 17;
            for(index = 0;index < num;index++)
            {
                TurnOnOff_t *TurnOnOff = new TurnOnOff_t;
                sprintf(TurnOnOff->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                TurnOnOff->turnonoff[0] = (Recvbuff[length+6] & 0x000000ff);
                TurnOnOff->turnonoff[1] = '\0';
                TurnOnOff_List.push_back(TurnOnOff);
                length += 7;
            }
            addTurnOnOffData(ui->tableWidget_SetTurnOnOff,TurnOnOff_List);

            QList<TurnOnOff_t *>::Iterator iter = TurnOnOff_List.begin();
            for ( ; iter != TurnOnOff_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_SetTurnOnOff->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_SetTurnOnOff->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_SetTurnOnOff_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[8192] = {'\0'};
    int select_item = 0;
    memset(Recvbuff,0x00,8192);

    select_item = ui->comboBox_SetTurnOnOff->currentIndex();
    qDebug("select_item:%d\n",select_item);
    //先判断是关闭  还是开启
    if(select_item == 0)
    {   //广播开机
        sprintf((char *)Sendbuff,"APS1100340026%s02END0END",ECUID);
    }else if(select_item == 1)
    {   //广播关机
        sprintf((char *)Sendbuff,"APS1100340026%s02END1END",ECUID);
    }

    flag = ECU_Client->ECU_Communication((char *)Sendbuff,34,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[15],"00",2))
        {
            statusBar()->showMessage(tr("Set TurnOnOff Success ... time:%1 ms").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set TurnOnOff Function Failed ... time:%1 ms").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::on_btn_SetTurnOnOff_Open_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[8];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_SetTurnOnOff->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_SetTurnOnOff->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,7);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = '0';

        memcpy(&ID_BCD_List[index*7],ID_BCD,7);
    }

    sprintf(Sendbuff,"APS1100000026%s03END",ECUID);
    memcpy(&Sendbuff[30],ID_BCD_List,(OPTCount*7));
    Sendbuff[OPTCount*7+30] = 'E';
    Sendbuff[OPTCount*7+31] = 'N';
    Sendbuff[OPTCount*7+32] = 'D';

    sprintf(packlength,"%04d",(OPTCount*7+33));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Turn ON OFF Open Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_SetTurnOnOff_Close_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[8];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_SetTurnOnOff->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_SetTurnOnOff->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,7);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = '1';

        memcpy(&ID_BCD_List[index*7],ID_BCD,7);
    }

    sprintf(Sendbuff,"APS1100000026%s03END",ECUID);
    memcpy(&Sendbuff[30],ID_BCD_List,(OPTCount*7));
    Sendbuff[OPTCount*7+30] = 'E';
    Sendbuff[OPTCount*7+31] = 'N';
    Sendbuff[OPTCount*7+32] = 'D';

    sprintf(packlength,"%04d",(OPTCount*7+33));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Turn ON OFF Open Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::addGFDIData(QTableWidget *table, QList<GFDI_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<GFDI_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText((*iter)->GFDI);

        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
    }
}

void MainWindow::on_btn_getClearGFDI_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100300027%s01END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,30,Recvbuff,&recvLen,2000,&commtime);
    GFDI_List.clear();
    if(flag == true)
    {
        ui->tableWidget_ClearGFDI->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_ClearGFDI->clearContents();
        if(Recvbuff[16] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get GFDI Data Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-20)/7;
            length = 17;
            for(index = 0;index < num;index++)
            {
                GFDI_t *GFDI = new GFDI_t;
                sprintf(GFDI->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                GFDI->GFDI[0] = (Recvbuff[length+6] & 0x000000ff);
                GFDI->GFDI[1] = '\0';
                GFDI_List.push_back(GFDI);
                length += 7;
            }
            addGFDIData(ui->tableWidget_ClearGFDI,GFDI_List);

            QList<GFDI_t *>::Iterator iter = GFDI_List.begin();
            for ( ; iter != GFDI_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_ClearGFDI->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_ClearGFDI->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_ClearGFDI_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[8];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_ClearGFDI->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_ClearGFDI->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,7);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = '1';

        memcpy(&ID_BCD_List[index*7],ID_BCD,7);
    }

    sprintf(Sendbuff,"APS1100000027%s02END",ECUID);
    memcpy(&Sendbuff[30],ID_BCD_List,(OPTCount*7));
    Sendbuff[OPTCount*7+30] = 'E';
    Sendbuff[OPTCount*7+31] = 'N';
    Sendbuff[OPTCount*7+32] = 'D';

    sprintf(packlength,"%04d",(OPTCount*7+33));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Clear GFDI Open Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_MaxPower_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[8192] = {'\0'};
    int maxpower = 0;
    unsigned char maxPowerStr[2] = {'\0'};
    memset(Recvbuff,0x00,8192);

    maxpower = ui->lineEdit_MaxPower->text().toInt();
    maxPowerStr[0] = maxpower/256;
    maxPowerStr[1] = maxpower%256;

    sprintf((char *)Sendbuff,"APS1100350025%s02END",ECUID);
    memcpy((char *)&Sendbuff[30],maxPowerStr,2);
    memcpy((char *)&Sendbuff[32],"END",3);
    flag = ECU_Client->ECU_Communication((char *)Sendbuff,35,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[15],"00",2))
        {
            statusBar()->showMessage(tr("Set maxPower Success ... time:%1 ms").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set maxPower Function Failed ... time:%1 ms").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::on_btn_SetMaxPower_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[9];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int maxpower = 0;
    int length = ui->plainTextEdit_SeMaxPower->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_SeMaxPower->toPlainText().toLatin1().data(),length);

    maxpower = ui->lineEdit_MaxPower_2->text().toInt();

    qDebug("%d\n",maxpower);
    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,8);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = maxpower/256;
        ID_BCD[7] = maxpower%256;
        memcpy(&ID_BCD_List[index*8],ID_BCD,8);
    }

    sprintf(Sendbuff,"APS1100000025%s03END",ECUID);
    memcpy(&Sendbuff[30],ID_BCD_List,(OPTCount*8));
    Sendbuff[OPTCount*8+30] = 'E';
    Sendbuff[OPTCount*8+31] = 'N';
    Sendbuff[OPTCount*8+32] = 'D';

    sprintf(packlength,"%04d",(OPTCount*8+33));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Max Power Open Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_MaxPower_get_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[8192] = {'\0'};
    memset(Recvbuff,0x00,8192);


    sprintf((char *)Sendbuff,"APS1100300025%s04END",ECUID);

    flag = ECU_Client->ECU_Communication((char *)Sendbuff,35,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[15],"00",2))
        {
            statusBar()->showMessage(tr("Get maxPower Success ... time:%1 ms").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Get maxPower Failed ... time:%1 ms").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::addMaxPowerData(QTableWidget *table, QList<MaxPower_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<MaxPower_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText(QString::number((*iter)->limitedpower));
        item2->setText(QString::number((*iter)->limitedresult));


        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));
        item2->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
    }
}


void MainWindow::on_btn_getMaxPower_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100300025%s01END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,30,Recvbuff,&recvLen,2000,&commtime);
    MaxPower_List.clear();

    if(flag == true)
    {
        ui->tableWidget_MaxPower->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_MaxPower->clearContents();
        if(Recvbuff[16] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Max Power Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-20)/10;
            length = 17;
            for(index = 0;index < num;index++)
            {
                MaxPower_t *MaxPower = new MaxPower_t;
                sprintf(MaxPower->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                MaxPower->limitedpower = (Recvbuff[length+6] & 0x000000ff)*256 + (Recvbuff[length+7] & 0x000000ff);
                MaxPower->limitedresult = (Recvbuff[length+8] & 0x000000ff)*256 + (Recvbuff[length+9] & 0x000000ff);
                MaxPower_List.push_back(MaxPower);
                length += 10;
            }
            addMaxPowerData(ui->tableWidget_MaxPower,MaxPower_List);

            QList<MaxPower_t *>::Iterator iter = MaxPower_List.begin();
            for ( ; iter != MaxPower_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_MaxPower->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_MaxPower->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_IRD_get_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[8192] = {'\0'};
    memset(Recvbuff,0x00,8192);


    sprintf((char *)Sendbuff,"APS1100300028%s04END",ECUID);

    flag = ECU_Client->ECU_Communication((char *)Sendbuff,35,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[15],"00",2))
        {
            statusBar()->showMessage(tr("Get IRD Success ... time:%1 ms").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Get IRD Failed ... time:%1 ms").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::on_btn_IRD_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    int commtime = 0;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[8192] = {'\0'};
    unsigned char ird = 0;
    memset(Recvbuff,0x00,8192);

    ird = ui->comboBox_IRDALL->currentIndex()+1;


    sprintf((char *)Sendbuff,"APS1100350028%s02END",ECUID);
    Sendbuff[30] = ird;
    memcpy((char *)&Sendbuff[31],"END",3);
    flag = ECU_Client->ECU_Communication((char *)Sendbuff,34,(char *)Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[15],"00",2))
        {
            statusBar()->showMessage(tr("Set IRD ALL Success ... time:%1 ms").arg(commtime), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set IRD ALL Failed ... time:%1 ms").arg(commtime), 1000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 1000);
    }
}

void MainWindow::on_btn_SetIRD_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[4096];
    char Recvbuff[200] = {'\0'};
    char ID_BCD[9];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int ird = 0;
    int length = ui->plainTextEdit_IRD->toPlainText().length();
    OPTCount = (length + 1)/13;
    memcpy(text,ui->plainTextEdit_IRD->toPlainText().toLatin1().data(),length);

    ird = ui->comboBox_IRD->currentIndex()+1;

    qDebug("%d\n",ird);
    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,8);
        ID_BCD[0] = ((text[0+index*13]&0x000000ff)-'0')*16+((text[1+index*13]&0x000000ff)-'0');
        ID_BCD[1] = ((text[2+index*13]&0x000000ff)-'0')*16+((text[3+index*13]&0x000000ff)-'0');
        ID_BCD[2] = ((text[4+index*13]&0x000000ff)-'0')*16+((text[5+index*13]&0x000000ff)-'0');
        ID_BCD[3] = ((text[6+index*13]&0x000000ff)-'0')*16+((text[7+index*13]&0x000000ff)-'0');
        ID_BCD[4] = ((text[8+index*13]&0x000000ff)-'0')*16+((text[9+index*13]&0x000000ff)-'0');
        ID_BCD[5] = ((text[10+index*13]&0x000000ff)-'0')*16+((text[11+index*13]&0x000000ff)-'0');
        ID_BCD[6] = ird;
        memcpy(&ID_BCD_List[index*7],ID_BCD,7);
    }

    sprintf(Sendbuff,"APS1100000028%s03END",ECUID);
    memcpy(&Sendbuff[30],ID_BCD_List,(OPTCount*7));
    Sendbuff[OPTCount*7+30] = 'E';
    Sendbuff[OPTCount*7+31] = 'N';
    Sendbuff[OPTCount*7+32] = 'D';

    sprintf(packlength,"%04d",(OPTCount*7+33));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    int commtime = 0;
    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*7+32),Recvbuff,&recvLen,3000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set IRD Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::addIRDData(QTableWidget *table, QList<IRD_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<IRD_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText(QString::number((*iter)->IRD));
        item2->setText(QString::number((*iter)->IRDresult));


        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));
        item2->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
    }
}

void MainWindow::on_btn_geIRD_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100300028%s01END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,30,Recvbuff,&recvLen,2000,&commtime);
    IRD_List.clear();

    if(flag == true)
    {
        ui->tableWidget_IRD->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_IRD->clearContents();
        if(Recvbuff[16] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get IRD Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-20)/8;
            length = 17;
            for(index = 0;index < num;index++)
            {
                IRD_t *IRD = new IRD_t;
                sprintf(IRD->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                IRD->IRD = (Recvbuff[length+6] & 0x000000ff);
                IRD->IRDresult = (Recvbuff[length+7] & 0x000000ff);
                IRD_List.push_back(IRD);
                length += 8;
            }
            addIRDData(ui->tableWidget_IRD,IRD_List);

            QList<IRD_t *>::Iterator iter = IRD_List.begin();
            for ( ; iter != IRD_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_IRD->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_IRD->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::addAlarmEventData(QTableWidget *table, QList<AlarmEvent_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<AlarmEvent_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText((*iter)->Time);
        item2->setText((*iter)->Event);


        item->setBackgroundColor(QColor(0,238,0));
        item1->setBackgroundColor(QColor(0,238,0));
        item2->setBackgroundColor(QColor(0,238,0));

        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
    }
}

void MainWindow::on_btn_alarmevent_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0,i=0;
    int year = ui->dateEdit_alarm->date().year();
    int month = ui->dateEdit_alarm->date().month();
    int day = ui->dateEdit_alarm->date().day();
    int serial =ui->spinBox_alarm->value();
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100420032%sEND%04d%02d%02d%03dEND",ECUID,year,month,day,serial);
    flag = ECU_Client->ECU_Communication(Sendbuff,42,Recvbuff,&recvLen,10000,&commtime);
    AlarmEvent_List.clear();

    if(flag == true)
    {
        ui->tableWidget_alarmEvent->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_alarmEvent->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Alarm Event Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-18)/17;
            length = 15;
            for(index = 0;index < num;index++)
            {
                AlarmEvent_t *AlarmEvent = new AlarmEvent_t;
                sprintf(AlarmEvent->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length]& 0x000000ff),(Recvbuff[length+1]& 0x000000ff),(Recvbuff[length+2]& 0x000000ff),(Recvbuff[length+3]& 0x000000ff),(Recvbuff[length+4]& 0x000000ff),(Recvbuff[length+5]& 0x000000ff));
                sprintf(AlarmEvent->Time,"%02x:%02x:%02x",(Recvbuff[length+6]& 0x000000ff),(Recvbuff[length+7]& 0x000000ff),(Recvbuff[length+8]& 0x000000ff));
                for(i = 0;i<64;i++)
                {
                    AlarmEvent->Event[i] =(((Recvbuff[length+9 + (i/8)]& 0x000000ff)&(0x01 <<(7-i%8)))>>(7-i%8)) + '0';
                }
                AlarmEvent->Event[64] = '\0';
                AlarmEvent_List.push_back(AlarmEvent);
                length += 17;
            }
            addAlarmEventData(ui->tableWidget_alarmEvent,AlarmEvent_List);

            QList<AlarmEvent_t *>::Iterator iter = AlarmEvent_List.begin();
            for ( ; iter != AlarmEvent_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_alarmEvent->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_alarmEvent->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_tableWidget_alarmEvent_itemClicked(QTableWidgetItem *item)
{
    QString UID;
    QString Time;
    char Event[64] = {'0'};
    QString string;
    UID = ui->tableWidget_alarmEvent->item(item->row(),0)->text();
    Time = ui->tableWidget_alarmEvent->item(item->row(),1)->text();
    memcpy(Event,ui->tableWidget_alarmEvent->item(item->row(),2)->text().toLatin1().data(),ui->tableWidget_alarmEvent->item(item->row(),2)->text().length());
    string = "UID:"+UID + "\n" + "Time:" + Time + "\n";
    if(Event[0] == '1')
    {
        string+="AC Frequency Exceeding Range\n";
    }

    if(Event[1] == '1')
    {
        string+= "AC Frequency Under Range\n";
    }

    if(Event[2] == '1')
    {
        string+= "Channel A: AC Voltage Exceeding Range\n";
    }

    if(Event[3] == '1')
    {
        string+= "Channel A: AC Voltage Under Range\n";
    }

    if(Event[4] == '1')
    {
        string+= "Channel B: AC Voltage Exceeding Range\n";
    }

    if(Event[5] == '1')
    {
        string+= "Channel B: AC Voltage Under Range\n";
    }

    if(Event[6] == '1')
    {
        string+= "Channel C: AC Voltage Exceeding Range\n";
    }

    if(Event[7] == '1')
    {
        string+= "Channel C: AC Voltage Under Range\n";
    }

    if(Event[8] == '1')
    {
        string+= "Channel A: DC Voltage Too High\n";
    }

    if(Event[9] == '1')
    {
        string+= "Channel A: DC Voltage Too Low\n";
    }

    if(Event[10] == '1')
    {
        string+= "Channel B: DC Voltage Too High\n";
    }

    if(Event[11] == '1')
    {
        string+= "Channel B: DC Voltage Too Low\n";
    }

    if(Event[16] == '1')
    {
        string+= "Over Critical Temperature\n";
    }

    if(Event[17] == '1')
    {
        string+= "GFDI Locked\n";
    }

    if(Event[18] == '1')
    {
        string+= "Remote Shut\n";
    }

    if(Event[19] == '1')
    {
        string+= "AC Disconnect\n";
    }

    if(Event[21] == '1')
    {
        string+= "Active Anti-island Protection\n";
    }

    if(Event[22] == '1')
    {
        string+= "CP Protection\n";
    }

    if(Event[23] == '1')
    {
        string+= "AC Voltage Exceeding Range\n";
    }

    if(Event[24] == '1')
    {
        string+= "AC Voltage Under Range\n";
    }

    if(Event[25] == '1')
    {
        string+= "10min Protect\n";
    }

    if(Event[26] == '1')
    {
        string+= "BUS Voltage Too Low\n";
    }

    if(Event[27] == '1')
    {
        string+= "BUS Voltage Too High\n";
    }

    if(Event[28] == '1')
    {
        string+= "Relay Failed\n";
    }
    if(Event[29] == '1')
    {
        string+= "AC Frequency_stage1 Exceeding Range\n";
    }
    if(Event[30] == '1')
    {
        string+= "AC Frequency_stage1 Under Range\n";
    }
    if(Event[31] == '1')
    {
        string+= "AC Frequency_stage2 Exceeding Range\n";
    }
    if(Event[32] == '1')
    {
        string+= "AC Frequency_stage2 Under Range\n";
    }
    if(Event[33] == '1')
    {
        string+= "AC Voltage_stage1 Exceeding Range\n";
    }
    if(Event[34] == '1')
    {
        string+= "AC Voltage_stage1 Under Range\n";
    }
    if(Event[35] == '1')
    {
        string+= "AC Voltage_stage1 Exceeding Range\n";
    }
    if(Event[36] == '1')
    {
        string+= "AC Voltage_stage1 Under Range\n";
    }if(Event[37] == '1')
    {
        string+= "AC Voltage_stage1 Exceeding Range\n";
    }
    if(Event[38] == '1')
    {
        string+= "AC Voltage_stage1 Under Range\n";
    }
    if(Event[39] == '1')
    {
        string+= "Channel C: DC Voltage Too High\n";
    }
    if(Event[40] == '1')
    {
        string+= "Channel C: DC Voltage Too Low\n";
    }
    if(Event[41] == '1')
    {
        string+= "Channel D: DC Voltage Too High\n";
    }
    if(Event[42] == '1')
    {
        string+= "Channel D: DC Voltage Too Low\n";
    }
    if(Event[43] == '1')
    {
        string+= "Get Data Failed  ";
    }
    ui->textBrowser_alarmEvent->clear();
    ui->textBrowser_alarmEvent->setText(string);
}

void MainWindow::on_comboBox_factor_currentIndexChanged(int index)
{
    //
    if(0 == index)
    {
        ui->comboBox_type->clear();
        ui->comboBox_type->addItem("01:30KTL-M");
        ui->comboBox_type->addItem("02:33KTL-M");
        ui->comboBox_type->addItem("03:36KTL-M");
        ui->comboBox_type->addItem("04:40KTL-M");
        ui->comboBox_type->addItem("05:50KTL-M");
        ui->comboBox_type->addItem("06:60KTL-M");
        ui->comboBox_type->addItem("07:60KU-M");
        ui->comboBox_type->addItem("08:49K5J");
        ui->comboBox_type->addItem("09:8KTL-M");
        ui->comboBox_type->addItem("10:10KTL-M");
        ui->comboBox_type->addItem("11:12KTL-M");
        ui->comboBox_type->addItem("12:80KTL");
        ui->comboBox_type->addItem("13:80KTL-M");
        ui->comboBox_type->addItem("14:80HV");
        ui->comboBox_type->addItem("15:125HV");
        ui->comboBox_type->addItem("16:60KTL");
        ui->comboBox_type->addItem("17:60KU");


    }else if(1 == index)
    {
        ui->comboBox_type->clear();
        ui->comboBox_type->addItem("01:SA Third");
    }


}

void MainWindow::on_btn_addThird_clicked()
{
    char ThirdID[32],ThirdFactor[20],ThirdType[20],BaudRate[20];
    int ModbusAddr = 0,row_count=0;

    QTableWidgetItem *item = new QTableWidgetItem();
    QTableWidgetItem *item1 = new QTableWidgetItem();
    QTableWidgetItem *item2 = new QTableWidgetItem();
    QTableWidgetItem *item3 = new QTableWidgetItem();
    QTableWidgetItem *item4 = new QTableWidgetItem();

    memcpy(ThirdID,ui->lineEdit_thirdID->text().toLatin1().data(),ui->lineEdit_thirdID->text().length());
    ThirdID[ui->lineEdit_thirdID->text().length()] = '\0';
    memcpy(ThirdFactor,ui->comboBox_factor->currentText().toLatin1().data(),ui->comboBox_factor->currentText().length());

    memcpy(ThirdFactor,&ThirdFactor[3],5);
    ThirdFactor[5] = '\0';
    memcpy(ThirdType,&ui->comboBox_type->currentText().toLatin1().data()[3],ui->comboBox_type->currentText().length()-3);
    ThirdType[ui->comboBox_type->currentText().length()-3] = '\0';

    memcpy(BaudRate,ui->comboBox_BaudRate->currentText().toLatin1().data(),ui->comboBox_BaudRate->currentText().length());
    BaudRate[ui->comboBox_BaudRate->currentText().length()] = '\0';

    ModbusAddr = ui->spinBox_third->value();
    row_count = ui->tableWidget_thirdID->rowCount(); //获取表单行数
    ui->tableWidget_thirdID->insertRow(row_count); //插入新行

    item->setText(ThirdID);
    item1->setText(QString::number(ModbusAddr));
    item2->setText(ThirdFactor);
    item3->setText(ThirdType);
    item4->setText(BaudRate);
    //qDebug("%s %s %s %d %d\n",ThirdID,ThirdFactor,ThirdType,ModbusAddr,row_count);

    ui->tableWidget_thirdID->setItem(row_count, 0, item);
    ui->tableWidget_thirdID->setItem(row_count, 1, item1);
    ui->tableWidget_thirdID->setItem(row_count, 2, item2);
    ui->tableWidget_thirdID->setItem(row_count, 3, item3);
    ui->tableWidget_thirdID->setItem(row_count, 4, item4);
    statusBar()->showMessage(tr("Add Third ID Successful ..."), 2000);
}

void MainWindow::on_btn_clearthirdID_clicked()
{
    ui->tableWidget_thirdID->setRowCount(0);
    //清空Table中内容
    ui->tableWidget_thirdID->clearContents();
    statusBar()->showMessage(tr("Clear Third ID Successful ..."), 2000);
}

void MainWindow::addThirdID(QTableWidget *table, QList<ThirdID_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<ThirdID_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();

        item->setText((*iter)->ID);
        item1->setText(QString::number((*iter)->modbusAddr));
        item2->setText((*iter)->Factor);
        item3->setText((*iter)->Type);
        if((*iter)->BaudRate == 1)
        {
            item4->setText("01:1200");
        }else if((*iter)->BaudRate == 2)
        {
            item4->setText("02:2400");
        }else if((*iter)->BaudRate == 3)
        {
            item4->setText("03:4800");
        }else if((*iter)->BaudRate == 4)
        {
            item4->setText("04:9600");
        }else if((*iter)->BaudRate == 5)
        {
            item4->setText("05:14400");
        }else if((*iter)->BaudRate == 6)
        {
            item4->setText("06:19200");
        }else if((*iter)->BaudRate == 7)
        {
            item4->setText("07:38400");
        }else if((*iter)->BaudRate == 8)
        {
            item4->setText("08:56000");
        }else if((*iter)->BaudRate == 9)
        {
            item4->setText("09:57600");
        }else if((*iter)->BaudRate == 10)
        {
            item4->setText("10:115200");
        }else if((*iter)->BaudRate == 11)
        {
            item4->setText("11:128000");
        }else if((*iter)->BaudRate == 12)
        {
            item4->setText("12:256000");
        }else
        {
            item4->setText("UNKNOWN");
        }



        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
        table->setItem(row_count, 3, item3);
        table->setItem(row_count, 4, item4);
    }
}

void MainWindow::on_btn_getthirdID_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    int num = 0;
    int commtime = 0,i=0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100300033%s02END",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,30,Recvbuff,&recvLen,2000,&commtime);
    ThirdID_List.clear();

    if(flag == true)
    {
        ui->tableWidget_thirdID->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_thirdID->clearContents();
        if(Recvbuff[16] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Third ID Success ... time:%1").arg(commtime), 2000);
            num = (recvLen-20)/53;
            length = 17;
            for(index = 0;index < num;index++)
            {
                ThirdID_t *ThirdID = new ThirdID_t;
                memcpy(ThirdID->ID,&Recvbuff[length],32);
                ThirdID->modbusAddr = Recvbuff[length+32];
                memcpy(ThirdID->Factor,&Recvbuff[length+33],10);
                memcpy(ThirdID->Type,&Recvbuff[length+43],10);
                ThirdID->BaudRate = Recvbuff[length+53];
                ThirdID_List.push_back(ThirdID);
                length += 54;
            }
            addThirdID(ui->tableWidget_thirdID,ThirdID_List);

            QList<ThirdID_t *>::Iterator iter = ThirdID_List.begin();
            for ( ; iter != ThirdID_List.end(); iter++)  {
                delete (*iter);
            }
        }


    }else
    {
        ui->tableWidget_thirdID->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_thirdID->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_registerThirdID_clicked()
{
    //从TableWeiget中获取数据  然后注册
    unsigned char ModbusAddr = 0;
    char thirdID[32];
    char factor[20];
    char type[20];
    char Len_Str[5];
    char baudrate[3];
    unsigned char baudrateNO;
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0;
    int commtime = 0,i=0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100000033%s01END",ECUID);
    length = 30;

    for(int i=0;i<ui->tableWidget_thirdID->rowCount();i++){
        memset(thirdID,'\0',32);
        memset(factor,'\0',20);
        memset(type,'\0',20);
        ModbusAddr =0;
        memcpy(thirdID,ui->tableWidget_thirdID->item(i,0)->text().toLatin1().data(),ui->tableWidget_thirdID->item(i,0)->text().length());
        ModbusAddr = ui->tableWidget_thirdID->item(i,1)->text().toInt();
        memcpy(factor,ui->tableWidget_thirdID->item(i,2)->text().toLatin1().data(),ui->tableWidget_thirdID->item(i,2)->text().length());
        memcpy(type,ui->tableWidget_thirdID->item(i,3)->text().toLatin1().data(),ui->tableWidget_thirdID->item(i,3)->text().length());
        memcpy(baudrate,ui->tableWidget_thirdID->item(i,4)->text().toLatin1().data(),2);
        baudrate[2] = '\0';
        baudrateNO =atoi(baudrate);

        qDebug()<<thirdID <<" "<< ModbusAddr <<" "<< factor <<" "<< type << " " << baudrateNO <<endl;
        memcpy(&Sendbuff[length],thirdID,32);
        Sendbuff[length+32] = ModbusAddr;
        memcpy(&Sendbuff[length+33],factor,10);
        memcpy(&Sendbuff[length+43],type,10);
        Sendbuff[length+53] = baudrateNO;
        length+=54;
    }
    memcpy(&Sendbuff[length],"END",3);
    length += 3;
    sprintf(Len_Str,"%04d",length);
    memcpy(&Sendbuff[5],Len_Str,4);
    flag = ECU_Client->ECU_Communication(Sendbuff,length,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Third ID Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::addThirdData(QTableWidget *table, QList<ThirdData_t *> &List)
{
    table->setRowCount(0);
    //清空Table中内容
    table->clearContents();

    QList<ThirdData_t *>::Iterator iter = List.begin();
    for ( ; iter != List.end(); iter++)  {
        int row_count = table->rowCount(); //获取表单行数
        table->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        QTableWidgetItem *item5 = new QTableWidgetItem();
        QTableWidgetItem *item6 = new QTableWidgetItem();
        QTableWidgetItem *item7 = new QTableWidgetItem();
        QTableWidgetItem *item8 = new QTableWidgetItem();
        QTableWidgetItem *item9 = new QTableWidgetItem();
        QTableWidgetItem *item10 = new QTableWidgetItem();
        QTableWidgetItem *item11 = new QTableWidgetItem();
        QTableWidgetItem *item12 = new QTableWidgetItem();
        QTableWidgetItem *item13 = new QTableWidgetItem();
        QTableWidgetItem *item14 = new QTableWidgetItem();
        QTableWidgetItem *item15 = new QTableWidgetItem();
        QTableWidgetItem *item16 = new QTableWidgetItem();
        QTableWidgetItem *item17 = new QTableWidgetItem();
        QTableWidgetItem *item18 = new QTableWidgetItem();
        QTableWidgetItem *item19 = new QTableWidgetItem();
        QTableWidgetItem *item20 = new QTableWidgetItem();
        QTableWidgetItem *item21 = new QTableWidgetItem();
        QTableWidgetItem *item22 = new QTableWidgetItem();
        QTableWidgetItem *item23 = new QTableWidgetItem();
        QTableWidgetItem *item24 = new QTableWidgetItem();
        QTableWidgetItem *item25 = new QTableWidgetItem();
        QTableWidgetItem *item26 = new QTableWidgetItem();
        QTableWidgetItem *item27 = new QTableWidgetItem();
        QTableWidgetItem *item28 = new QTableWidgetItem();
        QTableWidgetItem *item29 = new QTableWidgetItem();
        QTableWidgetItem *item30 = new QTableWidgetItem();
        QTableWidgetItem *item31 = new QTableWidgetItem();
        QTableWidgetItem *item32 = new QTableWidgetItem();
        QTableWidgetItem *item33 = new QTableWidgetItem();
        QTableWidgetItem *item34 = new QTableWidgetItem();
        QTableWidgetItem *item35 = new QTableWidgetItem();
        QTableWidgetItem *item36 = new QTableWidgetItem();



        item->setText((*iter)->ID);
        item1->setText((*iter)->factor);
        item2->setText((*iter)->type);
        item3->setText(QString::number((*iter)->PV_Voltage[0]));
        item4->setText(QString::number((*iter)->PV_Voltage[1]));
        item5->setText(QString::number((*iter)->PV_Voltage[2]));
        item6->setText(QString::number((*iter)->PV_Voltage[3]));
        item7->setText(QString::number((*iter)->PV_Voltage[4]));
        item8->setText(QString::number((*iter)->PV_Voltage[5]));

        item9->setText(QString::number((*iter)->PV_Current[0]));
        item10->setText(QString::number((*iter)->PV_Current[1]));
        item11->setText(QString::number((*iter)->PV_Current[2]));
        item12->setText(QString::number((*iter)->PV_Current[3]));
        item13->setText(QString::number((*iter)->PV_Current[4]));
        item14->setText(QString::number((*iter)->PV_Current[5]));

        item15->setText(QString::number((*iter)->PV_Power[0]));
        item16->setText(QString::number((*iter)->PV_Power[1]));
        item17->setText(QString::number((*iter)->PV_Power[2]));
        item18->setText(QString::number((*iter)->PV_Power[3]));
        item19->setText(QString::number((*iter)->PV_Power[4]));
        item20->setText(QString::number((*iter)->PV_Power[5]));

        item21->setText(QString::number((*iter)->AC_Voltage[0]));
        item22->setText(QString::number((*iter)->AC_Voltage[1]));
        item23->setText(QString::number((*iter)->AC_Voltage[2]));

        item24->setText(QString::number((*iter)->AC_Current[0]));
        item25->setText(QString::number((*iter)->AC_Current[1]));
        item26->setText(QString::number((*iter)->AC_Current[2]));

        item27->setText(QString::number((*iter)->Grid_Frequency[0]));
        item28->setText(QString::number((*iter)->Grid_Frequency[1]));
        item29->setText(QString::number((*iter)->Grid_Frequency[2]));

        item30->setText(QString::number((*iter)->Temperature));

        item31->setText(QString::number((*iter)->Reactive_Power));
        item32->setText(QString::number((*iter)->Active_Power));
        item33->setText(QString::number((*iter)->Power_Factor));
        item34->setText(QString::number((*iter)->Daily_Energy));
        item35->setText(QString::number((*iter)->Life_Energy));
        item36->setText(QString::number((*iter)->Current_Energy));

        if((*iter)->commStatus == 1)
        {
            item->setBackgroundColor(QColor(0,238,0));
            item1->setBackgroundColor(QColor(0,238,0));
            item2->setBackgroundColor(QColor(0,238,0));
            item3->setBackgroundColor(QColor(0,238,0));
            item4->setBackgroundColor(QColor(0,238,0));
            item5->setBackgroundColor(QColor(0,238,0));
            item6->setBackgroundColor(QColor(0,238,0));
            item7->setBackgroundColor(QColor(0,238,0));
            item8->setBackgroundColor(QColor(0,238,0));
            item9->setBackgroundColor(QColor(0,238,0));
            item10->setBackgroundColor(QColor(0,238,0));
            item11->setBackgroundColor(QColor(0,238,0));
            item12->setBackgroundColor(QColor(0,238,0));
            item13->setBackgroundColor(QColor(0,238,0));
            item14->setBackgroundColor(QColor(0,238,0));
            item15->setBackgroundColor(QColor(0,238,0));
            item16->setBackgroundColor(QColor(0,238,0));
            item17->setBackgroundColor(QColor(0,238,0));
            item18->setBackgroundColor(QColor(0,238,0));
            item19->setBackgroundColor(QColor(0,238,0));
            item20->setBackgroundColor(QColor(0,238,0));
            item21->setBackgroundColor(QColor(0,238,0));
            item22->setBackgroundColor(QColor(0,238,0));
            item23->setBackgroundColor(QColor(0,238,0));
            item24->setBackgroundColor(QColor(0,238,0));
            item25->setBackgroundColor(QColor(0,238,0));
            item26->setBackgroundColor(QColor(0,238,0));
            item27->setBackgroundColor(QColor(0,238,0));
            item28->setBackgroundColor(QColor(0,238,0));
            item29->setBackgroundColor(QColor(0,238,0));
            item30->setBackgroundColor(QColor(0,238,0));
            item31->setBackgroundColor(QColor(0,238,0));
            item32->setBackgroundColor(QColor(0,238,0));
            item33->setBackgroundColor(QColor(0,238,0));
            item34->setBackgroundColor(QColor(0,238,0));
            item35->setBackgroundColor(QColor(0,238,0));
            item36->setBackgroundColor(QColor(0,238,0));

        }


        table->setItem(row_count, 0, item);
        table->setItem(row_count, 1, item1);
        table->setItem(row_count, 2, item2);
        table->setItem(row_count, 3, item3);
        table->setItem(row_count, 4, item4);
        table->setItem(row_count, 5, item5);
        table->setItem(row_count, 6, item6);
        table->setItem(row_count, 7, item7);
        table->setItem(row_count, 8, item8);
        table->setItem(row_count, 9, item9);
        table->setItem(row_count, 10, item10);
        table->setItem(row_count, 11, item11);
        table->setItem(row_count, 12, item12);
        table->setItem(row_count, 13, item13);
        table->setItem(row_count, 14, item14);
        table->setItem(row_count, 15, item15);
        table->setItem(row_count, 16, item16);
        table->setItem(row_count, 17, item17);
        table->setItem(row_count, 18, item18);
        table->setItem(row_count, 19, item19);
        table->setItem(row_count, 20, item20);
        table->setItem(row_count, 21, item21);
        table->setItem(row_count, 22, item22);
        table->setItem(row_count, 23, item23);
        table->setItem(row_count, 24, item24);
        table->setItem(row_count, 25, item25);
        table->setItem(row_count, 26, item26);
        table->setItem(row_count, 27, item27);
        table->setItem(row_count, 28, item28);
        table->setItem(row_count, 29, item29);
        table->setItem(row_count, 30, item30);
        table->setItem(row_count, 31, item31);
        table->setItem(row_count, 32, item32);
        table->setItem(row_count, 33, item33);
        table->setItem(row_count, 34, item34);
        table->setItem(row_count, 35, item35);
        table->setItem(row_count, 36, item36);

    }
}


void MainWindow::on_btn_getThirdData_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0,index = 0;
    char dateTime[15] = {'\0'};
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100280034%sEND",ECUID);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000,&commtime);
    ThirdData_List.clear();
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else if(Recvbuff[14] == '2')
        {
            statusBar()->showMessage(tr("ECU Have No Data ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Third Data Success ... time:%1").arg(commtime), 2000);
            int num = (recvLen-27)/193;
            length = 24;
            sprintf(dateTime,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[17],Recvbuff[18],Recvbuff[19],Recvbuff[20],Recvbuff[21],Recvbuff[22],Recvbuff[23]);
            ui->label_ThirdTime->setText(dateTime);

            for(index = 0;index < num;index++)
            {
                ThirdData_t *ThirdData = new ThirdData_t;

                memcpy(ThirdData->ID,&Recvbuff[length],32);
                ThirdData->commStatus = Recvbuff[length+32];
                memcpy(ThirdData->factor,&Recvbuff[length+33],10);
                memcpy(ThirdData->type,&Recvbuff[length+43],10);


                ThirdData->PV_Voltage[0] = (float)((Recvbuff[length+53] & 0x000000ff)*256 + (Recvbuff[length+54] & 0x000000ff))/10;
                ThirdData->PV_Voltage[1] = (float)((Recvbuff[length+55] & 0x000000ff)*256 + (Recvbuff[length+56] & 0x000000ff))/10;
                ThirdData->PV_Voltage[2] = (float)((Recvbuff[length+57] & 0x000000ff)*256 + (Recvbuff[length+58] & 0x000000ff))/10;
                ThirdData->PV_Voltage[3] = (float)((Recvbuff[length+59] & 0x000000ff)*256 + (Recvbuff[length+60] & 0x000000ff))/10;
                ThirdData->PV_Voltage[4] = (float)((Recvbuff[length+61] & 0x000000ff)*256 + (Recvbuff[length+62] & 0x000000ff))/10;
                ThirdData->PV_Voltage[5] = (float)((Recvbuff[length+63] & 0x000000ff)*256 + (Recvbuff[length+64] & 0x000000ff))/10;

                ThirdData->PV_Current[0] = (float)((Recvbuff[length+65] & 0x000000ff)*256 + (Recvbuff[length+66] & 0x000000ff))/10;
                ThirdData->PV_Current[1] = (float)((Recvbuff[length+67] & 0x000000ff)*256 + (Recvbuff[length+68] & 0x000000ff))/10;
                ThirdData->PV_Current[2] = (float)((Recvbuff[length+69] & 0x000000ff)*256 + (Recvbuff[length+70] & 0x000000ff))/10;
                ThirdData->PV_Current[3] = (float)((Recvbuff[length+71] & 0x000000ff)*256 + (Recvbuff[length+72] & 0x000000ff))/10;
                ThirdData->PV_Current[4] = (float)((Recvbuff[length+73] & 0x000000ff)*256 + (Recvbuff[length+74] & 0x000000ff))/10;
                ThirdData->PV_Current[5] = (float)((Recvbuff[length+75] & 0x000000ff)*256 + (Recvbuff[length+76] & 0x000000ff))/10;

                ThirdData->PV_Power[0] = (float)((Recvbuff[length+77] & 0x000000ff)*256*256*256 + (Recvbuff[length+78] & 0x000000ff)*256*256 + (Recvbuff[length+79] & 0x000000ff)*256 + (Recvbuff[length+80] & 0x000000ff))/100;
                ThirdData->PV_Power[1] = (float)((Recvbuff[length+81] & 0x000000ff)*256*256*256 + (Recvbuff[length+82] & 0x000000ff)*256*256 + (Recvbuff[length+83] & 0x000000ff)*256 + (Recvbuff[length+84] & 0x000000ff))/100;
                ThirdData->PV_Power[2] = (float)((Recvbuff[length+85] & 0x000000ff)*256*256*256 + (Recvbuff[length+86] & 0x000000ff)*256*256 + (Recvbuff[length+87] & 0x000000ff)*256 + (Recvbuff[length+88] & 0x000000ff))/100;
                ThirdData->PV_Power[3] = (float)((Recvbuff[length+89] & 0x000000ff)*256*256*256 + (Recvbuff[length+90] & 0x000000ff)*256*256 + (Recvbuff[length+91] & 0x000000ff)*256 + (Recvbuff[length+92] & 0x000000ff))/100;
                ThirdData->PV_Power[4] = (float)((Recvbuff[length+93] & 0x000000ff)*256*256*256 + (Recvbuff[length+94] & 0x000000ff)*256*256 + (Recvbuff[length+95] & 0x000000ff)*256 + (Recvbuff[length+96] & 0x000000ff))/100;
                ThirdData->PV_Power[5] = (float)((Recvbuff[length+97] & 0x000000ff)*256*256*256 + (Recvbuff[length+98] & 0x000000ff)*256*256 + (Recvbuff[length+99] & 0x000000ff)*256 + (Recvbuff[length+100] & 0x000000ff))/100;

                ThirdData->AC_Voltage[0] = (float)((Recvbuff[length+101] & 0x000000ff)*256 + (Recvbuff[length+102] & 0x000000ff))/10;
                ThirdData->AC_Voltage[1] = (float)((Recvbuff[length+103] & 0x000000ff)*256 + (Recvbuff[length+104] & 0x000000ff))/10;
                ThirdData->AC_Voltage[2] = (float)((Recvbuff[length+105] & 0x000000ff)*256 + (Recvbuff[length+106] & 0x000000ff))/10;

                ThirdData->AC_Current[0] = (float)((Recvbuff[length+107] & 0x000000ff)*256 + (Recvbuff[length+108] & 0x000000ff))/10;
                ThirdData->AC_Current[1] = (float)((Recvbuff[length+109] & 0x000000ff)*256 + (Recvbuff[length+110] & 0x000000ff))/10;
                ThirdData->AC_Current[2] = (float)((Recvbuff[length+111] & 0x000000ff)*256 + (Recvbuff[length+112] & 0x000000ff))/10;

                ThirdData->Grid_Frequency[0] = (float)((Recvbuff[length+113] & 0x000000ff)*256 + (Recvbuff[length+114] & 0x000000ff))/10;
                ThirdData->Grid_Frequency[1] = (float)((Recvbuff[length+115] & 0x000000ff)*256 + (Recvbuff[length+116] & 0x000000ff))/10;
                ThirdData->Grid_Frequency[2] = (float)((Recvbuff[length+117] & 0x000000ff)*256 + (Recvbuff[length+118] & 0x000000ff))/10;

                ThirdData->Temperature = (float)((Recvbuff[length+119] & 0x000000ff)*256 + (Recvbuff[length+120] & 0x000000ff) - 1000)/10;
                ThirdData->Reactive_Power = ((Recvbuff[length+121] & 0x000000ff)*256*256*256 + (Recvbuff[length+122] & 0x000000ff)*256*256 + (Recvbuff[length+123] & 0x000000ff)*256 + (Recvbuff[length+124] & 0x000000ff));
                ThirdData->Active_Power = ((Recvbuff[length+125] & 0x000000ff)*256*256*256 + (Recvbuff[length+126] & 0x000000ff)*256*256 + (Recvbuff[length+127] & 0x000000ff)*256 + (Recvbuff[length+128] & 0x000000ff));
                ThirdData->Power_Factor = (float)((Recvbuff[length+129] & 0x000000ff)*256 + (Recvbuff[length+130] & 0x000000ff))/1000;
                ThirdData->Current_Energy = (float)((Recvbuff[length+131] & 0x000000ff)*256*256*256 + (Recvbuff[length+132] & 0x000000ff)*256*256 + (Recvbuff[length+133] & 0x000000ff)*256 + (Recvbuff[length+134] & 0x000000ff))/10;
                ThirdData->Daily_Energy = (float)((Recvbuff[length+135] & 0x000000ff)*256*256*256 + (Recvbuff[length+136] & 0x000000ff)*256*256 + (Recvbuff[length+137] & 0x000000ff)*256 + (Recvbuff[length+138] & 0x000000ff))/10;
                ThirdData->Life_Energy = (float)((Recvbuff[length+139] & 0x000000ff)*256*256*256 + (Recvbuff[length+140] & 0x000000ff)*256*256 + (Recvbuff[length+141] & 0x000000ff)*256 + (Recvbuff[length+142] & 0x000000ff));


                ThirdData_List.push_back(ThirdData);
                length += 193;
            }
            addThirdData(ui->tableWidget_ThirdData,ThirdData_List);

            QList<ThirdData_t *>::Iterator iter = ThirdData_List.begin();
            for ( ; iter != ThirdData_List.end(); iter++)  {
                delete (*iter);
            }





        }


    }else
    {
        ui->tableWidget_ThirdData->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_ThirdData->clearContents();
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_clearText_clicked()
{
    ui->plainTextEdit_ZigBeeSend->clear();
}

void MainWindow::on_btn_ZigBeeSend_clicked()
{
    //从TableWeiget中获取数据  然后注册
    char Len_Str[5];
    char UID[13];
    QString StrZigbee;
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[8192] = {'\0'};
    int length = 0;
    int commtime = 0;
    memset(Recvbuff,0x00,8192);
    sprintf(Sendbuff,"APS1100000035%sEND",ECUID);
    length = 28;
    if(ui->comboBox_Zigbee->currentIndex() == 0)
    {
        Sendbuff[length++] = '0';
        memcpy(&Sendbuff[length],"000000000000",12);
        length += 12;
    }else if(ui->comboBox_Zigbee->currentIndex() == 1)
    {
        Sendbuff[length++] = '1';
        if(ui->lineEdit_ZigBeeUID->text().length() == 12)
        {
            memcpy(UID,ui->lineEdit_ZigBeeUID->text().toLatin1().data(),12);
            memcpy(&Sendbuff[length],UID,12);
            length += 12;
        }
        else
        {
            statusBar()->showMessage(tr("ID Error ... time:%1").arg(commtime), 2000);
            return;
        }
    }else
    {
        Sendbuff[length++] = '2';
        memcpy(&Sendbuff[length],"000000000000",12);
        length += 12;
    }

    StrZigbee = ui->plainTextEdit_ZigBeeSend->toPlainText();
    StrZigbee.remove(QRegExp("\\s"));
    if(StrZigbee.length() == 0)
    {
        statusBar()->showMessage(tr("ID Send BUFF Error ... time:%1").arg(commtime), 2000);
        return;
    }else
    {
        sprintf(&Sendbuff[length],"%03d",(StrZigbee.length()));
        length+=3;
        memcpy(&Sendbuff[length],StrZigbee.toLatin1().data(),StrZigbee.length());
        length += StrZigbee.length();

    }
    sprintf(Len_Str,"%04d",length);
    memcpy(&Sendbuff[5],Len_Str,4);
    flag = ECU_Client->ECU_Communication(Sendbuff,length,Recvbuff,&recvLen,2000,&commtime);
    if(flag == true)
    {
        if(Recvbuff[16] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ... time:%1").arg(commtime), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Third ID Success ... time:%1").arg(commtime), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_trinasolarServer_clicked()
{
    if(m_socket != NULL)
    {
        m_socket->close();
        delete m_socket;
        m_socket = NULL;
    }

    if(server != NULL)
    {
        server->disconnect();
        server->close();
        delete server;
        server = NULL;
    }
    this->server = new QTcpServer(this);
    this->m_socket = NULL;
    if(!this->server->listen(QHostAddress::Any, 60000)) {
        qDebug()<<server->errorString(); //错误信息
        ui->label_ServerStatus->setText("CONNECT Error");
    }else
    {
        ui->label_ServerStatus->setText("CONNECT");
    }
    QObject::connect(this->server,SIGNAL(newConnection()),this,SLOT(newConnection()));
}

void MainWindow::on_btn_trinasolarServer_close_clicked()
{
    ui->label_ServerStatus->setText("DISCONNECT");
    if(m_socket != NULL)
    {
        m_socket->close();
        delete m_socket;
        m_socket = NULL;
    }

    if(server != NULL)
    {
        server->disconnect();
        server->close();
        delete server;
        server = NULL;
    }

}

void MainWindow::newConnection(){
    this->m_socket=this->server->nextPendingConnection();
    //    QMessageBox::about(this,"提示","有新的连接！");
    connect(this->m_socket,SIGNAL(readyRead()),this,SLOT(ReceiveData()));
}

unsigned short MainWindow::computeCRC(unsigned char* pByte, size_t nbBytes)
{
    unsigned short CRC = 0xFFFF;
    size_t count = 0;
    size_t bitCount = 0;
    unsigned char buff = 0;
    for(count = 0; count < nbBytes; count++)
    {
        CRC ^= pByte[count];
        for(bitCount = 0; bitCount != 8; bitCount++)
        {
            if(CRC & 1)
            {
                CRC >>= 1;
                CRC ^= 0xA001;
            }
            else
            {
                CRC >>= 1;
            }
        }
    }

    buff = (CRC >> 8);
    CRC <<= 8;
    CRC |= buff;

    return CRC;
}

void MainWindow::ReceiveData(){
    char Data[4096] = {'\0'};
    char UID[50] = {'\0'};
    QString Str;
    int cmd = 0;
    char curTime[15] = {'\0'};
    char SendData[4096] = {'\0'};
    QByteArray arr=this->m_socket->readAll();
    memcpy(Data,arr.data(),arr.length());

    cmd = Data[52] * 0x100 + Data[53];
    qDebug("length:%d cmd:%x\n",arr.length(),cmd);
    if(cmd == 0x0001)    //登录命令
    {   //回复0801
        memcpy(UID,&Data[2],25);
        memcpy(ECU_UID,UID,25);
        unsigned short CRC = 0;
        memcpy(SendData,Data,52);
        SendData[52] = 0x08;
        SendData[53] = 0x01;
        SendData[54] = 0x01;
        SendData[55] = 0x00;
        SendData[56] = 0x00;
        SendData[57] = 0x07;
        //时间
        memcpy(curTime,QDateTime::currentDateTime().toString("yyyyMMddHHmmss").toLatin1().data(),14);
        SendData[58] = (curTime[0]-'0')*0x10 + (curTime[1]-'0');
        SendData[59] = (curTime[2]-'0')*0x10 + (curTime[3]-'0');
        SendData[60] = (curTime[4]-'0')*0x10 + (curTime[5]-'0');
        SendData[61] = (curTime[6]-'0')*0x10 + (curTime[7]-'0');
        SendData[62] = (curTime[8]-'0')*0x10 + (curTime[9]-'0');
        SendData[63] = (curTime[10]-'0')*0x10 + (curTime[11]-'0');
        SendData[64] = (curTime[12]-'0')*0x10 + (curTime[13]-'0');
        CRC = computeCRC((unsigned char*)SendData, 65);

        SendData[66] = (CRC >> 8);
        SendData[65] = (CRC & 0xFF);
        this->m_socket->write(SendData,67);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" + QString(UID)+" Login";
        ui->browser->appendPlainText(Str);
        qDebug() << Str;

    }else if(cmd == 0x0002)  //心跳命令
    {
        memcpy(UID,&Data[2],25);
        unsigned short CRC = 0;
        memcpy(SendData,Data,52);
        SendData[52] = 0x08;
        SendData[53] = 0x02;
        SendData[54] = 0x01;
        SendData[55] = 0x00;
        SendData[56] = 0x00;
        SendData[57] = 0x00;
        CRC = computeCRC((unsigned char*)SendData, 58);

        SendData[59] = (CRC >> 8);
        SendData[58] = (CRC & 0xFF);
        this->m_socket->write(SendData,60);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Heart";
        ui->browser->appendPlainText(Str);
        qDebug() << Str;

    }else if(cmd == 0x0804)     //表示设置服务器成功
    {
        memcpy(UID,&Data[2],25);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Set Server Successful DOMAIN,IP:" + ui->lineEdit_trinaIP->text()+"  PORT:"+ui->lineEdit_trinaport->text();
        ui->browser->appendPlainText(Str);
    }else if(cmd == 0x0805)     //升级ECU
    {
        memcpy(UID,&Data[2],25);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Update";
        ui->browser->appendPlainText(Str);
    }else if(cmd == 0x0808)     //重启ECU
    {
        memcpy(UID,&Data[2],25);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Reboot";
        ui->browser->appendPlainText(Str);
    }else if(cmd == 0x0809)     //获取设备信息
    {
        char factory[3] = {'\0'};
        char Type[14] = {'\0'};
        char CCID[21] = {'\0'};
        char Time[15] = {'\0'};
        char Version[11] = {'\0'};
        char GB;
        memcpy(UID,&Data[2],25);
        //厂商
        memcpy(factory,&Data[58],2);
        //型号
        memcpy(Type,&Data[60],13);
        //CCID
        memcpy(CCID,&Data[73],20);
        //设备时间
        Time[0] = Data[93]/16 + '0';
        Time[1] = Data[93]%16 + '0';
        Time[2] = Data[94]/16 + '0';
        Time[3] = Data[94]%16 + '0';
        Time[4] = Data[95]/16 + '0';
        Time[5] = Data[95]%16 + '0';
        Time[6] = Data[96]/16 + '0';
        Time[7] = Data[96]%16 + '0';
        Time[8] = Data[97]/16 + '0';
        Time[9] = Data[97]%16 + '0';
        Time[10] = Data[98]/16 + '0';
        Time[11] = Data[98]%16 + '0';
        Time[12] = Data[99]/16 + '0';
        Time[13] = Data[99]%16 + '0';
        //固件版本
        memcpy(Version,&Data[100],10);
        //国家标准
        GB = Data[110];
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Device Info Factory:" + QString(factory) +" Type:" + QString(Type) +" CCID:" + QString(CCID) +" Time:" + QString(Time) +" Ver:"+ QString(Version) +" GB:" + QString::number(GB);
        ui->browser->appendPlainText(Str);
    }
    else if(cmd == 0x0201)
    {
        memcpy(UID,&Data[2],25);
        unsigned short CRC = 0;
        memcpy(SendData,Data,52);
        SendData[52] = 0x0A;
        SendData[53] = 0x01;
        SendData[54] = 0x01;
        SendData[55] = 0x00;
        SendData[56] = 0x00;
        SendData[57] = 0x00;
        CRC = computeCRC((unsigned char*)SendData, 58);

        SendData[59] = (CRC >> 8);
        SendData[58] = (CRC & 0xFF);
        this->m_socket->write(SendData,60);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Record";
        ui->browser->appendPlainText(Str);
        qDebug() << Str;
    }else if(cmd == 0x0206)
    {
        memcpy(UID,&Data[2],25);
        unsigned short CRC = 0;
        memcpy(SendData,Data,52);
        SendData[52] = 0x0A;
        SendData[53] = 0x06;
        SendData[54] = 0x01;
        SendData[55] = 0x00;
        SendData[56] = 0x00;
        SendData[57] = 0x00;
        CRC = computeCRC((unsigned char*)SendData, 58);

        SendData[59] = (CRC >> 8);
        SendData[58] = (CRC & 0xFF);
        this->m_socket->write(SendData,60);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+"History Record";
        ui->browser->appendPlainText(Str);
        qDebug() << Str;
    }
    else if(cmd == 0x0a02)
    {
        memcpy(UID,&Data[2],25);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" RSD Set Successful";
        ui->browser->appendPlainText(Str);
        qDebug() << Str;
    }else if(cmd == 0x0a05)
    {
        memcpy(UID,&Data[2],25);
        Str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + ":" +QString(UID)+" Relation";
        ui->browser->appendPlainText(Str);
        qDebug() << Str;
    }
    memset(Data,0x00,4096);
    cmd = -1;

}



void MainWindow::on_btn_setServer_clicked()
{
    char sendbuff[4096] = {'\0'};
    unsigned short CRC = 0;
    char domain[50] = {'\0'};
    int port;
    memcpy(domain,ui->lineEdit_trinaIP->text().toLatin1().data(),ui->lineEdit_trinaIP->text().length());
    port = ui->lineEdit_trinaport->text().toInt();
    sendbuff[0] = 'T';
    sendbuff[1] = 'S';
    memcpy(&sendbuff[2],ECU_UID,12);
    memcpy(&sendbuff[27],ECU_UID,12);
    sendbuff[52] = 0x00;
    sendbuff[53] = 0x04;
    sendbuff[54] = 0x01;
    sendbuff[55] = 0x00;
    sendbuff[56] = 0x00;
    sendbuff[57] = 52;
    //域名
    memcpy(&sendbuff[58],domain,50);
    //端口
    sendbuff[108] = port/256;
    sendbuff[109] = port%256;
    CRC = computeCRC((unsigned char*)sendbuff, 110);

    sendbuff[111] = (CRC >> 8);
    sendbuff[110] = (CRC & 0xFF);
    if(m_socket)
        this->m_socket->write(sendbuff,112);
}

void MainWindow::on_btn_trinaReboot_clicked()
{
    char sendbuff[4096] = {'\0'};
    unsigned short CRC = 0;

    sendbuff[0] = 'T';
    sendbuff[1] = 'S';
    memcpy(&sendbuff[2],ECU_UID,12);
    memcpy(&sendbuff[27],ECU_UID,12);
    sendbuff[52] = 0x00;
    sendbuff[53] = 0x08;
    sendbuff[54] = 0x01;
    sendbuff[55] = 0x00;
    sendbuff[56] = 0x00;
    sendbuff[57] = 00;

    CRC = computeCRC((unsigned char*)sendbuff, 58);

    sendbuff[59] = (CRC >> 8);
    sendbuff[58] = (CRC & 0xFF);
    if(m_socket)
        this->m_socket->write(sendbuff,60);
}

void MainWindow::on_btn_trinagetinfo_clicked()
{
    char sendbuff[4096] = {'\0'};
    unsigned short CRC = 0;

    sendbuff[0] = 'T';
    sendbuff[1] = 'S';
    memcpy(&sendbuff[2],ECU_UID,12);
    memcpy(&sendbuff[27],ECU_UID,12);
    sendbuff[52] = 0x00;
    sendbuff[53] = 0x09;
    sendbuff[54] = 0x01;
    sendbuff[55] = 0x00;
    sendbuff[56] = 0x00;
    sendbuff[57] = 00;

    CRC = computeCRC((unsigned char*)sendbuff, 58);

    sendbuff[59] = (CRC >> 8);
    sendbuff[58] = (CRC & 0xFF);
    if(m_socket)
        this->m_socket->write(sendbuff,60);
}

void MainWindow::on_btn_trinaUpdate_clicked()
{
    char sendbuff[4096] = {'\0'};
    unsigned short CRC = 0;
    char uri[101] = {'\0'};
    char user[20] = {'\0'};
    char passwd[20] = {'\0'};

    memcpy(uri,ui->lineEdit_trinaURI->text().toLatin1().data(),ui->lineEdit_trinaURI->text().length());
    memcpy(user,ui->lineEdit_trinauser->text().toLatin1().data(),ui->lineEdit_trinauser->text().length());
    memcpy(passwd,ui->lineEdit_trinapasswd->text().toLatin1().data(),ui->lineEdit_trinapasswd->text().length());


    sendbuff[0] = 'T';
    sendbuff[1] = 'S';
    memcpy(&sendbuff[2],ECU_UID,12);
    memcpy(&sendbuff[27],ECU_UID,12);
    sendbuff[52] = 0x00;
    sendbuff[53] = 0x05;
    sendbuff[54] = 0x01;
    sendbuff[55] = 0x00;
    sendbuff[56] = 0x00;
    sendbuff[57] = 114;

    sendbuff[58] = 0x01;
    sendbuff[59] = 0x02;
    memcpy(&sendbuff[60],uri,100);
    memcpy(&sendbuff[160],user,6);
    memcpy(&sendbuff[166],passwd,6);

    CRC = computeCRC((unsigned char*)sendbuff, 172);

    sendbuff[173] = (CRC >> 8);
    sendbuff[172] = (CRC & 0xFF);
    if(m_socket)
        this->m_socket->write(sendbuff,174);
}

void MainWindow::on_btn_trinaRSD_clicked()
{
    char sendbuff[4096] = {'\0'};
    int packlen = 0;
    char ID[16];
    char ID_List[4096];
    char text[4096] = {'\0'};
    int index=0;
    int length = 0;
    unsigned short CRC = 0;
    unsigned char num = 0;
    unsigned char FunctionStatus = 0;
    if(ui->comboBox_RSD->currentIndex() == 0)
    {
        num = 0;
    }else
    {
        length = ui->plainTextEdit_RSDLIST->toPlainText().length();
        num = (length + 1)/13;
        memcpy(text,ui->plainTextEdit_RSDLIST->toPlainText().toLatin1().data(),length);

        for(index = 0;index<num;index++)
        {
            memset(ID,0x00,16);
            memcpy(ID,&text[0+index*13],12);
            memcpy(&ID_List[index*15],ID,15);
        }

    }
    switch(ui->comboBox_RSDFunctionStatus->currentIndex())
    {
    case 0:
        FunctionStatus = 0x11;
        break;
    case 1:
        FunctionStatus = 0x10;
        break;
    case 2:
        FunctionStatus = 0x01;
        break;
    case 3:
        FunctionStatus = 0x00;
        break;
    }

    sendbuff[0] = 'T';
    sendbuff[1] = 'S';
    memcpy(&sendbuff[2],ECU_UID,12);
    memcpy(&sendbuff[27],ECU_UID,12);
    sendbuff[52] = 0x02;
    sendbuff[53] = 0x02;
    sendbuff[54] = 0x01;
    sendbuff[55] = 0x00;

    if(num == 0)
    {
        sendbuff[56] = 0x00;
        sendbuff[57] = 17;
        sendbuff[58] = num;
        sendbuff[59] = FunctionStatus;
        sendbuff[60] = 'a';
        sendbuff[61] = 'l';
        sendbuff[62] = 'l';
        packlen =75;
    }else
    {   //num*15+2
        sendbuff[56] = (num*15+2)/256;
        sendbuff[57] = (num*15+2)%256;
        sendbuff[58] = num;
        sendbuff[59] = FunctionStatus;
        memcpy(&sendbuff[60],ID_List,num*15);
        packlen =60+num*15;
    }

    CRC = computeCRC((unsigned char*)sendbuff, packlen);

    sendbuff[packlen+1] = (CRC >> 8);
    sendbuff[packlen] = (CRC & 0xFF);
    if(m_socket)
        this->m_socket->write(sendbuff,packlen+2);
}

void MainWindow::on_btn_trinagetrelation_clicked()
{
    char sendbuff[4096] = {'\0'};
    unsigned short CRC = 0;

    sendbuff[0] = 'T';
    sendbuff[1] = 'S';
    memcpy(&sendbuff[2],ECU_UID,12);
    memcpy(&sendbuff[27],ECU_UID,12);
    sendbuff[52] = 0x02;
    sendbuff[53] = 0x05;
    sendbuff[54] = 0x01;
    sendbuff[55] = 0x00;
    sendbuff[56] = 0x00;
    sendbuff[57] = 0x00;

    CRC = computeCRC((unsigned char*)sendbuff, 58);

    sendbuff[59] = (CRC >> 8);
    sendbuff[58] = (CRC & 0xFF);
    if(m_socket)
        this->m_socket->write(sendbuff,60);
}

void MainWindow::on_comboBox_ServerItem_currentIndexChanged(int index)
{
    if((index == 6) || (index == 7))
    {
        ui->label_trina->show();
        ui->comboBox_trina->show();
    }else
    {
        ui->label_trina->hide();
        ui->comboBox_trina->hide();
    }
}
