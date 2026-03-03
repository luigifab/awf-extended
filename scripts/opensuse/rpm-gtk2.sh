#!/bin/bash
# openSUSE: sudo zypper install rpmdevtools rpm-build autoconf automake libnotify-devel gtk2-devel desktop-file-utils aspell-fr


cd "$(dirname "$0")"
version="4.0.0"
gtk="gtk2"

mkdir -p builder ~/rpmbuild/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}
find builder/* ! -name "*$version*.rpm" ! -name "*$version*.gz" -exec rm -rf {} + 2>/dev/null
rm -f ~/rpmbuild/SOURCES/awf-$gtk-$version.tar.gz

# copy to a tmp directory
if [ true ]; then
	rm awf-$gtk.spec
	wget https://raw.githubusercontent.com/luigifab/awf-extended/refs/tags/v$version/scripts/opensuse/awf-$gtk.spec
	chmod 644 awf-$gtk.spec
	spectool -g -R awf-$gtk.spec
else
	temp=awf-extended-$version
	mkdir /tmp/$temp
	cp -r ../../* /tmp/$temp/
	rm -rf /tmp/$temp/scripts/*/builder/

	mv /tmp/$temp builder/
	cp /usr/share/licenses/*-firmware/GPL-3 builder/$temp/LICENSE # * = kernel

	cd builder/
	tar czf $temp.tar.gz $temp
	cd ..

	cp builder/$temp.tar.gz ~/rpmbuild/SOURCES/awf-$gtk-$version.tar.gz
	chmod 644 awf-$gtk.spec
fi

# create package (rpm sign https://access.redhat.com/articles/3359321)
rpmbuild -ba awf-$gtk.spec
rpm --addsign ~/rpmbuild/RPMS/*/awf-$gtk*.rpm
rpm --addsign ~/rpmbuild/SRPMS/awf-$gtk*.rpm
mv ~/rpmbuild/RPMS/*/awf-$gtk*.rpm builder/
mv ~/rpmbuild/SRPMS/awf-$gtk*.rpm builder/
echo "==========================="
rpm --checksig builder/awf-$gtk*.rpm
echo "==========================="
rpmlint awf-$gtk.spec builder/awf-$gtk*.rpm
echo "==========================="
rm builder/*debug*rpm
ls -dlth "$PWD/"builder/*.rpm
echo "==========================="

# cleanup
rm -rf builder/*/