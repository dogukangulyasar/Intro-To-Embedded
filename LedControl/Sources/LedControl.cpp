#include "LedControl.h"
LedControl::LedControl()
{

}

void LedControl::setLed(QString ledVal){
        this->ledPin = ledVal;
}

void LedControl::controlLed(QString ledPin, QString ctl){
        this->ledPin = ledPin;
        std::ofstream ledFile;
        QString path = "/sys/class/gpio/gpio"+this->ledPin+"/value";
        ledFile.open (path.toStdString());
        if(ctl=="on"){
                ledFile<< "1";
        }else if(ctl=="off"){
                ledFile<< "0";
        }
        ledFile.close();
}
