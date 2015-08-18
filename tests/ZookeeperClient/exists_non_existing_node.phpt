--TEST--
Check existence of non-existing node
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
var_dump($zc->exists('/non-existing'));
?>
--EXPECT--
bool(false)
