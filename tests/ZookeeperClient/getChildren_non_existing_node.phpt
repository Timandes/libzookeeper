--TEST--
Get child nodes from non-existing node
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
try {
    $zc->getChildren('/non-existing');
} catch (ZookeeperClientException $zce) {
    fprintf(STDOUT, "[#%d] %s\n", $zce->getCode(), $zce->getMessage());
}
?>
--EXPECT--
[#-101] no node
