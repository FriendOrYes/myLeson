#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

#include <memory>
#include <QString>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

signals:
    void HaveDataForSend(QByteArray );
    void MynewConnection();
public slots:
    void start();
    void onNewConnection();
    void onBytesWritten(qint64 bytes);
    void onReadyRead();
    void HaveConnect();
private:
    QTcpServer* m_server;
    bool IsConnect ;
};

#endif // SERVER_H
