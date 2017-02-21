#include "readsocket.h"
#include <QDateTime>

ReadSocket::ReadSocket(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
    , m_time(0)
    , m_num(0)
{     
//     connect(m_server, SIGNAL(readyRead()),
//             this, SLOT(onMyReadyRead()));
}

void ReadSocket::Start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(OnNewConnection()));

    if(!m_server->listen(QHostAddress::Any, 8888))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
    qDebug() << " started!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
}
void ReadSocket::OnNewConnection()
{
    qDebug() << "Connected (server)!";
    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(OnReadyRead()));
    emit NewConnection();
}
void ReadSocket::OnReadyRead()
{
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

    QByteArray byte = socket->readAll();

   // qDebug() << byte;
    if(byte.toStdString().find("test") == -1) return ;
   // qDebug() << byte;
    std::string DataOld = "";
    for(int i = byte.toStdString().find("test") + 4; i < byte.toStdString().find("test") + 17; ++i)
    {
        if(!isalpha(byte[i]))
            DataOld += byte[i];
    }
    m_time += QDateTime::currentMSecsSinceEpoch() - std::atoll(DataOld.c_str());
    //qDebug() << time << " = " << QDateTime::currentMSecsSinceEpoch() << " - " << std::atoll(DataOld.c_str());
    m_num += byte.size();
    if(m_time > 1000)
    {
        emit TimeForeUpdate(m_time, m_num);
        m_time = 0;
        m_num = 0;
    }
}

ReadSocket::~ReadSocket()
{
    delete m_server;
}
