#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H
#include <QObject>
#include "PinControl.h"
#include "LedControl.h"

class ApplicationManager : public QObject
{
Q_OBJECT
Q_PROPERTY(QString ledPin READ getLed NOTIFY managedPins) //Led pin number
Q_PROPERTY(QString buttonPin READ getButton NOTIFY managedPins) //Button pin number

public:
        ApplicationManager();
        QString getLed(); //To show the led pin to the user [QML]
        QString getButton(); //To show the button pin to the user [QML]
        void settedPins(QString led, QString btn); //To setting the button & led pin number in this class to show later.
signals:
        void setPins(QString led, QString btn);
        void managedPins(); //To notify the property which used for setting values of led & btn in qml.
public slots:

private:
        QString ledPin; //Led Pin Number in Linux
        QString buttonPin; //Button Pin Number in Linux
        PinControl btn; //Object for the button controlling
};

#endif // APPLICATIONMANAGER_H

