#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Qemu");

struct platform_device leddevice2 = {
    .name = "dev2",
    .id = 1,
};

static int __init device2_init(void ){
    printk("device2 is initialized\n");
    platform_device_register(&leddevice2);
    return 0;
}

static void __exit device2_deinit(void){
    printk("device2 deinit is called\n");
    platform_device_unregister(&leddevice2);
}

module_init(device2_init);
module_exit(device2_deinit);
