.. _examples:

Examples
========

No.1
-----

::

    <?php
    $zc = new ZookeeperClient();
    $zc->connect('localhost:2181');
    var_dump($zc->get('/zookeeper'));
    ?>

