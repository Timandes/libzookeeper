--TEST--
Set should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/set_test_node';
$zc->create($path, '1');
$zc->set($path, '2');
echo $zc->get($path);
$zc->delete($path)
?>
--EXPECT--
2