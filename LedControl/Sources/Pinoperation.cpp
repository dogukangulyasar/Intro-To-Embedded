#include "Headers/Pinoperation.h"
Pinoperation::Pinoperation()
{

}

void Pinoperation::readButton(){
        QString path = "/sys/class/gpio/gpio"+buttonPin.getPinNumber()+"/value";
        std::ifstream gpioButton(path.toStdString());
        std::string value;
        QString on = "on";
        while (getline (gpioButton, value)) {
          if(value=="1"){
                  ledControl("on",ledPin);
          }else if(value=="0") {
                  ledControl("off",ledPin);
          }
        }
        gpioButton.close();
}

void Pinoperation::startThread(Pinmodel ledP, Pinmodel btnP){
        this->ledPin = ledP;
        this->buttonPin = btnP;
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Pinoperation::readButton);
        timer->start(1000);
}

void Pinoperation::ledControl(QString val, Pinmodel ledP){
        QString path = "/sys/class/gpio/gpio"+ledP.getPinNumber()+"/value";
        std::ofstream gpioLed(path.toStdString());
        if(val == "on"){
                gpioLed << "1";
        }else if(val=="off"){
                gpioLed << "0";
        }
}
