#include "server.h"
#include <QTcpSocket>
#include <QThread>
#include <algorithm>


Server::Server(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
    , IsConnect(false)
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
     qDebug() << " started!!!!!!!!!!!!!!!";
}

void Server::onNewConnection()
{
    qDebug() << "Connected (server)!";
    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    emit MynewConnection();
}

void Server::onBytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes << " bytes";
}

void Server::HaveConnect()
{
    IsConnect = true;
}

void Server::onReadyRead()
{
    if(IsConnect)
    {
        QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

        QByteArray data = socket->readAll();

//        int count = 0;
//        for(int i = 0/*index + 1*/; data.size() - 3; ++i)
//        {
//            if(data[i] == 't' && data[i+1] == 'e' && data[i+2] == 's'  && data [i + 3] == 't')
//            {
//                count ++;
//            }
//        }
        qDebug() << "Read: " << data.size() /*<<" "<< count */;

        emit HaveDataForSend(data);
    }
}
