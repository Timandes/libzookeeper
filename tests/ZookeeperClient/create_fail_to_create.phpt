--TEST--
Fail to create node
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$zc->create('/create_test_node');
try {
    $zc->create('/create_test_node');
} catch (ZookeeperClientCoreException $zcce) {
    fprintf(STDOUT, "[#%d] %s\n", $zcce->getCode(), $zcce->getMessage());
}
$zc->delete('/create_test_node');
?>
--EXPECT--
[#-110] node exists 
