#include "mainwindow.h"
#include "painterwidget.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    QWidget w;
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *pushButton = new QPushButton(&w);

    pushButton->setText("Restart");
    pushButton->setStyleSheet("background: rgb(255,255,255);"
                              "color: rgb(0,0,0);");
    PainterWidget *painterWidget = new PainterWidget(&w);
    layout->addWidget(pushButton);
    layout->addWidget(painterWidget);
    w.setLayout(layout);
    w.show();

    return a.exec();
    }
