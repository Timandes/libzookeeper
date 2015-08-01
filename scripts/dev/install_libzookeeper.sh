#! /bin/sh
#
#   * Install & Launch Zookeeper
#   * Install Zookeeper C Client
#
# Authors:
#   * Timandes White <timands@gmail.com>
#   * Fábio da Silva <fabiorphp@gmail.com>
#

LIBZOOKEEPER_VERSION=$1
PACKAGE_NAME=zookeeper-${LIBZOOKEEPER_VERSION}
LIBZOOKEEPER_PREFIX=${HOME}/lib${PACKAGE_NAME}

wget http://apache.fayea.com/zookeeper/${PACKAGE_NAME}/${PACKAGE_NAME}.tar.gz || exit 1
tar xvf ${PACKAGE_NAME}.tar.gz || exit 1
mv ${PACKAGE_NAME}/conf/zoo_sample.cfg ${PACKAGE_NAME}/conf/zoo.cfg
${PACKAGE_NAME}/bin/zkServer.sh start || exit 1
cd ${PACKAGE_NAME}/src/c
    ./configure --prefix=${LIBZOOKEEPER_PREFIX} || exit 1
    make || exit 1
    make install || exit 1
cd ../../..

exit 0
