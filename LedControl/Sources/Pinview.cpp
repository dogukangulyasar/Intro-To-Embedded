#include "Headers/Pinview.h"

Pinview::Pinview()
{
        QObject::connect(this, &Pinview::pinSetted, &pc, &Pincontroller::setPins);
        QObject::connect(&pc, &Pincontroller::pinsSetted, this, &Pinview::setPins);
        QObject::connect(&pc, &Pincontroller::pinsSetted, this, &Pinview::setPins);
        QObject::connect(&pc, &Pincontroller::directSetted, this, &Pinview::directSetted);
        QObject::connect(this, &Pinview::setOn, &pc, &Pincontroller::setOn);
        QObject::connect(this, &Pinview::setOff, &pc, &Pincontroller::setOff);
}

void Pinview::setPins(QString ledVal, QString btnVal){
        this->ledPin = ledVal;
        this->btnPin = btnVal;
        emit modelled();
}

QString Pinview::getLed(){
        return this->ledPin;
}

QString Pinview::getBtn(){
        return this->btnPin;
}

QString Pinview::getStatus(){
        return this->status;
}

void Pinview::directSetted(QString status){
        this->status = status;
}
