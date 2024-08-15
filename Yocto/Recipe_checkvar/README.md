---
Create Recipe to check for variable value
---
#### 1- Set an environment
under /poky/
```
source oe-init-build-env
```
#### 2- Create my layer 
outside poky directory
under ~/yocto/meta-mylayer
```
cd yocto
mkdir meta-mylayer
cd poky/build/
bitbake-layers create-layer /home/somia/yocto/mylayer
```
Now layer is created

![recipetree](https://github.com/user-attachments/assets/c3f4744c-cb4b-474d-989e-03fe09416c4e)
#### 3- Add layer path to bblayers.conf
```
cd poky/build/conf/
```
![bblayers](https://github.com/user-attachments/assets/48c535d4-7c4c-408b-b7d5-490b412f5bd0)
#### 4- Check for added layer
```
bitbake-layers show-layers
```
Now layer is added

![showlayer](https://github.com/user-attachments/assets/6a2ad13e-35bb-484f-aa4b-058228ce5ca2)

#### 5- Add My_var to layer.conf 
```
cd /yocto/meta-mylayer/conf/
```
![layerconf](https://github.com/user-attachments/assets/069b5228-20ab-4993-bf14-21110ba2ebb2)

#### 6- Edit example recipe
```
SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "MIT"

python do_display_banner() {
    value= d.getVar("My_var",True)
    if value == "0": 
      bb.plain("***********************************************");
      bb.plain("*                                             *");
      bb.plain("*             Hello from somia recipe         *");
      bb.plain("*                                             *");
      bb.plain("***********************************************");
    elif value == "1":
      bb.plain("***********************************************");
      bb.plain("*                                             *");
      bb.plain("*              Hello from my recipe           *");
      bb.plain("*                                             *");
      bb.plain("***********************************************");
    else:
      bb.plain("***********************************************");
      bb.plain("*                                             *");
      bb.plain("*              bye from your recipe           *");
      bb.plain("*                                             *");
      bb.plain("***********************************************");


}

addtask display_banner before do_build
```
#### Bitbake the recipe
```
bitbake example
```
![bitrecipe](https://github.com/user-attachments/assets/1ce6eb2b-deac-4683-bd1f-ac39f3c46e30)














