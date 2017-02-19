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
    void Connect();
    ~MyWriteOnPort();

public slots:
    void CreatPacket();

private:
    QTcpSocket* m_socket;

};

#endif // WRITEONPORT_H
