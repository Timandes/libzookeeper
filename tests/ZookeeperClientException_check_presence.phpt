--TEST--
Check for class ZookeeperClientException presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
var_dump(class_exists("ZookeeperClientException"));
?>
--EXPECT--
bool(true)
