#ifndef WRITEONPORT_H
#define WRITEONPORT_H

#include <QObject>
#include <QTcpSocket>

class WriteOnPort: public QObject
{
    Q_OBJECT
public:
    WriteOnPort(QObject *parent = 0);
    QTcpSocket* GetSocket();
    ~WriteOnPort();

public slots:
    void Connect();
    void CreatPacket();
    //void HaveConnect();
private:
    QTcpSocket* m_socket;
    bool m_isConnectMy;
};

#endif // WRITEONPORT_H
