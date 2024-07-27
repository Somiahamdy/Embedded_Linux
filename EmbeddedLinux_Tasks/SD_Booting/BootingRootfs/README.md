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
##### 7. 
