--TEST--
Check for class ZookeeperClient presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
var_dump(class_exists("ZookeeperClient"));
?>
--EXPECT--
bool(true)
