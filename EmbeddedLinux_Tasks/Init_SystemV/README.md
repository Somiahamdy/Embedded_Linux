---
Create a Customized Run Level to start and kill specific apps
---
#### 1- create an application under /bin
```
cd /bin
touch myapp
vi myapp
```
```
#!/bin/bash
while true
   echo "my application is running"
done
```
make application executable
```
chmod +x myapp
```
#### 2- create a script for the applocation under /etc/init.d
The application script used to start and stop the application
```
#! /bin/sh
case "$1" in
      start)
           echo "Starting myapp........."
           start-stop-daemon -S -n myapp -a /bin/myapp &
           ;;
     stop)
           echo "Stopping myapp........."
           start-stop-daemon -K -n myapp
           ;;
     *)
           echo "Usage: $0 {start|stop}"
           exit 1
esac
exit 0
```
#### 3- create a run level to start myapp
run levels are created under /etc
```
mkdir rc2.d
cd rc2.d
```
#### 4- create a soft link to myapp script to start it 
```
cd rc2.d
ln -s /etc/init.d/myapp S01myapp
```
#### 5- create a run level to stop myapp
```
mkdir rc3.d
cd rc3.d
```
#### 6- create a soft link to myapp script to kill it 
```
cd rc3.d
ln -s /etc/init.d/myapp K01myapp
```
#### 7- create rc.c script to run different run levels
under /etc/init.d
```
touch rc.c
vi rc.c
```
```
#!/bin/sh
# Check if one argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <runlevel>"
    exit 1
fi
# Define the folder path based on the argument
folder="rc$1.d"
# Kill scripts starting with K
for i in /etc/$folder/K??* ;do
     # Ignore dangling symlinks (if any).
     [ ! -f "$i" ] && continue
     case "$i" in
        *.sh)
            # Source shell script for speed.
            (
                trap - INT QUIT TSTP
                set stop
                . $i
            )
            ;;
        *)
            # No sh extension, so fork subprocess.
            $i stop
            ;;
    esac
done
# Start scripts starting with S
for i in /etc/$folder/S??* ;do
     # Ignore dangling symlinks (if any).
     [ ! -f "$i" ] && continue
     case "$i" in
        *.sh)
            # Source shell script for speed.
            (
                trap - INT QUIT TSTP
                set start
                . $i
            )
            ;;
        *)
            # No sh extension, so fork subprocess.
            $i start
            ;;
    esac
done
```
change rc.c script permissions to be executable
```
chmod +x rc.c
```
#### 8- edit inittab to execute rc.c script
```
rc2:2:wait:/etc/init.d/rc.c 2
rc3:3:wait:/etc/init.d/rc.c 3
```
![inittabrc](https://github.com/user-attachments/assets/90a6927e-65b5-46a3-afe0-25e6b9732f51)
#### 9- switch to run level 2
```
init 2
```
![init2](https://github.com/user-attachments/assets/3692c396-507e-411d-bbb7-fd7279c4a4f8)
#### 10- switch to run level 3
```
init 3
```
![init3](https://github.com/user-attachments/assets/26f50d05-8653-404c-81cd-1343dd710301)





















