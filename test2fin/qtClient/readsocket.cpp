#include "readsocket.h"
#include <QDateTime>

MyReadSocket::MyReadSocket(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
    , time(0)
    , num(0)
{     
//     connect(m_server, SIGNAL(readyRead()),
//             this, SLOT(onMyReadyRead()));
}

void MyReadSocket::start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    if(!m_server->listen(QHostAddress::Any, 8888))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}
void MyReadSocket::onNewConnection()
{
    qDebug() << "Connected (server)!";

    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onMyReadyRead()));
}
void MyReadSocket::onMyReadyRead()
{
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

    QByteArray byte = socket->readAll();
    //int indxIndef = 0;

    std::string DataOld = "";
    for(int i = atoll(std::strstr(byte,"test"))/*index + 1*/; i < byte.length(); ++i)
    {
        if(!isalpha(byte[i]))
            DataOld += byte[i];
    }

    time += QDateTime::currentMSecsSinceEpoch() - std::atoll(DataOld.c_str());
    //qDebug() << time << " = " << QDateTime::currentMSecsSinceEpoch() << " - " << std::atoll(DataOld.c_str());
    num += byte.size();
    if(time > 1000)
    {
        emit TimForUbdate(time, num);
    }
}

//void MyReadSocket::Connect()
//{
//    m_socket->connectToHost("127.1.1.1", 9999);
//}

MyReadSocket::~MyReadSocket()
{
    delete m_server;
}
