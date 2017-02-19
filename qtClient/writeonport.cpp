#include "writeonport.h"
#include <QDateTime>

MyWriteOnPort::MyWriteOnPort(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
    connect(m_socket, SIGNAL(connected()),
            this, SLOT(CreatPacket()));
    connect(m_socket, SIGNAL(bytesWritten(qint64)),
            this, SLOT(CreatPacket()));
}

void MyWriteOnPort::CreatPacket()
{
    const int Len = 64*1024;
    std::string packet = "test";
    packet += std::to_string(QDateTime::currentMSecsSinceEpoch());

    for(int i = packet.length(); i < Len; ++i)
    {
        packet += 'a';
    }
    m_socket->write(packet.c_str());
}

void MyWriteOnPort::Connect()
{
    m_socket->connectToHost("127.0.0.1", 9999);
}

QTcpSocket* MyWriteOnPort::GetSocket()
{
    return m_socket;
}
