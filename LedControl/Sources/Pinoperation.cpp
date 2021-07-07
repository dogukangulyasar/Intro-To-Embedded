#include "Headers/Pinoperation.h"
#include <QDebug>
Pinoperation::Pinoperation()
{
        wiringPiSetupGpio() == -1 ? qDebug()<<"Error" : qDebug()<<"Not error";
        //digitalWrite(ledPin.getPinNumber().toInt(),1);
        //pwmSetRange(100);

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
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Pinoperation::readButton);
        timer->start(200);
}

void Pinoperation::ledControl(QString val, Pinmodel ledP){
        QString path = "/sys/class/gpio/gpio"+ledP.getPinNumber()+"/value";
        std::ofstream gpioLed(path.toStdString());
        if(val == "on"){
                pwm= pwm+1;
                //pinMode(ledPin.getPinNumber().toInt(), PWM_OUTPUT);
                pwmWrite(ledPin.getPinNumber().toInt(), pwm==0?50:pwm*3);
                //digitalWrite(ledPin.getPinNumber().toInt(),HIGH);
                //pwmWrite(ledPin.getPinNumber().toInt(),100);
                qDebug()<<"HIGH"<<pwm;
                //analogWrite(18,HIGH);
                //gpioLed << "1";
        }else if(val=="off"){
                pwm/=2;
                //gpioLed << "0";
                //pwmWrite(ledPin.getPinNumber().toInt(), 0);
                //pinMode(ledPin.getPinNumber().toInt(), PWM_OUTPUT);
                pwmWrite(ledPin.getPinNumber().toInt(), pwm);
                //analogWrite(18,LOW);
                //digitalWrite(ledPin.getPinNumber().toInt(),LOW);
                //pwmWrite(ledPin.getPinNumber().toInt(),75);
                qDebug()<<"LOW";
        }
}
