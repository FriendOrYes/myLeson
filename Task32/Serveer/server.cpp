#include "server.h"
#include "writesocket.h"
#include "readsocket.h"
#include <QThread>
#include <QTcpSocket>

Server::Server(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
    , m_isClientFirstConnect(true)
{

}

void Server::Start()
{
    connect(m_server,SIGNAL(newConnection()),SLOT(OnConnection()));
    if(!m_server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}
void Server::OnConnection()
{

    QTcpSocket *socket = m_server->nextPendingConnection();
    QThread* thread = new QThread();

    if(m_isClientFirstConnect)
    {
        qDebug() << "Connected!Read Client";
        //ReadSocket* readSocket = new ReadSocket(m_diskrRead);
        m_diskrRead = socket->socketDescriptor();
        WriteSocket* writeSocket = new WriteSocket(socket->socketDescriptor());
        writeSocket->moveToThread(thread);
        writeSocket->connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        writeSocket->connect(thread, SIGNAL(finished()), writeSocket,   SLOT(deleteLater()));
        m_isClientFirstConnect = false;
    }
    else
    {
        qDebug() << "Connected!Write Client";

        ReadSocket*readSocket = new ReadSocket(socket->socketDescriptor());
        readSocket->moveToThread(thread);
        readSocket->connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        readSocket->connect(thread, SIGNAL(finished()), readSocket,   SLOT(deleteLater()));
        readSocket->connect(readSocket, SIGNAL(HaveNewMessage(QByteArray)), new WriteSocket(m_diskrRead), SLOT(WriteOnClient(QByteArray)));
    }
    thread->start();
}

Server::~Server()
{
    delete m_server;
   // delete m_diskrRead;
}
void Server::OnHaveMessageFromReadSocket(QByteArray byte)
{

    emit HaveMessageFromReadSocket(byte);
    ////
    ////PROCESING DATA
    ////
}
