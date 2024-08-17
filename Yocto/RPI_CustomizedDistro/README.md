---
Create Raspberrypi image with Customized Distro and pingled recipe
---

#### 1- Create Almaza Distro
under /mylayer/conf
```
mkdir distro
cd distro/
touch almaza.conf
```
![almazatree](https://github.com/user-attachments/assets/dbce3d22-68d2-46b6-a8bd-4c6062d5629f)

#### 2- Edit almaza distro
include poky distro and append DIRSTO, DISTRONAME and MAINTAINER variables
```
include meta-poky/conf/distro/poky.conf

DISTRO = "almaza"
DISTRO_NAME = "almaza"
DISTRO_VERSION = "4.0.20"
MAINTAINER = "somiaahamdy@gmail.com"
```
#### 3- Create pingled bash script
a script to ping on my host machine ip and if it pings successfully it turns a led on else it turns it off
```
#!/bin/bash

LED_PIN=7  # GPIO pin number for LED 

# Initialize the GPIO pin
gpio mode $LED_PIN out

while true; do
    # Ping the IP address
    if ping -c 1 -W 1 192.168.1.6 > /dev/null 2>&1; then
        # Ping successful, turn on the LED
        gpio write $LED_PIN 1
        echo "Ping successful, LED ON"
    else
        # Ping failed, turn off the LED
        gpio write $LED_PIN 0
        echo "Ping failed, LED OFF"
    fi

    # Wait for 1 second before the next ping
    sleep 1
done
```
#### 4- Create recipe
```
SUMMARY = "iti-layers recipe"
DESCRIPTION = "Recipe to ping on my ip to control a led"
LICENSE = "CLOSED"

SRC_URI="file://pingled.sh"

S="${WORKDIR}/src"
D="${WORKDIR}/dest"

do_install(){
    install -d ${D}/usr/bin
    install -m 0755 ${B}/calculator ${D}/usr/bin/
}
```
#### 5- Clone meta-raspberrypi 
under poky/
```
git clone -b kirkstone https://github.com/agherzan/meta-raspberrypi.git
```
#### 6- Set the Environment
under poky/ 
```
source oe-init-build-env build-rpi
```
Now rpi build directory is created

![buildrpi](https://github.com/user-attachments/assets/04af2c65-92b8-46dc-bd68-ae159e47eec7)

#### 7- Edit local.conf file
under /poky/build-rpi/conf/local.conf

###### - Adjust the machine variable
```
MACHINE ?= "raspberrypi4-64"
```
###### - Adjust the distro variable
```
DISTRO ?= "almaza"
```
###### - Adjust the filesystem type to be sdcard
```
IMAGE_FSTYPES +=" tar.bz2 ext4 rpi-sdimg"
```
###### - Adjust number of threads according to number of cores
```
BB_NUMBER_THREADS ?= "4.5"
PARALLEL_MAKE ?= "-j 6
```
###### - Include the needed apps to your image 
```
IMAGE_INSTALL:append = " apt bash git"
IMAGE_INSTALL:append = " python3"
IMAGE_INSTALL:append = " openssh"
IMAGE_INSTALL:append = " pingrecipe"
```
![rpilocal](https://github.com/user-attachments/assets/abf8344d-1870-4d1b-a5be-b84eacfc0167)

#### 8- Edit bblayers.conf file
Add mylayer to the layers path
```
BBLAYERS ?= " \
  /home/somia/yocto/poky/meta \
  /home/somia/yocto/poky/meta-poky \
  /home/somia/yocto/poky/meta-yocto-bsp \ 
  /home/somia/yocto/meta-mylayer \
  /home/somia/yocto/poky/meta-raspberrypi \
  /home/somia/yocto/poky/meta-openembedded/meta-oe \
   "
```
#### 9- build the rpi image
under poky/build-rpi
```
bitbake core-image-minimal
```




















