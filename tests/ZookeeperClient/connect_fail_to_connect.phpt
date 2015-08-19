--TEST--
Fail to connect
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
try {
    $zc->connect('localhost:0');
} catch (ZookeeperClientException $zce) {
    fprintf(STDOUT, "[#%d] %s\n", $zce->getCode(), $zce->getMessage());
}
?>
--EXPECTF--
%d-%d-%d %d:%d:%d,%d:%d(0x%x):ZOO_ERROR@%s@%d: invalid port in localhost
[#1] Fail to initialize zookeeper client
