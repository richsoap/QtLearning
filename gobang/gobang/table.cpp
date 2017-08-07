#include "table.h"
#include <QPainter>
#include "constants.h"
#include <QDebug>
Table::Table(qreal x, qreal y) {
    setPos(x,y);
}

QRectF Table::boundingRect() const {
    return QRectF(0-SPACING,0-SPACING,17*SPACING,17*SPACING);
}

void Table::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    qDebug() << "Painting\n";

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setWidth(LINE_WIDTH);
    pen.setColor(QColor(232,44,12));
    pen.setCapStyle(Qt::RoundCap);
    pen.setStyle(Qt::DashDotLine);
    painter->setPen(pen);
    for(int i = 0;i < 15;i ++) {
        painter->drawLine(QPointF(0,i*SPACING),QPointF(TABLE_LENGTH,i*SPACING));
        painter->drawLine(QPointF(i*SPACING,0),QPointF(i*SPACING,TABLE_LENGTH));
    }
    painter->restore();
}

