#include "piece.h"
#include <QPainter>
#include "constants.h"

Piece::Piece(qreal x, qreal y, Qt::GlobalColor _color):color(_color) {
    setPos(x,y);
}

Piece::~Piece() {
    delete &color;

}

QRectF Piece::boundingRect() const {
    return QRectF(-1.5*PIECE_RADIUS,-1.5*PIECE_RADIUS,PIECE_RADIUS*3,PIECE_RADIUS*3);
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(),color);
    painter->restore();

}

QPainterPath Piece::shape() const {
    QPainterPath p;
    p.addEllipse(QPointF(0,0),PIECE_RADIUS,PIECE_RADIUS);
    return p;

}

void Piece::setColor(Qt::GlobalColor _color) {
    color = _color;
}

