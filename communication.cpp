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
    Client->write(Sendbuff,sendLen);
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

            read_Size = Client->read(&Recvbuff[length],8192);
            length+= read_Size;
            qDebug("recvLen: %d   length : %d    %d\n",read_Size,length,Recvbuff[(length-1)]);

            if(Recvbuff[(length-1)] == '\n')
            {
                *recvLen =length;
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
