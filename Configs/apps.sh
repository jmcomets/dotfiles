#!/bin/bash

# Check for root user:
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root!" 1>&2
   exit 1
fi

# Add repositories:

# For indicator-sysmonitor
add-apt-repository -y ppa:alexeftimie/ppa 

# For gnome-shell-extensions
add-apt-repository -y ppa:ferramroberto/gnome3 

# For gimp
add-apt-repository -y ppa:otto-kesselgulasch/gimp 

# Update repositories and upgrade 
apt-get -y update
apt-get -y upgrade

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
#   - exuberant-ctags
#   - gimp
#   - synaptic
#   - git
#   - tree

apt-get install -y ubuntu-restricted-extras build-essential cmake gnome-tweak-tool vlc compizconfig-settings-manager indicator-sysmonitor gnome-shell gnome-shell-extensions-common vim exuberant-ctags gimp synaptic git tree

# Shutdown (optional, uncomment if needed)
#shutdown -hP now
