#ifndef WRITEONPORT_H
#define WRITEONPORT_H

#include <QObject>
#include <QTcpSocket>

class WriteOnPort: public QObject
{
    Q_OBJECT
public:
    //WriteOnPort();

private:
    QTcpSocket* m_socket;
};

#endif // WRITEONPORT_H
