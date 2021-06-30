#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include <QObject>
#include <iostream>
#include <fstream>

class Fileoperations : public QObject
{
Q_OBJECT
public:
        Fileoperations();
private:

signals:
        void setted();
public slots:
         void pinOn();
         void pinOff();
};

#endif // FILEOPERATIONS_H
