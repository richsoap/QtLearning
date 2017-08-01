#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QHBoxLayout>
#include <QDialog>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    setWindowTitle(tr("Main Window"));

   openAction = new QAction(QIcon(":/icon/file-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    saveAction = new QAction(QIcon(":/icon/file-save"),tr("&Save..."),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save this file"));
    connect(saveAction,&QAction::triggered,this,&MainWindow::save);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    painterWidget = new PainterWidget(this);
    this->setCentralWidget(painterWidget);

    statusBar();
}

MainWindow::~MainWindow() {

}

void MainWindow::open() {
    QMessageBox::information(this,tr("Open"),tr("OpenFile"));
}
void MainWindow::save() {
    QMessageBox::information(this,tr("Save"),tr("SaveFile"));
}
