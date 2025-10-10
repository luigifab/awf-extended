AC_INIT([A widget factory], [3.2.0])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([foreign])

AC_PROG_CC
AM_PROG_CC_C_O

PKG_CHECK_MODULES([LIBNOTIFY], [libnotify >= 0.7.0])
AC_SUBST(LIBNOTIFY_CFLAGS)
AC_SUBST(LIBNOTIFY_LIBS)

# --disable-gtkx
AC_ARG_ENABLE([gtk5],
  AS_HELP_STRING([--disable-gtk5], [disable gtk5]),
  [enable_gtk5=no],
  [enable_gtk5=yes])
AC_ARG_ENABLE([gtk4],
  AS_HELP_STRING([--disable-gtk4], [disable gtk4]),
  [enable_gtk4=no],
  [enable_gtk4=yes])
AC_ARG_ENABLE([gtk3],
  AS_HELP_STRING([--disable-gtk3], [disable gtk3]),
  [enable_gtk3=no],
  [enable_gtk3=yes])
AC_ARG_ENABLE([gtk2],
  AS_HELP_STRING([--disable-gtk2], [disable gtk2]),
  [enable_gtk2=no],
  [enable_gtk2=yes])

# --enable-only-gtkx
AC_ARG_ENABLE([only-gtk5],
  AS_HELP_STRING([--enable-only-gtk5], [only enable gtk5]),
  [enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=yes],
  [])
AC_ARG_ENABLE([only-gtk4],
  AS_HELP_STRING([--enable-only-gtk4], [only enable gtk4]),
  [enable_gtk2=no
   enable_gtk3=no
   enable_gtk4=yes
   enable_gtk5=no],
  [])
AC_ARG_ENABLE([only-gtk3],
  AS_HELP_STRING([--enable-only-gtk3], [only enable gtk3]),
  [enable_gtk2=no
   enable_gtk3=yes
   enable_gtk4=no
   enable_gtk5=no],
  [])
AC_ARG_ENABLE([only-gtk2],
  AS_HELP_STRING([--enable-only-gtk2], [only enable gtk2]),
  [enable_gtk2=yes
   enable_gtk3=no
   enable_gtk4=no
   enable_gtk5=no],
  [])

# GTK 5
PKG_CHECK_MODULES(GTK5, gtk5, GTK5_SUFFIX=5, GTK5_SUFFIX=0)
if test "x$enable_gtk5" = "xyes"; then
  AM_CONDITIONAL([GTK5], [test "$GTK5_SUFFIX" -eq 5])
else
  AM_CONDITIONAL([GTK5], [test "$GTK5_SUFFIX" -eq -1])
fi
AC_SUBST(GTK5_CFLAGS)
AC_SUBST(GTK5_LIBS)
AC_SUBST(GTK5_SUFFIX)

# GTK 4
PKG_CHECK_MODULES(GTK4, gtk4, GTK4_SUFFIX=4, GTK4_SUFFIX=0)
if test "x$enable_gtk4" = "xyes"; then
  AM_CONDITIONAL([GTK4], [test "$GTK4_SUFFIX" -eq 4])
else
  AM_CONDITIONAL([GTK4], [test "$GTK4_SUFFIX" -eq -1])
fi
AC_SUBST(GTK4_CFLAGS)
AC_SUBST(GTK4_LIBS)
AC_SUBST(GTK4_SUFFIX)

# GTK 3
PKG_CHECK_MODULES(GTK3, gtk+-3.0, GTK3_SUFFIX=3, GTK3_SUFFIX=0)
if test "x$enable_gtk3" = "xyes"; then
  AM_CONDITIONAL([GTK3], [test "$GTK3_SUFFIX" -eq 3])
else
  AM_CONDITIONAL([GTK3], [test "$GTK3_SUFFIX" -eq -1])
fi
AC_SUBST(GTK3_CFLAGS)
AC_SUBST(GTK3_LIBS)
AC_SUBST(GTK3_SUFFIX)

# GTK 2
PKG_CHECK_MODULES(GTK2, gtk+-2.0 >= 2.24.0, GTK2_SUFFIX=2, GTK2_SUFFIX=0)
if test "x$enable_gtk2" = "xyes"; then
  AM_CONDITIONAL([GTK2], [test "$GTK2_SUFFIX" -eq 2])
else
  AM_CONDITIONAL([GTK2], [test "$GTK2_SUFFIX" -eq -1])
fi
AC_SUBST(GTK2_CFLAGS)
AC_SUBST(GTK2_LIBS)
AC_SUBST(GTK2_SUFFIX)


AC_CONFIG_FILES([
	Makefile
	src/Makefile
])

AC_OUTPUT