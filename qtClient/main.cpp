#include <QCoreApplication>
#include "client.h"
#include "readsocket.h"
#include "writeonport.h"
#include <Qthread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread thr1;
    QThread thr2;

    SimpleClient c;
    MyWriteOnPort wr;

    MyReadSocket read(wr.GetSocket());

    wr.Connect();
    c.connect(&read,SIGNAL(TimForUbdate(unsigned int&, double& )), &c, SLOT(UbdateSign(unsigned int&, double&)));

//    wr.moveToThread(&thr1);
//    wr.connect(&thr1, SIGNAL(started()), &wr, SLOT(CreatPacket()));

//    read.moveToThread(&thr2);
//    read.connect(&thr2, SIGNAL(started()), &read, SLOT(onMyReadyRead()));

//    thr1.start();
//    thr2.start();

    return a.exec();
}
