#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H
#include <QWidget>

class PainterWidget : public QWidget {
    Q_OBJECT
public:
    PainterWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // PAINTERWIDGET_H
