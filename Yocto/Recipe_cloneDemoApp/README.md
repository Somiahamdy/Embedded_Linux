---
Clone App from github then compile using Cmake
---
#### 1- Create your Recipe
under /yocto/meta-mylayer/recipes-example/
```
mkdir myrecipe
```
#### 2- Adjust the recipe with need variables
```
SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe to clone application"
LICENSE = "MIT" 

inherit cmake  

DEPENDS = "cmake"

LIC_FILES_CHKSUM="file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI= "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
SRCREV="720c663c5fd7246b4b42c5205d74db7d9784b5b2"

S= "${WORKDIR}/git"
D= "${WORKDIR}/image"
```
#### 3- Add cmake configuration for myrecipe
```
do_configure() {
    mkdir -p ${B}   #create directory for cmake config.txt file
    cd ${B}         
    cmake ${S} -DCMAKE_INSTALL_PREFIX=${D}    
}
```

#### 4- Compile using cmake
```
do_compile(){
    cmake --build ${B}
}
```
#### 5- Add the destination directory for the application bin file
```
do_install(){ 
    install -d ${D}/usr/bin     #create destination directory
    install -m 0755 ${B}/calculator ${D}/usr/bin/   #move built app from build diretory to destination directory anfd change its permissions
}
```
#### 6-bitbake your recipe
```
bitbake myrecipe
```
![myrecipeout](https://github.com/user-attachments/assets/845ca30b-9220-44db-8ec7-dde1224ea419)
#### 7- check for application in destination
![binfile](https://github.com/user-attachments/assets/db3b4f78-8ab6-4740-a271-7e6251cdc2ec)











