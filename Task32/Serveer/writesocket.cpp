#include "writesocket.h"
#include <QThread>

WriteSocket::WriteSocket(qintptr socketDescr, QObject *parent)
    : Socket(socketDescr)
{
}

WriteSocket::~WriteSocket()
{
}

void WriteSocket::WriteOnClient(QByteArray array)
{
    //qDebug() << "Write:" << array.size();
    m_socket->write(array);
}
