#!/bin/bash
# Debian: sudo apt install dpkg-dev devscripts build-essential dh-make dh-autoreconf intltool libnotify-dev libgtk-3-dev


cd "$(dirname "$0")"
export DH_QUIET=1
version="4.1.0"
engine="gtk3"

mkdir -p builder
rm -rf builder/*

# copy to a tmp directory
if [ true ]; then
	cd builder
	wget https://github.com/luigifab/awf-extended/archive/v$version/awf-extended-$version.tar.gz
	tar xzf awf-extended-$version.tar.gz
	cd ..
else
	temp=awf-extended-$version
	mkdir /tmp/$temp
	cp -r ../../* /tmp/$temp/
	rm -rf /tmp/$temp/scripts/*/builder/

	mv /tmp/$temp builder/
	cp /usr/share/common-licenses/GPL*3 builder/$temp/LICENSE

	cd builder/
	tar czf $temp.tar.gz $temp
	cd ..
fi


# create packages for Debian and Ubuntu
for serie in experimental resolute questing noble jammy focal bionic xenial trusty; do

	printf "\n\n################################################################### $serie ## awf-$engine\n\n"
	if [ $serie = "experimental" ]; then
		# copy for Ubuntu
		cp -a builder/awf-extended-$version/ builder/awf-extended-$version+src/
		cd builder/awf-extended-$version/
	elif [ $serie = "unstable" ]; then
		rm -rf builder/awf-extended-$version/
		cp -a builder/awf-extended-$version+src/ builder/awf-extended-$version/
		cd builder/awf-extended-$version/
	else
		cp -a builder/awf-extended-$version+src/ builder/awf-extended-$serie-$version/
		cd builder/awf-extended-$serie-$version/
	fi

	dh_make -s -y -f ../awf-extended-$version.tar.gz -p awf-$engine

	rm -rf debian/*/*ex debian/*ex debian/*EX debian/README* debian/*doc*
	cp scripts/debian-$engine/* debian/
	cp scripts/debian-gtk/*$engine* scripts/debian-gtk/copyright scripts/debian-gtk/metadata debian/
	head -n -1 debian/*$engine*.install > debian/install ; rm debian/awf-$engine.install
	rm -f debian/deb.sh
	mkdir debian/upstream ; mv debian/metadata debian/upstream/metadata

	# debhelper: experimental:13 focal/mx21:12 bionic:9 xenial:9 trusty:9
	if [ $serie = "experimental" ] || [ $serie = "unstable" ]; then
		mv debian/control.debian debian/control
	elif [ $serie = "mx21" ]; then
		sed -i 's/debhelper-compat (= 13)/debhelper-compat (= 12)/g' debian/control
	elif [ $serie = "focal" ]; then
		mv debian/control.ubuntu debian/control
		sed -i 's/debhelper-compat (= 13)/debhelper-compat (= 12)/g' debian/control
	elif [ $serie = "bionic" ]; then
		mv debian/control.ubuntu debian/control
		sed -i 's/dh $@/dh $@ --with autoreconf/g' debian/rules
		sed -i 's/execute_before_dh_install:/override_dh_update_autotools_config:/g' debian/rules
		sed -i 's/debhelper-compat (= 13)/debhelper-compat (= 9), dh-autoreconf/g' debian/control
	elif [ $serie = "xenial" ]; then
		mv debian/control.ubuntu debian/control
		sed -i 's/dh $@/dh $@ --with autoreconf/g' debian/rules
		sed -i 's/execute_before_dh_install:/override_dh_update_autotools_config:/g' debian/rules
		sed -i 's/debhelper-compat (= 13)/debhelper (>= 9), dh-autoreconf/g' debian/control
		sed -i ':a;N;$!ba;s/Rules-Requires-Root: no\n//g' debian/control
		echo 9 > debian/compat
	elif [ $serie = "trusty" ]; then
		mv debian/control.ubuntu debian/control
		sed -i 's/dh $@/dh $@ --with autotools_dev,autoreconf/g' debian/rules
		sed -i 's/execute_before_dh_install:/override_dh_autotools-dev_updateconfig:/g' debian/rules
		sed -i 's/debhelper-compat (= 13)/debhelper (>= 9), autotools-dev, dh-autoreconf/g' debian/control
		sed -i ':a;N;$!ba;s/Rules-Requires-Root: no\n//g' debian/control
		echo 9 > debian/compat
	else
		mv debian/control.ubuntu debian/control
	fi

	if [ $serie = "mx25" ] || [ $serie = "mx23" ] || [ $serie = "mx21" ]; then
		mv debian/changelog.mx debian/changelog
		sed -i 's/-1) /-1~'$serie'+1) /' debian/changelog
		sed -i 's/ experimental; / mx; /' debian/changelog
		sed -i 's/ unstable; / mx; /' debian/changelog
	elif [ $serie = "experimental" ] || [ $serie = "unstable" ]; then
		sed -i 's/ experimental; / '$serie'; /g' debian/changelog
		mv debian/changelog.debian debian/changelog
	else
		mv debian/changelog.ubuntu debian/changelog
		sed -i 's/ experimental; / '$serie'; /g' debian/changelog
		sed -i 's/-1) /-1+'$serie') /' debian/changelog
	fi
	rm -f debian/*.mx debian/*.debian debian/*.ubuntu

	if [ $serie = "experimental" ]; then
		echo "===================== build package ($serie) =="
		dpkg-buildpackage -us -uc
		echo "=========================== lintian ($serie) =="
		lintian -EviIL +pedantic ../awf-${gtk}_$version*.changes
		rm ../*amd64.changes
	fi

	echo "============== build source package ($serie) =="
	dpkg-buildpackage -us -uc -ui -d -S
	cd ..

	if [ $serie = "experimental" ] || [ $serie = "unstable" ]; then
		echo "=========================== debsign ($serie) =="
		debsign awf-$engine*$version-*_source.changes
	else
		echo "=========================== debsign ($serie) =="
		debsign awf-$engine*$version*$serie*source.changes
	fi
	cd ..
done

printf "\n\n"
rm builder/*dbgsym*deb
ls -dlth "$PWD"/builder/*.deb "$PWD"/builder/*.changes
printf "\n"
rm -rf builder/*/