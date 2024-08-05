---
Add a package to buildroot
---
#### 1- Create package directory
under /buildroot/package/src
```
mkdir simpleapp
cd simpleapp
touch simpleapp.cpp Makefile
```
#### 2- Edit your application 
```
vi simpleapp.cpp
```
```
#include <iostream>
#include <thread>
using namespace std;

void print(void)
{
   cout << "hello from my simpleapp/n";
}

int main(){
  thread t1(print);
  thread t2(print);

  t1.join();
  t2.join();
  return 0;

  }
```
#### 3- Edit makefile 
To execute the application
```
vi Makefile
```
```
.PHONY: clean
.PHONY: simpleapp

hello: hello.cpp
        $(CC) -o $@ $<

clean:
        -rm simpleapp
```
#### 4- Create .mk file
under /package/simpleapp/
```
touch simpleapp.mk
```
To define how package will be built
```
################################################################################
#
# simpleapp package
#
################################################################################

SIMPLEAPP_VERSION = 1.0
SIMPLEAPP_SITE = package/simpleapp/src
SIMPLEAPP_SITE_METHOD = local# Other methods like git,wget,scp,file etc. are also available.

define SIMPLEAPP_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define SIMPLEAPP_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/main.c  $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))

```
#### 5- Create Config.in file
under /package/simpleapp/
```
touch config.in
```
To define options for package
```
config BR2_PACKAGE_SIMPLEAPP
    bool "simpleapp"
    help
        simpleapp package.
```
#### 6- Add the simpleapp menu at Config.in file under /package/Config.in
```
menu "SIMPLEAPP Packages"
    source "package/simpleapp/Config.in"
endmenu
```
![menu](https://github.com/user-attachments/assets/64c18a3e-9621-47f6-b5ac-518e1ba32321)
#### 7- open menuconfig to check for the added package
```
cd /buildroot
make menuconfig
```
![menuconfig](https://github.com/user-attachments/assets/dce295a2-65a3-49ec-957b-6ab69de016a2)
![simmenu](https://github.com/user-attachments/assets/5c42f573-2d3d-4bf7-941e-c5df08d99582)


