--TEST--
Fail to delete node
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
try {
    $zc->delete('/delete_test_node');
} catch (ZookeeperClientCoreException $zcce) {
    fprintf(STDOUT, "[#%d] %s\n", $zcce->getCode(), $zcce->getMessage());
}
?>
--EXPECT--
[#-101] no node
