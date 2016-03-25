/* $Id$ */

#ifndef PHP_LIBZOOKEEPER_H
#define PHP_LIBZOOKEEPER_H

extern zend_module_entry libzookeeper_module_entry;
#define phpext_libzookeeper_ptr &libzookeeper_module_entry

#ifdef PHP_WIN32
#   define PHP_LIBZOOKEEPER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_LIBZOOKEEPER_API __attribute__ ((visibility("default")))
#else
#   define PHP_LIBZOOKEEPER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(libzookeeper);
PHP_MSHUTDOWN_FUNCTION(libzookeeper);
PHP_RINIT_FUNCTION(libzookeeper);
PHP_RSHUTDOWN_FUNCTION(libzookeeper);
PHP_MINFO_FUNCTION(libzookeeper);

ZEND_BEGIN_MODULE_GLOBALS(libzookeeper)
    long  log_level;
ZEND_END_MODULE_GLOBALS(libzookeeper)

/* In every utility function you add that needs to use variables 
   in php_libzookeeper_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as LIBZOOKEEPER_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define LIBZOOKEEPER_G(v) TSRMG(libzookeeper_globals_id, zend_libzookeeper_globals *, v)
#else
#define LIBZOOKEEPER_G(v) (libzookeeper_globals.v)
#endif


#endif  /* PHP_LIBZOOKEEPER_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
