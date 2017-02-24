#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>


class Server: public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

signals:

   void  HaveMessageFromReadSocket(QByteArray);
private slots:
   void OnConnection();
   void  OnHaveMessageFromReadSocket(QByteArray);
public :
    void Start();
private:
    QTcpServer *m_server;
    bool m_isClientFirstConnect;
    qintptr m_diskrRead;

};

#endif // SERVER_H
