/* $Id$ */

#ifndef LIBZOOKEEPER_SIMULATION_H
#define LIBZOOKEEPER_SIMULATION_H

#ifndef ZEND_ENGINE_3

void zend_hash_get_current_key_zval_ex(const HashTable *ht, zval *key, HashPosition *pos);

#define zend_hash_get_current_key_zval(ht, key) \
    zend_hash_get_current_key_zval_ex(ht, key, NULL)

#define ZEND_HASH_FOREACH_KEY_VAL(ht, _h, _key, _val) do { \
    for (zend_hash_internal_pointer_reset(ht); \
            (zend_hash_has_more_elements(ht) == SUCCESS); \
            zend_hash_move_forward(ht)) { \
        zend_hash_get_current_key_zval(ht, _key); \
        zend_hash_get_current_data(ht, (void**)&_val); \

#define ZEND_HASH_FOREACH_END() \
        } \
    } while (0)

#endif

void *zend_hash_str_find_ptr(const HashTable *ht, const char *str, size_t len);

#endif  /* LIBZOOKEEPER_SIMULATION_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
