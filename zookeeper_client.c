/* $Id$ */

#include "zookeeper_client.h"

// ---- Core functions ----

void register_zookeeper_client_class(TSRMLS_D)
{
    zend_class_entry class_entry;

    INIT_CLASS_ENTRY(class_entry, "ZookeeperClient", NULL);
    zookeeper_client_class_entry = zend_register_internal_class_ex(&class_entry, NULL, NULL TSRMLS_CC);
    zookeeper_client_class_entry->create_object = zookeeper_client_create_object;
}

zend_object_value zookeeper_client_create_object(zend_class_entry *class_entry TSRMLS_DC)
{
    zend_object_value retval;
    zookeeper_client_storage_object *storage_object;

    storage_object = ecalloc(1, sizeof(*storage_object));
    zend_object_std_init( &storage_object->zo, class_entry TSRMLS_CC );
    object_properties_init( (zend_object *) storage_object, class_entry);

    retval.handle = zend_objects_store_put(storage_object, (zend_objects_store_dtor_t)zend_objects_destroy_object, (zend_objects_free_object_storage_t)zookeeper_client_free_object, NULL TSRMLS_CC);
    retval.handlers = zend_get_std_object_handlers();

    return retval;
}

void zookeeper_client_free_object(zookeeper_client_storage_object *storage_object TSRMLS_DC)
{
    if (storage_object->zk_handle) {
        zookeeper_close(storage_object->zk_handle);
    }

    zend_object_std_dtor(&storage_object->zo TSRMLS_CC);
    efree(storage_object);
}

// ---- PHP Methods ----

PHP_METHOD(ZookeeperClient, connect)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *hosts = NULL;
    int hosts_len = 0;
    zhandle_t *zk_handle = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|f!l", &hosts, &hosts_len) == FAILURE) {
        return;
    }

    zk_handle = zookeeper_init(hosts, NULL, 10, 0, NULL, 0);
    if (NULL == zk_handle) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Fail to initialize zookeeper client");
    }

    storage = zend_object_store_get_object(me TSRMLS_CC);
    me->zk_handle = zk_handle;
}

PHP_METHOD(ZookeeperClient, get)
{
    // TODO:
}


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
