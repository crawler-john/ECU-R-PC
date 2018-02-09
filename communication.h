#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <QtNetwork>
#include "String.h"
#include "QDebug"


class Communication
{
public:
    Communication();
    Communication(QString ip,quint16 port);
    ~Communication();

    bool ECU_Communication(char *Sendbuff,qint64 sendLen, char *Recvbuff,qint64 *recvLen,int timeout,int *commtime);
    bool IDWrite_Communication(char *Sendbuff,qint64 sendLen, char *Recvbuff,qint64 *recvLen,int timeout,int *commtime);
    bool ECU_Connect();
    bool ECU_Disconnect();

    int ECU_Write(char *Sendbuff, qint64 sendLen);
    int ECU_Read(char *Recvbuff, qint64 *recvLen, int timeout,int *commtime);

private:
    QTcpSocket *Client;     //´´½¨µÄSOCKET Client
    QString IP;
    quint16 Port;
};

#endif // COMMUNICATION_H
