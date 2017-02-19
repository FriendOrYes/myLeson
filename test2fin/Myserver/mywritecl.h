#ifndef MYWRITECL_H
#define MYWRITECL_H

#include <QObject>
#include <QTcpSocket>

class MyWriteCl: public QObject
{
    Q_OBJECT

public:
    explicit MyWriteCl(QObject *parent = 0);

signals:

public slots:
    void onReadyRead(QByteArray& );
    void Connect();

private:
     QTcpSocket* m_socket;
};


#endif // MYWRITECL_H
