#include <iostream>
#include "readsocket.h"
#include <QCoreApplication>
#include <QThread>
#include "writeonport.h"


using namespace std;

int main(int argc, char *argv[])
{
    cout << "Enter!" << endl;

    QCoreApplication app(argc, argv);
    ReadSocket Read;
    WriteOnPort Write;
    Read.Start();
    QThread threadRead;
    Write.moveToThread(&threadRead);

    Write.connect(&Read, SIGNAL(HaveDataForeSend(QByteArray )), &Write, SLOT(OnReadyRead(QByteArray)));

    Write.connect(&threadRead, SIGNAL(started()), &Write, SLOT(Connect()));
    Read.connect(Write.GetSocket(), SIGNAL(connected()), &Read, SLOT(OnNewConnection()));

    threadRead.start();

    return app.exec();
}
