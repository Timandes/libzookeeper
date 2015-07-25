dnl $Id$
dnl config.m4 for extension libzookeeper

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(libzookeeper, for libzookeeper support,
dnl Make sure that the comment is aligned:
dnl [  --with-libzookeeper             Include libzookeeper support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(libzookeeper, whether to enable libzookeeper support,
dnl Make sure that the comment is aligned:
dnl [  --enable-libzookeeper           Enable libzookeeper support])

if test "$PHP_LIBZOOKEEPER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-libzookeeper -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/libzookeeper.h"  # you most likely want to change this
  dnl if test -r $PHP_LIBZOOKEEPER/$SEARCH_FOR; then # path given as parameter
  dnl   LIBZOOKEEPER_DIR=$PHP_LIBZOOKEEPER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for libzookeeper files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       LIBZOOKEEPER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$LIBZOOKEEPER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the libzookeeper distribution])
  dnl fi

  dnl # --with-libzookeeper -> add include path
  dnl PHP_ADD_INCLUDE($LIBZOOKEEPER_DIR/include)

  dnl # --with-libzookeeper -> check for lib and symbol presence
  dnl LIBNAME=libzookeeper # you may want to change this
  dnl LIBSYMBOL=libzookeeper # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBZOOKEEPER_DIR/lib, LIBZOOKEEPER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_LIBZOOKEEPERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong libzookeeper lib version or lib not found])
  dnl ],[
  dnl   -L$LIBZOOKEEPER_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(LIBZOOKEEPER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(libzookeeper, libzookeeper.c, $ext_shared)
fi
