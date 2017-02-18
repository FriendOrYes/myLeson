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

    void Connect();

    void setValue(int newValue);

signals:

    void valueSet(int);

public slots:

    void onConnected();
    void onDisconnected();
    void onBytesWritten(qint64 bytes);
    void onReadyRead();

private:

    int m_value;


    QTcpSocket* m_socket;
    int m_count;
    double Speed;
    int time;
    double num;
};

#endif // CLIENT_H
