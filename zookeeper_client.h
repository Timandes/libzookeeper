/* $Id$ */

#ifndef ZOOKEEPER_CLIENT_H
#define ZOOKEEPER_CLIENT_H

#include <zookeeper/zookeeper.h>

/* class ZookeeperClient { */
zend_class_entry *zookeeper_client_class_entry;

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
