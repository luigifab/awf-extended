#!/bin/bash



cd "$(dirname "$0")"
version="3.2.0"
gtk="gtk4"

mkdir -p builder builder/{BUILD,RPMS,SRPMS}
find builder/* ! -name "*$version*.rpm" ! -name "*$version*.gz" -exec rm -rf {} + 2>/dev/null


# copy to a tmp directory
if [ true ]; then
	rm awf-$gtk.spec
	wget https://raw.githubusercontent.com/luigifab/awf-extended/refs/tags/v$version/scripts/openmandriva/awf-$gtk.spec
	chmod 644 awf-$gtk.spec
	spectool -g -R awf-$gtk.spec
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

	mv builder/$temp.tar.gz awf-$gtk-$version.tar.gz
	chmod 644 awf-$gtk.spec
fi

# create package (rpm sign https://access.redhat.com/articles/3359321)
cp -a awf-$gtk-$version.tar.gz awf-$gtk.spec builder/
cd builder/
abb builda
rpm --addsign RPMS/*/awf-$gtk*.rpm
rpm --addsign SRPMS/awf-$gtk*.rpm
mv RPMS/*/awf-$gtk*.rpm .
mv SRPMS/awf-$gtk*.rpm .
echo "==========================="
rpm --checksig *.rpm
echo "==========================="
rpmlint awf-$gtk.spec *.rpm
echo "==========================="
rm *debug*rpm
ls -dlth "$PWD/"*.rpm
echo "==========================="
cd ..

# cleanup
rm -rf builder/*/ builder/*buildlog builder/*spec awf-$gtk-$version.tar.gz