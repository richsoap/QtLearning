#include "mainwindow.h"
#include "constants.h"
#include <QVBoxLayout>
#include <QDebug>
#include <math.h>
#include <QMouseEvent>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    scene(new MyScene(this)),
    view(new QGraphicsView(scene,this)),
    button(new Piece(-70,-70,Qt::black)),
    whichSide(0),
    isInit(false),
    cacuFive(new five),
    winResult(new int[5]),
    winLine(new WinLine)
    {
    qDebug() << "init mainwindow\n";
    view->resize(900,900);
    setFixedSize(TABLE_LENGTH + 6*SPACING,TABLE_LENGTH + 6*SPACING);
    restart();
    QMainWindow::setMouseTracking(true);
}
MainWindow::~MainWindow() {
    delete view;
    delete scene;
    delete winResult;
    delete cacuFive;
}

void MainWindow::restart() {
    scene->initScene();
    qDebug() << "initScene";
    if(isInit)
    scene->removeItem(button);
    button->setColor(Qt::black);
    scene->addItem(button);
    qDebug() << "addButton";
    if(whichSide == 2)
        scene->removeItem(winLine);
    whichSide = 0;
    view->setBackgroundBrush(QBrush(Qt::gray));
    qDebug() << "setBrush";
    isInit = true;
    cacuFive->init(0);
}

int MainWindow::getLoc(qreal qx, qreal qy) {
    int bx,by,nx,ny,x,y;
    int out = 0;
    x = (int)qx;
    y = (int)qy;
    x -= 110;
    y -= 110;
	bx = x / SPACING;
	by = y / SPACING;
    nx = x - bx * SPACING;
    ny = y - by * SPACING;
    if(x > 14*SPACING + 1.5*PIECE_RADIUS ||  y > 14*SPACING + 1.5*PIECE_RADIUS) {
        return -1;
    }
    if(abs(x + 80) < 1.5 * PIECE_RADIUS && abs(y + 80) < 1.5 * PIECE_RADIUS) {
		return 0xffff;
    }
    if(x < -1.5*PIECE_RADIUS || y < -1.5*PIECE_RADIUS) {
        return -1;
    }
    if(nx > SPACING - 1.5*PIECE_RADIUS) {
		bx ++;
	}
    else if(nx > 1.5*PIECE_RADIUS) {
		return -1;
	}
    if(ny > SPACING - 1.5*PIECE_RADIUS) {
		by ++;
	}
    else if(ny > 1.5*PIECE_RADIUS) {
		return -1;
	}
    out = by;
	out = out | bx << 4;
	return out;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "Moving";
    int x,y,result;
	result = getLoc(event->x(),event->y());
    if(result != -1 && result !=  0xffff) {
		x = (result >> 4) & 0xf;
		y = result & 0xf;
        qDebug() << "Movement:"<<x<<y;
	}
    else {
        qDebug() <<"Movement: ban";
		return;
    }
    if(whichSide) {
        scene->addTempPiece(x,y,Qt::black);
    }
    else {
        scene->addTempPiece(x,y,Qt::white);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    int x,y,result;
	result = getLoc(event->x(),event->y());
    if(result == 0xffff) {
        qDebug() << "restart";
        restart();
        return;
	}
    else if(result == -1) {
        qDebug() << "illegal";
		return;
	}
	else{
		x = (result >> 4) & 0xf;
        y = result & 0xf;
        qDebug() << "after: "<<x<<' '<<y<<"\n";
	}
    switch(whichSide) {
    case 0:
        if(scene->addPiece(x,y,Qt::black) && cacuFive->addPiece(x,y,five::black) ) {//It is needed more logic here.
            qDebug() << "cacu add black";
            whichSide = 1;
            scene->removeItem(button);
            button->setColor(Qt::white);
            scene->addItem(button);

		}
        else {
            scene->removePiece(x,y);
            cacuFive->removePiece(x,y);
        }
        break;
    case 1:
        if(scene->addPiece(x,y,Qt::white) && cacuFive->addPiece(x,y,five::white)) {
            qDebug() << "cacu add white";
            whichSide = 0;
            scene->removeItem(button);
            button->setColor(Qt::black);
            scene->addItem(button);

		}
		else {
            scene->removePiece(x,y);
            cacuFive->removePiece(x,y);
       }
        break;
    }
    if(whichSide != 2 && cacuFive->whoWin(winResult)) {
        qDebug() << winResult[0] << winResult[1] << winResult[2] << winResult[3] << winResult[4];
        winLine->setLine(winResult[1],winResult[2],winResult[3],winResult[4]);
        scene->addItem(winLine);
        if(winResult[0] == five::black) {
            QMessageBox::about(this,tr("Game Over"),tr("black win!"));
        }
        else {
            QMessageBox::about(this,tr("Game Over"),tr("white win!"));
        }
        whichSide = 2;
    }

}
