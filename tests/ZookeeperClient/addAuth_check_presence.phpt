--TEST--
Check for method addAuth presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
var_dump(method_exists($zc, "addAuth"));
?>
--EXPECT--
bool(true)
