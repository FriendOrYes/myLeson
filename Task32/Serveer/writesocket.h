#ifndef WRITESOCKET_H
#define WRITESOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "creatsocket.h"

class WriteSocket: public CreatSocket
{
    Q_OBJECT
public:
    WriteSocket(qintptr socketDescr, QObject *parent = 0);
    ~WriteSocket();
private slots:
    void WriteOnClient(QByteArray array) override;
};

#endif // WRITESOCKET_H
