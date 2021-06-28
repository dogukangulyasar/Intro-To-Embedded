#!/bin/bash
path=/sys/class/gpio
newpath=$path/gpio$1
#take the path of the pinon script as second parameter
pressed=0
cd $newpath
while [ 1 ]
do
if grep -Fxq "1" value; then
cd $2
#take the led pin as an third parameter
sudo ./PINON.sh $3 off
cd $newpath
echo "LED OFF"
else
pressed=1
cd $2
sudo ./PINON.sh $3 on
cd $newpath
echo "LED ON"
fi
done

