#ifndef READSOCKET_H
#define READSOCKET_H

#include <QObject>
#include <QTcpSocket>

class ReadSocket: public QObject
{
    Q_OBJECT
public:
    ReadSocket(qintptr socketDescr, QObject *parent = 0);
    ~ReadSocket();

signals:
    void SocketReadData(QByteArray array);
private slots:
    void OnReadyRead();
    void OnConnected();
    void OnDisconnected();
    void OnError(QAbstractSocket::SocketError err);
    void OnStateChanged(QAbstractSocket::SocketState state);

private :
    QTcpSocket *m_socket;
};

#endif // READSOCKET_H
