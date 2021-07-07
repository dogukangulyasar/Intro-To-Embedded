#include "Headers/Pinoperation.h"

Pinoperation::Pinoperation()
{
        wiringPiSetupGpio();
}

void Pinoperation::readButton(){
        QString path = "/sys/class/gpio/gpio"+buttonPin.getPinNumber()+"/value";
        std::ifstream gpioButton(path.toStdString());
        std::string value;
        while (getline (gpioButton, value)) {
          if(value=="1"){
                  ledControl("off",ledPin);
          }else if(value=="0") {
                  ledControl("on",ledPin);
          }
        }
        gpioButton.close();
}

void Pinoperation::startThread(Pinmodel ledP, Pinmodel btnP){
        this->ledPin = ledP;
        this->buttonPin = btnP;
        pinMode(ledPin.getPinNumber().toInt(),PWM_OUTPUT);
        pwmSetRange(100);
        connect(timer, &QTimer::timeout, this, &Pinoperation::readButton);
        timer->start(200);
}

void Pinoperation::ledControl(QString val, Pinmodel ledP){
        QString path = "/sys/class/gpio/gpio"+ledP.getPinNumber()+"/value";
        std::ofstream gpioLed(path.toStdString());
        if(val == "on"){
                pwm=pwm+2;
                pwmWrite(ledPin.getPinNumber().toInt(), pwm==0?50:pwm*3);
        }else if(val=="off"){
                pwm/=2;
                pwmWrite(ledPin.getPinNumber().toInt(), pwm);
        }
}

void Pinoperation::ledControlDirect(QString led, QString status){
        QString path = "/sys/class/gpio/gpio"+led+"/value";
        std::ofstream gpioLed(path.toStdString());
        if(status == "on"){
                pinMode(ledPin.getPinNumber().toInt(),OUTPUT);
                gpioLed << "1";
                //digitalWrite(led.toInt(),HIGH);
                timer->stop();
        }else if(status=="off"){
                pinMode(ledPin.getPinNumber().toInt(),OUTPUT);
                gpioLed << "0";
                //digitalWrite(led.toInt(),LOW);
                timer->start();
        }
}
