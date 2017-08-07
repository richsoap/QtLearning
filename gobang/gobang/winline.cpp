#include "winline.h"
#include "constants.h"

WinLine::WinLine():x1(0),y1(0),x2(0),y2(0) {
    setPos(0,0);
}
WinLine::~WinLine() {

}
void WinLine::setLine(int _x1, int _y1, int _x2, int _y2) {
    x1 = _x1;
    x2 = _x2;
    y1 = _y1;
    y2 = _y2;
}
QRectF WinLine::boundingRect() const {
    return QRectF(-SPACING,-SPACING,17*SPACING,17*SPACING);
}
void WinLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(8);
    pen.setCapStyle(Qt::RoundCap);
    painter->setPen(pen);
    painter->drawLine(QPointF(x1 * SPACING,y1*SPACING),QPointF(x2*SPACING,y2*SPACING));
    painter->restore();
}
