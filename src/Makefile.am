bin_PROGRAMS =
BUILT_SOURCES =

if GTK5
bin_PROGRAMS += awf-gtk@GTK5_SUFFIX@
awf_gtk@GTK5_SUFFIX@_SOURCES = awf-gtk5.c
awf_gtk@GTK5_SUFFIX@_CPPFLAGS = $(GTK5_CFLAGS) $(LIBNOTIFY_CFLAGS) -I/usr/include/gtk-5.0/unix-print
awf_gtk@GTK5_SUFFIX@_LDADD = $(GTK5_LIBS) $(LIBNOTIFY_LIBS)
endif

if GTK4
bin_PROGRAMS += awf-gtk@GTK4_SUFFIX@
awf_gtk@GTK4_SUFFIX@_SOURCES = awf-gtk4.c
awf_gtk@GTK4_SUFFIX@_CPPFLAGS = $(GTK4_CFLAGS) $(LIBNOTIFY_CFLAGS) -I/usr/include/gtk-4.0/unix-print
awf_gtk@GTK4_SUFFIX@_LDADD = $(GTK4_LIBS) $(LIBNOTIFY_LIBS)
endif

if GTK3
bin_PROGRAMS += awf-gtk@GTK3_SUFFIX@
awf_gtk@GTK3_SUFFIX@_SOURCES = awf-gtk3.c
awf_gtk@GTK3_SUFFIX@_CPPFLAGS = $(GTK3_CFLAGS) $(LIBNOTIFY_CFLAGS) -I/usr/include/gtk-3.0/unix-print
awf_gtk@GTK3_SUFFIX@_LDADD = $(GTK3_LIBS) $(LIBNOTIFY_LIBS)
endif

if GTK2
bin_PROGRAMS += awf-gtk@GTK2_SUFFIX@
awf_gtk@GTK2_SUFFIX@_SOURCES = awf-gtk2.c
awf_gtk@GTK2_SUFFIX@_CPPFLAGS = $(GTK2_CFLAGS) $(LIBNOTIFY_CFLAGS) -I/usr/include/gtk-unix-print-2.0
awf_gtk@GTK2_SUFFIX@_LDADD = $(GTK2_LIBS) $(LIBNOTIFY_LIBS)
endif

if QT7
AM_CXXFLAGS = -fPIC -std=c++17
bin_PROGRAMS += awf-qt@QT7_SUFFIX@
BUILT_SOURCES += awf-qt7.moc
awf-qt7.moc: awf-qt7.cpp
	$(QT7_MOC) $(QT7_CFLAGS) $< -o $@
awf_qt@QT7_SUFFIX@_SOURCES = awf-qt7.cpp
awf_qt@QT7_SUFFIX@_CPPFLAGS = $(QT7_CFLAGS)
awf_qt@QT7_SUFFIX@_LDADD = $(QT7_LIBS)
endif

if QT6
AM_CXXFLAGS = -fPIC -std=c++17
bin_PROGRAMS += awf-qt@QT6_SUFFIX@
BUILT_SOURCES += awf-qt6.moc
awf-qt6.moc: awf-qt6.cpp
	$(QT6_MOC) $(QT6_CFLAGS) $< -o $@
awf_qt@QT6_SUFFIX@_SOURCES = awf-qt6.cpp
awf_qt@QT6_SUFFIX@_CPPFLAGS = $(QT6_CFLAGS)
awf_qt@QT6_SUFFIX@_LDADD = $(QT6_LIBS)
endif

if QT5
AM_CXXFLAGS = -fPIC
bin_PROGRAMS += awf-qt@QT5_SUFFIX@
BUILT_SOURCES += awf-qt5.moc
awf-qt5.moc: awf-qt5.cpp
	$(QT5_MOC) $(QT5_CFLAGS) $< -o $@
awf_qt@QT5_SUFFIX@_SOURCES = awf-qt5.cpp
awf_qt@QT5_SUFFIX@_CPPFLAGS = $(QT5_CFLAGS)
awf_qt@QT5_SUFFIX@_LDADD = $(QT5_LIBS)
endif