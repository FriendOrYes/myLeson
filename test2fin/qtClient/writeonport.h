#ifndef WRITEONPORT_H
#define WRITEONPORT_H

#include <QObject>
#include <QTcpSocket>

class MyWriteOnPort: public QObject
{
    Q_OBJECT
public:
    MyWriteOnPort(QObject *parent = 0);
    QTcpSocket* GetSocket();
    ~MyWriteOnPort();

public slots:
    void Connect();
    void CreatPacket();
    //void HaveConnect();
private:
    QTcpSocket* m_socket;
    bool isConnectMy;
};

#endif // WRITEONPORT_H
