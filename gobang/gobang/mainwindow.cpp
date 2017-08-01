#include "mainwindow.h"
#include "constants.h"
#include <QVBoxLayout>
#include <QDebug>
#include <math.h>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    scene(new MyScene(this)),
    view(new QGraphicsView(scene,this)),
    button(0),
    whichSide(true){
    qDebug() << "init mainwindow\n";
    view->resize(900,900);
    setFixedSize(TABLE_LENGTH + 6*SPACING,TABLE_LENGTH + 6*SPACING);
    qDebug() << "before restart";
    restart();
}
MainWindow::~MainWindow() {
    delete view;
    delete scene;
}

void MainWindow::restart() {
    if(button)
        delete button;
    button = new Piece(-100,-100,Qt::black);
    scene->initScene();
    scene->addItem(button);
    whichSide = true;
    view->setBackgroundBrush(QBrush(Qt::gray));
	if(tempPiece)
		scene->removeItem(tempPiece);
	tempPiece = 0;
}

int MainWindow::getLoc(qreal x, qreal y) {
	int bx,by,nx,ny;
	int out = 0;
	bx = x / SPACING;
	by = y / SPACING;
	nx = x - bx;
	ny = y - by;
	if(abs(x + 100) < 10 && abs(y + 100) < 10) {
		return 0xffff;
	}
	if(nx > SPACING - PIECE_RADIUS) {
		bx ++;
	}
	else if(nx > PIECE_RADIUS) {
		return -1;
	}
	if(ny > SPACING - PIECE_RADIUS) {
		by ++;
	}
	else if(ny > PIECE_RADIUS) {
		return -1;
	}
	out = by;
	out = out | bx << 4;
	return out;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
	int x,y,result;
	result = getLoc(event->x(),event->y());
	if(result != -1 && result !=  0xff) {
		x = (result >> 4) & 0xf;
		y = result & 0xf;
	}
	else {
		return;
	}
	if(tempPiece)
		scene->removeItem(tempPiece);
	if(whichside) {
		tempPiece = new Piece(x,y,Qt::black);
	}
	else {
		tempPiece = new Piece(x,y,Qt::white);	
	}
	scene->addItem(tempPiece);
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    int x,y,result;
	result = getLoc(event->x(),event->y());
	if(result == 0xff) {
		restart();
	}
	else if(result = -1) {
		return;
	}
	else{
		x = (result >> 4) & 0xf;
		y = result & 0xf;	
	}
	if(whichside) {
		if(scene->addPiece(x,y,Qt::black) ) {//It is needed more logic here. 	
		scene->removePiece(x,y);
		}
		else {
			whichside = false;
			scene->removeItem(button);
			button->setColor(Qt::white);
			scene->addItem(button);
		}
	}
	else {
		if(scene->addPiece(x,y,Qt::white)) {
			scene->removePiece(x,y);
		}
		else {
			whichside = true;
			scene->removeItem(button);
			button->setColor(Qt::black);
			scene->addItem(button);
		}
	}
	//add judgement code here


}