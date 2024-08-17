#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x367fcc51, "module_layout" },
	{ 0x7fbb56eb, "class_destroy" },
	{ 0x9bd226fc, "platform_driver_unregister" },
	{ 0xf7795eed, "__platform_driver_register" },
	{ 0xc6e25dc2, "cdev_del" },
	{ 0xec8c17d0, "__class_create" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x6bfecf8d, "cdev_add" },
	{ 0xbe15ede5, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xfe990052, "gpio_free" },
	{ 0xa95a24d, "gpiod_set_raw_value" },
	{ 0x4ce2483a, "device_destroy" },
	{ 0xfff45d34, "device_create" },
	{ 0xe66e0f70, "gpiod_direction_output_raw" },
	{ 0x6928ae65, "gpio_to_desc" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5656D9A035C710EC062F34C");
