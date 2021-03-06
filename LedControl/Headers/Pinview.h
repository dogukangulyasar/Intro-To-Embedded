#ifndef PINVIEW_H
#define PINVIEW_H
#include <QString>
#include <QObject>
#include "Headers/Pincontroller.h"
class Pinview : public QObject
{
        Q_OBJECT
        Q_PROPERTY(QString ledPin READ getLed NOTIFY modelled) //Viewing led pin in the qml
        Q_PROPERTY(QString buttonPin READ getBtn NOTIFY modelled) //Viewing button pin in the qml
        Q_PROPERTY(QString ledStatus READ getStatus NOTIFY statusChanged) //Viewing button pin in the qml
public:
        Pinview();
        QString getLed(); //Getting led pin
        QString getBtn(); //Gettin button pin
        QString getStatus(); //Gettin button pin
public slots:
        void setPins(QString ledVal, QString btnVal); //For the setting pins from the qml.
        void directSetted(QString status);
signals:
        void pinSetted(QString ledPin, QString ledGrd, QString btnPin, QString btnGrd); //Notifying pins setted in the qml to controller
        void modelled(); //When pins modeled in the controlled getting signal and show on the qml
        void setOn(QString led, QString status);
        void setOff(QString led, QString status);
        void statusChanged();


private:
        Pincontroller pc; //Controller object
        QString ledPin; //Led pin
        QString btnPin; //Button pin
        QString status = 0;
};

#endif // PINVIEW_H
