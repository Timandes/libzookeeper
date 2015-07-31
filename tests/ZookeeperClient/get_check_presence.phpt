--TEST--
Check for method get presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
var_dump(method_exists($zc, "get"));
?>
--EXPECT--
bool(true)
