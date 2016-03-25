.. _create:

ZookeeperClient::create
========================

ZookeeperClient::create — Create a new node

Description
-----------

::

    public string ZookeeperClient::create(string $path [[, string $value], array $acls])

Parameters
----------

path
    Path of the node (e.g. "/zookeeper/quota")

value
    Default value of the new node

acls
    The acls to be set on the path

Return Values
-------------

Returns real path of the new node on success, or false on error.
