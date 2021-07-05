#ifndef LEDCONTROL_H
#define LEDCONTROL_H
#include <QObject>
#include <QTimer>
#include <iostream>
#include <fstream>

class LedControl : public QObject
{
//Q_OBJECT
public:
        LedControl();

public slots:
        void setLed(QString ledVal); //Setting led number in he led control class.
        void controlLed(QString ledPin, QString ctl); //To controlling led pin in the led class.
signals:

private:
        QString ledPin; //Led pin number
};

#endif // LEDCONTROL_H
