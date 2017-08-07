#ifndef TABLE_H
#define TABLE_H

#include <QGraphicsItem>

class Table : public QGraphicsItem {
public: Table(qreal x, qreal y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // TABLE_H
