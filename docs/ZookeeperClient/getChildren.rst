.. _getChildren:

ZookeeperClient::getChildren
========================

ZookeeperClient::getChildren — Get child nodes of given node

Description
-----------

::

    public array ZookeeperClient::getChildren(string $path)

Parameters
----------

path
    Path of the node (e.g. "/zookeeper/quota")

Return Values
-------------

Returns array filled of names of child nodes on success, or false on error.
