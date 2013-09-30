#!/bin/sh
#
#   Install script for needed apps.
#
#   Author: Jean-Marie Comets <jean.marie.comets@gmail.com>
#   Version: 0.9 - 17/08/2013, 15:36
#

# Must be run as root
if [ "$(id -u)" != "0" ]; then
    echo "This script must be run as root" 1>&2
    exit 1
fi

# Base packages
apt-get -y install  \
    build-essential \
    cmake           \
    git             \
    python-pip      \
    tree            \
    curl            \
    vim
if [ "$?" -ne "0" ]; then
    echo "Installation failed at step: base packages" 1>&2
    exit 2
fi

# Python packages
pip install     \
    requests    \
    virtualenv
if [ "$?" -ne "0" ]; then
    echo "Installation failed at step: python packages" 1>&2
    exit 2
fi

# Node
node_git='https://github.com/joyent/node.git'
cd /tmp                         \
    && git clone $node_git node \
    && cd node                  \
    && ./configure              \
    && make -j                  \
    && make install             \
if [ "$?" -ne "0" ]; then
    echo "Installation failed at step: node" 1>&2
    exit 2
fi
# ...and packages
npm install -g  \
    grunt-cli   \
    bower
if [ "$?" -ne "0" ]; then
    echo "Installation failed at step: node packages" 1>&2
    exit 2
fi

# vim: ft=sh et sw=4 sts=4
