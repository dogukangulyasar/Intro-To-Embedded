# Introduction to the Embedded Linux part1

Firstly I get the necessary parts which they:
* Raspberry Pi 3 b+
* SD card for the booting
* Breadboard
* Led
* 1K Resistence
* 2 Man-Woman Jumper Cables
* HDMI cable
* Raspberry Power cable

After getting equipments, firstly enable the ssh for the raspberry and then tried on and off led from the GPIO library in python. It has few codes like:
```
>import RPi.GPIO as GPIO
>GPIO.setmode(GPIO.BCM)
>GPIO.setup(32, GPIO.OUT)
>GPIO.output(32, True)
```
This will turn on the led, after this process I started to researching about linux pins and I found this link:

[LINUX PINS](https://www.kernel.org/doc/Documentation/gpio/sysfs.txt)

This is a very useful document about the Linux pins, commands and the directories. Also linux pins can be find in the **/sys/class/gpio**. After spending some time on this document I tried the changing files and folders by hand which they located in the below path. It has few comments like:
```
>echo (PINNUM)18 > export
>cd gpio(PINNUM)18
>nano direction (change it's inside as in/out)
>nano value (change it's inside as 1/0)
```
After spend some time on this process, I decide to make a script for make automated this process. **PINON.sh** file is the script for the on and off the pins located in linux. It's using format is:
```
>./pinon.sh *PINNUMBER* *on/off*
>./pinon.sh 18 on
>./pinon.sh 18 off
```

#Button.sh

**button.sh** file is created for the turn on or off from the physical button. I created this file as an dynamic script it has 3 different parameters for the running it.

>$1 -> pin number of the buton
>$2 -> path of the PINON.sh script
>$3 -> pin number of the led

It's usage is:
>chmod +x button.sh
>sudo ./button.sh 5(button pin no) /home/desktop/.../(PINON.sh path) 18(led pin no)




