--TEST--
Set acls on non-existing node
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$acls = array (
    'world:anyone' => \ZookeeperClient::PERM_READ,
    'digest:user0:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_ALL,
    'digest:user1:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
    );
try {
    $zc->setAcls('/setAcls_test_node', $acls);
} catch (ZookeeperClientCoreException $zcce) {
    fprintf(STDOUT, "[#%d] %s\n", $zcce->getCode(), $zcce->getMessage());
}
?>
--EXPECT--
[#-101] no node
