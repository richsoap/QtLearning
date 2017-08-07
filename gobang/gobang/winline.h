#ifndef WINLINE_H
#define WINLINE_H
#include <QGraphicsItem>
class WinLine : public QGraphicsItem {
public:WinLine();
    ~WinLine();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setLine(int _x1, int _y1, int _x2, int _y2);
private:
    int x1,x2,y1,y2;
};

#endif // WINLINE_H
