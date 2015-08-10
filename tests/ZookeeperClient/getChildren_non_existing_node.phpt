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
} catch (ZookeeperClientCoreException $zcce) {
    fprintf(STDOUT, "[#%d] %s\n", $zcce->getCode(), $zcce->getMessage());
}
?>
--EXPECT--
[#-101] no node
