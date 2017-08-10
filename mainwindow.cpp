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


    ui->label_22->hide();
    ui->label_24->hide();
    ui->label_26->hide();
    ui->label_28->hide();
    ui->label_31->hide();

    ui->label_32->hide();
    ui->label_33->hide();
    ui->label_34->hide();
    ui->label_35->hide();
    ui->label_36->hide();
    ui->label_37->hide();
    ui->label_38->hide();
    ui->label_39->hide();
    ui->label_40->hide();
    ui->label_41->hide();


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
        //����ECUID
        memcpy(ECUID,&Recvbuff[13],12);
        ECUID[12]  = '\0';
        ui->lineEdit_ECUID->setText(ECUID);
        memcpy(ECU_Model,&Recvbuff[25],2);
        ECU_Model[2] = '\0';
        ui->label_ECUModel->setText(ECU_Model);
        //ϵͳ������
        Lifttime_Energy = ((double)(Recvbuff[27]*(256*256*256) + Recvbuff[28]*(256*256) + Recvbuff[29]*256 + Recvbuff[30]))/10;
        qDebug("%d\n",(Recvbuff[27]*(256*256*256) + Recvbuff[28]*(256*256) + Recvbuff[29]*256 + Recvbuff[30]));
        ui->label_LifttimeEnergy->setText(QString::number(Lifttime_Energy));

        //��ǰϵͳ����
        Last_System_Power = (Recvbuff[31]*(256*256*256) + Recvbuff[32]*(256*256) + Recvbuff[33]*256 + Recvbuff[34]);
        ui->label_LastSystemPower->setText(QString::number(Last_System_Power));
        //���췢����
        Generation_Current_Day = ((double)(Recvbuff[35]*(256*256*256) + Recvbuff[36]*(256*256) + Recvbuff[37]*256 + Recvbuff[38]))/100;
        ui->label_GenerationCurrentDay->setText(QString::number(Generation_Current_Day));

        //���һ������EMAʱ��
        sprintf(Last_To_EMA,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[39]&0x000000ff,Recvbuff[40]&0x000000ff,Recvbuff[41]&0x000000ff,Recvbuff[42]&0x000000ff,Recvbuff[43]&0x000000ff,Recvbuff[44]&0x000000ff,Recvbuff[45]&0x000000ff);
        ui->label_LastToEMA->setText(QString(Last_To_EMA));

        //�������̨��
        Number_Inverters = (Recvbuff[46]*256 + Recvbuff[47]);
        ui->label_NumberInverters->setText(QString::number(Number_Inverters));

        //��ǰ���������̨��
        Last_Number_Inverters = (Recvbuff[48]*256 + Recvbuff[49]);
        ui->label_LastNumberInverters->setText(QString::number(Last_Number_Inverters));

        //����汾
        version_length = (Recvbuff[50]-'0')*100 + (Recvbuff[51]-'0')*10 + (Recvbuff[52]-'0');
        memcpy(Version,&Recvbuff[53],version_length);
        Version[version_length] = '\0';
        ui->label_Version->setText(Version);

        //ʱ��
        Time_length = (Recvbuff[53+version_length]-'0')*100 + (Recvbuff[54+version_length]-'0')*10 + (Recvbuff[55+version_length]-'0');
        memcpy(Time_Zone,&Recvbuff[56+version_length],Time_length);
        Time_Zone[Time_length] = '\0';
        ui->label_TimeZone->setText(Time_Zone);
        //MAC��ַ
        sprintf(MAC,"%02x-%02x-%02x-%02x-%02x-%02x",Recvbuff[56+version_length+Time_length]&0x000000ff,Recvbuff[57+version_length+Time_length]&0x000000ff,Recvbuff[58+version_length+Time_length]&0x000000ff,Recvbuff[59+version_length+Time_length]&0x000000ff,Recvbuff[60+version_length+Time_length]&0x000000ff,Recvbuff[61+version_length+Time_length]&0x000000ff);
        ui->label_MacAddress->setText(MAC);
        //WIFI MAC��ַ
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
    //��ȡ��ǰ��ʱ��
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
    //����ECU-R��ʱ��
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
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int select_item = 0;
    memset(Recvbuff,0x00,4096);

    select_item = ui->comboBox->currentIndex();
    qDebug("%d\n",select_item);
    //���ж��Ǿ�̬  ���Ƕ�̬
    if(select_item == 0)
    {   //��̬��ȡIP
        sprintf(Sendbuff,"APS1100530007%sEND0000000000000000000000END",ECUID);
        qDebug("%d  Sendbuff: %s\n",select_item,Sendbuff);
    }else if(select_item == 1)
    {   //��̬��ȡIP
        sprintf(Sendbuff,"APS1100530007%sEND0100000000000000000000END",ECUID);
        qDebug("%d  Sendbuff: %s\n",select_item,Sendbuff);
        //Sendbuff[30] = 0x00; //IP 1

    }

    flag = ECU_Client->ECU_Communication(Sendbuff,53,Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(!memcmp(&Recvbuff[13],"00",2))
        {
            statusBar()->showMessage(tr("Set Network Success ..."), 1000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Network Failed ..."), 1000);
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
        qDebug("�ֽڳ���̫��\n");
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
        {//ECU ID��ƥ��
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Password Success ..."), 2000);
            qDebug("����WIFI����ɹ���");
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


        ui->label_22->hide();
        ui->label_24->hide();
        ui->label_26->hide();
        ui->label_28->hide();
        ui->label_31->hide();

        ui->label_32->hide();
        ui->label_33->hide();
        ui->label_34->hide();
        ui->label_35->hide();
        ui->label_36->hide();
        ui->label_37->hide();
        ui->label_38->hide();
        ui->label_39->hide();
        ui->label_40->hide();
        ui->label_41->hide();


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
    }else if(index == 1)
    {
        ui->label_6->show();
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();

        ui->label_22->show();
        ui->label_24->show();
        ui->label_26->show();
        ui->label_28->show();
        ui->label_31->show();

        ui->label_32->show();
        ui->label_33->show();
        ui->label_34->show();
        ui->label_35->show();
        ui->label_36->show();
        ui->label_37->show();
        ui->label_38->show();
        ui->label_39->show();
        ui->label_40->show();
        ui->label_41->show();

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
    }
}
