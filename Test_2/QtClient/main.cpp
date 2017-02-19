#include <QCoreApplication>
#include "readsocket.h"
#include "writeonport.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread thrWrite;
    QThread thrRead;

    WriteOnPort write;
    ReadSocket read;


    read.connect(&read, &ReadSocket::TimeForeUpdate, [](unsigned int time, double num)
                                            {
                                                qDebug() <<  "Speed - " << num / time << "B/s";
                                                time = 0;
                                                num = 0;
                                            }
    );

    write.moveToThread(&thrWrite);
    read.moveToThread(&thrRead);

    read.connect(&thrRead, SIGNAL(started()), &read, SLOT(Start()));
    write.connect(&read, SIGNAL(NewConnection()), &write, SLOT(Connect()));
    thrWrite.start();
    thrRead.start();


    return a.exec();
}
