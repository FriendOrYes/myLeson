#ifndef READSOCKET_H
#define READSOCKET_H

#include <QObject>
#include <QTcpSocket>

class ReadSocket: public QObject
{
    Q_OBJECT
public:
    ReadSocket();
private:
    QTcpSocket* m_socket;
};

#endif // READSOCKET_H
