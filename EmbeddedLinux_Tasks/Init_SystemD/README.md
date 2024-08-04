---
Main Directories in systemd
---
1- /etc/systemd/system: where all units get created
2- /etc/systemd/system.conf: where all globla configurations of systemd exist
3- /lib./systemd/system: where all units from installed packages exist

---
To create a service
---
under /etc/systemd/system
#### 1- create network service 
```
cd /etc/systend/system
sudo touch mynetwork.network
sudo vi mynetwork.network
```
```
[Unit]
	Name="wlp0s20f3"

[Network]
	Address=192.168.1.6/24
```
#### 2- create service
```
sudo touch myservice.service
sudo vi myservice.service
```
```
[Unit]
	Wants=mynetwork.network

[Service]
	Type=simple
	ExecStart=/usr/bin/ping 192.168.1.7 -c 3
	Restart=always
	RestartSec=3
	WorkingDirectory=/usr/bin

[Install]
	WantedBy=graphical.target
```
#### 3- start myservice
```
systemctl start myservice.service
systemctl enable myservice.service
```

![ctlstart](https://github.com/user-attachments/assets/f8b1a2c2-e3b6-4431-84b6-4c38f31d9a30)

#### 4- check for logs
```
journalctl -u myservice.service
```
![servceoutput](https://github.com/user-attachments/assets/3e208209-7192-44ef-80a1-aabe01af215e)









