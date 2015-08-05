.. _create:

ZookeeperClient::create
========================

ZookeeperClient::create — Create a new node

Description
-----------

::

    public string ZookeeperClient::create(string path [, string value])

Parameters
----------

path
    Path of the node (e.g. "/zookeeper/quota")

value
    Default value of the new node

Return Values
-------------

Returns real path of the new node on success, or false on error.
