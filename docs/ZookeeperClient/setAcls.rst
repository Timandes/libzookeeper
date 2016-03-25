.. _setAcls:

ZookeeperClient::setAcls
========================

ZookeeperClient::setAcls — sets the acl associated with a node synchronously

Description
-----------

::

    public void ZookeeperClient::setAcls(string $path, array $acls)

Parameters
----------

path
    path the name of the node. Expressed as a file name with slashes separating ancestors of the node.

acls
    the acl to be set on the path.

Return Values
-------------

No value is returned.
