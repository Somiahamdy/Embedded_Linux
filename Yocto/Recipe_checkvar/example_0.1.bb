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
