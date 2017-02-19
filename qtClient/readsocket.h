#ifndef READSOCKET_H
#define READSOCKET_H

#include <QObject>
#include <QTcpSocket>

class MyReadSocket: public QObject
{
    Q_OBJECT
public:
    MyReadSocket(QTcpSocket *m_socket, QObject *parent = 0);
    void Connect();

public slots:
    void onMyReadyRead();
signals:
    int TimForUbdate(unsigned int&, double&);
private:
    QTcpSocket* m_socket;

    unsigned int time;
    double num;
};

#endif // READSOCKET_H
