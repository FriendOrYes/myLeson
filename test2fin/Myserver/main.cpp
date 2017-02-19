#include <iostream>
#include "server.h"
#include <QCoreApplication>
#include <QThread>
#include "mywritecl.h"


using namespace std;

int main(int argc, char *argv[])
{
    cout << "Enter!" << endl;

    QCoreApplication app(argc, argv);
    Server s;
    MyWriteCl SerRead;
    s.start();
    QThread th1;
    SerRead.moveToThread(&th1);

    SerRead.connect(&s, SIGNAL(HaveDataForSend(QByteArray )), &SerRead,SLOT(onReadyRead(QByteArray)));
    SerRead.connect(&s, SIGNAL(newConnection()), &SerRead,SLOT(Connect()));
    th1.start();

    return app.exec();
}
