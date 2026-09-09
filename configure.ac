# supported options
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

AC_INIT([A widget factory], [4.3.0], [https://github.com/luigifab/awf-extended/issues], [awf-extended], [https://github.com/luigifab/awf-extended])
AC_CONFIG_SRCDIR([src/])
AM_INIT_AUTOMAKE([foreign])
AC_PROG_CC
AC_PROG_CXX
PKG_PROG_PKG_CONFIG

# --disable-gtkx --disable-qtx
AC_ARG_ENABLE([gtk5],
  AS_HELP_STRING([--disable-gtk5], [disable gtk5 (default: enabled if available)]),
  [enable_gtk5=no],
  [enable_gtk5=yes])
AC_ARG_ENABLE([gtk4],
  AS_HELP_STRING([--disable-gtk4], [disable gtk4 (default: enabled if available)]),
  [enable_gtk4=no],
  [enable_gtk4=yes])
AC_ARG_ENABLE([gtk3],
  AS_HELP_STRING([--disable-gtk3], [disable gtk3 (default: enabled if available)]),
  [enable_gtk3=no],
  [enable_gtk3=yes])
AC_ARG_ENABLE([gtk2],
  AS_HELP_STRING([--disable-gtk2], [disable gtk2 (default: enabled if available)]),
  [enable_gtk2=no],
  [enable_gtk2=yes])
AC_ARG_ENABLE([qt7],
  AS_HELP_STRING([--disable-qt7], [disable qt7 (default: enabled if available)]),
  [enable_qt7=no],
  [enable_qt7=yes])
AC_ARG_ENABLE([qt6],
  AS_HELP_STRING([--disable-qt6], [disable qt6 (default: enabled if available)]),
  [enable_qt6=no],
  [enable_qt6=yes])
AC_ARG_ENABLE([qt5],
  AS_HELP_STRING([--disable-qt5], [disable qt5 (default: enabled if available)]),
  [enable_qt5=no],
  [enable_qt5=yes])
AC_ARG_ENABLE([qt4],
  AS_HELP_STRING([--disable-qt4], [disable qt4 (default: enabled if available)]),
  [enable_qt4=no],
  [enable_qt4=yes])

# --enable-only-gtkx --enable-only-qtx
AC_ARG_ENABLE([only-gtk5],
  AS_HELP_STRING([--enable-only-gtk5], [only enable gtk5]),
  [only_gtk=yes
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=yes
   enable_qt4=no
   enable_qt5=no
   enable_qt6=no
   enable_qt7=no],
  [])
AC_ARG_ENABLE([only-gtk4],
  AS_HELP_STRING([--enable-only-gtk4], [only enable gtk4]),
  [only_gtk=yes
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=yes
   enable_gtk5=no
   enable_qt4=no
   enable_qt5=no
   enable_qt6=no
   enable_qt7=no],
  [])
AC_ARG_ENABLE([only-gtk3],
  AS_HELP_STRING([--enable-only-gtk3], [only enable gtk3]),
  [only_gtk=yes
   enable_gtk2=no
   enable_gtk3=yes
   enable_gtk4=no
   enable_gtk5=no
   enable_qt4=no
   enable_qt5=no
   enable_qt6=no
   enable_qt7=no],
  [])
AC_ARG_ENABLE([only-gtk2],
  AS_HELP_STRING([--enable-only-gtk2], [only enable gtk2]),
  [only_gtk=yes
   enable_gtk2=yes
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no
   enable_qt4=no
   enable_qt5=no
   enable_qt6=no
   enable_qt7=no],
  [])
AC_ARG_ENABLE([only-qt7],
  AS_HELP_STRING([--enable-only-qt7], [only enable qt7]),
  [only_qt=yes
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no
   enable_qt4=no
   enable_qt5=no
   enable_qt6=no
   enable_qt7=yes],
  [])
AC_ARG_ENABLE([only-qt6],
  AS_HELP_STRING([--enable-only-qt6], [only enable qt6]),
  [only_qt=yes
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no
   enable_qt4=no
   enable_qt5=no
   enable_qt6=yes
   enable_qt7=no],
  [])
AC_ARG_ENABLE([only-qt5],
  AS_HELP_STRING([--enable-only-qt5], [only enable qt5]),
  [only_qt=yes
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no
   enable_qt4=no
   enable_qt5=yes
   enable_qt6=no
   enable_qt7=no],
  [])
AC_ARG_ENABLE([only-qt4],
  AS_HELP_STRING([--enable-only-qt4], [only enable qt4]),
  [only_qt=yes
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no
   enable_qt4=yes
   enable_qt5=no
   enable_qt6=no
   enable_qt7=no],
  [])

# --disable-gtk --disable-qt (shortcuts)
AC_ARG_ENABLE([gtk],
  AS_HELP_STRING([--disable-gtk], [disable all gtk versions]),
  [only_gtk=no
   enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no],
  [])
AC_ARG_ENABLE([qt],
  AS_HELP_STRING([--disable-qt], [disable all qt versions]),
  [only_qt=no
   enable_qt4=no
   enable_qt5=no
   enable_qt6=no
   enable_qt7=no],
  [])

# gettext
AC_PATH_PROG([MSGFMT], [msgfmt])
if test -z "$MSGFMT"; then
  AC_MSG_ERROR([gettext/msgfmt not found (FATAL)])
fi

# check if it's windows
case "`uname -s`" in
  *MINGW* | *CYGWIN* | *MSYS*)
    windows=yes ;;
  *)
    windows=no ;;
esac
AM_CONDITIONAL([WINDOWS], [test "x$windows" = "xyes"])

AC_CHECK_TOOL([WINDRES], [windres])
if test "x$windows" = "xyes" && test -z "$WINDRES"; then
  AC_MSG_ERROR([windres not found (FATAL)])
fi

# C & libnotify / C++
# to avoid the following stupid error without gtk, pkgconf is required (in Build-Depends)
# ./configure: line 5306: syntax error near unexpected token `LIBNOTIFY,'
# ./configure: line 5306: `PKG_CHECK_MODULES...
# for windows, libnotify is not required
PKG_CHECK_MODULES(LIBNOTIFY, libnotify >= 0.7.0, have_libnotify=yes, have_libnotify=no)
if test "x$windows" = "xyes"; then
  have_libnotify=ignore
fi

if test "x$enable_gtk5" = "xyes" || test "x$enable_gtk4" = "xyes" || test "x$enable_gtk3" = "xyes" || test "x$enable_gtk2" = "xyes"; then
  compiler=$(command -v ${CC%% *})
  if test "x$only_gtk" = "xyes" && test "x$compiler" = "x"; then
    AC_MSG_ERROR([C compiler not found (FATAL)])
  elif test "x$compiler" = "x"; then
    enable_gtk2=no
    enable_gtk3=no
    enable_gtk4=no
    enable_gtk5=no
  elif test "x$have_libnotify" = "xno"; then
    if test "x$only_gtk" = "xyes"; then
      AC_MSG_ERROR([libnotify not found (FATAL)])
    fi
    enable_gtk2=no
    enable_gtk3=no
    enable_gtk4=no
    enable_gtk5=no
  fi
fi

if test "x$enable_qt7" = "xyes" || test "x$enable_qt6" = "xyes" || test "x$enable_qt5" = "xyes"; then
  compiler=$(command -v ${CXX%% *})
  if test "x$only_qt" = "xyes" && test "x$compiler" = "x"; then
    AC_MSG_ERROR([C++ compiler not found (FATAL)])
  elif test "x$compiler" = "x"; then
    enable_qt5=no
    enable_qt6=no
    enable_qt7=no
  fi
fi

# GTK 5
PKG_CHECK_MODULES(GTK5, gtk5, GTK5_SUFFIX=5, GTK5_SUFFIX=-5)
if test "x$enable_gtk5" = "xyes"; then
  if test "x$only_gtk" = "xyes" && test "x$GTK5_SUFFIX" != "x5"; then
    AC_MSG_ERROR([GTK5 not found (FATAL)])
  fi
  AM_CONDITIONAL([GTK5], [test "x$GTK5_SUFFIX" = "x5"])
else
  AM_CONDITIONAL([GTK5], [false])
fi

# GTK 4
PKG_CHECK_MODULES(GTK4, gtk4, GTK4_SUFFIX=4, GTK4_SUFFIX=-4)
if test "x$enable_gtk4" = "xyes"; then
  if test "x$only_gtk" = "xyes" && test "x$GTK4_SUFFIX" != "x4"; then
    AC_MSG_ERROR([GTK4 not found (FATAL)])
  fi
  AM_CONDITIONAL([GTK4], [test "x$GTK4_SUFFIX" = "x4"])
else
  AM_CONDITIONAL([GTK4], [false])
fi

# GTK 3
PKG_CHECK_MODULES(GTK3, gtk+-3.0, GTK3_SUFFIX=3, GTK3_SUFFIX=-3)
if test "x$enable_gtk3" = "xyes"; then
  if test "x$only_gtk" = "xyes" && test "x$GTK3_SUFFIX" != "x3"; then
    AC_MSG_ERROR([GTK3 not found (FATAL)])
  fi
  AM_CONDITIONAL([GTK3], [test "x$GTK3_SUFFIX" = "x3"])
else
  AM_CONDITIONAL([GTK3], [false])
fi

# GTK 2
PKG_CHECK_MODULES(GTK2, gtk+-2.0 >= 2.24.0, GTK2_SUFFIX=2, GTK2_SUFFIX=-2)
if test "x$enable_gtk2" = "xyes"; then
  if test "x$only_gtk" = "xyes" && test "x$GTK2_SUFFIX" != "x2"; then
    AC_MSG_ERROR([GTK2 not found (FATAL)])
  fi
  AM_CONDITIONAL([GTK2], [test "x$GTK2_SUFFIX" = "x2"])
else
  AM_CONDITIONAL([GTK2], [false])
fi

# QT 7
PKG_CHECK_MODULES(QT7, [Qt7Core Qt7Gui Qt7Widgets Qt7PrintSupport], QT7_SUFFIX=7, QT7_SUFFIX=-7)
if test "x$enable_qt7" = "xyes"; then
  if test "x$only_qt" = "xyes" && test "x$QT7_SUFFIX" != "x7"; then
    AC_MSG_ERROR([QT7 not found (FATAL)])
  fi
  AM_CONDITIONAL([QT7], [test "x$QT7_SUFFIX" = "x7"])
  if test "x$QT7_SUFFIX" = "x7"; then
    QT7_BINDIR=`$PKG_CONFIG --variable=libexecdir Qt7Core`
    QT7_MOC="$QT7_BINDIR/moc"
  fi
else
  AM_CONDITIONAL([QT7], [false])
fi
AC_SUBST(QT7_MOC)

# QT 6
# Ubuntu 22.04 Jammy & pkgconf 6.2.4, pc files are missing (https://bugs.launchpad.net/ubuntu/+source/qt6-base/+bug/2067202), so it's not working
# and pkg-config may return an incorrect path, fallback to qtpaths6
PKG_CHECK_MODULES(QT6, [Qt6Core Qt6Gui Qt6Widgets Qt6PrintSupport], QT6_SUFFIX=6, QT6_SUFFIX=-6)
if test "x$enable_qt6" = "xyes"; then
  if test "x$only_qt" = "xyes" && test "x$QT6_SUFFIX" != "x6"; then
    AC_MSG_ERROR([QT6 not found (FATAL)])
  fi
  AM_CONDITIONAL([QT6], [test "x$QT6_SUFFIX" = "x6"])
  if test "x$QT6_SUFFIX" = "x6"; then
    QT6_BINDIR=`$PKG_CONFIG --variable=libexecdir Qt6Core`
    if test -z "$QT6_BINDIR"; then
      QT6_BINDIR=`LC_ALL=C.UTF-8 qtpaths6 --query QT_INSTALL_LIBEXECS`
    fi
    QT6_MOC="$QT6_BINDIR/moc"
  fi
else
  AM_CONDITIONAL([QT6], [false])
fi
AC_SUBST(QT6_MOC)

# QT 5
qt5_modules="Qt5Core Qt5Gui Qt5Widgets Qt5PrintSupport"
if test "x$windows" = "xyes"; then
    qt5_modules="Qt5Core Qt5Gui Qt5Widgets Qt5PrintSupport Qt5WinExtras"
fi
PKG_CHECK_MODULES(QT5, [$qt5_modules], QT5_SUFFIX=5, QT5_SUFFIX=-5)
if test "x$enable_qt5" = "xyes"; then
  if test "x$only_qt" = "xyes" && test "x$QT5_SUFFIX" != "x5"; then
    AC_MSG_ERROR([QT5 not found (FATAL)])
  fi
  AM_CONDITIONAL([QT5], [test "x$QT5_SUFFIX" = "x5"])
  if test "x$QT5_SUFFIX" = "x5"; then
    QT5_BINDIR=`$PKG_CONFIG --variable=host_bins Qt5Core 2>/dev/null`
    if test -z "$QT5_BINDIR"; then
      QT5_BINDIR=`$PKG_CONFIG --variable=bindir Qt5Core`
    fi
    QT5_MOC="$QT5_BINDIR/moc"
  fi
else
  AM_CONDITIONAL([QT5], [false])
fi
AC_SUBST(QT5_MOC)

# QT 4
PKG_CHECK_MODULES(QT4, [QtCore QtGui >= 4.8.0], QT4_SUFFIX=4, QT4_SUFFIX=-4)
if test "x$enable_qt4" = "xyes"; then
  if test "x$only_qt" = "xyes" && test "x$QT4_SUFFIX" != "x4"; then
    AC_MSG_ERROR([QT4 not found (FATAL)])
  fi
  AM_CONDITIONAL([QT4], [test "x$QT4_SUFFIX" = "x4"])
  if test "x$QT4_SUFFIX" = "x4"; then
    QT4_BINDIR=`$PKG_CONFIG --variable=exec_prefix QtCore 2>/dev/null`
    QT4_MOC="$QT4_BINDIR/bin/moc"
  fi
else
  AM_CONDITIONAL([QT4], [false])
fi
AC_SUBST(QT4_MOC)

# files
AC_CONFIG_FILES([
  Makefile
  src/Makefile
])

AC_OUTPUT