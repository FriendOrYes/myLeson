#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class SimpleClient : public QObject
{
    Q_OBJECT
public:
    explicit SimpleClient(QObject *parent = 0);
    ~SimpleClient();

    //QTcpSocket* GetSocket();
signals:


public slots:

    void UbdateSign(unsigned int time, double num);

private:


     //QTcpSocket* m_socket;
    int m_count;
    double Speed;

};

#endif // CLIENT_H
