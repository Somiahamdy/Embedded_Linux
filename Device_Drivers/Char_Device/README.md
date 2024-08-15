---
Creating Character Device Driver for linux kernel
---
#### Driver Initialization
1- Allocate range for character device ID   

2- Initialize cdev for the device creation

3- Add cdev to kernel

4- Create class to hold the devices

5- Create the device 

#### Deriver Deinitialization
1- Remove created device

2- Remove created class

3- Remove cdev from kernel

4- Remove ID range for the device

#### File Operations
Implement the needed file operations on devices (Open - Read - Write - Close)
#### Create Makefile
Create makefile to compile the driver modules
#### Compilation and Installation
Run ```make``` to compile the driver modules
Insert the module using ```insmod``` 
check for output using ```dmesg```
#### Test the driver
Write using ```echo``` on to the device file under /dev 
Read using ```cat``` the device file under /dev
#### Cleanup
Remove module using ```rmmod```
Remove device from kernel under /dev









