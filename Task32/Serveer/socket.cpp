#include "socket.h"
#include <QThread>

void Socket::WriteOnClient(QByteArray array)
{
    m_socket->write(array);

}

void Socket::OnReadyRead()
{
    QByteArray array = m_socket->readAll();
    emit HaveNewMessage(array);
}

Socket::Socket(qintptr socketDescr, QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{   
    m_socket->setSocketDescriptor(socketDescr);
    connect(m_socket, SIGNAL(connected()),
            this, SLOT(OnConnected()));
    connect(m_socket, SIGNAL(disconnected()),
            this, SLOT(OnDisconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(OnError(QAbstractSocket::SocketError)));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(OnStateChanged(QAbstractSocket::SocketState)));

}

Socket::~Socket()
{
    delete m_socket;
}
void Socket::OnConnected()
{
    qDebug() << __FUNCTION__;
}
void Socket::OnDisconnected()
{
    qDebug() << "Disconnected";
    thread()->quit();
}
void Socket::OnError(QAbstractSocket::SocketError err)
{
    qWarning() << "Error: " << err;
}

void Socket::OnStateChanged(QAbstractSocket::SocketState state)
{
    qWarning() << "State changed to: " << state;
}
