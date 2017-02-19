#ifndef READSOCKET_H
#define READSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class MyReadSocket: public QObject
{
    Q_OBJECT
public:
    MyReadSocket(QObject *parent = 0);
    //void Connect();
    ~MyReadSocket();

public slots:
    void onMyReadyRead();
    void start();
    void onNewConnection();
signals:

    int TimForUbdate(unsigned int&, double&);
private:
    QTcpServer * m_server;

    unsigned int time;
    double num;
};

#endif // READSOCKET_H
