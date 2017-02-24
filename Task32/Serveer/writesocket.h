#ifndef WRITESOCKET_H
#define WRITESOCKET_H

#include <QObject>
#include <QTcpSocket>

class WriteSocket: public QObject
{
    Q_OBJECT
public:
    WriteSocket(qintptr socketDescr, QObject *parent = 0);
    ~WriteSocket();
private slots:
    void WriteOnClient(QByteArray array);
    void OnDisconnected();
    void OnError(QAbstractSocket::SocketError err);
    void OnStateChanged(QAbstractSocket::SocketState state);

private :
    QTcpSocket *m_socket;
};

#endif // WRITESOCKET_H
