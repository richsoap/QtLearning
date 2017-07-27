#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include <QObject>
class Newspaper : public QObject {
    Q_OBJECT
public: Newspaper(QString _name):name(_name){}
    void sendPaper() {
        emit newPaper(name);
    }

signals:void newPaper(const QString &name);

private:
    QString name;
};

#endif // NEWSPAPER_H
