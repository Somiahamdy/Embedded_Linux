#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>


MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("somia");

#define MODULE_NAME "platformdevice"
#define buffer_size 1024
char buffer[buffer_size]; //to hold data 

dev_t deviceID;
struct class *myclass; //class device belongs to
struct cdev devicestruct; //structure that holds device info
static ssize_t buffer_pointer;

static char led_1[3]={0}; //input values to led1
static char led_2[3]={0}; //input values to led2

enum dev{
    LED1=2,
    LED2
}status;


/**********************platfrom device***************************/

//struct of devices ids
struct platform_device_id device_id[2] = {
    [0] = { .name = "led1" } ,
    [1] = { .name = "led2" } ,
};


// prob function to detect the added device called when device is added
int prob_device(struct platform_device *deviceobj){
    printk("%s device is detected\n",deviceobj->name);
    //check for added device id
    if(strcmp(deviceobj->name , "led1") == 0){
        //request for gpio pin 2 to be reserved for led1
        if(gpio_request(2,"reserved for led1")){
            printk("gpio pin2 didn't reserve successfully for led1/n");

        }else {
            printk("gpio pin2 reserved successfully for led1/n");
        }
        //set gpio pin2 direction to be output
        if(gpio_direction_output(2,0)){
            printk("failed to set gpio pin2 direction\n");
        }else {
            printk("gpio pin2 direction is output\n");
        }

    }else if(strcmp(deviceobj->name , "led2") == 0){
        //request for gpio pin 3 to be reserved for led2
        if(gpio_request(3,"reserved for led2")){
            printk("gpio pin3 wasn't reserved successfully for led2/n");

        }else {
            printk("gpio pin3 reserved successfully for led2/n");
        }
        //set gpio pin3 direction to be output
        if(gpio_direction_output(3,0)){
            printk("failed to set gpio pin3 direction\n");
        }else {
            printk("gpio pin3 direction is output\n");
        }

    }
    //create device file for the detected device
    if(device_create(myclass,NULL,deviceID + deviceobj->id,NULL,deviceobj->name) == NULL){
        printk("failed to create device for %s \n",deviceobj->name);
    }else {
        printk("device for %s created successfully\n",deviceobj->name);
    }
    printk("device added successfully!\n");
    return 0; //function succeeded to add the detected device
}

// device remove function called when device is removed
int device_remove(struct platform_device *deviceobj){
    //check for the device id
    if(strcmp(deviceobj->name , "led1")==0){
        // set pin2 value to be 0 and release it
        gpio_set_value(2,0);
        gpio_free(2);
    }else if(strcmp(deviceobj->name , "led2")==0){
        // set pin3 value to be 0 and release it
        gpio_set_value(3,0);
        gpio_free(3);
    }

    //destroy the device file that was created for it
    device_destroy(myclass,deviceID + deviceobj->id);

    printk("device removed successfully\n");

    return 0;
}

// platform driver structure to hold the platform device data
struct platform_driver pfd_data = {
    .probe = prob_device,
    .remove = device_remove,
    .id_table = device_id,
    .driver = {
        .name = "my driver"
    }

};




/*************************** file operations ********************************/

//called when device file is opened
int driver_open(struct inode *device_file,struct file *instance){
    //get device major and minor ids
    int major = MAJOR(device_file->i_rdev);
    int minor = MINOR(device_file->i_rdev);
    
    instance->private_data = &minor ; //points to the device
    
    printk("device %d is opened!\n",minor);

    return 0;
}
//called when device file is closed
int driver_close(struct inode *device_file,struct file *instance){
    printk("device is closed!\n");
    return 0;
}
//called when write to a file
ssize_t driver_write(struct file *file,const char __user *user_buffer,size_t count,loff_t *offs){
    printk("write function is called\n");
    char (*value)[3] = NULL;
    int not_copied;
    
    //determine the device based on the minor number.
    if (*(int *)file->private_data == 0)
    {
        value = &led_1;
        status = LED1;
    }
    else if (*(int *)file->private_data == 1)
    {
        value = &led_2;
        status = LED2;
    }

    //copy data to kernel buffer
    not_copied = copy_from_user(value, user_buffer, 3);

    //process the user input data
    switch ((*value)[0])
    {
    case '0':
        gpio_set_value(status, 0);
        printk("cleared gpio pin successfully\n");
        break;
    case '1':
        gpio_set_value(status, 1);
        printk("set gpio pin successfully\n");
        break;
    default:
        printk("invalid input\n");
        break;
    }

    //adjust the count 
    count = count - not_copied;
    return count;
}

ssize_t driver_read(struct file *file,char __user *user_buffer,size_t count,loff_t *offs){
    printk("read function is called!\n");
    return -ENOSYS;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close,
    .read = driver_read,
    .write = driver_write,
};

/********************* module initialization ***********************/

static int __init device_init(void){
    printk("module init function is called\n");
    //allocate char device region
    if(alloc_chrdev_region(&deviceID,0,1,MODULE_NAME) < 0){
        printk("couldn't allocate char device region/n");
        return -1;
    }

    //initialize cdev 
    cdev_init(&devicestruct,&fops);

    //add device to kernel
    if(cdev_add(&devicestruct,deviceID,1)<0){
        printk("device wasn't added\n");
        unregister_chrdev_region(deviceID,1);
        return -1;
    }

    //add device class to device
    if(class_create(NULL,MODULE_NAME)==NULL){
        printk("class wasn't created\n");
        cdev_del(&devicestruct);
    }

    //register platform driver
    platform_driver_register(&pfd_data);

    return 0;

}

/************************* module deinitialization **********************/

static void __exit device_deinit(void){
    printk("module deinit is called\n");
    //unregister platform driver
    platform_driver_unregister(&pfd_data);

    // destroy device class
    class_destroy(myclass);

    //destroy device
    cdev_del(&devicestruct);

    //remove reserved blocks for device
    unregister_chrdev_region(deviceID,1);

}

module_init(device_init);
module_exit(device_deinit);


