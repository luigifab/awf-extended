# build
bin_PROGRAMS =
BUILT_SOURCES =
CLEANFILES = $(BUILT_SOURCES)

if GTK5
bin_PROGRAMS += awf-gtk5
awf_gtk5_SOURCES = awf-gtk5.c
awf_gtk5_CPPFLAGS = $(GTK5_CFLAGS) $(LIBNOTIFY_CFLAGS)
awf_gtk5_LDADD = $(GTK5_LIBS) $(LIBNOTIFY_LIBS)
if WINDOWS
awf_gtk5_LDADD += awf-gtk5-res.o
awf-gtk5-res.o: awf.rc
	$(WINDRES) -c 65001 -DENGINE=GTK5 $< -o $@
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
	$(WINDRES) -c 65001 -DENGINE=GTK4 $< -o $@
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
	$(WINDRES) -c 65001 -DENGINE=GTK3 $< -o $@
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
	$(WINDRES) -c 65001 -DENGINE=GTK2 $< -o $@
endif
endif

if QT7
AM_CXXFLAGS = -fPIC -std=c++17
bin_PROGRAMS += awf-qt7
BUILT_SOURCES += awf-qt7.moc
awf-qt7.moc: awf-qt7.cpp
	$(QT7_MOC) $(QT7_CFLAGS) $< -o $@
awf_qt7_SOURCES = awf-qt7.cpp
awf_qt7_CPPFLAGS = $(QT7_CFLAGS)
awf_qt7_LDADD = $(QT7_LIBS)
if WINDOWS
awf_qt7_LDADD += awf-qt7-res.o -lintl
awf-qt7-res.o: awf.rc
	$(WINDRES) -c 65001 -DENGINE=QT7 $< -o $@
endif
endif

if QT6
AM_CXXFLAGS = -fPIC -std=c++17
bin_PROGRAMS += awf-qt6
BUILT_SOURCES += awf-qt6.moc
awf-qt6.moc: awf-qt6.cpp
	$(QT6_MOC) $(QT6_CFLAGS) $< -o $@
awf_qt6_SOURCES = awf-qt6.cpp
awf_qt6_CPPFLAGS = $(QT6_CFLAGS)
awf_qt6_LDADD = $(QT6_LIBS)
if WINDOWS
awf_qt6_LDADD += awf-qt6-res.o -lintl
awf-qt6-res.o: awf.rc
	$(WINDRES) -c 65001 -DENGINE=QT6 $< -o $@
endif
endif

if QT5
AM_CXXFLAGS = -fPIC -std=c++17
bin_PROGRAMS += awf-qt5
BUILT_SOURCES += awf-qt5.moc
awf-qt5.moc: awf-qt5.cpp
	$(QT5_MOC) $(QT5_CFLAGS) $< -o $@
awf_qt5_SOURCES = awf-qt5.cpp
awf_qt5_CPPFLAGS = $(QT5_CFLAGS)
awf_qt5_LDADD = $(QT5_LIBS)
if WINDOWS
awf_qt5_LDADD += awf-qt5-res.o -lintl
awf-qt5-res.o: awf.rc
	$(WINDRES) -c 65001 -DENGINE=QT5 $< -o $@
endif
endif

if QT4
AM_CXXFLAGS = -fPIC -std=gnu++11
bin_PROGRAMS += awf-qt4
BUILT_SOURCES += awf-qt4.moc
awf-qt4.moc: awf-qt4.cpp
	$(QT4_MOC) $(QT4_CFLAGS) $< -o $@
awf_qt4_SOURCES = awf-qt4.cpp
awf_qt4_CPPFLAGS = $(QT4_CFLAGS)
awf_qt4_LDADD = $(QT4_LIBS)
if WINDOWS
awf_qt4_LDADD += awf-qt4-res.o -lintl
awf-qt4-res.o: awf.rc
	$(WINDRES) -c 65001 -DENGINE=QT4 $< -o $@
endif
endif

# install (desktop files)
if !WINDOWS
desktop_DATA =
desktopdir = $(datadir)/applications
if GTK5
desktop_DATA += $(srcdir)/../data/awf-gtk5.desktop
endif
if GTK4
desktop_DATA += $(srcdir)/../data/awf-gtk4.desktop
endif
if GTK3
desktop_DATA += $(srcdir)/../data/awf-gtk3.desktop
endif
if GTK2
desktop_DATA += $(srcdir)/../data/awf-gtk2.desktop
endif
if QT7
desktop_DATA += $(srcdir)/../data/awf-qt7.desktop
endif
if QT6
desktop_DATA += $(srcdir)/../data/awf-qt6.desktop
endif
if QT5
desktop_DATA += $(srcdir)/../data/awf-qt5.desktop
endif
if QT4
desktop_DATA += $(srcdir)/../data/awf-qt4.desktop
endif
endif

# install (man pages)
man_MANS =
if GTK5
man_MANS += $(srcdir)/../data/awf-gtk5.1
endif
if GTK4
man_MANS += $(srcdir)/../data/awf-gtk4.1
endif
if GTK3
man_MANS += $(srcdir)/../data/awf-gtk3.1
endif
if GTK2
man_MANS += $(srcdir)/../data/awf-gtk2.1
endif
if QT7
man_MANS += $(srcdir)/../data/awf-qt7.1
endif
if QT6
man_MANS += $(srcdir)/../data/awf-qt6.1
endif
if QT5
man_MANS += $(srcdir)/../data/awf-qt5.1
endif
if QT4
man_MANS += $(srcdir)/../data/awf-qt4.1
endif

# install (translated man pages/icons/locales/bash-completion)
# test -z "$(EXEEXT)" = check if EXEEXT is empty
install-data-hook:
	for app in $(bin_PROGRAMS); do \
		app=$${app%$(EXEEXT)}; \
		install -Dpm 644 $(srcdir)/../data/$$app.fr.1 $(DESTDIR)$(mandir)/fr/man1/$$app.1; \
		if test -z "$(EXEEXT)"; then \
			install -Dpm 644 $(srcdir)/../data/icons/scalable/apps/awf.svg $(DESTDIR)$(datadir)/icons/hicolor/scalable/apps/$$app.svg; \
			for size in 16x16 22x22 24x24 32x32 48x48 64x64 128x128; do \
				install -Dpm 644 $(srcdir)/../data/icons/$$size/apps/awf.png $(DESTDIR)$(datadir)/icons/hicolor/$$size/apps/$$app.png; \
			done; \
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
	for app in awf-gtk5 awf-gtk4 awf-gtk3 awf-gtk2 awf-qt7 awf-qt6 awf-qt5 awf-qt4; do \
		rm -f $(DESTDIR)$(mandir)/fr/man1/$$app.1; \
		if test -z "$(EXEEXT)"; then \
			rm -f $(DESTDIR)$(datadir)/icons/hicolor/scalable/apps/$$app.svg; \
			for size in 16x16 22x22 24x24 32x32 48x48 64x64 128x128; do \
				rm -f $(DESTDIR)$(datadir)/icons/hicolor/$$size/apps/$$app.png; \
			done; \
		fi; \
		for file in $(srcdir)/po/*.po; do \
			code=`basename $$file .po`; \
			rm -f $(DESTDIR)$(datadir)/locale/$$code/LC_MESSAGES/$$app.mo; \
		done; \
		rm -f $(DESTDIR)$(datadir)/bash-completion/completions/$$app; \
	done
