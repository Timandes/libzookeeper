--TEST--
Check class ZookeeperClientCoreException's parent
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zcce = new ZookeeperClientCoreException();
var_dump($zcce instanceof ZookeeperClientCoreException);
?>
--EXPECT--
bool(true)
