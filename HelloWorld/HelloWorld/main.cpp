#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <Newspaper.h>
#include <Reader.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Newspaper newspaper("China Daily");
    Reader reader;
    QObject::connect(&newspaper,&Newspaper::newPaper,&reader,&Reader::receiveNewspaper);
    newspaper.sendPaper();

    return a.exec();
}
