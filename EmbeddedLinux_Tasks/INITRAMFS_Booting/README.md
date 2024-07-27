---
Booting into initRamfs
---
##### 1. Create initramfs directory
```
mkdir initramfs
```
##### 2. Create required directories
```
mkdir sys proc etc root usr dev
```
##### 3. Copy binary files from busybox to initramfs directory
```
cp -a ~/busybox/_install/* ./
```
##### 4. Create init script 
```
touch init.scr
vim init.scr
```
```
mount -t devtmpfs devtmpfs /dev
mount -t proc none /proc
mount -t sysfs none /sys
exec /bin/sh
```
##### 5. Change script permissions to be executable
```
chmod +x init.scr
```
##### 6. Archive and compress the initramfs directory
```
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio

cd ..

gzip initramfs.cpio

mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```
![uramdisk](https://github.com/user-attachments/assets/8caadfd9-981b-4e7a-baa4-3a8b3295f3e0)

##### 7. Copy uRamdisk image to boot partition in sd card
```
sudo cp uRamdisk sdcard/boot
```
##### 8. Set Environment variables at Qemu
```
setenv $kernel_addr_r 0x60200000
setenv $fdt_addr_r 0x60000000
setenv $initramfs 0x62000000

setenv bootargs "console=ttyAMA0 rdinit=/bin/sh"
```
##### 9. Load zImage , .dtb file and uRamdisk from fat patition
```
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initramfs uRamdisk
```
##### 10. Boot the loaded files 
```
bootz $kernel_addr_r $initramfs $fdt_addr_r
```
![ramfskernel](https://github.com/user-attachments/assets/17e71503-fac9-4e51-89fd-c8fee37bf14a)










