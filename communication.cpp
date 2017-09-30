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
    clock_t start = clock();   //��¼��ʼʱ��


    //��ȡ���ݣ������������\n  ��ʾ�������
    while(1)
    {
        flag =  Client->waitForReadyRead(timeout);
        if(flag == false)
        {
            *recvLen = 0;
            break;
        }else
        {
            //���������ֽ�Ϊ'\n'  ��ʾ��ȡ����

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
    //��ȡ����ʱ��
    clock_t finish = clock();   //����ʱ��
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
