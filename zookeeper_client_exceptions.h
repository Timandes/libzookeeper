/* $Id$ */

#ifndef ZOOKEEPER_CLIENT_EXCEPTIONS_H
#define ZOOKEEPER_CLIENT_EXCEPTIONS_H

#include <php.h>
#include <zookeeper/zookeeper.h>

/* class ZookeeperClientException { */
zend_class_entry *zookeeper_client_exception_class_entry;
/* } ZookeeperClientException */

/* class ZookeeperClientCoreException extends ZookeeperClientException { */
zend_class_entry *zookeeper_client_core_exception_class_entry;
/* } ZookeeperClientCoreException */

/* Register classes extended from `RuntimeException` */
void register_zookeeper_client_exception_classes(TSRMLS_D);

/* Register Constants of `ZookeeperClientException` */
void register_zookeeper_client_exception_class_constants(INIT_FUNC_ARGS);

/* Throw `ZookeeperClientException` */
void throw_zookeeper_client_exception(char *message, int code TSRMLS_DC);

/* Throw `ZookeeperClientCoreException` */
void throw_zookeeper_client_core_exception(int code TSRMLS_DC);

#endif  /* ZOOKEEPER_CLIENT_EXCEPTIONS_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
