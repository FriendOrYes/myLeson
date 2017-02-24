#ifndef CREATSOCKET_H
#define CREATSOCKET_H

#include <QObject>
#include <QTcpSocket>


class CreatSocket: public QObject
{
    Q_OBJECT
signals:
    void HaveNewMessage(QByteArray);
protected slots:
    virtual void WriteOnClient(QByteArray);
    virtual void OnReadyRead();
    void OnConnected();
    void OnDisconnected();
    void OnError(QAbstractSocket::SocketError err);
    void OnStateChanged(QAbstractSocket::SocketState state);

public:
    CreatSocket(qintptr socketDescr, QObject *parent = 0);
    virtual ~CreatSocket();
protected:
    QTcpSocket *m_socket;

};

#endif // CREATSOCKET_H
