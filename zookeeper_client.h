/* $Id$ */

#ifndef ZOOKEEPER_CLIENT_H
#define ZOOKEEPER_CLIENT_H

#include <php.h>
#include <zookeeper/zookeeper.h>

/* class ZookeeperClient { */
zend_class_entry *zookeeper_client_class_entry;

zend_function_entry zookeeper_client_method_entry[];

PHP_METHOD(ZookeeperClient, connect);
PHP_METHOD(ZookeeperClient, get);
PHP_METHOD(ZookeeperClient, getChildren);
PHP_METHOD(ZookeeperClient, create);
PHP_METHOD(ZookeeperClient, delete);
PHP_METHOD(ZookeeperClient, exists);

/* } ZookeeperClient */

/* Storage object of `ZookeeperClient` */
typedef struct _zookeeper_client_storage_object {
	zend_object	object;
    zhandle_t *zk_handle;
} zookeeper_client_storage_object;

/* Register `ZookeeperClient` */
void register_zookeeper_client_class(TSRMLS_D);

/* Register Constants of `ZookeeperClient` */
void register_zookeeper_client_class_constants(INIT_FUNC_ARGS);

/* Create `ZookeeperClient` object */
zend_object_value zookeeper_client_create_object(zend_class_entry *class_entry TSRMLS_DC);

/* Free `ZookeeperClient` object */
void zookeeper_client_free_object(zookeeper_client_storage_object *storage_object TSRMLS_DC);

#endif  /* ZOOKEEPER_CLIENT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
