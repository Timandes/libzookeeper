/* $Id$ */

#include "zookeeper_client.h"
#include "zookeeper_client_exceptions.h"
#include "error_codes.h"
#include "simulation.h"

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
    ZEND_ARG_INFO(0, acls)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(delete_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(exists_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(set_arg_info, 0, 0, 2)
    ZEND_ARG_INFO(0, path)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(close_arg_info, 0, 0, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(setLogLevel_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, logLevel)
ZEND_END_ARG_INFO()

zend_function_entry zookeeper_client_method_entry[] = {
    PHP_ME(ZookeeperClient, connect, connect_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, get, get_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, getChildren, getChildren_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, create, create_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, delete, delete_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, exists, exists_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, set, set_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, close, close_arg_info, ZEND_ACC_PUBLIC)

    PHP_ME(ZookeeperClient, setLogLevel, setLogLevel_arg_info, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)

    { NULL, NULL, NULL }
};

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
    // ERR_*
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_OK") - 1, ZOK TSRMLS_CC);

    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_SYSTEMERROR") - 1, ZSYSTEMERROR TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_RUNTIMEINCONSISTENCY") - 1, ZRUNTIMEINCONSISTENCY TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_DATAINCONSISTENCY") - 1, ZDATAINCONSISTENCY TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_CONNECTIONLOSS") - 1, ZCONNECTIONLOSS TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_MARSHALLINGERROR") - 1, ZMARSHALLINGERROR TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_UNIMPLEMENTED") - 1, ZUNIMPLEMENTED TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_OPERATIONTIMEOUT") - 1, ZOPERATIONTIMEOUT TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_BADARGUMENTS") - 1, ZBADARGUMENTS TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_INVALIDSTATE") - 1, ZINVALIDSTATE TSRMLS_CC);
#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_NEWCONFIGNOQUORUM") - 1, ZNEWCONFIGNOQUORUM TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("ERR_RECONFIGINPROGRESS") - 1, ZRECONFIGINPROGRESS TSRMLS_CC);
#endif

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

    // LOG_LEVEL_*
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("LOG_LEVEL_NONE") - 1, 0 TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("LOG_LEVEL_ERROR") - 1, ZOO_LOG_LEVEL_ERROR TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("LOG_LEVEL_WARN") - 1, ZOO_LOG_LEVEL_WARN TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("LOG_LEVEL_INFO") - 1, ZOO_LOG_LEVEL_INFO TSRMLS_CC);
    zend_declare_class_constant_long(zookeeper_client_class_entry, ZEND_STRS("LOG_LEVEL_DEBUG") - 1, ZOO_LOG_LEVEL_DEBUG TSRMLS_CC);
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

    storage_object = ecalloc(1, sizeof(zookeeper_client_storage_object)
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



void zookeeper_client_free_object(
#if PHP_VERSION_ID >= 70000
        zend_object *object
#else
        zookeeper_client_storage_object *storage_object TSRMLS_DC
#endif
        )
{
#if PHP_VERSION_ID >= 70000
    zookeeper_client_storage_object *storage_object;

    storage_object = FETCH_ZOOKEEPER_CLIENT_OBJECT(object);
#endif

    if (storage_object->zk_handle) {
        zookeeper_close(storage_object->zk_handle);
    }
    storage_object->zk_handle = NULL;

    zend_object_std_dtor(&storage_object->object TSRMLS_CC);
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
#if PHP_VERSION_ID >= 70000
    zend_string *hosts_string = NULL;
#endif

    storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);

    if (storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'close' should be called before 'connect'", LIBZOOKEEPER_ERROR_CLOSE_FIRST TSRMLS_CC);
        return;
    }

#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &hosts_string) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hosts, &hosts_len) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    hosts = hosts_string->val;
    hosts_len = hosts_string->len;
#endif
    zk_handle = zookeeper_init(hosts, NULL, 10000, 0, NULL, 0);
    if (NULL == zk_handle) {
        throw_zookeeper_client_exception("Fail to initialize zookeeper client", LIBZOOKEEPER_ERROR_INIT_FAILURE TSRMLS_CC);
        return;
    }

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
    zend_string *path_string = NULL;
	zend_string *retval_string = NULL;
#endif

#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &path_string) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    path = path_string->val;
    path_len = path_string->len;
#endif

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);

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
        efree(retval);
		RETURN_NULL();
    }

    retval[retval_len] = 0;
#if PHP_VERSION_ID >= 70000
	retval_string = zend_string_init(retval, retval_len, 0);
    efree(retval);
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
#if PHP_VERSION_ID >= 70000
    zend_string *path_string = NULL;
#endif

#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "S", &path_string) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    path = path_string->val;
    path_len = path_string->len;
#endif
	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);

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
    struct ACL_vector *acl_vector_p = NULL;
    char *buffer = NULL;
    int buffer_len = 0;
#if PHP_VERSION_ID >= 70000
    zend_string *path_string = NULL;
    zend_string *value_string = NULL;
    zend_string *retval = NULL;
#endif
    zval *acls = NULL;


#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "S|S!a!", &path_string, &value_string, &acls) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s!a!", &path, &path_len, &value, &value_len, &acls) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    path = path_string->val;
    path_len = path_string->len;
    if (value_string) {
        value = value_string->val;
        value_len = value_string->len;
    }
#endif
    if (!value
            || strlen(value) <= 0) {
        value_len = -1;
    }

	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);
    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'create'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    // array => vector
    acl_vector_p = zookeeper_client_zarrval_2_acl_vector(acls TSRMLS_CC);
    if (NULL == acl_vector_p
            || acl_vector_p->count <= 0) {
        if (NULL == acl_vector_p)
            acl_vector_p = (struct ACL_vector *)calloc(1, sizeof(struct ACL_vector));
        acl_vector_p->count = 1;
        acl_vector_p->data = (struct ACL *)calloc(1, sizeof(struct ACL));
        acl_vector_p->data[0].perms = ZOO_PERM_ALL;
        acl_vector_p->data[0].id.id = "anyone";
        acl_vector_p->data[0].id.scheme = "world";
    }

    buffer_len = path_len + 1;
    buffer = emalloc(buffer_len);

    response = zoo_create(storage->zk_handle, path, value, value_len, acl_vector_p, 0, buffer, buffer_len);
    free(acl_vector_p->data);
    free(acl_vector_p);
    if (response != ZOK) {
        efree(buffer);
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    buffer[buffer_len - 1] = 0;
#if PHP_VERSION_ID >= 70000
	retval = zend_string_init(buffer, buffer_len - 1, 0);
    efree(buffer);
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
#if PHP_VERSION_ID >= 70000
    zend_string *path_string = NULL;
#endif

#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "S", &path_string) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    path = path_string->val;
    path_len = path_string->len;
#endif
	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);

    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'delete'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zoo_delete(storage->zk_handle, path, -1);
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
#if PHP_VERSION_ID >= 70000
    zend_string *path_string = NULL;
#endif

#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "S", &path_string) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    path = path_string->val;
    path_len = path_string->len;
#endif
	storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);

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

PHP_METHOD(ZookeeperClient, set)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    char *path = NULL;
    int path_len = 0;
    char *value = NULL;
    int value_len = 0;
    int response = ZOK;
#if PHP_VERSION_ID >= 70000
    zend_string *path_string = NULL;
    zend_string *value_string = NULL;
#endif

#if PHP_VERSION_ID >= 70000
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "S|S!", &path_string, &value_string) == FAILURE) {
#else
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s!", &path, &path_len, &value, &value_len) == FAILURE) {
#endif
        return;
    }
#if PHP_VERSION_ID >= 70000
    path = path_string->val;
    path_len = path_string->len;
    if (value_string) {
        value = value_string->val;
        value_len = value_string->len;
    }
#endif
    if (!value
            || strlen(value) <= 0) {
        value_len = -1;
    }

    storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);
    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'set'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zoo_set(storage->zk_handle, path, value, value_len, -1);
    if (response != ZOK) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }
}

PHP_METHOD(ZookeeperClient, setLogLevel)
{
    long log_level = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS()
#if PHP_VERSION_ID < 70000
            TSRMLS_CC
#endif
            , "l", &log_level) == FAILURE) {
        return;
    }

    zoo_set_debug_level((ZooLogLevel)log_level);
}

PHP_METHOD(ZookeeperClient, close)
{
    zval *me = getThis();
    zookeeper_client_storage_object *storage;
    int response = ZOK;

    storage = FETCH_ZOOKEEPER_CLIENT_OBJECT_BY_THIS(me);

    if (!storage->zk_handle) {
        throw_zookeeper_client_exception("Method 'connect' should be called before 'close'", LIBZOOKEEPER_ERROR_CONNECT_FIRST TSRMLS_CC);
        return;
    }

    response = zookeeper_close(storage->zk_handle);
    if (response != ZOK) {
        throw_zookeeper_client_core_exception(response TSRMLS_CC);
        return;
    }

    storage->zk_handle = NULL;
}


// ---- ACL functions ----

struct ACL_vector *zookeeper_client_zarrval_2_acl_vector(zval *arr TSRMLS_DC)
{
    zval *parts = NULL;
    int arr_count = 0;
    struct ACL_vector *return_value = NULL;
    int i = 0;
#ifdef ZEND_ENGINE_3
    zend_ulong h = 0;
    zend_string *key = NULL;
    zval *value = NULL;

    zval *id = NULL;
    zval *scheme = NULL;

    zend_string *delim = NULL;
#else
    ulong h = 0;
    zval *key = NULL;
    zval **value = NULL;

    zval **id = NULL;
    zval **scheme = NULL;

    zval *delim = NULL;
#endif

    // allocate
    if (NULL == arr)
        return return_value;

    arr_count = zend_hash_num_elements(Z_ARRVAL_P(arr));
    if (arr_count <= 0)
        return return_value;

#ifdef ZEND_ENGINE_3
    delim = zend_string_init(":", 1, 0);
#else
    ZVAL_STRING(delim, ":", 0);
#endif

    return_value = (struct ACL_vector *)calloc(1, sizeof(struct ACL_vector));
    return_value->count = 0;
    return_value->data = (struct ACL *)calloc(arr_count, sizeof(struct ACL));

    // array => vector
    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(arr), h, key, value) {
        // Split scheme & id from "scheme:id"
        php_explode(delim, key, parts, 1);

        if (Z_TYPE_P(parts) != IS_ARRAY
                || zend_hash_num_elements(Z_ARRVAL_P(parts)) < 2) {
            php_error_docref(NULL TSRMLS_CC, E_WARNING, "Ilegal acl key");
            continue;
        }

#ifdef ZEND_ENGINE_3
        scheme = zend_hash_index_find(Z_ARRVAL_P(parts), 0);
        id = zend_hash_index_find(Z_ARRVAL_P(parts), 1);

        return_value->data[i].perms = (int32_t)Z_LVAL_P(value);
        return_value->data[i].id.id = Z_STRVAL_P(id);
        return_value->data[i].id.scheme = Z_STRVAL_P(scheme);
#else
        zend_hash_index_find(Z_ARRVAL_P(parts), 0, (void **)&scheme);
        zend_hash_index_find(Z_ARRVAL_P(parts), 1, (void **)&id);

        return_value->data[i].perms = (int32_t)Z_LVAL_PP(value);
        return_value->data[i].id.id = Z_STRVAL_PP(id);
        return_value->data[i].id.scheme = Z_STRVAL_PP(scheme);
#endif

        i++;
    } ZEND_HASH_FOREACH_END();
    return_value->count = i;

#ifdef ZEND_ENGINE_3
    zend_string_free(delim);
#endif

    return return_value;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 expandtab fdm=marker
 * vim<600: noet sw=4 ts=4 expandtab
 */
