#include "painterwidget.h"
#include <QPainter>

PainterWidget::PainterWidget(QWidget *parent):QWidget(parent) {
    setFixedSize(800,600);
    setWindowTitle(tr("Painter"));
}

void PainterWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawLine(80,100,650,500);
    painter.setPen(Qt::red);
    painter.drawRect(10,10,100,400);
}
