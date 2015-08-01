PHP Libzookeeper Extension
----

[![Build Status](https://img.shields.io/travis/Timandes/libzookeeper/master.svg?style=flat-square)](https://travis-ci.org/Timandes/libzookeeper)

Communicate with Zookeeper using PHP.

Requirements
====

* Zookeeper C Client

Install
====

    $ phpize
    $ ./configure --with-libzookeeper=/path/to/zookeeper-c-client
    $ make
    $ make install

Examples
====

    <?php
    $zc = new ZookeeperClient();
    $zc->connect('localhost:2181');
    var_dump($zc->get('/zookeeper'));
    ?>
