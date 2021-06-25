#!/bin/bash



path=/sys/class/gpio
newpath=$path/gpio$1

standart() {
if [ ! -d "$newpath" ]; then
cd $path
echo 18 > export
fi
}

if [ $2 == "on" ]; then
standart
cd $newpath
echo "out" > direction
echo "1" > value
fi

if [ $2 == "off" ]; then
standart
cd $newpath
echo "out" > direction
echo "0" > value
fi


