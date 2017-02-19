#include "readsocket.h"
#include <QDateTime>

MyReadSocket::MyReadSocket(QTcpSocket* socket, QObject *parent)
    : QObject(parent)
    , m_socket(socket)
    , time(0)
    , num(0)
{     
     connect(m_socket, SIGNAL(readyRead()),
             this, SLOT(onMyReadyRead()));
}

void MyReadSocket::onMyReadyRead()
{
    QByteArray byte = m_socket->readAll();

    int indxIndef = 0;

    for(int i = 0; i < byte.size() - 3; ++i)
    {
        if(byte[i] == 't' && byte[i + 1] == 'e' && byte[i + 2] == 's' && byte[i + 3] == 't')
        {
            indxIndef = i + 3;
        }
    }
    std::string DataOld = "";
    for(int i = indxIndef + 1; i < byte.length(); ++i)
    {
        char c = byte[i];
        if(!isalpha(c))
            DataOld += byte[i];
    }

    time += QDateTime::currentMSecsSinceEpoch() - std::atoll(DataOld.c_str());
    //qDebug() << time << " = " << QDateTime::currentMSecsSinceEpoch() << " - " << std::atoll(DataOld.c_str());
    num += byte.size();
    if(time > 1000)
    {
        emit TimForUbdate(time, num);
    }
}

void MyReadSocket::Connect()
{
    m_socket->connectToHost("127.0.0.1", 9999);
}
