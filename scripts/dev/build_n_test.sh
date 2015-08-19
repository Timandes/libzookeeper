#! /bin/sh
#
#   * Build PHP extension 'libzookeeper'
#   * Test it
#
# Authors:
#   * Timandes White <timands@gmail.com>
#   * Fábio da Silva <fabiorphp@gmail.com>
#

LIBZOOKEEPER_VERSION=$1
LIBZOOKEEPER_PREFIX=${HOME}/libzookeeper-${LIBZOOKEEPER_VERSION}

phpize || exit 1
CFLAGS="--coverage -fprofile-arcs -ftest-coverage" \
LDFLAGS="--coverage" \
./configure --with-libzookeeper=${LIBZOOKEEPER_PREFIX} || exit 1
make || exit 1

lcov --directory . --zerocounters &&
    lcov --directory . --capture --initial --output-file coverage.info
export NO_INTERACTION=1 && make test
lcov --no-checksum --directory . --capture --output-file coverage.info

OUT_FILES=`find tests/ |grep "out$"`
if [ "${OUT_FILES}" != "" ]; then
    for f in `find tests/ |grep "out$"`; do cmd="cat $f" && echo $cmd: && $cmd && echo; done
    exit 1
fi

exit 0
