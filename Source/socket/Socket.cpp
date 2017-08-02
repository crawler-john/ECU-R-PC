#include <QtNetwork>
#include "Socket.h"
#include "String.h"
#include "QDebug"
void testSocket(void)
{
    QTcpSocket *client;
    char *data="hello qt!";
    char recv[4096] = {'\0'};
    qint64 maxLen = 4096;
    client = new QTcpSocket();
    client->connectToHost(QHostAddress("192.168.1.106"), 8899);
    client->write(data);
    client->waitForReadyRead(15000);
    client->read(recv,4096);
    qDebug("%s\n",recv);
    client->disconnect();

}

