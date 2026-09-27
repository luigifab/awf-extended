# build
bin_PROGRAMS =
BUILT_SOURCES =
CLEANFILES = $(BUILT_SOURCES)

ICON_SIZES     = 16 22 24 32 48 64 128
ICON_CONVERT   = -background none svg:- \( -clone 0 -resize 64x64 \) \( -clone 0 -resize 48x48 \) \( -clone 0 -resize 32x32 \) \( -clone 0 -resize 24x24 \) \( -clone 0 -resize 16x16 \) -delete 0
ICON_COLOR_ADW = 9141AC
ICON_COLOR_GTK = 09F
ICON_COLOR_QT  = 2ED03C

if ADWAITA
bin_PROGRAMS += awf-adw
awf_adw_SOURCES = awf-adw.c
awf_adw_CPPFLAGS = $(ADWAITA_CFLAGS) $(LIBNOTIFY_CFLAGS)
awf_adw_LDADD = $(ADWAITA_LIBS) $(LIBNOTIFY_LIBS)
if WINDOWS
awf_adw_LDADD += awf-adw-res.o
awf-adw-res.o: awf.rc
	sed -e 's/>0</>A</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_ADW)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-adw.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=ADW $< -o $@
endif
endif

if GTK2
bin_PROGRAMS += awf-gtk2
awf_gtk2_SOURCES = awf-gtk2.c
awf_gtk2_CPPFLAGS = $(GTK2_CFLAGS) $(LIBNOTIFY_CFLAGS)
awf_gtk2_LDADD = $(GTK2_LIBS) $(LIBNOTIFY_LIBS)
if WINDOWS
awf_gtk2_LDADD += awf-gtk2-res.o
awf-gtk2-res.o: awf.rc
	sed -e 's/>0</>2</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-gtk2.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=GTK2 $< -o $@
endif
endif

if GTK3
bin_PROGRAMS += awf-gtk3
awf_gtk3_SOURCES = awf-gtk3.c
awf_gtk3_CPPFLAGS = $(GTK3_CFLAGS) $(LIBNOTIFY_CFLAGS)
awf_gtk3_LDADD = $(GTK3_LIBS) $(LIBNOTIFY_LIBS)
if WINDOWS
awf_gtk3_LDADD += awf-gtk3-res.o
awf-gtk3-res.o: awf.rc
	sed -e 's/>0</>3</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-gtk3.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=GTK3 $< -o $@
endif
endif

if GTK4
bin_PROGRAMS += awf-gtk4
awf_gtk4_SOURCES = awf-gtk4.c
awf_gtk4_CPPFLAGS = $(GTK4_CFLAGS) $(LIBNOTIFY_CFLAGS)
awf_gtk4_LDADD = $(GTK4_LIBS) $(LIBNOTIFY_LIBS)
if WINDOWS
awf_gtk4_LDADD += awf-gtk4-res.o
awf-gtk4-res.o: awf.rc
	sed -e 's/>0</>4</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-gtk4.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=GTK4 $< -o $@
endif
endif

if GTK5
bin_PROGRAMS += awf-gtk5
awf_gtk5_SOURCES = awf-gtk5.c
awf_gtk5_CPPFLAGS = $(GTK5_CFLAGS) $(LIBNOTIFY_CFLAGS)
awf_gtk5_LDADD = $(GTK5_LIBS) $(LIBNOTIFY_LIBS)
if WINDOWS
awf_gtk5_LDADD += awf-gtk5-res.o
awf-gtk5-res.o: awf.rc
	sed -e 's/>0</>5</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-gtk5.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=GTK5 $< -o $@
endif
endif

if QT4
bin_PROGRAMS += awf-qt4
BUILT_SOURCES += awf-qt4.moc
awf-qt4.moc: awf-qt4.cpp
	$(QT4_MOC) $(QT4_CFLAGS) $< -o $@
awf_qt4_SOURCES = awf-qt4.cpp
awf_qt4_CPPFLAGS = $(QT4_CFLAGS)
awf_qt4_LDADD = $(QT4_LIBS)
awf_qt4_CXXFLAGS = -fPIC -std=gnu++11
if WINDOWS
awf_qt4_LDADD += awf-qt4-res.o -lintl
awf-qt4-res.o: awf.rc
	sed -e 's/>0</>4</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-qt4.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=QT4 $< -o $@
endif
endif

if QT5
bin_PROGRAMS += awf-qt5
BUILT_SOURCES += awf-qt5.moc
awf-qt5.moc: awf-qt5.cpp
	$(QT5_MOC) $(QT5_CFLAGS) $< -o $@
awf_qt5_SOURCES = awf-qt5.cpp
awf_qt5_CPPFLAGS = $(QT5_CFLAGS)
awf_qt5_LDADD = $(QT5_LIBS)
awf_qt5_CXXFLAGS = -fPIC -std=c++17
if WINDOWS
awf_qt5_LDADD += awf-qt5-res.o -lintl
awf-qt5-res.o: awf.rc
	sed -e 's/>0</>5</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-qt5.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=QT5 $< -o $@
endif
endif

if QT6
bin_PROGRAMS += awf-qt6
BUILT_SOURCES += awf-qt6.moc
awf-qt6.moc: awf-qt6.cpp
	$(QT6_MOC) $(QT6_CFLAGS) $< -o $@
awf_qt6_SOURCES = awf-qt6.cpp
awf_qt6_CPPFLAGS = $(QT6_CFLAGS)
awf_qt6_LDADD = $(QT6_LIBS)
awf_qt6_CXXFLAGS = -fPIC -std=c++17
if WINDOWS
awf_qt6_LDADD += awf-qt6-res.o -lintl
awf-qt6-res.o: awf.rc
	sed -e 's/>0</>6</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-qt6.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=QT6 $< -o $@
endif
endif

if QT7
bin_PROGRAMS += awf-qt7
BUILT_SOURCES += awf-qt7.moc
awf-qt7.moc: awf-qt7.cpp
	$(QT7_MOC) $(QT7_CFLAGS) $< -o $@
awf_qt7_SOURCES = awf-qt7.cpp
awf_qt7_CPPFLAGS = $(QT7_CFLAGS)
awf_qt7_LDADD = $(QT7_LIBS)
awf_qt7_CXXFLAGS = -fPIC -std=c++17
if WINDOWS
awf_qt7_LDADD += awf-qt7-res.o -lintl
awf-qt7-res.o: awf.rc
	sed -e 's/>0</>7</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $(srcdir)/../data/awf.svg | \
	$(CONVERT) $(ICON_CONVERT) $(srcdir)/awf-qt7.ico && \
	$(WINDRES) -I$(srcdir) -c 65001 -DENGINE=QT7 $< -o $@
endif
endif

clean-local:
	rm -f awf-*.ico

# install (desktop files)
if !WINDOWS
desktop_DATA =
desktopdir = $(datadir)/applications
if ADWAITA
desktop_DATA += $(srcdir)/../data/awf-adw.desktop
endif
if GTK2
desktop_DATA += $(srcdir)/../data/awf-gtk2.desktop
endif
if GTK3
desktop_DATA += $(srcdir)/../data/awf-gtk3.desktop
endif
if GTK4
desktop_DATA += $(srcdir)/../data/awf-gtk4.desktop
endif
if GTK5
desktop_DATA += $(srcdir)/../data/awf-gtk5.desktop
endif
if QT4
desktop_DATA += $(srcdir)/../data/awf-qt4.desktop
endif
if QT5
desktop_DATA += $(srcdir)/../data/awf-qt5.desktop
endif
if QT6
desktop_DATA += $(srcdir)/../data/awf-qt6.desktop
endif
if QT7
desktop_DATA += $(srcdir)/../data/awf-qt7.desktop
endif
endif

# install (man pages)
man_MANS =
if ADWAITA
man_MANS += $(srcdir)/../data/awf-adw.1
endif
if GTK2
man_MANS += $(srcdir)/../data/awf-gtk2.1
endif
if GTK3
man_MANS += $(srcdir)/../data/awf-gtk3.1
endif
if GTK4
man_MANS += $(srcdir)/../data/awf-gtk4.1
endif
if GTK5
man_MANS += $(srcdir)/../data/awf-gtk5.1
endif
if QT4
man_MANS += $(srcdir)/../data/awf-qt4.1
endif
if QT5
man_MANS += $(srcdir)/../data/awf-qt5.1
endif
if QT6
man_MANS += $(srcdir)/../data/awf-qt6.1
endif
if QT7
man_MANS += $(srcdir)/../data/awf-qt7.1
endif

# install (translated man pages/icons/locales/bash-completion)
# test -z "$(EXEEXT)" = check if EXEEXT is empty
install-data-hook:
	for app in $(bin_PROGRAMS); do \
		app=$${app%$(EXEEXT)}; \
		install -Dpm 644 $(srcdir)/../data/$$app.fr.1 $(DESTDIR)$(mandir)/fr/man1/$$app.1; \
		install -Dpm 644 $(srcdir)/../data/$$app.ka.1 $(DESTDIR)$(mandir)/ka/man1/$$app.1; \
		if test -z "$(EXEEXT)"; then \
			svg=$$app.tmp.svg; \
			cp $(srcdir)/../data/awf.svg $$svg; \
			case $$app in \
				awf-adw)  sed -i -e 's/>0</>A</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_ADW)"/g' $$svg ;; \
				awf-gtk2) sed -i -e 's/>0</>2</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $$svg ;; \
				awf-gtk3) sed -i -e 's/>0</>3</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $$svg ;; \
				awf-gtk4) sed -i -e 's/>0</>4</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $$svg ;; \
				awf-gtk5) sed -i -e 's/>0</>5</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_GTK)"/g' $$svg ;; \
				awf-qt4)  sed -i -e 's/>0</>4</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $$svg ;; \
				awf-qt5)  sed -i -e 's/>0</>5</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $$svg ;; \
				awf-qt6)  sed -i -e 's/>0</>6</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $$svg ;; \
				awf-qt7)  sed -i -e 's/>0</>7</' -e 's/fill="#09F"/fill="#$(ICON_COLOR_QT)"/g' $$svg ;; \
			esac; \
			install -Dpm 644 $$svg $(DESTDIR)$(datadir)/icons/hicolor/scalable/apps/$$app.svg; \
			for size in $(ICON_SIZES); do \
				install -dm 755 $(DESTDIR)$(datadir)/icons/hicolor/$${size}x$${size}/apps; \
				$(CONVERT) -w $$size -h $$size $$svg -o $(DESTDIR)$(datadir)/icons/hicolor/$${size}x$${size}/apps/$$app.png; \
			done; \
			rm -f $$svg; \
		fi; \
		for file in $(srcdir)/po/*.po; do \
			code=`basename $$file .po`; \
			install -dm 755 $(DESTDIR)$(datadir)/locale/$$code/LC_MESSAGES/; \
			$(MSGFMT) $$file -o $(DESTDIR)$(datadir)/locale/$$code/LC_MESSAGES/$$app.mo; \
		done; \
		install -Dpm 644 $(srcdir)/../data/$$app.bash $(DESTDIR)$(datadir)/bash-completion/completions/$$app; \
	done

# uninstall (translated man pages/icons/locales/bash-completion)
uninstall-hook:
	for app in awf-adw awf-gtk2 awf-gtk3 awf-gtk4 awf-gtk5 awf-qt4 awf-qt5 awf-qt6 awf-qt7; do \
		rm -f $(DESTDIR)$(mandir)/*/man1/$$app.1; \
		if test -z "$(EXEEXT)"; then \
			rm -f $(DESTDIR)$(datadir)/icons/hicolor/scalable/apps/$$app.svg; \
			for size in $(ICON_SIZES); do \
				rm -f $(DESTDIR)$(datadir)/icons/hicolor/$${size}x$${size}/apps/$$app.png; \
			done; \
		fi; \
		for file in $(srcdir)/po/*.po; do \
			code=`basename $$file .po`; \
			rm -f $(DESTDIR)$(datadir)/locale/$$code/LC_MESSAGES/$$app.mo; \
		done; \
		rm -f $(DESTDIR)$(datadir)/bash-completion/completions/$$app; \
	done
