
SUMMARY = "Connectivity application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# Force BitBake to pick main.c from your fork path first
FILESEXTRAPATHS:prepend := "/home/jnedic/workspace/fork/teamb-platform-connectivity/project/stm32mp1xx/ca7/meta-connectivity/recipes-connectivity/connectivity-app/files:"
SRC_URI = "file://main.c"

# Development version bump to ensure rootfs uses new package
PV = "1.0"

S = "${WORKDIR}"
B = "${WORKDIR}/build"

# Build-time deps so headers and .pc files are in target sysroot
DEPENDS = "gtk+3"
inherit pkgconfig

# Ensure we’re targeting a Wayland distro (Weston)
REQUIRED_DISTRO_FEATURES = "wayland"

# Optional: tidy flags
CFLAGS += " -O2 -Wall -Wextra "

do_compile() {
    mkdir -p ${B}
    # Use the native pkg-config explicitly
    PC="${STAGING_BINDIR_NATIVE}/pkg-config"

    ${CC} ${CFLAGS} \
        $(${PC} --cflags gtk+-3.0) \
        -o ${B}/connectivity-app ${S}/main.c \
        $(${PC} --libs gtk+-3.0) \
        ${LDFLAGS}
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/connectivity-app ${D}${bindir}/connectivity-app
}

# Usually unnecessary; shlibdeps will add runtime libs automatically
# RDEPENDS:${PN} += "gtk+3"
