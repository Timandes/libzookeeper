--TEST--
Set before connecting
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
try {
    $zc->set('/set_test_node', 'test_value');
} catch (ZookeeperClientException $zce) {
    fprintf(STDOUT, "[#%d] %s\n", $zce->getCode(), $zce->getMessage());
}
?>
--EXPECT--
[#2] Method 'connect' should be called before 'set'
