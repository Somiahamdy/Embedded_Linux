##### 1. Add tap interface on your host machine
```
ip tuntap add tap0 mode tap
```
##### 2. set up the tap interface on your host machine
```
ip a add 192.168.1.6/24 dev tap0
ip link set tap0 up
```
##### 3. to check that tap0 interface added properly
```
ip a
```
![tap0](https://github.com/user-attachments/assets/e612e061-d1b7-4b91-ad09-aa15f908bb3f)

##### 4. create the booting script 
```
#check for mmc existance
if mmc dev; then
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
bootz $kernel_addr_r - $fdt_addr_r
elif ping 192.168.1.7; then
echo "booting from network"
else
echo "no option"
```
##### 5. convert booting script from .src file to a uImage to run on u-boot
```
mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "Boot Script" -d bootingscript.scr bootingscript.img
```
![mkimg](https://github.com/user-attachments/assets/5e00c147-2ad1-42c3-886d-8c92c2c821c5)

##### 6. at qemu set your ip addr and the kernel , fdt & load addresses
```
setenv ipaddr 192.168.1.7
setenv kernel_addr_r 0x601000000
setenv fdt_addr_r 0x600000000
setenv loadaddr 0x601000000
saveenv
```
##### 7. at qemu set bootcmd var to run the script once autoboot is done & reset to start the qemu
```
setenv bootcmd "load mmc 0:1 $loadaddr bootingscript.img"
saveenv
reset
```

