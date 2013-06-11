#!/bin/bash
#
#   Setup script for workspace configuration.
#
#   Author: Jean-Marie Comets <jean.marie.comets@gmail.com>
#   Version: 1.2 - 23/02/2013, 21:47
#
#   Run as follows:
#     > chmod 0777 config.sh
#     > ./config.sh
#   Or quicker:
#     > bash config.sh
#

WORKSPACE=$HOME
PROJECTS=$WORKSPACE/Projects
CONFIGS=$WORKSPACE/Configs
BUNDLE=$WORKSPACE/Bundle

# Setup projects subdirectory links
ln -fs $PROJECTS/Configs $CONFIGS
ln -fs $PROJECTS/Bundle $BUNDLE

# Setup Vim file links
ln -fs $CONFIGS/Vim ~/.vim
ln -fs ~/.vim/vimrc ~/.vimrc

# Setup Bash file links
ln -fs $CONFIGS/Bash ~/.bash
ln -fs ~/.bash/bashrc ~/.bashrc
ln -fs ~/.bash/profile ~/.profile
ln -fs ~/.bash/inputrc ~/.inputrc
ln -fs ~/.bash/dircolors ~/.dircolors
