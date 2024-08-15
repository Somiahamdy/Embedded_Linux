#include "fileoperations.h"
define buffer_size 1024
char buffer[buffer_size]; //to hold data 
static ssize_t buffer_pointer;


//called when device file is opened
int driver_open(struct inode *device_file,struct file *instance){
    printk("device is opened!\n");
    return 0;
}
//called when device file is closed
int driver_close(struct inode *device_file,struct file *instance){
    printk("device is closed!\n");
    return 0;
}
//called when write to a file
ssize_t driver_write(struct file *file,const char __user *user_buffer,size_t count,loff_t *offs){
    printk("write function is called!\n");
    int to_copy , not_copied , difference;
    // get available data in kernel buffer
    int available_space = buffer_size - buffer_pointer;
    // get size of data to copy
    to_copy = min(available_space,count);

    // copy data to buffer
    not_copied = copy_from_user (buffer+buffer_pointer,user_buffer,to_copy);

    // to change the offset of the buffer
    buffer_pointer += to_copy - not_copied ;

    // to get the data the not copied
    difference = to_copy - not_copied ;

    return difference;

}

ssize_t driver_read(struct file *file,char __user *user_buffer,size_t count,loff_t *offs){
    printk("read function is called!\n");
    int to_copy , not_copied , difference;
    // get the data to copy
    to_copy = min(count , buffer_pointer);
    // if there's no data to copy 
    if(to_copy < 0){
       return 0;
    }
    //copy data to user buffer
    not_copied = copy_to_user(user_buffer,buffer,to_copy);

    // to change offset of the buffer
    buffer_pointer -= to_copy - not_copied ;
    // calculate difference 
    difference = to_copy - not_copied ;

    return difference ;

}

