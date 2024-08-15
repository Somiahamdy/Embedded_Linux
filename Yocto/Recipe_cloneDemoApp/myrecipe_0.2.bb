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

do_configure() {
    mkdir -p ${B}
    cd ${B}
    cmake ${S} -DCMAKE_INSTALL_PREFIX=${D}
}

do_compile(){
    cmake --build ${B}
}

do_install(){
    install -d ${D}/usr/bin
    install -m 0755 ${B}/calculator ${D}/usr/bin/
}
