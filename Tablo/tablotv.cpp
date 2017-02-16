#include "tablotv.h"
#include "ui_tablotv.h"

TabloTV::TabloTV(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TabloTV)
    , NumberOfLight(10)
    , m_begin(1)
    , comp(90)
{
    ui->setupUi(this);
    paintTimer = new QTimer(this);
    paintTimer->start(300);
    connect(paintTimer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
}

TabloTV::~TabloTV()
{
    delete ui;
}

void TabloTV::on_pushButton_clicked()
{
    //emit on_pushButton_clicked();
}

void TabloTV::updatePixmap()
{
    SetLight(m_begin);
}
void TabloTV::ChakeStart(int& begin, const int& Compare)
{
    if(begin > Compare)
    {
        begin = 1;
    }
}

void TabloTV::SetLight(int& begin)
{

    QPainter paint;
    QPixmap graph(540,370);
    paint.begin(&graph); // запускаем отрисовку

    //    int count = 10;
    //    while(count--)
    //    {
    paint.eraseRect(0, 0, 540, 370); // очищаем рисунок

    //        for(int i = 1; i < NumberOfLight; ++i)
    //        {
    //            for(int j = 1; j < 60; ++j)
    //            {
    //                paint.setPen(QPen(Qt::green,8 ,Qt::SolidLine));
    //                paint.drawEllipse(j * 10, i * 10 , 4, 4);
    //            }
    //        }

    int fl = 10;
    SetA(paint, begin, fl);
    SetN(paint, begin, fl);
    SetT(paint, begin, fl);
    SetO(paint, begin, fl);
    SetN(paint, begin, fl);

    SetSpace(begin);
    SetI(paint, begin, fl);

    SetSpace(begin);
    SetH(paint, begin, fl);
    SetA(paint, begin, fl);
    SetT(paint, begin, fl);
    SetE(paint, begin, fl);

    //   SetSpace(begin);
    SetSpace(begin);

    SetY(paint, begin, fl);
    SetO(paint, begin, fl);
    SetU(paint, begin, fl);

    ui->label->setPixmap(graph); // и помещаем рисунок на форму
    paint.end();
}

//void TabloTV::ConvertFloor(int& floor)
//{
//    floor += 5;
//}

void TabloTV::SetA(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if((i == begin + 2 && j == floor) ||
                    (j == floor + 1 && (i == begin + 1 || i == begin + 3 )) ||
                    (j == floor + 2 && (i >= begin + 1 && i <= begin + 3)) ||
                    ((j >= floor + 2 && j <= floor + 4 ) && (i == begin || i == begin + 4)))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10, 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}

void TabloTV::SetN(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if((i == begin  || i == begin + 4) ||
                    (j == floor + 1 && (i == begin + 1)) ||
                    (j == floor + 2 && (i == begin + 2)) ||
                    (j == floor + 3 && (i == begin + 3)) ||
                    (j == floor + 4 && (i == begin + 4)))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}

void TabloTV::SetT(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if( j == floor || (i == begin + 2))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}

void TabloTV::SetO(QPainter& paint, int& begin, const int & floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if(((i <= begin + 3 && i >= begin + 1) && (j == floor || j == floor + 4)) ||
                    ((j == floor + 1 || j == floor + 3 )&& (i == begin || i == begin + 4)) ||
                    ((j == floor + 2) && (i == begin || i == begin + 4)))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}

void TabloTV::SetI(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 1;
    for(int i = floor; i < floor + 5; ++i)
    {
        paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
        paint.drawEllipse(begin * 10, i * 10 , 1, 1);
    }
    begin = end + 1;
}

void TabloTV::SetH(QPainter& paint, int& begin, const int &floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if(((i == begin  || i == begin + 4)) || (j == floor + 2))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}

void TabloTV::SetE(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if((j%2 == 0) || (j%2 && i == begin))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j*10, 1, 1);
        }
    }
    begin = end + 1;
}

void TabloTV::SetY(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if(((i == begin  || i == begin + 4) && j == floor) ||
                    (j == floor + 1 && (i == begin + 1 || i == begin + 3)) ||
                    (j == floor + 2 && (i == begin + 2)) ||
                    ((j >= floor + 3 ) && (i == begin + 2)))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //           paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}
void TabloTV::SetU(QPainter& paint, int& begin, const int& floor)
{
    ChakeStart(begin, comp);
    int end = begin + 5;
    for(int i = begin; i < end; ++i)
    {
        for(int j = floor; j < floor + 5; ++j)
        {
            if(((i == begin  || i == begin + 4) && j <= floor + 3) || (j == floor + 4))
            {
                paint.setPen(QPen(Qt::black,8 ,Qt::SolidLine));
                paint.drawEllipse(i * 10, j * 10 , 1, 1);
            }
            //            else
            //            {
            //                paint.setPen(QPen(Qt::yellow,8 ,Qt::SolidLine));
            //            }
            //            paint.drawEllipse(i * 10, j * 10 , 1, 1);
        }
    }
    begin = end + 1;
}
void TabloTV::SetSpace(int& begin)
{
    ChakeStart(begin, comp);
    begin = begin + 2;
}

void TabloTV::on_lamp_clicked()
{
    qDebug() << ui->lamp->isChecked();
    if(ui->lamp->isChecked())
    {

        paintTimer->stop();
    }
    else
    {
        paintTimer->start(300);
        connect(paintTimer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
    }
}
