#ifndef PINCONTROLLER_H
#define PINCONTROLLER_H
#include "Headers/Pinmodel.h"
#include "Headers/Pinoperation.h"
#include <QObject>
class Pincontroller : public QObject
{
        Q_OBJECT
public:
        Pincontroller();

public slots:
        void setPins(QString ledPin, QString ledGrd, QString btnPin, QString btnGrd); //Setting pins


signals:
        void pinsSetted(QString ledVal, QString btnVal); //Notifying View class for pins setted
        void startThread(Pinmodel p1, Pinmodel p2); //Starting thread in the file operation for reading button activity
        void setOn(QString led, QString status);
        void setOff(QString led, QString status);
        void directSetted(QString status);
private:
        Pinmodel ledPinModel;
        Pinmodel buttonPinModel;
        Pinoperation po;
};

#endif // PINCONTROLLER_H
