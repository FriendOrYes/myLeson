#include "writeonport.h"
#include <QDateTime>

WriteOnPort::WriteOnPort(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , m_isConnectMy(false)
{
    connect(m_socket, SIGNAL(connected()),
            this, SLOT(CreatPacket()));
    connect(m_socket, SIGNAL(bytesWritten(qint64)),
            this, SLOT(CreatPacket()));
}

WriteOnPort::~WriteOnPort()
{
    delete m_socket;
}

void WriteOnPort::CreatPacket()
{
   // qDebug() << "Creat packet";
    const int Len = 4*1024;
    std::string packet = "test";
    packet += std::to_string(QDateTime::currentMSecsSinceEpoch());

    for(int i = packet.length(); i < Len; ++i)
    {
        packet += 'a';
    }
    m_socket->write(packet.c_str());
}

void WriteOnPort::Connect()
{
    m_socket->connectToHost("127.0.0.1", 9999);
}

QTcpSocket* WriteOnPort::GetSocket()
{
    return m_socket;
}

