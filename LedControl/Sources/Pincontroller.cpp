#include "Headers/Pincontroller.h"

Pincontroller::Pincontroller()
{
        QObject::connect(this, &Pincontroller::startThread, &po, &Pinoperation::startThread);
        QObject::connect(this, &Pincontroller::setOn, &po, &Pinoperation::ledControlDirect);
        QObject::connect(this, &Pincontroller::setOff, &po, &Pinoperation::ledControlDirect);
        //QObject::connect(&po, &Pinoperation::directSet, this, &Pincontroller::directSetted);
}

void Pincontroller::setPins(QString ledPin, QString ledGrd, QString btnPin, QString btnGrd){
        ledPinModel.setPinNumber(ledPin);
        ledPinModel.setGrdNumber(ledGrd);
        buttonPinModel.setPinNumber(btnPin);
        buttonPinModel.setGrdNumber(btnGrd);
        emit pinsSetted(ledPinModel.getPinNumber(), buttonPinModel.getPinNumber());
        emit startThread(ledPinModel, buttonPinModel);
}
