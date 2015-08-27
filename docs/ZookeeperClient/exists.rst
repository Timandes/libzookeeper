.. _exists:

ZookeeperClient::exists
========================

ZookeeperClient::exists — Check existence of some node

Description
-----------

::

    public bool ZookeeperClient::exists(string $path)

Parameters
----------

path
    Path of the node (e.g. "/zookeeper/quota")

Return Values
-------------

Returns true when node existing, otherwise returns false.
