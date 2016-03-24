--TEST--
Method create n getAcls
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/create_n_getAcls';
$acls = array (
    'world:anyone' => \ZookeeperClient::PERM_READ,
    'digest:user0:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_ALL,
    'digest:user1:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
    );
$zc->create($path, null, $acls);
$actual = $zc->getAcls($path);
$zc->delete($path);
var_dump($acls == $actual);
?>
--EXPECT--
bool(true)