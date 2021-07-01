#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H
#include <QTimer>
#include <QObject>
#include <iostream>
#include <fstream>


class Buttoncontrol : public QObject
{
Q_OBJECT
public:
        Buttoncontrol();
private:

signals:
        void buttonOn();
        void buttonOff();
public slots:
        void checkButton();
};

#endif // BUTTONCONTROL_H
