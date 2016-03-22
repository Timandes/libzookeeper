--TEST--
Set acls before connecting
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$acls = array (
    'world:anyone' => \ZookeeperClient::PERM_READ,
    'digest:user0:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_ALL,
    'digest:user1:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
    );
try {
    $zc->setAcls('/setAcls_test_node', $acls);
} catch (ZookeeperClientException $zce) {
    fprintf(STDOUT, "[#%d] %s\n", $zce->getCode(), $zce->getMessage());
}
?>
--EXPECT--
[#2] Method 'connect' should be called before 'setAcls'
