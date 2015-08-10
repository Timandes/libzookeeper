/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_libzookeeper.h"
#include "zookeeper_client.h"
#include "zookeeper_client_exceptions.h"
#include "version.h"

/* If you declare any globals in php_libzookeeper.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(libzookeeper)
*/

/* True global resources - no need for thread safety here */
static int le_libzookeeper;

/* {{{ libzookeeper_functions[]
 *
 * Every user visible function must have an entry in libzookeeper_functions[].
 */
const zend_function_entry libzookeeper_functions[] = {
    PHP_FE(confirm_libzookeeper_compiled,   NULL)       /* For testing, remove later. */
    PHP_FE_END  /* Must be the last line in libzookeeper_functions[] */
};
/* }}} */

/* {{{ libzookeeper_module_entry
 */
zend_module_entry libzookeeper_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "libzookeeper",
    libzookeeper_functions,
    PHP_MINIT(libzookeeper),
    PHP_MSHUTDOWN(libzookeeper),
    PHP_RINIT(libzookeeper),        /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(libzookeeper),    /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(libzookeeper),
#if ZEND_MODULE_API_NO >= 20010901
    LIBZOOKEEPER_VERSION, /* Replace with version number for your extension */
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LIBZOOKEEPER
ZEND_GET_MODULE(libzookeeper)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("libzookeeper.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_libzookeeper_globals, libzookeeper_globals)
    STD_PHP_INI_ENTRY("libzookeeper.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_libzookeeper_globals, libzookeeper_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_libzookeeper_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_libzookeeper_init_globals(zend_libzookeeper_globals *libzookeeper_globals)
{
    libzookeeper_globals->global_value = 0;
    libzookeeper_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(libzookeeper)
{
    /* If you have INI entries, uncomment these lines
    REGISTER_INI_ENTRIES();
    */

    // zookeeper_client.h
    register_zookeeper_client_class(TSRMLS_C);
    register_zookeeper_client_class_constants(INIT_FUNC_ARGS_PASSTHRU);

    // zookeeper_client_exceptions.h
    register_zookeeper_client_exception_classes(TSRMLS_C);

    /* Debug Level */
    zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(libzookeeper)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(libzookeeper)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(libzookeeper)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(libzookeeper)
{
    char version[10];

    php_info_print_table_start();
    php_info_print_table_header(2, "libzookeeper support", "enabled");

    php_info_print_table_row(2, "Version", LIBZOOKEEPER_VERSION);

    snprintf(version, sizeof(version), "%d.%d.%d", ZOO_MAJOR_VERSION, ZOO_MINOR_VERSION, ZOO_PATCH_VERSION);
	php_info_print_table_row(2, "Zookeeper C Client Version", version);

    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_libzookeeper_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_libzookeeper_compiled)
{
    char *arg = NULL;
    int arg_len, len;
    char *strg;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
        return;
    }

    len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "libzookeeper", arg);
    RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
