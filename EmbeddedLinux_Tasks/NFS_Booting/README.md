---
Booting into NFS server
---
#### 1. Install kernel server
```
sudo apt install nfs-kernel-server
```
#### 2.Check NFS service status
```
systemctl status nfs-kernel-server
```
![nfssatus](https://github.com/user-attachments/assets/737385a3-5103-4575-a86b-50ee4b3254e8)
#### 3. Mount the directory of NFS server then copy Rootfs to it 
```
sudo mkdir /srv/nfs-share
sudo cp -rp ~/rootfs_k /srv/nfs-share
```
#### 4. Edit the NFS configurations
```
sudo vim /etc/exports
```
Add the NFS client ip
```
/srv/nfs-share 192.168.1.7(rw,no_root_squash,no_subtree_check)
```
![nfsexport](https://github.com/user-attachments/assets/d9b3f02f-a8df-4746-bd46-1fcd99318c99)
#### 5. Restart the NFS server to set the configurations
```
sudo systemctl restart nfs-kernel-server
```
#### 6. Set tap0 ip address and set it up
```
ip a add 192.168.1.6/24 dev tap0
ip link set tap0 up
```
#### 7. Launch Qemu 
```
qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0 -kernel u-boot -sd ~/sdcard/sdd.img
```
#### 8. Set Environment variables at Qemu
```
setenv $kernel_addr_r 0x60200000
setenv $fdt_addr_r 0x60000000

setenv serverip 192.168.1.6
setenv ipaddr 192.168.1.7

setenv bootargs 'console=ttyAMA0  root=/dev/nfs ip=192.168.1.7:::::eth0 nfsroot=192.168.1.6:/srv/nfs-share,nfsvers=3,tcp rw init=/sbin/init'

```
#### 9. Load zImage and .dtb file through TFTP
```
tftp $kernel_addr_r zImage
tftp $fdt_addr_r vexpress-v2p-ca9.dtb
```
![nfszimg](https://github.com/user-attachments/assets/5001b85c-0ea4-4ed9-8ed3-ba7404c8ae77)
![nfsdtb](https://github.com/user-attachments/assets/c203506e-6d63-4099-8eb9-2de854f15a95)
#### 10. Boot loaded files 
```
bootz $kernel_addr_r - $fdt_addr_r
```
![nfskernel](https://github.com/user-attachments/assets/cdc11923-828c-4884-8628-368d20a23f8a)








