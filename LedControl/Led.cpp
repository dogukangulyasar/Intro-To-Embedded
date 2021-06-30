#include "Led.h"
Led::Led()
{
        QObject::connect(this, &Led::setOn, &fo, &Fileoperations::pinOn);
        QObject::connect(this, &Led::setOff, &fo, &Fileoperations::pinOff);
        QObject::connect(&fo, &Fileoperations::setted, this, &Led::fileOperationDone);
}

QString Led::getStatus(){
        return this->status;
}


void Led::setStatusOn(){
        this->status = "on";
        emit setOn();
}

void Led::setStatusOff(){
        this->status = "off";
        emit setOff();
}


void Led::fileOperationDone(){
        emit setted();
}
