#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton {
    Q_OBJECT
public:
    MyPushButton(QWidget * parent = 0);
    ~MyPushButton();
    void changeColor(int color = 0);
    const static int black = 0;
    const static int white = 1;
};

#endif // MYPUSHBUTTON_H
