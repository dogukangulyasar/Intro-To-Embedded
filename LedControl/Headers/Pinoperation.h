#ifndef PINOPERATION_H
#define PINOPERATION_H
#include <QObject>
#include <QString>
#include <QTimer>
#include "Headers/Pinmodel.h"
#include <iostream>
#include <fstream>

///CLASS FOR THE FILE OPERATIONS
class Pinoperation : public QObject
{
        //Q_OBJECT
public:
        Pinoperation();

public slots:
        void ledControl(QString status, Pinmodel ledP); //For controlling led
        void readButton(); //For reading button every 1 second
        void startThread(Pinmodel ledP, Pinmodel btnP); //Starting the thread for the reading button every 1s.

private:
        Pinmodel ledPin;
        Pinmodel buttonPin;
};

#endif // PINOPERATION_H
