#include "writesocket.h"
#include <QThread>

WriteSocket::WriteSocket(qintptr socketDescr, QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
    m_socket->setSocketDescriptor(socketDescr);
    connect(m_socket, SIGNAL(disconnected()),       this, SLOT(OnDisconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)),              this, SLOT(OnError(QAbstractSocket::SocketError)));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),       this, SLOT(OnStateChanged(QAbstractSocket::SocketState)));
}

WriteSocket::~WriteSocket()
{
    delete m_socket;
}

void WriteSocket::WriteOnClient(QByteArray array)
{
    //qDebug() << "Write:" << array.size();
    m_socket->write(array);
}
void WriteSocket::OnDisconnected()
{
    qDebug() << "Disconnected";
    thread()->quit();
}
void WriteSocket::OnError(QAbstractSocket::SocketError err)
{
    qWarning() << "Error: " << err;
}

void WriteSocket::OnStateChanged(QAbstractSocket::SocketState state)
{
    qWarning() << "State changed to: " << state;
}
