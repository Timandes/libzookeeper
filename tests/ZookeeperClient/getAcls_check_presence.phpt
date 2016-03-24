--TEST--
Check for method getAcls presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
var_dump(method_exists($zc, "getAcls"));
?>
--EXPECT--
bool(true)
