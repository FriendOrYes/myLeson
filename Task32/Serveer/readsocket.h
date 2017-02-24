#ifndef READSOCKET_H
#define READSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "creatsocket.h"

class ReadSocket: public CreatSocket
{
    Q_OBJECT
public:
    ReadSocket(qintptr socketDescr, QObject *parent = 0);
    ~ReadSocket();

private slots:
    void OnReadyRead() override;

};

#endif // READSOCKET_H
