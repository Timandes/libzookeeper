--TEST--
Check for php.ini entry
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php 
ob_start();
phpinfo(INFO_MODULES);
$s = ob_get_contents();
$a = explode("\n", $s);
$r = false;
foreach ($a as $l) {
     if (preg_match('/^libzookeeper/', $l))
         $r = true;
}
ob_end_clean();
var_dump($r);
?>
--EXPECT--
bool(true)
