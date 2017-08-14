#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug.h"
#include "QDateTime"

#define MAJOR_VERSION   1
#define MINOR_VERSION   0

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sprintf(ECUID,"000000000000");
    ECUID[12]  = '\0';
    ui->setupUi(this);
    IPInterfaceSataus(false);
    setWindowTitle(tr("ECU-R Test V%1.%2").arg(MAJOR_VERSION).arg(MINOR_VERSION));
    setFixedSize(781,440);
    ECU_Client = new Communication("10.10.100.254",8899);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ECU_Client;
    ECU_Client = NULL;
}

void MainWindow::IPInterfaceSataus(bool status)
{
    if(status == true)
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
    }else
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
    qint64 recvLen=0;
    bool flag = false;
    unsigned char Sendbuff[200] = {'\0'};
    unsigned char Recvbuff[4096] = {'\0'};
    int select_item = 0;
    memset(Recvbuff,0x00,4096);

    select_item = ui->comboBox->currentIndex();
    qDebug("%d\n",select_item);
    //先判断是静态  还是动态
    if(select_item == 0)
    {   //动态获取IP
        sprintf((char *)Sendbuff,"APS1100530007%sEND0000000000000000000000END",ECUID);
        qDebug("%d  Sendbuff: %s\n",select_item,Sendbuff);
    }else if(select_item == 1)
    {   //静态获取IP
        sprintf((char *)Sendbuff,"APS1100530007%sEND0100000000000000000000END",ECUID);
        qDebug("%d  Sendbuff: %s\n",select_item,Sendbuff);
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

        qDebug("ip:%d.%d.%d.%d\n",Sendbuff[30],Sendbuff[31],Sendbuff[32],Sendbuff[33]);
        qDebug("mask:%d.%d.%d.%d\n",Sendbuff[34],Sendbuff[35],Sendbuff[36],Sendbuff[37]);
        qDebug("gate:%d.%d.%d.%d\n",Sendbuff[38],Sendbuff[39],Sendbuff[40],Sendbuff[41]);
        qDebug("dns1:%d.%d.%d.%d\n",Sendbuff[42],Sendbuff[43],Sendbuff[44],Sendbuff[45]);
        qDebug("dns2:%d.%d.%d.%d\n",Sendbuff[46],Sendbuff[47],Sendbuff[48],Sendbuff[49]);

    }

    flag = ECU_Client->ECU_Communication((char *)Sendbuff,53,(char *)Recvbuff,&recvLen,2000);
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
        qDebug("字节长度太短\n");
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
    qDebug("%s\n",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,QString(Sendbuff).length(),Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
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
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[300];
    char Recvbuff[200] = {'\0'};

    sprintf(Sendbuff,"APS1100280009%sEND",ECUID);
    memset(Recvbuff,0x00,200);
    qDebug("%s\n",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,QString(Sendbuff).length(),Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(Recvbuff[14] == '2')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else if(Recvbuff[14] == '1')
        {
            ui->checkBox->setCheckState(Qt::Checked);
            statusBar()->showMessage(tr("Check Connect Success ..."), 2000);

        }else
        {
            ui->checkBox->setCheckState(Qt::Unchecked);
            statusBar()->showMessage(tr("Check Connect Success ..."), 2000);
        }
    }else
    {
        statusBar()->showMessage(tr("Please verify WIFI Connect ..."), 2000);
    }
}

void MainWindow::on_btn_configWIFI_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[300];
    char Recvbuff[200] = {'\0'};
    int SSIDLen = 0;
    int PASSWDLen = 0;
    char SSID[100];
    char Passwd[100];
    char length[5] = {'\0'};

    SSIDLen = ui->lineEdit_SSID->text().length();
    PASSWDLen = ui->lineEdit_Passwd->text().length();

    if(SSIDLen < 3 || PASSWDLen < 8)
    {
        statusBar()->showMessage(tr("size too short ..."), 2000);
        return;
    }

    memcpy(SSID, ui->lineEdit_SSID->text().toLatin1().data(),SSIDLen);
    memcpy(Passwd, ui->lineEdit_Passwd->text().toLatin1().data(),PASSWDLen);
    SSID[SSIDLen] = '\0';
    Passwd[PASSWDLen] = '\0';

    sprintf(Sendbuff,"APS1100000008%sEND%03d%s%03d%sEND",ECUID,SSIDLen,SSID,PASSWDLen,Passwd);
    sprintf(length,"%04d",QString(Sendbuff).length());
    memcpy(&Sendbuff[5],length,4);
    memset(Recvbuff,0x00,200);
    qDebug("%s\n",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,QString(Sendbuff).length(),Recvbuff,&recvLen,2000);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set Config SSID Success ..."), 2000);
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
    char ID_BCD[13];
    char ID_BCD_List[4096];
    char text[4096] = {'\0'};
    int OPTCount = 0,index=0;
    char packlength[5] = {'\0'};
    int length = ui->plainTextEdit_ID->toPlainText().length();
    OPTCount = (length + 1)/13;
    qDebug("%d %d,%s",OPTCount,length,ui->plainTextEdit_ID->toPlainText().toLatin1().data());
    memcpy(text,ui->plainTextEdit_ID->toPlainText().toLatin1().data(),length);

    for(index = 0;index<OPTCount;index++)
    {
        memset(ID_BCD,0x00,13);
        memcpy(ID_BCD,&text[0+index*13],12);
        qDebug("%s \n",ID_BCD);
        memcpy(&ID_BCD_List[index*12],ID_BCD,12);
    }

    sprintf(Sendbuff,"APS1100000005%sEND",ECUID);
    memcpy(&Sendbuff[28],ID_BCD_List,(OPTCount*12));
    Sendbuff[OPTCount*12+28] = 'E';
    Sendbuff[OPTCount*12+29] = 'N';
    Sendbuff[OPTCount*12+30] = 'D';

    sprintf(packlength,"%04d",(OPTCount*12+31));
    memcpy(&Sendbuff[5],packlength,4);

    memset(Recvbuff,0x00,200);
    qDebug("len:%d send:%s\n",(OPTCount*12+31),Sendbuff);

    flag = ECU_Client->ECU_Communication(Sendbuff,(OPTCount*12+31),Recvbuff,&recvLen,3000);
    if(flag == true)
    {
        if(Recvbuff[14] == '1')
        {//ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("Set ID Success ..."), 2000);
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
    char dateTime[15] = {'\0'};
    int optcount = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280002%sEND",ECUID);
    qDebug("send:%s\n",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000);
    ui->plainTextEdit_ID->clear();
    if(flag == true)
    {

        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else if(Recvbuff[14] == '2')
        {
            statusBar()->showMessage(tr("ECU Have No Data ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Real Data Success ..."), 2000);
            optcount = (recvLen-27)/18;
            qDebug("%d\n",optcount);
            length = 24;
            for(index = 0;index < optcount;index++)
            {

                sprintf(ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length] & 0x000000ff),(Recvbuff[length+1] & 0x000000ff),(Recvbuff[length+2] & 0x000000ff),(Recvbuff[length+3] & 0x000000ff),(Recvbuff[length+4] & 0x000000ff),(Recvbuff[length+5] & 0x000000ff));
                ui->plainTextEdit_ID->appendPlainText(ID);
                length += 18;
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

        item->setText((*iter)->ID);
        item1->setText(QString::number((double)((*iter)->Grid_Frequency/10)));
        item2->setText(QString::number(((*iter)->Temperature - 100)));
        item3->setText(QString::number((*iter)->Inverter_Power));
        item4->setText(QString::number((*iter)->Grid_Voltage));
        item5->setText(QString::number((*iter)->Inverter_Power_B));
        item6->setText(QString::number((*iter)->Grid_Voltage_B));


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

void MainWindow::on_btn_getRealData_clicked()
{
    qint64 recvLen=0;
    bool flag = false;
    char Sendbuff[200] = {'\0'};
    char Recvbuff[4096] = {'\0'};
    int length = 0,index = 0;
    char dateTime[15] = {'\0'};
    int optcount = 0;
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100280002%sEND",ECUID);
    qDebug("send:%s\n",Sendbuff);
    flag = ECU_Client->ECU_Communication(Sendbuff,28,Recvbuff,&recvLen,2000);
    YC600_RealData_List.clear();

    if(flag == true)
    {
        ui->tableWidget_RealData->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_RealData->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else if(Recvbuff[14] == '2')
        {
            statusBar()->showMessage(tr("ECU Have No Data ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Real Data Success ..."), 2000);
            optcount = (recvLen-27)/18;
            qDebug("%d\n",optcount);
            length = 24;
            for(index = 0;index < optcount;index++)
            {
                YC600_RealData_t *YC600_RealData = new YC600_RealData_t;

                sprintf(YC600_RealData->ID,"%02x%02x%02x%02x%02x%02x",(Recvbuff[length] & 0x000000ff),(Recvbuff[length+1] & 0x000000ff),(Recvbuff[length+2] & 0x000000ff),(Recvbuff[length+3] & 0x000000ff),(Recvbuff[length+4] & 0x000000ff),(Recvbuff[length+5] & 0x000000ff));
                YC600_RealData->Grid_Frequency = (Recvbuff[length+6] & 0x000000ff)*256 + (Recvbuff[length+7] & 0x000000ff);
                YC600_RealData->Temperature = (Recvbuff[length+8] & 0x000000ff)*256 + (Recvbuff[length+9] & 0x000000ff);
                YC600_RealData->Inverter_Power = (Recvbuff[length+10] & 0x000000ff)*256 + (Recvbuff[length+11] & 0x000000ff);
                YC600_RealData->Grid_Voltage = (Recvbuff[length+12] & 0x000000ff)*256 + (Recvbuff[length+13] & 0x000000ff);
                YC600_RealData->Inverter_Power_B = (Recvbuff[length+14] & 0x000000ff)*256 + (Recvbuff[length+15] & 0x000000ff);
                YC600_RealData->Grid_Voltage_B = (Recvbuff[length+16] & 0x000000ff)*256 + (Recvbuff[length+17] & 0x000000ff);

                YC600_RealData_List.push_back(YC600_RealData);
                length += 18;
                qDebug("%s\n",YC600_RealData->ID);

            }
            addRealData(ui->tableWidget_RealData,YC600_RealData_List);
            sprintf(dateTime,"%02x%02x%02x%02x%02x%02x%02x",Recvbuff[17],Recvbuff[18],Recvbuff[19],Recvbuff[20],Recvbuff[21],Recvbuff[22],Recvbuff[23]);
            ui->label_all->setText(QString::number(optcount));
            ui->label_time->setText(dateTime);
            QList<YC600_RealData_t *>::Iterator iter = YC600_RealData_List.begin();
            for ( ; iter != YC600_RealData_List.end(); iter++)  {
                delete (*iter);
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
    int year = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int day = ui->dateEdit->date().day();
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100390003%sEND%02d%02d%02dEND",ECUID,year,month,day);
    qDebug("send:%s\n",Sendbuff);

    flag = ECU_Client->ECU_Communication(Sendbuff,39,Recvbuff,&recvLen,2000);
    YC600_PowerData_List.clear();

    if(flag == true)
    {
        ui->tableWidget_Power->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Power->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Power Data Success ..."), 2000);
            num = (recvLen-18)/4;
            qDebug("%d\n",num);
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
    int select_item = ui->comboBox_2->currentIndex();
    memset(Recvbuff,0x00,4096);
    sprintf(Sendbuff,"APS1100330004%sEND%02dEND",ECUID,select_item);
    qDebug("send:%s\n",Sendbuff);

    flag = ECU_Client->ECU_Communication(Sendbuff,33,Recvbuff,&recvLen,2000);
    YC600_EnergyData_List.clear();

    if(flag == true)
    {
        ui->tableWidget_Energy->setRowCount(0);
        //清空Table中内容
        ui->tableWidget_Energy->clearContents();
        if(Recvbuff[14] == '1')
        {   //ECU ID不匹配
            statusBar()->showMessage(tr("ECU ID Mismatching ..."), 2000);
        }
        else
        {
            statusBar()->showMessage(tr("ECU Get Energy Data Success ..."), 2000);
            num = (recvLen-20)/6;
            qDebug("%d\n",num);
            length = 17;
            for(index = 0;index < num;index++)
            {
                YC600_EnergyData_t *YC600_EnergyData = new YC600_EnergyData_t;

                sprintf(YC600_EnergyData->date,"%02x%02x-%02x-%02x",Recvbuff[length],Recvbuff[length+1],Recvbuff[length+2],Recvbuff[length+3]);
                qDebug("%d\n",((Recvbuff[length+4] & 0x000000ff)*256 + (Recvbuff[length+5] & 0x000000ff)));
                YC600_EnergyData->energy = ((double)((Recvbuff[length+4] & 0x000000ff)*256 + (Recvbuff[length+5] & 0x000000ff))/100);
                qDebug("%f\n",YC600_EnergyData->energy);
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
