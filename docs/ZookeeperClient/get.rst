.. _get:

ZookeeperClient::get
========================

ZookeeperClient::get — Get node value from Zookeeper cluster

Description
-----------

::

    public string ZookeeperClient::get(string path)

Parameters
----------

path
    Path of the node (e.g. "/zookeeper/quota")

Return Values
-------------

Returns value as a string(NULL for empty value) on sucesss, or false on error.
