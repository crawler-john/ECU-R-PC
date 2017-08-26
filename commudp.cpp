#include "commudp.h"

CommUDP::CommUDP()
{
    this->IP = "10.10.100.254";
    this->Port = 49000;
    Client = new QUdpSocket;

}

CommUDP::CommUDP(QString ip, quint16 port)
{
    this->IP = ip;
    this->Port = port;
    Client = new QUdpSocket;
}

CommUDP::~CommUDP()
{
    delete Client;
    Client = NULL;
}

bool CommUDP::ECU_Connect()
{
    Client->connectToHost(QHostAddress(IP), Port);
}

bool CommUDP::ECU_CommUDP(char *Sendbuff, qint64 sendLen, char *Recvbuff, qint64 *recvLen, int timeout)
{

    Client->write(Sendbuff,sendLen);
    Client->waitForReadyRead(timeout);
    *recvLen = Client->read(Recvbuff,4096);
    qDebug(" UDP %d \n",*recvLen);
    if(*recvLen > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool CommUDP::ECU_SendUDP(char *Sendbuff, qint64 sendLen)
{
    Client->write(Sendbuff,sendLen);
}

bool CommUDP::ECU_Abrot()
{
    Client->abort();
}
