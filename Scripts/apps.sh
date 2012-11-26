#!/bin/bash
#
# Script for installing apps when installing Ubuntu.
#
# Arguments:
#   -h : display help
#   -s : shutdown after installing
#   -i : prompt for confirm all installations
#
# vim: set ft=sh:

# UNIX timestamp concatenated with nanoseconds
T="$(date +%s%N)"

# Display help:
if [[ $* = *-h* ]]; then
    echo -e "Ubuntu apps installation script.\nArguments:\n-h : display this help\n-i : confirm before each operation\n-s : shutdown after installing apps\n\nThis script must be run as root!"
    exit 0
fi

# Check for root user:
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root!" 1>&2
   exit 1
fi

# Shutdown flag:
if [[ $* = *-s* ]]; then
    shutdown=true
else
    shutdown=false
fi

# Confirm flag for installing:
if [[ $* = *-i* ]]; then
    confirm=""
else
    confirm="-y"
fi

# Add repositories:
echo "Beginning repository updating..."

# For indicator-sysmonitor
add-apt-repository $confirm ppa:alexeftimie/ppa

# For gnome-shell-extensions
add-apt-repository $confirm ppa:ferramroberto/gnome3

# For gimp
add-apt-repository $confirm ppa:otto-kesselgulasch/gimp

# Update repositories and upgrade
apt-get $confirm update
apt-get $confirm upgrade

# Install apps, currently:
#   - ubuntu-restricted-extras
#   - build-essential
#   - cmake
#   - gnome-tweak-tool
#   - vlc
#   - compizconfig-settings-manager
#   - indicator-sysmonitor
#   - gnome-shell
#   - gnome-shell-extensions-common
#   - vim
#   - vim-gtk
#   - exuberant-ctags
#   - gimp
#   - synaptic
#   - git
#   - tree

apt-get install $confirm ubuntu-restricted-extras build-essential cmake gnome-tweak-tool vlc compizconfig-settings-manager indicator-sysmonitor gnome-shell gnome-shell-extensions-common vim vim-gtk exuberant-ctags gimp synaptic git tree dvtm

# Time interval in nanoseconds:
T="$(($(date +%s%N)-T))"

# Converted in secnds:
S="$((T/1000000000))"

# Show script time:
printf "Script duration: %02d:%02d:%02d\n" "$((S/3600%24))" "$((S/60%60))" "$((S%60))"

# Shutdown if argument given
if $shutdown; then
    shutdown -h now
fi
