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
