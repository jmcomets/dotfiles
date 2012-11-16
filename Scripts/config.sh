#!/bin/bash
#
# Setup script for Bash / Vim configurations.
#
# Author: Jean-Marie Comets <jean.marie.comets@gmail.com>
# Version: 1.1 - 28/08/2012, 15:41
#
# Run as follows:
#   $ chmod 0777 config.sh
#   $ ./config.sh
# Or quicker:
#   $ bash config.sh
#

# Setup Config's folder link
ln -fs ~/Projects/Configs ~/Configs

# Setup Vim file links
ln -fs ~/Configs/Vim ~/.vim
ln -fs ~/.vim/vimrc ~/.vimrc

# Setup Bash file links
ln -fs ~/Configs/Bash ~/.bash
ln -fs ~/.bash/bashrc ~/.bashrc
ln -fs ~/.bash/inputrc ~/.inputrc
ln -fs ~/.bash/dircolors ~/.dircolors
