#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsItem>

class Piece : public QGraphicsItem {
public: Piece(qreal x,qreal y,Qt::GlobalColor _color);
    ~Piece();
   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   QPainterPath shape() const;
   void setColor(Qt::GlobalColor _color);
private:
   Qt::GlobalColor color;
};

#endif // PIECE_H
