#include "myscene.h"
#include "constants.h"
#include <QDebug>

MyScene::MyScene(QWidget *parent):
    QGraphicsScene(parent),
    table(0),
    tempPiece(new Piece(0,0,Qt::black)),
    isTempPieceUsing(false)
{
   pieces = new Piece**[15];
   for(int i = 0;i < 15;i ++) {
       pieces[i] = new Piece*[15];
   }
   for(int p = 0;p < 15;p ++) {
       for(int q = 0;q < 15;q ++) {
           pieces[p][q] = 0;
       }
   }
}

MyScene::~MyScene() {
    for(int i = 0;i < 15;i ++) {
        for(int p = 0;p < 15;p ++) {
           if(pieces[i][p] != 0) {
               delete pieces[i][p];
           }
        }
        delete pieces[i];
    }
    delete pieces;
    delete tempPiece;
    delete table;
}

void MyScene::initScene() {
    if(table == 0) {
        QGraphicsScene::setSceneRect(0,0,17*SPACING,17*SPACING);
        table = new Table(0,0);
        QGraphicsScene::addItem(table);
    }
    qDebug() << "add Table";
    for(int p = 0;p < 15;p ++) {
        for(int q = 0;q < 15;q ++) {
            if(pieces[p][q] != 0) {
                QGraphicsScene::removeItem(pieces[p][q]);
                pieces[p][q] = 0;
            }
        }
    }
    if(isTempPieceUsing) {
        QGraphicsScene::removeItem(tempPiece);
        isTempPieceUsing = false;
    }
}

bool MyScene::addPiece(int x, int y, Qt::GlobalColor color) {
   if(pieces[x][y] != 0) {
       return false;
   }
   else {
       qDebug() << x << y << "Piece is adding";
       pieces[x][y] = new Piece(x * SPACING,y * SPACING,color);
       QGraphicsScene::addItem(pieces[x][y]);
       return true;
   }
}

bool MyScene::removePiece(int x, int y) {
    if(pieces[x][y] == 0) {
        return false;
    }
    else {
        QGraphicsScene::removeItem(pieces[x][y]);
        delete pieces[x][y];
        pieces[x][y] = 0;
        return true;
    }
}

void MyScene::addTempPiece(int x,int y,Qt::GlobalColor color) {
    if(isTempPieceUsing) {
        QGraphicsScene::removeItem(tempPiece);
        isTempPieceUsing = false;
    }
    if(pieces[x][y] != 0) {
        return;
    }
    tempPiece->setColor(color);
    tempPiece->setPos(x,y);
    QGraphicsScene::addItem(tempPiece);
    isTempPieceUsing = true;
}

