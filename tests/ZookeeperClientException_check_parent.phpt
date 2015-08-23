--TEST--
Check class ZookeeperClientException's parent
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zce = new ZookeeperClientException();
var_dump($zce instanceof RuntimeException);
?>
--EXPECT--
bool(true)
