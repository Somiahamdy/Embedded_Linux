SUMMARY = "iti-layers recipe"
DESCRIPTION = "Recipe to ping on my ip to control a led"
LICENSE = "CLOSED"

SRC_URI="file://pingled.sh"

S="${WORKDIR}/src"
D="${WORKDIR}/dest"

do_install(){
    install -d ${D}/usr/bin
    install -m 0755 ${B}/calculator ${D}/usr/bin/
}
