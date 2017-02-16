#include "tablotv.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabloTV w;
    w.show();
    qDebug() << "show";

    return a.exec();
}
