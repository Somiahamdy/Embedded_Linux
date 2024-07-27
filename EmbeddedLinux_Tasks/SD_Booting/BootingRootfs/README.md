---
Booting Rootfs from SD Card
---
##### 1. Clone Busybox Repository
```
git clone https://github.com/mirror/busybox.git
```
##### 2. Set Environment Variables
```
export ARCH=arm
export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
```
##### 3. Adjust Busybox configurations
```
make menuconfig
```
select build static binary 
##### 4. Build then Install Busybox
```
make
make install
```
##### 5. Make rootfs directory and copy all binaries to it
```
cd ~
mkdir rootfs_k
rsync -a ~/busybox/_install/* rootfs_k
```
##### 6. Make all required directories
```
mkdir etc usr proc dev boot mnt srv sys root
```
##### 7. Create startup script rcS
```
mkdir etc/init.d
touch etc/init.d/ rcS
vim etc/init.d/rcS
```
##### 8. put initiatlization commands to the script
```
#!/bin/sh
# Mount proc and sys filesystems
mount -t proc nodev /proc
mount -t sysfs nodev /sys
# Mount devtmpfs if not configured in Kernel
mount -t devtmpfs devtmpfs /dev
```
##### 9. Change script permissions to be executable
```
chmod +x ~/rootfs_k/etc/init.d/rcS
```
##### 10. Create inittab script
```
touch etc/ inittab
vim etc/inittab
```
```
 Execute rcS script during system startup
::sysinit:/etc/init.d/rcS
# Start a shell on the console (ask for key press)
ttyAMA0::askfirst:-/bin/sh
# Restart init process
::restart:/sbin/init
```
##### 11. Change rootfs_k owner to be root
```
chown -R root:root path/rootfs
```
##### 12. Copy rootfs_k file content to rootfs partition in sd card
```
sudo cp -rp ~/rootfs_k/* ~/sdcard/rootfs
```
##### 13. Copy zImage and .dtb file to boot partition in sd card
```
sudo cp path/linux/arch/arm/boot/zImage ~/sdcard/boot
sudo cp path/linux/arch/arm/boot/dts/arm/vexpress-v2p-ca9.dtb ~/sdcard/boot
```
##### 14. set bootargs , kernel address and fdt address in Qemu
```
setenv bootargs "console=ttyAMA0 root=/dev/mmcblk0p2 rootfstpye=ext4 rw rootwait init=/sbin/init"
setenv kernel_addr_r	0x60100000 
setenv fdt_addr_r	0x60000000
```
##### 15. load zIamge and .dtb file from sd card
```
fatload mmc 0:1 $kernel_addr_r	zImage
fatload mmc 0:1 $fdt_addr_r	vexpress-v2p-ca9.dtb
```
##### 16. check for loaded zImage in kernel address
```
md $kernel_addr_r
```
![kernelmd](https://github.com/user-attachments/assets/7dcf4493-e13e-437d-bb06-1d3d0521a5a3)
##### 17. check for loaded vexpress-v2p-ca9.dtb file in fdt address
```
md $fdt_addr_r
```
![fdtmd](https://github.com/user-attachments/assets/a6a24293-2aae-4bea-a329-4671016b5005)
##### 18. Boot the kernel
```
bootz $kernel_addr_r - $fdt_addr_r
```
![rfskernel](https://github.com/user-attachments/assets/49057c35-995e-4d05-ba01-8f136d8c2c97)









 
