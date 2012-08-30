#!/bin/bash
# 
# Simple script for mounting a read-only
# partition using the `gksudo` command.
#
# Arguments:
#   -s : source partition
#   -d : mounting destination
#
# Default script configuration,
# paths are to be given absolute:
#   - SRC_PART = source partition
#   - MNT_DEST = mounting destination
#
# vim: map <F5> :!bash %<cr>:
# vim: set ft=sh:

# Default values:
SRC_PART=/dev/sda2
MNT_DEST=/mnt

# Handle command-line arguments
while [ $# -gt 1 ] ; do
    case $1 in
        -s) SRC_PART=$2 ; shift 2 ;;
        -d) MNT_DEST=$2 ; shift 2 ;;
        *) shift 1 ;;
    esac
done

# Mount partition
gksudo "mount -r $SRC_PART $MNT_DEST"
