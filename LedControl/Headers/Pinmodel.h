#ifndef PINMODEL_H
#define PINMODEL_H
#include <QString>

class Pinmodel
{
public:
        Pinmodel();
        void setPinNumber(QString pin); //Setting pin numbers
        void setGrdNumber(QString grd); //Setting grd numbers
        QString getPinNumber(); //Getting pin numbers
        QString getGrdNumber(); //Getting Grd numbers

private:
        QString pinNumber;
        QString grdNumber;

};

#endif // PINMODEL_H
