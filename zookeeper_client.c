/* $Id$ */

#include "zookeeper_client.h"
#include "zookeeper_client_exceptions.h"
#include "error_codes.h"

// ---- Core functions ----

void register_zookeeper_client_class(TSRMLS_D)
{
    zend_class_entry class_entry;

    INIT_CLASS_ENTRY(class_entry, "ZookeeperClient", zookeeper_client_method_entry);
    zookeeper_client_class_entry = zend_register_internal_class_ex(&class_entry, NULL
#if PHP_VERSION_ID < 70000
			, NULL 
#endif
			TSRMLS_CC);
    zookeeper_client_class_entry->create_object = zookeeper_client_create_object;
	memcpy(&zookeeper_client_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
#if PHP_VERSION_ID >= 70000
	zookeeper_client_object_handlers.free_obj = (zend_object_free_obj_t)zookeeper_client_free_object;
#endif
}

void register_zookeeper_client_class_constants(INIT_FUNC_ARGS)
{
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_OK") - 1, ZOK TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_APIERROR") - 1, ZAPIERROR TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NONODE") - 1, ZNONODE TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NOAUTH") - 1, ZNOAUTH TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_BADVERSION") - 1, ZBADVERSION TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NOCHILDRENFOREPHEMERALS") - 1, ZNOCHILDRENFOREPHEMERALS TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NODEEXISTS") - 1, ZNODEEXISTS TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NOTEMPTY") - 1, ZNOTEMPTY TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_SESSIONEXPIRED") - 1, ZSESSIONEXPIRED TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_INVALIDCALLBACK") - 1, ZINVALIDCALLBACK TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_INVALIDACL") - 1, ZINVALIDACL TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_AUTHFAILED") - 1, ZAUTHFAILED TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_CLOSING") - 1, ZCLOSING TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NOTHING") - 1, ZNOTHING TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_SESSIONMOVED") - 1, ZSESSIONMOVED TSRMLS_CC);
#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NOTREADONLY") - 1, ZNOTREADONLY TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_EPHEMERALONLOCALSESSION") - 1, ZEPHEMERALONLOCALSESSION TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NOWATCHER") - 1, ZNOWATCHER TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_RWSERVERFOUND") - 1, ZRWSERVERFOUND TSRMLS_CC);
#endif
}

#if PHP_VERSION_ID >= 70000
zend_object *
#else
zend_object_value
#endif
		zookeeper_client_create_object(zend_class_entry *class_entry TSRMLS_DC)
{
#if PHP_VERSION_ID < 70000
    zend_object_value retval;
#endif
    zookeeper_client_storage_object *storage_object;

    storage_object = ecalloc(1, sizeof(*storage_object)
#if PHP_VERSION_ID >= 70000
				+ zend_object_properties_size(class_entry)
#endif
			);
    zend_object_std_init( &storage_object->object, class_entry TSRMLS_CC );
#if PHP_VERSION_ID < 50399
	zend_hash_copy(storage_object->object.properties, &class_entry->default_properties, (copy_ctor_func_t) zval_add_ref, NULL, sizeof(zval *));
#else
    object_properties_init( &storage_object->object, class_entry);
#endif

#if PHP_VERSION_ID < 70000
    retval.handle = zend_objects_store_put(storage_object, (zend_objects_store_dtor_t)zend_objects_destroy_object, (zend_objects_free_object_storage_t)zookeeper_client_free_object, NULL TSRMLS_CC);
    retval.handlers = &zookeeper_client_object_handlers;
#else
	storage_object->object.handlers = &zookeeper_client_object_handlers;
#endif


#if PHP_VERSION_ID >= 70000
	zookeeper_client_object_handlers.offset = XtOffsetOf(zookeeper_client_storage_object, object);
#endif

#if PHP_VERSION_ID >= 70000
	return &storage_object->object;
#else
    return retval;
#endif
}

void zookeeper_client_free_object(zookeeper_client_storage_object *storage_object TSRMLS_DC)
{
    if (storage_object->zk_handle) {
        zookeeper_close(storage_object->zk_handle);
    }

    zend_object_std_dtor(&storage_object->object TSRMLS_CC);
    efree(storage_object);
}

// ---- Definitions ----

ZEND_BEGIN_ARG_INFO_EX(connect_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, hosts)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(get_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(getChildren_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(create_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(delete_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(exists_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

zend_function_entry zookeeper_client_method_entry[] = {
    PHP_ME(ZookeeperClient, connect, connect_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, get, get_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, getChildren, getChildren_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, create, create_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, delete, delete_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, exists, exists_arg_info, ZEND_ACC_PUBLIC)

    { NULL, NULL, NULL }
};

// ---- PHP Methods ----

PHP_METHOD(ZookeeperClient, connect)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *hosts = NULL;
    int hosts_len = 0;
    zhandle_t *zk_handle = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hosts, &hosts_len) == FAILURE) {
        return;
    }

    zk_handle = zookeeper_init(hosts, NULL, 10000, 0, NULL, 0);
    if (NULL == zk_handle) {
        throw_zookeeper_client_exception("Fail to initialize zookeeper client", LIBZOOKEEPER_ERROR_INIT_FAILURE TSRMLS_CC);
        return;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT(me);
    storage->zk_handle = zk_handle;
}

PHP_METHOD(ZookeeperClient, get)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *path = NULL;
    int path_len = 0;
    int response = ZOK;
    struct Stat stat;
    char *retval = NULL;
    int retval_len = 0;
#if PHP_VERSION_ID >= 70000
	zend_string *retval_string;
#endif

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
        return;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT(me);

    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'get'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zoo_exists(storage->zk_handle, path, 1, &stat);
    if (response != ZOK) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    /* Found NULL in node */
    if (stat.dataLength < 0)
        RETURN_NULL();

	retval_len = stat.dataLength + 1;
    retval = emalloc(retval_len);
    response = zoo_wget(storage->zk_handle, path, NULL, NULL, retval, &retval_len, &stat);
    if (response != ZOK) {
        efree(retval);
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }
	/* Found NULL in node */
    if (retval_len <= 0) {
		RETURN_NULL();
    }

    retval[retval_len] = 0;
#if PHP_VERSION_ID >= 70000
	retval_string = zend_string_init(retval, retval_len, 0);
	RETURN_STR(retval_string);
#else
    RETURN_STRINGL(retval, retval_len, 0);
#endif
}

PHP_METHOD(ZookeeperClient, getChildren)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *path = NULL;
    int path_len = 0;
    int response = ZOK;
    struct String_vector children;
	int i;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
        return;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT(me);

    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'getChildren'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zoo_wget_children(storage->zk_handle, path, NULL, NULL, &children);
    if (response != ZOK) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    array_init(return_value);
    for (i = 0; i < children.count; i++) {
        add_next_index_string(return_value, children.data[i]
#if PHP_VERSION_ID < 70000
				, 1
#endif
				);
    }
}

PHP_METHOD(ZookeeperClient, create)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *path = NULL;
    int path_len = 0;
    char *value = NULL;
    int value_len = 0;
    int response = ZOK;
    struct ACL_vector acl_vector = { 0, };
    char *buffer = NULL;
    int buffer_len = 0;
#if PHP_VERSION_ID >= 70000
	zend_string *retval;
#endif

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s!", &path, &path_len, &value, &value_len) == FAILURE) {
        return;
    }

    if (!value) {
        value_len = -1;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT(me);
    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'create'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    acl_vector.count = 1;
    acl_vector.data = (struct ACL *)ecalloc(1, sizeof(struct ACL));
    acl_vector.data[0].perms = ZOO_PERM_ALL;
    acl_vector.data[0].id.id = "anyone";
    acl_vector.data[0].id.scheme = "world";

    buffer_len = path_len + 1;
    buffer = emalloc(buffer_len);

    response = zoo_create(storage->zk_handle, path, value, value_len, &acl_vector, 0, buffer, buffer_len);
    if (response != ZOK) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    buffer[buffer_len - 1] = 0;
#if PHP_VERSION_ID >= 70000
	retval = zend_string_init(buffer, buffer_len - 1, 0);
	RETURN_STR(retval);
#else
    RETURN_STRINGL(buffer, buffer_len - 1, 0);
#endif
}

PHP_METHOD(ZookeeperClient, delete)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *path = NULL;
    int path_len = 0;
    int response = ZOK;
    int version = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
        return;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT(me);

    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'delete'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zoo_delete(storage->zk_handle, path, version);
    if (response != ZOK) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    RETURN_TRUE;
}

PHP_METHOD(ZookeeperClient, exists)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *path = NULL;
    int path_len = 0;
    struct Stat stat;
    int response = ZOK;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
        return;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT(me);

    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'exists'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zoo_exists(storage->zk_handle, path, 0, &stat);
    if (response == ZOK)
        RETURN_TRUE;

    if (response != ZNONODE) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    RETURN_FALSE;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 expandtab fdm=marker
 * vim<600: noet sw=4 ts=4 expandtab
 */
