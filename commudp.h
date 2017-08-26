#ifndef COMMUDP_H
#define COMMUDP_H
#include <QtNetwork>
#include "String.h"
#include "QDebug"

class CommUDP
{
public:
    CommUDP();
    CommUDP(QString ip,quint16 port);
    ~CommUDP();
    bool ECU_Connect();
    bool ECU_CommUDP(char *Sendbuff,qint64 sendLen, char *Recvbuff,qint64 *recvLen,int timeout);
    bool ECU_SendUDP(char *Sendbuff,qint64 sendLen);
    bool ECU_Abrot();

    QString IP;
    quint16 Port;
private:
    QUdpSocket *Client;     //´´½¨µÄSOCKET Client

};

#endif // COMMUDP_H
