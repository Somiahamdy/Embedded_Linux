#ifndef FILEOPERATION
#define FILEOPERATION
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>


int driver_open(struct inode *device_file,struct file *instance);
int driver_close(struct inode *device_file,struct file *instance);
ssize_t driver_write(struct file *file,const char __user *user_buffer,size_t count,loff_t *offs);
ssize_t driver_read(struct file *file,char __user *user_buffer,size_t count,loff_t *offs);


#endif
