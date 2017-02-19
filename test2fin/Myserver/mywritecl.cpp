#include "mywritecl.h"


MyWriteCl::MyWriteCl(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , IsConnect(false)
{
    connect(m_socket, SIGNAL(connected()),
            this, SLOT(OnConnect()));
}

void MyWriteCl::OnConnect()
{
    qDebug() << "We connected!!!!: ";
    IsConnect = true;
}
void MyWriteCl::onReadyRead(QByteArray data)
{
    // qDebug() << "We have signal: ";
    if(IsConnect)
    {
        //qDebug() << "We wrote: ";
        m_socket->write(data);
    }
}
void MyWriteCl::Connect()
{
    qDebug() << "We try connected: ";

    m_socket->connectToHost("127.2.2.2", 8888);

}
QTcpSocket* MyWriteCl::GetSocket()
{
    return m_socket;
}
