--TEST--
Connect should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
var_dump($zc->connect('localhost:2181'));
?>
--EXPECT--
NULL
