/* $Id$ */

#include "simulation.h"

void zend_hash_get_current_key_zval_ex(const HashTable *ht, zval *zkey, HashPosition *pos)
{
    char *key = NULL;
    uint key_len = 0;
    ulong index = 0;

    zend_hash_get_current_key_ex(ht, &key, &key_len, &index, 0, pos);
    ZVAL_STRINGL(zkey, key, key_len, 0);
}

void *zend_hash_str_find_ptr(const HashTable *ht, const char *str, size_t len)
{
    zend_class_entry **class_entry = NULL;

    if (zend_hash_find(ht, str, len, (void **) &class_entry) == SUCCESS)
        return class_entry;
    else
        return NULL;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 expandtab fdm=marker
 * vim<600: noet sw=4 ts=4 expandtab
 */
