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
    void HaveDataForeSend(QByteArray );
    void NewConnection();
public slots:
    void Start();
    void OnNewConnection();
    void OnReadyRead();
    void HaveConnect();
private:
    QTcpServer* m_server;
    bool m_isConnect ;
};

#endif // SERVER_H
