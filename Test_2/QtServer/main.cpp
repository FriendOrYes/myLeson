#include <iostream>
#include "server.h"
#include <QCoreApplication>
#include <QThread>
#include "writeonport.h"


using namespace std;

int main(int argc, char *argv[])
{
    cout << "Enter!" << endl;

    QCoreApplication app(argc, argv);
    Server server;
    WriteOnPort SerRead;
    server.Start();
    QThread threadRead;
    SerRead.moveToThread(&threadRead);

    SerRead.connect(&server, SIGNAL(HaveDataForeSend(QByteArray )), &SerRead, SLOT(OnReadyRead(QByteArray)));

    SerRead.connect(&threadRead, SIGNAL(started()), &SerRead, SLOT(Connect()));
    server.connect(SerRead.GetSocket(), SIGNAL(connected()), &server, SLOT(OnNewConnection()));

    threadRead.start();

    return app.exec();
}
