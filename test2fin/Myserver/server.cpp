#include "server.h"
#include <QTcpSocket>
#include <QThread>
#include <algorithm>

Server::Server(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
{

}


Server::~Server()
{
    delete m_server;
}

void Server::start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    if(!m_server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void Server::onNewConnection()
{
    qDebug() << "Connected (server)!";

    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Server::onBytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes << " bytes";

//    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
//    socket->close();
}


void Server::onReadyRead()
{

    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

    QByteArray data = socket->readAll();

    qDebug() << "Read: " << data.size() << endl;

    emit HaveDataForSend(data);
}
