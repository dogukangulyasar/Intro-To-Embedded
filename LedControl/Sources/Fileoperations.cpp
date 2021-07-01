#include "Fileoperations.h"
Fileoperations::Fileoperations()
{

}

void Fileoperations::pinOn(){
        std::ofstream gpio;
        gpio.open ("/sys/class/gpio/gpio18/value");
        gpio << "1";
        gpio.close();
        emit setted();
}


void Fileoperations::pinOff(){
        std::ofstream gpio;
        gpio.open ("/sys/class/gpio/gpio18/value");
        gpio << "0";
        gpio.close();
        emit setted();
}
