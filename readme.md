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


#Button.sh

**button.sh** file is created for the turn on or off from the physical button. I created this file as an dynamic script it has 3 different parameters for the running it.

>$1 -> pin number of the buton
>$2 -> path of the PINON.sh script
>$3 -> pin number of the led

It's usage is:
>chmod +x button.sh
>sudo ./button.sh 5(button pin no) /home/desktop/.../(PINON.sh path) 18(led pin no)

#Raspberry Pi 3 B+ Qt Cross Compile Documentation (Part 2)

There are really important steps in there. Firstly need to boot the rapsberry with the raspbian os using imager

Can be foundable at:

```
[Raspberry](https://www.raspberrypi.org/software/)
```

After install raspbian to the raspberry firstly update the raspbian
```
>sudo rpi-update
>reboot
```

Then enable the SSH

```
>Click top left raspberry logo
>Click **preferences**
>Click **Raspberry Pi Configuration**
>Click **interfaces**
>Click SSH - Enable
```

After enable the SSH there are some steps between host pc and the pi. I am seperating them with the **[HOST]** **[PI]**. Host for host pc, PI for the raspbian.

##[PI]
Need to enable build-dep installation for the installing some libraries.

```
sudo nano /etc/apt/sources.list
```

Delete the comment symbol(#) from the line which starts with #deb-src...

Then install the required packages

```
>sudo apt-get update
>sudo apt-get build-dep qt4-x11
>sudo apt-get build-dep libqt5gui5
>sudo apt-get install libudev-dev libinput-dev libts-dev libxcb-xinerama0-dev libxcb-xinerama0
```

Create a directory from the raspbian

```
>sudo mkdir /usr/local/qt5pi
>sudo chown pi:pi /usr/local/qt5pi
```

Congratulations you completed the PI part mostly :)

##[HOST]

Create directories at the **home** of host pc and clone the tools for the raspberrypi from git.

```
>mkdir ~/raspi
>cd ~/raspi
>git clone https://github.com/raspberrypi/tools
```

Create the system folder structure inside of the **raspi** folder.

```
>mkdir sysroot sysroot/usr sysroot/opt

```

After this process, you need to rsync the pi folders and your host folders with these codes.

```
>rsync -avz pi@raspberrypi_ip:/lib sysroot
>rsync -avz pi@raspberrypi_ip:/usr/include sysroot/usr
>rsync -avz pi@raspberrypi_ip:/usr/lib sysroot/usr
>rsync -avz pi@raspberrypi_ip:/opt/vc sysroot/opt
```

_raspberypi_ can find at-> ```hostname -I``` command at terminal **[PI]**
Password for the ssh default is: **raspberry**

After that you need to clone the special script for the linking process

```
>wget https://raw.githubusercontent.com/riscv/riscv-poky/master/scripts/sysroot-relativelinks.py
>chmod +x sysroot-relativelinks.py
>./sysroot-relativelinks.py sysroot
```

After that you need to download the Qt to the **raspi** folder.

```
>wget http://download.qt.io/official_releases/qt/5.12/5.12.5/single/ qt-everywhere-src-5.12.5.tar.xz
>tar xvf  qt-everywhere-src-5.12.5.tar.xz
>cd  qt-everywhere-src-5.12.5
```

You need to change the **-lEGL** & **-LGLESv2** to the **-lbrcmEGL** & **-lbrcmGLESv2** in this folder: _./qtbase/mkspecs/devices/linux-rasp-pi-g++/qmake.conf_

Then run this command for the 64 bit and the raspberry-pi-3. We are using _linux-rasp-pi-g++_ instead _linux-rasp-pi3-g++_ because we are using **5.12.5** version. So please be careful at there.


```
./configure -release -opengl es2 -device linux-rasp-pi-g++ -device-option CROSS_COMPILE=~/raspi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf- -sysroot ~/raspi/sysroot -opensource -confirm-license -skip qtwayland -skip qtlocation -skip qtscript -make libs -prefix /usr/local/qt5pi -extprefix ~/raspi/qt5pi -hostprefix ~/raspi/qt5 -no-use-gold-linker -v -no-gbm
```

After the configuration (without any error messages)

```
>make
>make install
```

Will complete the process. After the installation

```
rsync -avz qt5pi pi@raspberrypi_ip:/usr/local

```
to send the new folders to the pi.

**Becareful at there**
You need to copy this file.
```
cp -R qt-everywhere-src-5.12.5/qtbase/mkspecs/linux-arm-gnueabi-g++ qt-everywhere-src-5.12.5/qtbase/mkspecs/linux-arm-gnueabihf-g++
```
After that moving you need to
```
sudo mv /usr/lib/arm-linux-gnueabihf/libEGL.so.1.0.0 /usr/lib/arm-linux-gnueabihf/libEGL.so.1.0.0_backup
```
And at the and link your libraries at the pi libraries
```
sudo ln -s /opt/vc/lib/libEGL.so /usr/lib/arm-linux-gnueabihf/libEGL.so.1.0.0
sudo ln -s /opt/vc/lib/libGLESv2.so /usr/lib/arm-linux-gnueabihf/libGLESv2.so.2.0.0
sudo ln -s /opt/vc/lib/libbrcmEGL.so /opt/vc/lib/libEGL.so
sudo ln -s /opt/vc/lib/libbrcmGLESv2.so /opt/vc/lib/libGLESv2.so
```

**This EGL/GLES libraries must be match the files from your raspbian.**

Congratulations you setted up your raspberry pi 3 for the cross compile process :)

```
~/raspi/qt5/bin/qmake
make -j8
scp _filename_ pi@_hostname_:/home/pi
```
These codes will cross compile your project fully.
