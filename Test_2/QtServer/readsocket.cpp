#include "readsocket.h"
#include <QTcpSocket>
#include <QThread>
#include <algorithm>


ReadSocket::ReadSocket(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
    , m_isConnect(false)
{

}

ReadSocket::~ReadSocket()
{
    delete m_server;
}

void ReadSocket::Start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(OnNewConnection()));

    if(!m_server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
     qDebug() << " started!!!!!!!!!!!!!!!";
}

void ReadSocket::OnNewConnection()
{
    qDebug() << "Connected (server)!";
    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(OnReadyRead()));
    emit NewConnection();
}


void ReadSocket::HaveConnect()
{
    m_isConnect = true;
}

void ReadSocket::OnReadyRead()
{
    if(m_isConnect)
    {
        QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

        QByteArray data = socket->readAll();

        qDebug() << "Read: " << data.size() /*<<" "<< count */;

        emit HaveDataForeSend(data);
    }
}
