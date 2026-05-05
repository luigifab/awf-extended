#!/bin/bash
# Mageia: sudo urpmi --no-recommends rpmdevtools rpm-sign autoconf automake qt7-devel desktop-file-utils aspell-fr enchant2-aspell


cd "$(dirname "$0")"
version="4.1.0"
engine="qt7"

mkdir -p builder ~/rpmbuild/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}
find builder/* ! -name "*$version*.rpm" ! -name "*$version*.gz" -exec rm -rf {} + 2>/dev/null
rm -f ~/rpmbuild/SOURCES/awf-$engine-$version.tar.gz

# copy to a tmp directory
if [ true ]; then
	rm awf-$engine.spec
	wget https://raw.githubusercontent.com/luigifab/awf-extended/refs/tags/v$version/scripts/mageia/awf-$engine.spec
	chmod 644 awf-$engine.spec
	spectool -g -R awf-$engine.spec
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

	cp builder/$temp.tar.gz ~/rpmbuild/SOURCES/awf-$engine-$version.tar.gz
	chmod 644 awf-$engine.spec
fi

# create package (rpm sign https://access.redhat.com/articles/3359321)
printf "\n############################################################################## awf-$engine\n"
rpmbuild --quiet -ba awf-$engine.spec
echo "=================================== rpm-sign =="
rpm --addsign ~/rpmbuild/RPMS/*/awf-$engine*.rpm
rpm --addsign ~/rpmbuild/SRPMS/awf-$engine*.rpm
mv ~/rpmbuild/RPMS/*/awf-$engine*.rpm builder/
mv ~/rpmbuild/SRPMS/awf-$engine*.rpm builder/
rpm --checksig builder/awf-$engine*.rpm
echo "=================================== rpm-lint =="
rpmlint awf-$engine.spec builder/awf-$engine*.rpm | grep awf
echo "==============================================="
rm builder/*debug*rpm
ls -dlth "$PWD"/builder/*.rpm

# cleanup
rm -rf builder/*/