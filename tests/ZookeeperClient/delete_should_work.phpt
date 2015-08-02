--TEST--
Delete should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/delete_test_node';
echo $zc->create($path);
$zc->delete($path)
?>
--EXPECT--
/delete_test_node