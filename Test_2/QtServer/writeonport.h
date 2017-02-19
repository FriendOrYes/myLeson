#ifndef MYWRITECL_H
#define MYWRITECL_H

#include <QObject>
#include <QTcpSocket>

class WriteOnPort: public QObject
{
    Q_OBJECT

public:
    explicit WriteOnPort(QObject *parent = 0);
    QTcpSocket* GetSocket();
signals:

public slots:
    void OnReadyRead(QByteArray );
    void Connect();
    void OnConnect();

private:
     QTcpSocket* m_socket;
     bool m_isConnect;
};


#endif // MYWRITECL_H
