--TEST--
Create should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/create_test_node';
echo $zc->create($path);
$zc->delete($path)
?>
--EXPECT--
/create_test_node