#include "readsocket.h"
#include <QThread>

ReadSocket::ReadSocket(qintptr socketDescr, QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
    m_socket->setSocketDescriptor(socketDescr);
    connect(m_socket, SIGNAL(connected()),
            this, SLOT(OnConnected()));
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(OnReadyRead()));
    connect(m_socket, SIGNAL(disconnected()),
            this, SLOT(OnDisconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(OnError(QAbstractSocket::SocketError)));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(OnStateChanged(QAbstractSocket::SocketState)));
}

ReadSocket::~ReadSocket()
{
    delete m_socket;
}

void ReadSocket::OnReadyRead()
{

    QByteArray value = m_socket->readAll();
    //qDebug() << "Read :" << value.size();
    emit SocketReadData(value);
}

void ReadSocket::OnConnected()
{
    qDebug() << __FUNCTION__;
}
void ReadSocket::OnDisconnected()
{
    qDebug() << "Disconnected";
    thread()->quit();
}
void ReadSocket::OnError(QAbstractSocket::SocketError err)
{
    qWarning() << "Error: " << err;
}

void ReadSocket::OnStateChanged(QAbstractSocket::SocketState state)
{
    qWarning() << "State changed to: " << state;
}
