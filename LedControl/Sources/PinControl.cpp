#include "PinControl.h"
PinControl::PinControl()
{
        QObject::connect(this, &PinControl::pinsManaged, this, &PinControl::startThread); //Start thread for reading button.
        QObject::connect(this, &PinControl::buttonChange, &pc, &LedControl::controlLed); //If button pressed notify the led.
}

void PinControl::setPins(QString led, QString btn){
        this->ledPin = led;
        this->buttonPin = btn;
        emit pinsManaged(this->ledPin, this->buttonPin);
}

void PinControl::startThread(){
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &PinControl::readButton);
        timer->start(100);
}

void PinControl::readButton(){
        std::string line;
        QString path = "/sys/class/gpio/gpio"+this->buttonPin+"/value";
        std::ifstream buttonFile(path.toStdString());
        while (getline (buttonFile, line)) {
                if(line=="1"){
                        emit buttonChange(this->ledPin,"on");
                }else if(line=="0"){
                        emit buttonChange(this->ledPin,"off");
                }
        }
        buttonFile.close();
}

