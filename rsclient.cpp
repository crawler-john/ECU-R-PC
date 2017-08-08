#include "rsclient.h"

RSClient::RSClient()
{
    rsClient = new QTcpSocket;
}

RSClient::~RSClient()
{
    delete rsClient;
    rsClient = NULL;
}

bool RSClient::ECU_Communication(char *Sendbuff,qint64 sendLen, char *Recvbuff,qint64 *recvLen,int timeout)
{
    rsClient->connectToHost(QHostAddress("10.10.100.254"), 8899);
    rsClient->write(Sendbuff,sendLen);
    rsClient->waitForReadyRead(timeout);
    *recvLen = rsClient->read(Recvbuff,4096);
    qDebug("recv :%s\n",Recvbuff);
    rsClient->abort();
    if(*recvLen > 0)
    {
        return true;
    }else
    {
        return false;
    }
}
