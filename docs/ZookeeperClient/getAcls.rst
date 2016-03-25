.. _getAcls:

ZookeeperClient::getAcls
========================

ZookeeperClient::getAcls — Get node value from Zookeeper cluster

Description
-----------

::

    public string ZookeeperClient::getAcls(string $path)

Parameters
----------

path
    the name of the node. Expressed as a file name with slashes separating ancestors of the node.

Return Values
-------------

Returns acls as a assoc array on sucesss, or false on error.
