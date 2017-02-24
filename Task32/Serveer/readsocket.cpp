#include "readsocket.h"
#include <QThread>

ReadSocket::ReadSocket(qintptr socketDescr, QObject *parent)
    : CreatSocket(socketDescr)
{
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(OnReadyRead()));
}

ReadSocket::~ReadSocket()
{
   // delete m_socket;
}

void ReadSocket::OnReadyRead()
{

    QByteArray value = m_socket->readAll();
    //qDebug() << "Read :" << value.size();
    emit HaveNewMessage(value);
}
