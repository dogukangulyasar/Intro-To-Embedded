#ifndef PINCONTROL_H
#define PINCONTROL_H
#include <QTimer>
#include <QObject>
#include <iostream>
#include <fstream>
#include "LedControl.h"

class PinControl : public QObject
{
Q_OBJECT
public:
        PinControl();
        void startThread(); //To Starting Thread for listening button process.
        void readButton(); //Reading button process

private:
        QString buttonPin; //Pin number of button
        LedControl pc; //Controlling led with button.
        QString ledPin; //Led pin number

signals:
        void pinsManaged(QString led, QString btn); //After pins setted
        void buttonChange(QString ledPin, QString ctl); //To notify changing button status

public slots:
        void setPins(QString led, QString btn); //To setting pins.

};

#endif // PINCONTROL_H

