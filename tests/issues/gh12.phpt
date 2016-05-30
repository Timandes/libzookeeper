--TEST--
GitHub Issue #12
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$path = 'some-existing-file.php';
file_put_contents($path, '<?php echo "OK"; ?>');
$zc = new \ZookeeperClient();
unset($zc);
require $path;
?>
--EXPECT--
OK
