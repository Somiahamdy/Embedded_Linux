#include "fileoperations.h"
MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("somia");

define DEVICE_NAME "itidevice"

dev_t deviceID;
struct class *myclass; //class device belongs to
struct cdev devicestruct; //structure that holds device info

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close,
    .read = driver_read,
    .write = driver_write,
};

/***************** device initialization ************************/
static int __init device_init(void){

    printk("hello from device init\n");

    //allocat range of character devices
    if(alloc_chrdev_region(&deviceID,0,1,DEVICE_NAME) < 0){
        printk("couldn't reserve space");
        return -1;
    }
    printk("major: %d, minor: %d\n",MAJOR(deviceID),MINOR(deviceID));

    //initialize cdev of my device
    cdev_init(&devicestruct,&fops);

    //add device to kernel
    if(cdev_add(&devicestruct,deviceID,1)== -1){
        printk("device wasn't added to kernel\n");
        unregister_chrdev_region(deviceID,1);
        return -1;
    }

    //create class under dev to hold my devices
    myclass=class_create(NULL,DEVICE_NAME);

    //check for class creation by checking the class the device belongs to
    if(myclass==NULL){
        printk("class wasn't created\n");
        cdev_del(&devicestruct);
       
    }
    //create a device under my class
    if(device_create(myclass,NULL,deviceID,NULL,DEVICE_NAME)==NULL){
        printk("device file wasn't created\n");
        class_destroy(myclass);
    }
    return 0;
}

static void __exit device_deinit(void){
    //remove structure from last created to first created
    //first -> remove device
    device_destroy(myclass,deviceID);
    //second -> remove class
    class_destroy(myclass);
    //third -> remove device from kernel
    cdev_del(&devicestruct);
    //fourth -> remove reserved blocks for device
    unregister_chrdev_region(deviceID,1);

    printk("hello from device deinit");
}

module_init(device_init);
module_exit(device_deinit);
