.. _ZookeeperClientCoreException:

ZookeeperClientCoreException
============================

Introduction
------------

Exception thrown if anything wrong about zookeeper client occurred.

Method `getCode()` returns the error code which is returned by Zookeeper C Client, and method `getMessage()` returns the error message which is returned by function 'zerror()'.

Class synopsis
--------------

::

    class ZookeeperClientCoreException extends ZookeeperClientException {
    }
