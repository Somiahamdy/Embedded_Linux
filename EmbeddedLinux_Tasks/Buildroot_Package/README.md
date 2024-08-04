---
Add a package to buildroot
---
#### 1- Create package directory
under /buildroot/package
```
mkdir helloapp
cd helloapp
touch hello.cpp hello.mk Makefile config.in
```
#### 2- Edit your application 
```
vi hello.cpp
```
```
#include <iostream>
#include <thread>
using namespace std;

void print(void)
{
   cout << "hello from my app/n";
}

int main(){
  thread t1(print);
  thread t2(print);

  t1.join();
  t2.join();
  return 0;

  }
```
#### 3- edit makefile 
To execute the application
```
vi Makefile
```
```
.PHONY: clean
.PHONY: hello

hello: hello.cpp
        $(CC) -o '$@' '$<'

clean:
        -rm hello
```
#### 4- Edit mk file
To define how package will be built
```
################################################################################
#
# hello package
#
################################################################################

SIMPLEAPP_VERSION = 1.0
SIMPLEAPP_SITE = package/helloapp/src
SIMPLEAPP_SITE_METHOD = local# Other methods like git,wget,scp,file etc. are also available.

define SIMPLEAPP_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define SIMPLEAPP_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/main.c  $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))

```
#### 5- Edit Config.in file
To define options for package
```
config BR2_PACKAGE_SIMPLEAPP
    bool "HelloApp"
    help
        helloapp package.
```
