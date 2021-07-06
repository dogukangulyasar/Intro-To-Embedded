#include "Headers/Pinmodel.h"

Pinmodel::Pinmodel()
{

}

void Pinmodel::setPinNumber(QString pin){
        this->pinNumber = pin;
}

QString Pinmodel::getPinNumber(){
        return this->pinNumber;
}

void Pinmodel::setGrdNumber(QString grd){
        this->grdNumber = grd;
}

QString Pinmodel::getGrdNumber(){
        return this->grdNumber;
}
