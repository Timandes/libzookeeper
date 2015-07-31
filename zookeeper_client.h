/* $Id$ */

#ifndef ZOOKEEPER_CLIENT_H
#define ZOOKEEPER_CLIENT_H

#include <zookeeper.h>

/* class ZookeeperClient { */
zend_class_entry *zookeeper_client_class_entry;

ZEND_BEGIN_ARG_INFO_EX(connect_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, hosts)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(get_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

zend_function_entry zookeeper_client_method_entry[] = {
    PHP_ME(ZookeeperClient, connect, connect_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, get, get_arg_info, ZEND_ACC_PUBLIC)

    { NULL, NULL, NULL }
};

PHP_METHOD(ZookeeperClient, connect);
PHP_METHOD(ZookeeperClient, get);

/* } ZookeeperClient */

/* Storage object of `ZookeeperClient` */
typedef struct _zookeeper_client_storage_object {
    zhandle_t *zk_handle;
} zookeeper_client_storage_object;

/* Register `ZookeeperClient` */
void register_zookeeper_client_class(TSRMLS_D);

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