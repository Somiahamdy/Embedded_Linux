---
Booting into RAMFS by choosing the partition of the rootfs
---
#### 1. Create initramfs directory 
```
mkdir initramfs
```
#### 2. Create required directories
```
mkdir sys proc etc root usr dev mnt
```
#### 3. Copy binary files from busybox to initramfs directory
```
cp -a ~/busybox/_install/* ./
```
#### 4. Create init script 
```
touch init.scr
vim init.scr
```
```
mount -t devtmpfs devtmpfs /dev
mount -t proc none /proc
mount -t sysfs none /sys
sh /etc/dbscript.scr
exec /bin/sh
```
#### 5. Change script permissions to be executable
```
chmod +x init.scr
```
#### 6. Create a script to choose the partition
```
touch /etc/dbscript.scr
vim /etc/dbscript.scr
```
```
#!/bin/sh
echo "Available options
1-> Partition 1
2-> Partition 2
3-> No option"
echo "Enter your option"
read -r option
case $option in
1)
mount -t ext4 /dev/mmcblk0p2 /mnt/rootfsp1
chroot /mnt/rootfsp1
;;
2)
mount -t ext4 /dev/mmcblk0p3 /mnt/rootfsp2
chroot /mnt/rootfsp2
;;
3)
echo "No option"
break
;;
esac
```
#### 7. Archive and compress the initramfs directory
```
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio

cd ..

gzip initramfs.cpio

mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```
![uramdisk](https://github.com/user-attachments/assets/8caadfd9-981b-4e7a-baa4-3a8b3295f3e0)

#### 8. Copy uRamdisk image to boot partition in sd card
```
sudo cp uRamdisk sdcard/boot
```
#### 9. launch Qemu
```
qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0 -kernel u-boot -sd ~/sdcard/sdd.img
```
##### 10. Set Environment variables at Qemu
```
setenv $kernel_addr_r 0x60200000
setenv $fdt_addr_r 0x60000000
setenv $initramfs 0x62000000

setenv bootargs "console=ttyAMA0 rdinit=init.src"
```
##### 11. Load zImage , .dtb file and uRamdisk from fat patition
```
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initramfs uRamdisk
```
##### 12. Boot the loaded files 
```
bootz $kernel_addr_r $initramfs $fdt_addr_r
```
![ramfspartkerel](https://github.com/user-attachments/assets/67a48b2a-b8f0-4c34-9020-1c88d9bb6c62)



