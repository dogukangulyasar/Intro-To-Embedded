#include "Headers/Pinview.h"

Pinview::Pinview()
{
        QObject::connect(this, &Pinview::pinSetted, &pc, &Pincontroller::setPins);
        QObject::connect(&pc, &Pincontroller::pinsSetted, this, &Pinview::setPins);

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
