--TEST--
Check for class ZookeeperClientCoreException presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
var_dump(class_exists("ZookeeperClientCoreException"));
?>
--EXPECT--
bool(true)
