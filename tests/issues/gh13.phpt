--TEST--
GitHub Issue #13
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new \ZookeeperClient();
unset($zc);
$zc = new \ZookeeperClient();
$zc->connect('localhost:2182');
try {
    $zc->get('/zookeeper');
} catch(\ZookeeperClientCoreException $zcce) {
    fprintf(STDOUT, "[#%d] %s\n", $zcce->getCode(), $zcce->getMessage());
}
--EXPECT--
[#-4] connection loss
