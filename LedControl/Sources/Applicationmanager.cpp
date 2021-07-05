#include "Applicationmanager.h"

ApplicationManager::ApplicationManager()
{
        QObject::connect(this, &ApplicationManager::setPins, &btn, &PinControl::setPins); //Connect this settedLed signal to the model (Led Class)


        QObject::connect(&btn, &PinControl::pinsManaged, this, &ApplicationManager::settedPins); //Connect this settedLed signal to the model (Led Class)
}

QString ApplicationManager::getLed(){
        return this->ledPin;
}

void ApplicationManager::settedPins(QString led, QString btn){
        this->ledPin = led;
        this->buttonPin = btn;
        emit managedPins();
}

QString ApplicationManager::getButton(){
        return this->buttonPin;
}




