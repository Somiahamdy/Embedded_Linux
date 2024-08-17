#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Qemu");

static struct platform_device leddevice1 = {
    .name = "dev1",
    .id = 0,
};

static int __init device1_init(void ){
    printk("device1 is initialized\n");
    platform_device_register(&leddevice1);
    return 0;
}

static void __exit device1_deinit(void){
    printk("device1 deinit is called\n");
    platform_device_unregister(&leddevice1);
}

module_init(device1_init);
module_exit(device1_deinit);
