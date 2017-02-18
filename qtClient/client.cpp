#include "client.h"
#include <QDateTime>
#include <QThread>
#include <algorithm>
#include <memory>
#include <cstring>

#include <QString>


SimpleClient::SimpleClient(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , m_count(0)
    , Speed(0)
    , time(0)
    , num(0)
{

    connect(m_socket, SIGNAL(connected()),          this, SLOT(onConnected()));
    connect(m_socket, SIGNAL(readyRead()),          this, SLOT(onReadyRead()));
    connect(m_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));
    connect(m_socket, SIGNAL(disconnected()),       this, SLOT(onDisconnected()));

}

SimpleClient::~SimpleClient()
{
    delete m_socket;
}

void SimpleClient::Connect()
{
    m_socket->connectToHost("127.0.0.1", 9999);
}

void SimpleClient::setValue(int newValue)
{
    m_value = newValue;
    emit valueSet(m_value);
}

void SimpleClient::onConnected()
{
    //qDebug() << "Connected (client)!";

    const int size = 64;
    char packet[size] = "test";

    std::string Date = std::to_string(QDateTime::currentMSecsSinceEpoch());

    int j = 0;
    for(int i = strlen(packet); j < Date.length(); ++i)
    {
        packet[i] = Date[j++];
    }
    std::shared_ptr<char*> data = std::make_shared<char*>(new char[size - strlen(packet)]);
    memset(*data, 'a', size - strlen(packet));
    std::strcat(packet, *data);

    //qDebug() << packet;

    m_socket->write(packet);

    //qDebug() << "Written!";
}

void SimpleClient::onDisconnected()
{
    //qDebug() << "Disconnected!";
}

void SimpleClient::onBytesWritten(qint64 bytes)
{
    //qDebug() << "We wrote: " << bytes << " bytes";
}

void SimpleClient::onReadyRead()
{
   // qDebug() << "Reading...";
    QByteArray byte = m_socket->readAll();

    int indxIndef = 0;
    //std::string str = byte.data();
    for(int i = 0; i < byte.size() - 3; ++i)
    {
        if(byte[i] == 't' && byte[i + 1] == 'e' && byte[i + 2] == 's' && byte[i + 3] == 't')
        {
            indxIndef = i + 3;
        }
    }

    //qDebug() << byte;
    //qDebug() << indxIndef;

    std::string DataOld = "";
    //int j = 0;
    for(int i = indxIndef + 1; i < byte.length(); ++i)
    {
        char c = byte[i];
        if(!std::isalpha(c))
            DataOld += byte[i];
    }

    time += QDateTime::currentMSecsSinceEpoch() - std::atoi(DataOld.c_str());
    //qDebug() << time << " = " << QDateTime::currentMSecsSinceEpoch() << " - " << DataOld.c_str();
    //time
    num += byte.size();
    if(m_count++ > 1000)
    {
        Speed = num / time;
        qDebug() << "Speed - " << Speed << " " << time;
        time = 0;
        m_count = 0;
        num = 0;
    }
    m_socket->close();
    Connect();
}
