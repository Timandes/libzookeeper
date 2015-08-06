dnl $Id$
dnl config.m4 for extension libzookeeper

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(libzookeeper, for libzookeeper support,
[  --with-libzookeeper[=DIR]       Include libzookeeper support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(libzookeeper, whether to enable libzookeeper support,
dnl [  --enable-libzookeeper           Enable libzookeeper support])

if test "$PHP_LIBZOOKEEPER" != "no"; then
  dnl Write more examples of tests here...

  # --with-libzookeeper -> check with-path
  SEARCH_PATH="/usr/local /usr /usr/local/libzookeeper"     # you might want to change this
  SEARCH_FOR="/include/zookeeper/zookeeper.h"  # you most likely want to change this
  if test -r $PHP_LIBZOOKEEPER/$SEARCH_FOR; then # path given as parameter
     LIBZOOKEEPER_DIR=$PHP_LIBZOOKEEPER
  else # search default path list
    AC_MSG_CHECKING([for libzookeeper files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        LIBZOOKEEPER_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
  
  if test -z "$LIBZOOKEEPER_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the libzookeeper distribution])
  fi

  # --with-libzookeeper -> add include path
  PHP_ADD_INCLUDE($LIBZOOKEEPER_DIR/include)

  # --with-libzookeeper -> check for lib and symbol presence
  LIBNAME=zookeeper_mt # you may want to change this
  LIBSYMBOL=zookeeper_init # you most likely want to change this 

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBZOOKEEPER_DIR/lib, LIBZOOKEEPER_SHARED_LIBADD)
    AC_DEFINE(HAVE_LIBZOOKEEPERLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong libzookeeper lib version or lib not found])
  ],[
    -L$LIBZOOKEEPER_DIR/lib -lm
  ])
  
  PHP_SUBST(LIBZOOKEEPER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(libzookeeper, php_libzookeeper.c zookeeper_client.c zookeeper_client_exceptions.c, $ext_shared)
fi
