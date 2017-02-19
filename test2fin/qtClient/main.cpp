#include <QCoreApplication>
#include "client.h"
#include "readsocket.h"
#include "writeonport.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread thr1;
    QThread thr2;

    SimpleClient c;
    MyWriteOnPort wr;

    MyReadSocket read;


    c.connect(&read,SIGNAL(TimForUbdate(unsigned int, double )), &c, SLOT(UbdateSign(unsigned int, double)));

    wr.moveToThread(&thr1);
    read.moveToThread(&thr2);

    read.connect(&thr2, SIGNAL(started()), &read, SLOT(start()));
    wr.connect(&read, SIGNAL(GetConnection()), &wr, SLOT(Connect()));
    thr1.start();
    thr2.start();
   // read.start();
    return a.exec();
}
