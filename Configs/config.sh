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
ln -s ~/Projects/Configs ~/Configs

# Setup Vim file links
ln -s ~/Configs/Vim/ ~/.vim
ln -s ~/.vim/vimrc ~/.vimrc

# Setup Bash file links
ln -s ~/Configs/Bash ~/.bash
ln -fs ~/.bash/bashrc ~/.bashrc
