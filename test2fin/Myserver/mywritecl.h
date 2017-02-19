#ifndef MYWRITECL_H
#define MYWRITECL_H

#include <QObject>
#include <QTcpSocket>

class MyWriteCl: public QObject
{
    Q_OBJECT

public:
    explicit MyWriteCl(QObject *parent = 0);
    QTcpSocket* GetSocket();
signals:

public slots:
    void onReadyRead(QByteArray );
    void Connect();
    void OnConnect();

private:
     QTcpSocket* m_socket;
     bool IsConnect;
};


#endif // MYWRITECL_H
