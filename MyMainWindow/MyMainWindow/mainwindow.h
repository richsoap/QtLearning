#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSpinBox>
#include <QSlider>
#include <QTextEdit>

#include "eventlabel.h"


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void open();
    void save();
    QAction *openAction;
    QAction *saveAction;
    EventLabel *eventLabel;
};

#endif // MAINWINDOW_H
