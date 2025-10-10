#!/bin/bash
# Debian: sudo apt install build-essential dh-make dh-autoreconf intltool libnotify-dev libgtk2.0-dev libgtk-3-dev libgtk-4-dev libgtk-5-dev
# Fedora: sudo dnf install autoconf automake libnotify-devel gtk2-devel gtk3-devel gtk4-devel gtk5-devel desktop-file-utils
# openSUSE: sudo zypper install autoconf automake libnotify-devel gtk2-devel gtk3-devel gtk4-devel gtk5-devel desktop-file-utils
#
# supported options for build.sh and configure.ac
#  --disable-gtk2 --disable-gtk3 --disable-gtk4 --disable-gtk5
# OR
#  --enable-only-gtk2
# OR
#  --enable-only-gtk3
# OR
#  --enable-only-gtk4
# OR
#  --enable-only-gtk5

# remove old builds
rm -f awf-gtk2 awf-gtk3 awf-gtk4 awf-gtk5

# copy to a tmp directory
mkdir builder builder/src
cp /usr/share/common-licenses/GPL*3 builder/LICENSE
cp configure.ac    builder/
cp Makefile.am     builder/
cp src/Makefile.am builder/src/
cp src/awf-gtk*.c  builder/src/

# build
cd builder/
autoreconf -fi
./configure "$@"
make -s

# final
cp src/awf-gtk* ..
cd ..
ls -altrh awf-gtk5 awf-gtk4 awf-gtk3 awf-gtk2
rm -rf builder/