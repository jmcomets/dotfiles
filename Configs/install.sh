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

# Command for "install"
INSTALL='apt-get -y install'

# Install packages
$INSTALL            \
    aptitude        \
    build-essential \
    cmake           \
    git             \
    python-pip      \
    tree            \
    vim             \
    zsh

# vim: ft=sh et sw=4 sts=4
