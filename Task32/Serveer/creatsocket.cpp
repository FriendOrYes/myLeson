#include "creatsocket.h"
#include <QThread>

void CreatSocket::WriteOnClient(QByteArray array)
{
    m_socket->write(array);

}

void CreatSocket::OnReadyRead()
{
    QByteArray array = m_socket->readAll();
    emit HaveNewMessage(array);
}

CreatSocket::CreatSocket(qintptr socketDescr, QObject *parent)
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

CreatSocket::~CreatSocket()
{
    delete m_socket;
}
void CreatSocket::OnConnected()
{
    qDebug() << __FUNCTION__;
}
void CreatSocket::OnDisconnected()
{
    qDebug() << "Disconnected";
    thread()->quit();
}
void CreatSocket::OnError(QAbstractSocket::SocketError err)
{
    qWarning() << "Error: " << err;
}

void CreatSocket::OnStateChanged(QAbstractSocket::SocketState state)
{
    qWarning() << "State changed to: " << state;
}
