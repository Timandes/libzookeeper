--TEST--
SetAcls should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/setAcls_test_node';
$zc->create($path, '1');
$acls = array (
    'world:anyone' => \ZookeeperClient::PERM_READ,
    'digest:user0:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_ALL,
    'digest:user1:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
    );
$zc->setAcls($path, $acls);
$zc->delete($path)
?>
--EXPECT--
