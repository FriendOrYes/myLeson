#ifndef TABLOTV_H
#define TABLOTV_H

#include <QMainWindow>
#include <vector>
#include <QtGui>

namespace Ui {
class TabloTV;
}

class TabloTV : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabloTV(QWidget *parent = 0);
    ~TabloTV();
    void LightButton();
    void SetLight(int &start);
    void SetA(QPainter&, int&, const int&);
    void SetN(QPainter&, int&, const int&);
    void SetT(QPainter&, int&, const int&);
    void SetO(QPainter&, int&, const int&);
    void SetI(QPainter&, int&, const int&);
    void SetH(QPainter&, int&, const int&);
    void SetE(QPainter&, int&, const int&);
    void SetY(QPainter&, int&, const int&);
    void SetU(QPainter&, int&, const int&);
    void SetSpace(int&);
    int GetFloor(int& floor);

private slots:
    void on_pushButton_clicked();
////
    void on_lamp_clicked();
    void updatePixmap();

private:
    Ui::TabloTV *ui;
    bool flag;
    int NumberOfLight;
    int m_begin;
    int comp;
    QTimer *paintTimer;
    void ChakeStart(int&, const int&);
};

#endif // TABLOTV_H
