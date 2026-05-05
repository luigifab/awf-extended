#!/bin/bash
#
# Windows XP + mingw32
#
# 1/ download mingw-get-setup.exe from https://sourceforge.net/projects/mingw/files/Installer/ (2013-10-04)
#    install in C:\MinGw
#
# 2/ run C:\MinGW\msys\1.0\msys.bat
#    then run: mingw-get.exe install mingw32-gcc-bin mingw32-gcc-g++-bin mingw32-make mingw32-gettext mingw32-gettext-dev msys-base msys-autoconf msys-automake msys-libtool   or install them from MinGW GUI
#
# 3/ download pkg.m4 from https://raw.githubusercontent.com/pkgconf/pkgconf/refs/heads/master/pkg.m4
#    put the file in C:\MinGW\msys\1.0\share\aclocal
#
# 4/ download gtk+-bundle_2.24.10-20120208_win32.zip from https://download.gnome.org/binaries/win32/gtk+/2.24/
#    extract the archive in C:\GTK2
#
# 5/ download gtk+-bundle_3.6.4-20130513_win32.zip from https://tarnyko.net/dl/gtk3.htm
#	extract the archive in C:\GTK3
#    copy C:\GTK3\share\themes\Default to C:\GTK3\share\themes\gtk-win32-xp
#
# 6/ download qt-opensource-windows-x86-mingw482_opengl-5.3.2.exe from https://download.qt.io/new_archive/qt/5.3/5.3.2/
#    install in C:\tempQT
#	move C:\tempQT\5.3\mingw482_32 to C:\QT5
#	uninstall qt-opensource-windows-x86-mingw482_opengl-5.3.2.exe and remove C:\tempQT
#
# 7/ download pkg-config-lite-0.28-1_bin-win32.zip from https://sourceforge.net/projects/pkgconfiglite/files/0.28-1/
#	extract the archive in C:\QT5
#
# 8/ download and install NSIS from https://sourceforge.net/projects/nsis/files/
#
# 9/ open My Computer → Properties → Advanced → Environment Variables, in PATH add
#    ;C:\MinGW\bin;C:\MinGW\msys\1.0\bin;C:\Program Files\NSIS
#
#
# To manually build with GTK2 run: C:\MinGW\msys\1.0\msys.bat
#  cd /c/awf-gtk
#  export PATH=/c/GTK2/bin:$PATH
#  export PKG_CONFIG_PATH=/c/GTK2/lib/pkgconfig
#  bash build.sh LDFLAGS="-mwindows" --enable-only-gtk2
#
# To manually build with GTK3 run: C:\MinGW\msys\1.0\msys.bat
#  cd /c/awf-gtk
#  export PATH=/c/GTK3/bin:$PATH
#  export PKG_CONFIG_PATH=/c/GTK3/lib/pkgconfig
#  bash build.sh LDFLAGS="-mwindows" --enable-only-gtk3
#
# To manually build with QT5 run: C:\MinGW\msys\1.0\msys.bat
#  cd /c/awf-gtk
#  export PATH=/c/QT5/bin:$PATH
#  export PKG_CONFIG_PATH=/c/QT5/lib/pkgconfig
#  bash build.sh LDFLAGS="-mwindows -static-libstdc++" --enable-only-qt5
#
# To build with GTK2/GTK3/QT5 with this script run: C:\MinGW\msys\1.0\msys.bat
#  cd /c/awf-gtk
#  bash scripts/windows/zip.sh

cd "$(dirname "$0")"
originalpath="$PATH"
version="4.1.0"

rm -rf builder/*
mkdir -p builder

# copy to a tmp directory
if [ true ]; then
	cd builder
	wget https://github.com/luigifab/awf-extended/archive/v$version/awf-extended-$version.tar.gz
	tar xzf awf-extended-$version.tar.gz
	cd ..
else
	mkdir builder/awf-extended-$version
	cp -r ../../* builder/awf-extended-$version/
fi

# search things
function copydeps {
	# 1=file 2=dest 3=root
	objdump.exe -p "$1" | grep -i 'DLL Name' | awk '{print $NF}' | grep -v -i '^\(libgcc\|libstdc++\)' | while read dll
	do
		if [ -f "$3/$dll" ] && [ ! -f "$2/$dll" ]; then
			echo " - $dll"
			cp -a "$3/$dll" "$2"
			copydeps "$3/$dll" "$2" "$3"
		fi
	done
}

if [ -d "/mingw64" ]; then
	host="--host=x86_64-w64-mingw32"
else
	host=""
fi

arch=$(echo "$PROCESSOR_ARCHITECTURE" | tr '[:upper:]' '[:lower:]')
[ "$arch" = "x86" ] && [ -n "$PROCESSOR_ARCHITEW6432" ] && arch=$(echo "$PROCESSOR_ARCHITEW6432" | tr '[:upper:]' '[:lower:]')
case "$arch" in
	x86|i386|i486|i586|i686) arch="x86"    archname="(32 bits)" ;;
	amd64|x86_64)            arch="x86_64" archname="(64 bits)" ;;
	arm64|aarch64)           arch="arm64"  archname="(64 bits)" ;;
	*)
		arch=$(uname -m 2>/dev/null)
		case "$arch" in
			i386|i486|i586|i686) arch="x86"     archname="(32 bits)" ;;
			x86_64|amd64)        arch="x86_64"  archname="(64 bits)" ;;
			aarch64|arm64)       arch="arm64"   archname="(64 bits)" ;;
			*)                   arch="unknown" archname=""          ;;
		esac
		;;
esac

# create packages
cd builder/awf-extended-$version/

for engine in "2" "3" "4"; do

	printf "\n\n############################################################ awf-gtk$engine\n\n"
	if [ -d "/mingw64" ]; then
		ROOT=/mingw64
	else
		ROOT=/c/GTK$engine
		if [ ! -d "$ROOT" ]; then
			echo "$ROOT not found, skipping..."
			continue
		fi
	fi

	export PATH=$ROOT/bin:$PATH
	export PKG_CONFIG_PATH=$ROOT/lib/pkgconfig
	export PKG_CONFIG_LIBDIR=$ROOT/lib/pkgconfig
	autoreconf -fi && ./configure $host LDFLAGS="-mwindows" --enable-only-gtk$engine && make -s
	result=$?

	if [ $result -eq 0 ]; then

		echo "Success..."

		echo " awf-gtk$engine.exe"
		mkdir ../gtk$engine
		mv src/awf-gtk$engine.exe ../gtk$engine/
		copydeps ../gtk$engine/awf-gtk$engine.exe ../gtk$engine/ $ROOT/bin/

		if [ $engine = "2" ]; then
			echo " - lib/engines"
			mkdir -p ../gtk$engine/share
			mkdir -p ../gtk$engine/lib/gtk-2.0/2.10.0/engines
			cp -a $ROOT/lib/gtk-2.0/2.10.0/engines/*.dll ../gtk$engine/lib/gtk-2.0/2.10.0/engines/
		elif [ $engine = "3" ]; then
			echo " - share/schemas"
			mkdir -p ../gtk$engine/share/glib-2.0/schemas
			cp -a $ROOT/share/glib-2.0/schemas/gschemas.compiled ../gtk$engine/share/glib-2.0/schemas/
		elif [ $engine = "4" ]; then
			echo " - share/schemas"
			mkdir -p ../gtk$engine/share/glib-2.0/schemas
			cp -a $ROOT/share/glib-2.0/schemas/gschemas.compiled ../gtk$engine/share/glib-2.0/schemas/
		fi

		echo " - share/themes"
		cp -ar $ROOT/share/themes/ ../gtk$engine/share/

		echo " - share/locale"
		cp -ar $ROOT/share/locale/ ../gtk$engine/share/

		echo " - msgfmt"
		for file in src/po/*.po; do
			code=`basename "${file}" .po`
			mkdir -p ../gtk$engine/share/locale/$code/LC_MESSAGES
			msgfmt src/po/$code.po -o ../gtk$engine/share/locale/$code/LC_MESSAGES/awf-gtk$engine.mo
		done

		echo "Nsis..."
		cp ../../setup-awf-gtk$engine.nsi ../setup-awf-gtk$engine.nsi
		enginever=$(strings.exe -e l ../gtk$engine/libgtk*.dll | grep -A1 "ProductVersion" | tail -1)
		sed -i 's/:ENGINEVERSION:/'"$enginever"'/g' ../setup-awf-gtk$engine.nsi
		sed -i 's/:AWFVERSION:/'"$version"'/g' ../setup-awf-gtk$engine.nsi
		sed -i 's/:ARCHNAME:/'"$archname"'/g' ../setup-awf-gtk$engine.nsi
		sed -i 's/:ARCH:/'"$arch"'/g' ../setup-awf-gtk$engine.nsi

		makensis -V1 ../setup-awf-gtk$engine.nsi
		result=$?
		if [ $result -eq 0 ]; then
			rm ../setup-awf-gtk$engine.nsi
			echo " setup-awf-gtk$engine.exe"
		fi
	fi
	export PATH=$originalpath
done

for engine in "5" "6"; do

	printf "\n\n############################################################# awf-qt$engine\n\n"
	if [ -d "/mingw64" ]; then
		ROOT=/mingw64
		ROOTRANS=$ROOT/share/qt5/
		ROOTPLUG=$ROOT/share/qt5/
	else
		ROOT=/c/QT$engine
		ROOTRANS=$ROOT/
		ROOTPLUG=$ROOT/
		if [ ! -d "$ROOT" ]; then
			echo "WARNING: $ROOT not found, skipping..."
			continue
		fi
	fi

	export PATH=$ROOT/bin:$PATH
	export PKG_CONFIG_PATH=$ROOT/lib/pkgconfig
	export PKG_CONFIG_LIBDIR=$ROOT/lib/pkgconfig
	autoreconf -fi && ./configure $host LDFLAGS="-mwindows -static-libstdc++" --enable-only-qt$engine && make -s
	result=$?

	if [ $result -eq 0 ]; then

		echo "Success..."

		echo " awf-qt$engine.exe"
		mkdir ../qt$engine
		mv src/awf-qt$engine.exe ../qt$engine/
		copydeps ../qt$engine/awf-qt$engine.exe ../qt$engine/ $ROOT/bin/

		echo " - plugins/platforms"
		mkdir -p ../qt$engine/platforms
		cp -a $ROOTPLUG/plugins/platforms/qwindows*.dll ../qt$engine/platforms/

		echo " - translations"
		cp -ar $ROOTRANS/translations/ ../qt$engine/

		echo " - msgfmt"
		for file in src/po/*.po; do
			code=`basename "${file}" .po`
			mkdir -p ../qt$engine/share/locale/$code/LC_MESSAGES
			msgfmt src/po/$code.po -o ../qt$engine/share/locale/$code/LC_MESSAGES/awf-qt$engine.mo
		done

		echo "Nsis..."
		cp ../../setup-awf-qt$engine.nsi ../setup-awf-qt$engine.nsi
		enginever=$(strings.exe -e l ../qt$engine/*Core*.dll | grep -A1 "ProductVersion" | tail -1)
		sed -i 's/:ENGINEVERSION:/'"$enginever"'/g' ../setup-awf-qt$engine.nsi
		sed -i 's/:AWFVERSION:/'"$version"'/g' ../setup-awf-qt$engine.nsi
		sed -i 's/:ARCHNAME:/'"$archname"'/g' ../setup-awf-qt$engine.nsi
		sed -i 's/:ARCH:/'"$arch"'/g' ../setup-awf-qt$engine.nsi

		makensis -V1 ../setup-awf-qt$engine.nsi
		result=$?
		if [ $result -eq 0 ]; then
			rm ../setup-awf-qt$engine.nsi
			echo " setup-awf-qt$engine.exe"
		fi
	fi
	export PATH=$originalpath
done

cd ../..
printf "\n\n"
ls -dlth "$PWD"/builder/*.exe
rm -rf builder/awf-extended-$version/