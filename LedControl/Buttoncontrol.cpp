#include "Buttoncontrol.h"
#include <QDebug>
Buttoncontrol::Buttoncontrol()
{
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Buttoncontrol::checkButton);
        timer->start(100);

}


void Buttoncontrol::checkButton(){
        std::string line;
         std::ifstream gpio ("/sys/class/gpio/gpio5/value");
          if (gpio.is_open())
          {
            while ( std::getline(gpio,line) )
            {
              if(QString::fromStdString(line) == "1"){
                      emit buttonOff();
              }else if(QString::fromStdString(line) == "0"){
                      emit buttonOn();
              }
            }
            gpio.close();
          }
}
