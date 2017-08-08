#include "communication.h"

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

bool Communication::ECU_Communication(char *Sendbuff, qint64 sendLen, char *Recvbuff, qint64 *recvLen, int timeout)
{
    Client->connectToHost(QHostAddress(IP), Port);
    Client->write(Sendbuff,sendLen);
    Client->waitForReadyRead(timeout);
    *recvLen = Client->read(Recvbuff,4096);
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
