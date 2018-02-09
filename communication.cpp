#include "communication.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Communication::Communication()
{
    this->IP = "10.10.100.254";
    this->Port = 8899;
    Client = new QTcpSocket;
}

Communication::Communication(QString ip, quint16 port)
{
    this->IP = ip;
    this->Port = port;
    Client = new QTcpSocket;
}

Communication::~Communication()
{
    delete Client;
    Client = NULL;
}

bool Communication::ECU_Communication(char *Sendbuff, qint64 sendLen, char *Recvbuff, qint64 *recvLen, int timeout,int *commtime)
{
    bool flag;
    int length = 0,read_Size = 0;
    Client->connectToHost(QHostAddress(IP), Port);
    if(Client->isValid() == false)
    {
        *recvLen = 0;
        return false;
    }

    Client->write(Sendbuff,sendLen);
    //获取开始时间
    clock_t start = clock();   //记录开始时间
    //读取数据，如果读到的是\n  表示接受完毕
    while(1)
    {
        flag =  Client->waitForReadyRead(timeout);
        if(flag == false)
        {
            *recvLen = 0;
            break;
        }else
        {
            //读到最后个字节为'\n'  表示读取结束

            read_Size = Client->read(&Recvbuff[length],16384);
            length+= read_Size;
            if(Recvbuff[(length-1)] == '\n')
            {
                *recvLen = length;
                break;
            }
        }
    }
    //获取结束时间
    clock_t finish = clock();   //结束时间
    int duration = (finish - start) ;
    *commtime = duration;
    qDebug("Time iterations: %d ms",duration);

    qDebug("recv :%d\n",*recvLen);
    qDebug("recv :%s\n",Recvbuff);
    Client->abort();

    if(*recvLen > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Communication::IDWrite_Communication(char *Sendbuff, qint64 sendLen, char *Recvbuff, qint64 *recvLen, int timeout, int *commtime)
{
    bool flag;
    int length = 0,read_Size = 0;
    Client->connectToHost(QHostAddress(IP), Port);
    if(Client->isValid() == false)
    {
        *recvLen = 0;
        return false;
    }

    Client->write(Sendbuff,sendLen);
    //获取开始时间
    clock_t start = clock();   //记录开始时间
    //读取数据，如果读到的是\n  表示接受完毕

    flag =  Client->waitForReadyRead(timeout);
    if(flag == false)
    {
        *recvLen = 0;
    }else
    {
        //读到最后个字节为'\n'  表示读取结束
        read_Size = Client->read(&Recvbuff[length],16384);
        *recvLen = read_Size;
    }

    //获取结束时间
    clock_t finish = clock();   //结束时间
    int duration = (finish - start) ;
    *commtime = duration;
    qDebug("Time iterations: %d ms",duration);

    qDebug("recv :%d\n",*recvLen);
    qDebug("recv :%s\n",Recvbuff);
    Client->abort();

    if(*recvLen > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Communication::ECU_Connect()
{
    Client->connectToHost(QHostAddress(IP), Port);
}

bool Communication::ECU_Disconnect()
{
    Client->disconnect();
}

int Communication::ECU_Write(char *Sendbuff, qint64 sendLen)
{
    Client->write(Sendbuff,sendLen);
}

int Communication::ECU_Read(char *Recvbuff, qint64 *recvLen, int timeout, int *commtime)
{
    bool flag;
    int length = 0,read_Size = 0;
    clock_t start = clock();   //记录开始时间
    flag = Client->waitForReadyRead(timeout);
    if(flag == false)
    {
        *recvLen = 0;
    }else
    {
        //读到最后个字节为'\n'  表示读取结束
        read_Size = Client->read(&Recvbuff[length],8192);
        *recvLen = read_Size;
    }
    clock_t finish = clock();   //结束时间
    int duration = (finish - start) ;
    *commtime = duration;
    qDebug("Time iterations: %d ms",duration);

    qDebug("recv :%d\n",*recvLen);
    qDebug("recv :%s\n",Recvbuff);

    if(*recvLen > 0)
    {
        return true;
    }else
    {
        return false;
    }
}
