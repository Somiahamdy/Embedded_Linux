---
Create Platform Device Driver to control raspberrypi leds
---
#### Install the raspberrypi kernel headers
```
sudo apt-get install raspberrypi-kernel-headers
```
#### Device Initialization

1- Register each led to platform bus with name and id

2- Allocate GPIO pin for each led 

3- Create character device for each led

#### Device Deinitialization

1- Unregister each led from plaform bus 

2- Release GPIO pins

3- Remove created devices for each led

#### File operations

Implement the needed file operations on devices (Open - Read - Write - Close)

#### Create Makefile

Create makefile to compile the driver modules

#### Compilation and Installation

- Run ```make``` to compile the driver modules 

- Insert the modules
```
sudo insmod device1.ko
sudo insmod device2.ko
sudo insmod driver.ko
```

#### Test the driver 
```
echo "1" > /dev/led1
echo "1" > /dev/led2
```

#### cleanup 

Remove module using rmmod Remove devices from kernel under /dev








