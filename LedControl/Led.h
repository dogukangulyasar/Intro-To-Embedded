#ifndef LED_H
#define LED_H
#include <QObject>
#include "Fileoperations.h"
#include "Buttoncontrol.h"
class Led : public QObject
{
Q_OBJECT
Q_PROPERTY(QString status READ getStatus NOTIFY setted)

public:
        Led();
        QString getStatus();

private:
        QString status;
        Fileoperations fo;
        Buttoncontrol bc; //When we create it will automatically start reading the file. Because I defined timer in the Constructor of bc.

signals:
        void setOn();
        void setOff();
        void setted();

public slots:
        void setStatusOn();
        void setStatusOff();
        void fileOperationDone();
};

#endif // LED_H
