#!/bin/bash
# Debian: sudo apt install build-essential dh-make dh-autoreconf pkgconf intltool libnotify-dev libgtk2.0-dev libgtk-3-dev libgtk-4-dev libgtk-5-dev qtbase5-dev qt6-base-dev qt7-base-dev libnotify-bin
# Fedora: sudo dnf install autoconf automake libnotify-devel gtk2-devel gtk3-devel gtk4-devel gtk5-devel desktop-file-utils qt5-qtbase-devel qt6-qtbase-devel qt7-qtbase-devel
# openSUSE: sudo zypper install autoconf automake libnotify-devel gtk2-devel gtk3-devel gtk4-devel gtk5-devel desktop-file-utils qt5-base-devel qt6-base-devel qt7-base-devel
#
# supported options for build.sh/configure.ac
#  none
# OR
#  --disable-gtk2 --disable-gtk3 --disable-gtk4 --disable-gtk5 --disable-qt4 --disable-qt5 --disable-qt6 --disable-qt7
#  --disable-gtk                                               --disable-qt
# OR
#  --enable-only-gtk2
# OR
#  --enable-only-gtk3
# OR
#  --enable-only-gtk4
# OR
#  --enable-only-gtk5
# OR
#  --enable-only-qt4
# OR
#  --enable-only-qt5
# OR
#  --enable-only-qt6
# OR
#  --enable-only-qt7

rm -rf awf-gtk2* awf-gtk3* awf-gtk4* awf-gtk5* awf-qt4* awf-qt5* awf-qt6* awf-qt7* builder/

# copy to a tmp directory
mkdir builder builder/src builder/data
cp /usr/share/common-licenses/GPL*3 builder/LICENSE
cp configure.ac      builder/
cp Makefile.am       builder/
cp src/Makefile.am   builder/src/
cp src/awf-gtk*.c    builder/src/
cp src/awf-qt*.cpp   builder/src/
cp src/awf.rc        builder/src/
# for windows
cp data/awf.ico      builder/data/
# for make install
cp data/awf*.bash    builder/data/
cp data/awf*.desktop builder/data/
cp data/awf*.1       builder/data/
cp -r data/icons     builder/data/

# build
cd builder/
autoreconf -fi && ./configure "$@" && make -s
result=$?
cd ..

# final
if [ $result -eq 0 ]; then
	cp builder/src/awf-gtk* builder/src/awf-qt* .
	rm -f awf-gtk*.c awf-qt*.cpp awf-qt*.moc awf-qt*.o
	ls -altrh awf-gtk2* awf-gtk3* awf-gtk4* awf-gtk5* awf-qt4* awf-qt5* awf-qt6* awf-qt7*
fi
rm -rf builder/