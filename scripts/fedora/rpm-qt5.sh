#!/bin/bash
# Fedora: sudo dnf install rpmdevtools rpm-sign autoconf automake qt5-qtbase-devel desktop-file-utils aspell-fr enchant2-aspell
# Fedora: configure: error: C compiler cannot create executables? remove and reinstall glibc-devel gcc

cd "$(dirname "$0")"
version="4.0.0"
qt="qt5"

mkdir -p builder ~/rpmbuild/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}
find builder/* ! -name "*$version*.rpm" ! -name "*$version*.gz" -exec rm -rf {} + 2>/dev/null
rm -f ~/rpmbuild/SOURCES/awf-$qt-$version.tar.gz

# copy to a tmp directory
if [ true ]; then
	rm awf-$qt.spec
	wget https://raw.githubusercontent.com/luigifab/awf-extended/refs/tags/v$version/scripts/fedora/awf-$qt.spec
	chmod 644 awf-$qt.spec
	spectool -g -R awf-$qt.spec
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

	cp builder/$temp.tar.gz ~/rpmbuild/SOURCES/awf-$qt-$version.tar.gz
	chmod 644 awf-$qt.spec
fi

# create package (rpm sign https://access.redhat.com/articles/3359321)
rpmbuild -ba awf-$qt.spec
rpm --addsign ~/rpmbuild/RPMS/*/awf-$qt*.rpm
rpm --addsign ~/rpmbuild/SRPMS/awf-$qt*.rpm
mv ~/rpmbuild/RPMS/*/awf-$qt*.rpm builder/
mv ~/rpmbuild/SRPMS/awf-$qt*.rpm builder/
echo "==========================="
rpm --checksig builder/awf-$qt*.rpm
echo "==========================="
rpmlint awf-$qt.spec builder/awf-$qt*.rpm
echo "==========================="
rm builder/*debug*rpm
ls -dlth "$PWD/"builder/*.rpm
echo "==========================="

# cleanup
rm -rf builder/*/