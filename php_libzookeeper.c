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

ZEND_DECLARE_MODULE_GLOBALS(libzookeeper)

/* True global resources - no need for thread safety here */
static int le_libzookeeper;

/* {{{ libzookeeper_functions[]
 *
 * Every user visible function must have an entry in libzookeeper_functions[].
 */
const zend_function_entry libzookeeper_functions[] = {
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
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("libzookeeper.log_level",      "0", PHP_INI_PERDIR, OnUpdateLong, log_level, zend_libzookeeper_globals, libzookeeper_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_libzookeeper_init_globals
 */
static void php_libzookeeper_init_globals(zend_libzookeeper_globals *libzookeeper_globals)
{
    libzookeeper_globals->log_level = 0;
}
/* }}} */
/* {{{ php_libzookeeper_destroy_globals
 */
static void php_libzookeeper_destroy_globals(zend_libzookeeper_globals *libzookeeper_globals)
{
}
/* }}} */


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(libzookeeper)
{
    // zookeeper_client.h
    register_zookeeper_client_class(TSRMLS_C);
    register_zookeeper_client_class_constants(INIT_FUNC_ARGS_PASSTHRU);

    // zookeeper_client_exceptions.h
    register_zookeeper_client_exception_classes(TSRMLS_C);
    register_zookeeper_client_exception_class_constants(INIT_FUNC_ARGS_PASSTHRU);

#ifdef ZTS
    ts_allocate_id(&libzookeeper_globals_id, sizeof(zend_libzookeeper_globals),
                   (ts_allocate_ctor) php_libzookeeper_init_globals, (ts_allocate_dtor) php_libzookeeper_destroy_globals);
#else
    php_libzookeeper_init_globals(&libzookeeper_globals TSRMLS_CC);
#endif

    REGISTER_INI_ENTRIES();

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(libzookeeper)
{
#ifdef ZTS
    ts_free_id(libzookeeper_globals_id);
#else
    php_libzookeeper_destroy_globals(&libzookeeper_globals TSRMLS_CC);
#endif

    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(libzookeeper)
{
    /* Debug Level */
    zoo_set_debug_level(LIBZOOKEEPER_G(log_level));

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

    DISPLAY_INI_ENTRIES();
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
