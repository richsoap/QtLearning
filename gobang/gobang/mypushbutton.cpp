#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) :
    QPushButton(parent) {

    setText(tr("Restart"));
    setStyleSheet("background: rgb(0,0,0);"
                  "color: rgb(255,255,255);");

}
MyPushButton::~MyPushButton() {

}

void MyPushButton::changeColor(int color) {
   if(color == black) {
       setStyleSheet("background: rgb(0,0,0);"
                     "color: rgb(255,255,255);");
   }
   else {
       setStyleSheet("background: rgb(255,255,255);"
                     "color:rgb(0,0,0)");
   }
}
