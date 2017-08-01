#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QWidget>
#include "piece.h"
#include "table.h"

class MyScene : public QGraphicsScene{
public: MyScene(QWidget *parent = 0);
       ~MyScene();
    bool addPiece(int x,int y,Qt::GlobalColor color);
    bool removePiece(int x,int y);
    void initScene();

private:
     Piece* pieces[15][15];
     Table* table;
};


#endif // MYSCENE_H
