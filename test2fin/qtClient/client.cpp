#include "client.h"
#include <QDateTime>
#include <QThread>
#include <algorithm>
#include <memory>
#include <cstring>
#include <iostream>

#include <QString>


SimpleClient::SimpleClient(QObject *parent)
    : QObject(parent)
    , Speed(0)
{

}

void SimpleClient::UbdateSign(unsigned int time, double num)
{
    Speed = num / time;
    std::cout <<  "Speed - " << Speed << "B/s" << std::endl;
    time = 0;
    num = 0;
}

//QTcpSocket* SimpleClient::GetSocket()
//{
//    return m_socket;
//}

SimpleClient::~SimpleClient()
{
   // delete m_socket;
}


//void SimpleClient::setValue(int newValue)
//{
//    m_value = newValue;
//    emit valueSet(m_value);
//}


//void SimpleClient::onDisconnected()
//{
//    //qDebug() << "Disconnected!";
//}

//void SimpleClient::onBytesWritten(qint64 bytes)
//{
//    //qDebug() << "We wrote: " << bytes << " bytes";
//}

//void SimpleClient::onReadyRead()
//{

////    QByteArray byte = m_socket->readAll();

////    int indxIndef = 0;

////    for(int i = 0; i < byte.size() - 3; ++i)
////    {
////        if(byte[i] == 't' && byte[i + 1] == 'e' && byte[i + 2] == 's' && byte[i + 3] == 't')
////        {
////            indxIndef = i + 3;
////        }
////    }
////    std::string DataOld = "";
////    for(int i = indxIndef + 1; i < byte.length(); ++i)
////    {
////        char c = byte[i];
////        if(!isalpha(c))
////            DataOld += byte[i];
////    }

//  //  time += QDateTime::currentMSecsSinceEpoch() - std::atoll(DataOld.c_str());
//    //qDebug() << time << " = " << QDateTime::currentMSecsSinceEpoch() << " - " << std::atoll(DataOld.c_str());
//  //  num += byte.size();
////    if(time > 1000)
////    {
////        emit TimForUbdate();
////    }

//  //  CreatPacket();
//   // m_socket->close();
//}


//void SimpleClient::onConnected()
//{
//    //qDebug() << "Connected (client)!";

////    std::string pak = "";
//    CreatPacket(/*pak*/);
//   // m_socket->write(pak.c_str());
//    //qDebug() << "Written!";
//}

//void SimpleClient::CreatPacket(/*std::string& packet*/)
//{
////    const int Len = 64*1024;
////    std::string packet = "test";
////    packet += std::to_string(QDateTime::currentMSecsSinceEpoch());

////    for(int i = packet.length(); i < Len; ++i)
////    {
////        packet += 'a';
////    }
////    m_socket->write(packet.c_str());
//}
