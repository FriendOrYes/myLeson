#include "writeonport.h"


WriteOnPort::WriteOnPort(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , m_isConnect(false)
{
    connect(m_socket, SIGNAL(connected()),
            this, SLOT(OnConnect()));
}

void WriteOnPort::OnConnect()
{
    qDebug() << "We connected!!!!: ";
    m_isConnect = true;
}
void WriteOnPort::OnReadyRead(QByteArray data)
{
    // qDebug() << "We have signal: ";
    if(m_isConnect)
    {
        //qDebug() << "We wrote: ";
        m_socket->write(data);
    }
}
void WriteOnPort::Connect()
{
    qDebug() << "We try connected: ";

    m_socket->connectToHost("127.0.0.1", 8888);

}
QTcpSocket* WriteOnPort::GetSocket()
{
    return m_socket;
}
