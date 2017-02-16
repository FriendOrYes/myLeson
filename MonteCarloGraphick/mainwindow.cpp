#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QString>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // означает, что будем использовать форму
    pictHeight = 370; // задаем высоту картинки
    pictWidth = 540; // и её ширину
    step = 0.1; // задаем начальный шаг
    leftX = -100; rightX = 100; // и начальные значения границ
    leftY = -100; rightY = 100;
    drawGraph(); // сразу же отрисовываем пустой график
}

MainWindow::~MainWindow()
{
    delete ui;
}
// следующие 4 метода -- это лишь задания функций, которые мы хотим отрисовывать
double MainWindow::f(double x)
{
    return 2 - x*x;
}

double MainWindow::f1(double x)
{
    return -1;
}


// метод вычисляет середину экрана и пересчитывает количество пикселей на шаг
void MainWindow::recountPixels()
{
    onePixelX = 540.0/(rightX-leftX);
    onePixelY = 370.0/(rightY-leftY);
    Ox = fabs(leftX);
    Oy = rightY;
}

void MainWindow::getData()
{
    // ui->name->method() означает, что мы обращаемся к объекту name, который помещен на форме ui
    leftX = ui->lineEdit->text().toDouble(); // узнаем границы
    rightX = ui->lineEdit_2->text().toDouble();
    leftY = ui->lineEdit_3->text().toDouble();
    rightY = ui->lineEdit_4->text().toDouble();
    Acuraccy = ui->lineEdit_5->text().toInt();
    step = 1.0/Acuraccy; // и шаг
}

void MainWindow::drawGraph(bool notEmpty)
{
    QPixmap graph(540,370); // создаем саму картинку
    QPainter paint; // и пэинтер
    paint.begin(&graph); // запускаем отрисовку
    paint.eraseRect(0,0,540,370); // очищаем рисунок
    paint.drawLine(Ox*onePixelX,0,Ox*onePixelX,pictHeight); // и рисуем координатные оси
    paint.drawLine(0,Oy*onePixelY,pictWidth,Oy*onePixelY);

    paint.setPen(QPen(Qt::black,3)); // устанавливаем цвет и толщину "пера"
    for(double i = leftX;i<=rightX;i+=10.0) // рисуем черточки на координатой оси
        paint.drawPoint((i+Ox)*onePixelX,Oy*onePixelY);
    for(double i = leftY;i<=rightY;i+=10.0)
        paint.drawPoint(Ox*onePixelX,(i+Oy)*onePixelY);

    // если мы не рисуем график, то отображаем координатную ось и выключаемся
    if(!notEmpty) {
        paint.end();
        ui->label_4->setPixmap(graph);
        return;
    }

    paint.setPen(QPen(Qt::green,1,Qt::SolidLine)); // снова задаем цвет и тип линии
    paint.setRenderHint(QPainter::Antialiasing, true); // задаем параметры рендеринга
    QPainterPath path,p; // QPainterPath означаем, что мы вначале занесем все необходимые точки, а затем соединим их
    bool first[2] = {1,1}; // узнаем первая ли точка, или надо сдвигаться

    // последовательно проходимся по всем точкам графика, проверяем, существует ли функция в данной точке, и если существует -- заносим точку в массив отрисовки

    for(double i = (double)leftX+step;i<=(double)rightX;i+=step) {
        if(!isnan(f(i))) {
            if(first[0]) {
                path.moveTo((i+Ox)*onePixelX,(Oy - f(i))*onePixelY);
                first[0] = false;
            }
            else
                path.lineTo((i+Ox)*onePixelX,(Oy - f(i))*onePixelY);
        }
        if(!isnan(f1(i))) {
            if(first[1]) {
                p.moveTo((i+Ox)*onePixelX,(Oy - f1(i))*onePixelY);
                first[1] = false;
            }
            else
                p.lineTo((i+Ox)*onePixelX,(Oy - f1(i))*onePixelY);

        }
    }


    paint.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    paint.drawPath(path);

    paint.setPen(QPen(Qt::green,1,Qt::SolidLine));
    paint.drawPath(p);

    paint.setPen(QPen(Qt::green,1,Qt::SolidLine));
    MainWindow::MonteCarlo(paint);

    paint.end(); // заканчиваем рисование
    ui->label_4->setPixmap(graph); // и помещаем рисунок на форму
    return;
}

void MainWindow::on_exit_clicked()
{
    this->close(); // при нажатии на кнопку выхода, закрываем окно
}

void MainWindow::on_clear_clicked()
{
    // при нажатии на кнопку очистки, пересчитываем пиксели и рисуем координатную ось
    recountPixels();
    drawGraph();
}

void MainWindow::on_draw_clicked()
{
    // при нажатии на кнопку отрисовки, получаем границы и точность, пересчитываем значение шага и отрисовываем график
    getData();
    recountPixels();
    drawGraph(1);
}

void MainWindow::MonteCarlo(QPainter& paint)
{
    double SS = 2 * 3 * sqrt(2);
    double count = 0;
    std::mt19937_64 gen(time(0));
    int GranPin = Acuraccy;
    bool flag = true;
    std::uniform_real_distribution<float> urd(-sqrt(2), sqrt(2));
    std::uniform_real_distribution<float> urd2(-1, 2);


    for(int i = 0; i < Acuraccy; ++i)
    {
        double x = urd(gen);
        double y = urd2(gen);

        if(flag)
        {
            paint.setPen(QPen(Qt::green,5,Qt::SolidLine));
            paint.drawEllipse((x+Ox)*onePixelX, (Oy - y)*onePixelY, 5 ,5);
            if(GranPin-- < 0) flag = false;
        }
        else
        {
            if(GranPin++ > 100) flag = true;
        }
        qDebug() << (x+Ox) * onePixelX << " " << (Oy - y) *onePixelY;
        if(f(x) >= y)
        {
            count++;
        }
    }
    qDebug() << Acuraccy;
    ui->lineEdit_7->setText(QString::fromStdString(to_string((int)count)));
    ui->lineEdit_8->setText(QString::fromStdString(to_string(Acuraccy)));
    ui->lineEdit_6->setText(QString::fromStdString(to_string(SS * (count*1.0/Acuraccy))));
}
