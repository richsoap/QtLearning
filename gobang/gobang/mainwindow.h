#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mypushbutton.h"
#include "myscene.h"
#include "five.h"
#include "winline.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void restart();

private:
    int getLoc(qreal x,qreal y);
    Piece* button;
    MyScene *scene;
    QGraphicsView *view;
    int whichSide;
    bool isInit;
    five* cacuFive;
    int* winResult;
    WinLine *winLine;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};


#endif // MAINWINDOW_H
