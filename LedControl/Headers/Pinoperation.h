#ifndef PINOPERATION_H
#define PINOPERATION_H
#include <QObject>
#include <QString>
#include <QTimer>
#include "Headers/Pinmodel.h"
#include <iostream>
#include <fstream>
#include <wiringPi.h>
#include <softPwm.h>

///CLASS FOR THE FILE OPERATIONS
class Pinoperation : public QObject
{
        //Q_OBJECT
public:
        Pinoperation();

public slots:
        void ledControl(QString status, Pinmodel ledP); //For controlling led
        void readButton(); //For reading button every 1 second
        void startThread(Pinmodel ledP, Pinmodel btnP); //Starting the thread for the reading button every 1s.;
        void ledControlDirect(QString led, QString status);


private:
        Pinmodel ledPin;
        Pinmodel buttonPin;
        int pwm = 0;
        QTimer *timer = new QTimer(this);
};

#endif // PINOPERATION_H
