#include "mywritecl.h"

MyWriteCl::MyWriteCl(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
}
void MyWriteCl::onReadyRead(QByteArray& data)
{
    m_socket->write(data);
}
void MyWriteCl::Connect()
{
    m_socket->connectToHost("127.1.1.1", 9999);
}
