AC_INIT([guiComparison], [0.0.1],       [William Emerison Six <billsix@gmail.com>], [guiComparison])
AC_CANONICAL_SYSTEM
AC_CONFIG_SRCDIR([src/wxapp.cpp])
AC_CONFIG_HEADER([config.h])
AC_CHECK_HEADER([stdio.h])
AC_REVISION([: 0.0.1 $])
AM_INIT_AUTOMAKE()
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_CONFIG_FILES([Makefile src/Makefile presentation/Makefile])


CXXFLAGS+=" $(wx-config --cflags) --std=c++14 "
LDFLAGS+=" $(wx-config --libs) "




AC_OUTPUT
