/* $Id$ */

#ifndef ZOOKEEPER_CLIENT_H
#define ZOOKEEPER_CLIENT_H

#include <php.h>
#include <zookeeper/zookeeper.h>

/* class ZookeeperClient { */
zend_class_entry *zookeeper_client_class_entry;
zend_object_handlers zookeeper_client_object_handlers;

PHP_METHOD(ZookeeperClient, connect);
PHP_METHOD(ZookeeperClient, get);
PHP_METHOD(ZookeeperClient, getChildren);
PHP_METHOD(ZookeeperClient, create);
PHP_METHOD(ZookeeperClient, delete);
PHP_METHOD(ZookeeperClient, exists);
PHP_METHOD(ZookeeperClient, set);

/* } ZookeeperClient */

/* Storage object of `ZookeeperClient` */
typedef struct _zookeeper_client_storage_object {
#if PHP_VERSION_ID < 70000
	zend_object	object;
#endif
    zhandle_t *zk_handle;
#if PHP_VERSION_ID >= 70000
	zend_object	object;
#endif
} zookeeper_client_storage_object;

/* Register `ZookeeperClient` */
void register_zookeeper_client_class(TSRMLS_D);

/* Register Constants of `ZookeeperClient` */
void register_zookeeper_client_class_constants(INIT_FUNC_ARGS);

/* Create `ZookeeperClient` object */
#if PHP_VERSION_ID >= 70000
zend_object *
#else
zend_object_value
#endif
		zookeeper_client_create_object(zend_class_entry *class_entry TSRMLS_DC);

/* Free `ZookeeperClient` object */
void zookeeper_client_free_object(
#if PHP_VERSION_ID >= 70000
		zend_object *object
#else
		zookeeper_client_storage_object *storage_object TSRMLS_DC
#endif
		);

/* PHP 7 only {{{ */
//#if PHP_VERSION_ID >= 70000

/* Fetching the custom object */
/*
static inline zookeeper_client_storage_object* zookeeper_client_storage_object_fetch_object(zend_object *obj)
{
    return (zookeeper_client_storage_object *)((char *)obj - XtOffsetOf(zookeeper_client_storage_object, object));
}

#define Z_LIBZOOKEEPER_OBJ_P(zv) zookeeper_client_storage_object_fetch_object(Z_OBJ_P(zv));

#endif*/
/* }}} */

/* Fetch `ZookeeperClient` object */
#if PHP_VERSION_ID >= 70000
#define FETCH_ZOOKEEPER_CLIENT_OBJECT(me) (zookeeper_client_storage_object *)((char *)me - XtOffsetOf(zookeeper_client_storage_object, object));
#define FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me) FETCH_ZOOKEEPER_CLIENT_OBJECT(Z_OBJ_P(me))
#else
#define FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me) zend_object_store_get_object(me TSRMLS_CC);
#endif

#endif  /* ZOOKEEPER_CLIENT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
