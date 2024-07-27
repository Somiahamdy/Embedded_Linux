---
Loading zImage and .dtb file via TFTP server
---
##### 1. Install TFTP 
```
sudo apt install tftpd-hpa
```
##### 2. Edit TFTP configurations to allow read and write operations
```
sudo vim /etc/default/tftpd-hpa
```

![tftpconf](https://github.com/user-attachments/assets/bb79c5d1-2c92-49d2-b372-d644e040ab4f)
##### 3. restart TFTP service
```
systemctl restart tftpd-hpa
```
##### 4. check TFTP service status
```
systemctl status tftpd-hpa.service
```
![tftpstatus](https://github.com/user-attachments/assets/e593c7df-9f31-4bba-a661-3461c9e375bf)
##### 5. Change TFTP directory permissions to be accessible by Qemu
```
chown tftp:tftp /srv/tftp
```
##### 6. Copy zImage and .dtb file to TFTP directory
```
cp ~/linux/arch/arm/boot/zImage /srv/tftp/
cp ~/linux/arch/arm/boot/dts/arm/vexpress-v2p-ca9.dtb /srv/tftp/
```
#### 7. Set server ip address of host machine and transfer zImage and .dtb file via tftp at Qemu
```
setenv ipaddr 192.168.1.6
tftp $kernel_addr_r zImage
tftp $fdt_addr_r vexpress-v2p-ca9.dtb
```
![zimgtftp1](https://github.com/user-attachments/assets/432c5ee5-7856-439b-bc6d-bd74fd41e0ec)
![fdttftp](https://github.com/user-attachments/assets/39548f27-a0e7-4290-8b5c-ca3ec5bdd16c)
#### 8. check for loaded image in kernel address
```
md $kernel_addr_r
```
![kernelmd](https://github.com/user-attachments/assets/39ff77a8-a969-4b6e-9c93-dd72f0099287)
#### 9. check for loaded file in fdt address
```
md $kernel_addr_r
```
![fdtmd](https://github.com/user-attachments/assets/e1eb80c4-2f55-4fc2-aae7-08b089a0f0d5)

