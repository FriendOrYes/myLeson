#ifndef READSOCKET_H
#define READSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class ReadSocket: public QObject
{
    Q_OBJECT
public:
    ReadSocket(QObject *parent = 0);
    //void Connect();
    ~ReadSocket();

public slots:
    void OnReadyRead();
    void Start();
    void OnNewConnection();
signals:
    void NewConnection();
    void TimeForeUpdate(unsigned int, double);
private:
    QTcpServer* m_server;

    unsigned int m_time;
    double m_num;
};

#endif // READSOCKET_H
