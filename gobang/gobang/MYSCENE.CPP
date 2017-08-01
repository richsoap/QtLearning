#include "myscene.h"
#include "constants.h"
#include <string.h>
MyScene::MyScene(QWidget *parent):
    QGraphicsScene(parent),
    table(new Table(0,0))
{
	for(int i = 0;i < 15;i ++) {
		memset(pieces[i],0,sizeof(Piece*)*15);
	}	
}

MyScene::~MyScene() {

}

void MyScene::initScene() {
    QGraphicsScene::clear();
    QGraphicsScene::setSceneRect(0,0,17*SPACING,17*SPACING);
    QGraphicsScene::addItem(table);
	for(int i = 0;i < 15;i ++) {
		memset(pieces[i],0,sizeof(Piece*) *15);
	}
}

bool MyScene::addPiece(int x, int y, Qt::GlobalColor color) {
   if(pieces[x][y] != 0) {
       return false;
   }
   else {
       pieces[x][y] = new Piece(x,y,color);
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



