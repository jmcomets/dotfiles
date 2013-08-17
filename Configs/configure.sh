#!/bin/sh
#
#   Setup script for workspace configuration.
#
#   Author: Jean-Marie Comets <jean.marie.comets@gmail.com>
#   Version: 1.4 - 25/07/2013, 15:26
#

WORKSPACE=$HOME
PROJECTS=$WORKSPACE/Projects
CONFIGS=$WORKSPACE/Configs
BUNDLE=$WORKSPACE/Bundle

# Refactored link command
function setup_link()
{
    rm -f $2 && ln -s $1 $2
    return $?
}

# Setup projects subdirectory links
setup_link $PROJECTS/Configs $CONFIGS
setup_link $PROJECTS/Bundle $BUNDLE

# Setup Vim file links
setup_link $CONFIGS/Vim ~/.vim
setup_link ~/.vim/vimrc ~/.vimrc

# Setup Bash file links
setup_link $CONFIGS/Bash ~/.bash
setup_link ~/.bash/rc ~/.bashrc
setup_link ~/.bash/profile ~/.profile
setup_link ~/.bash/inputrc ~/.inputrc
setup_link ~/.bash/dircolors ~/.dircolors

# Setup Zsh file links
setup_link $CONFIGS/Zsh ~/.zsh
setup_link ~/.zsh/rc ~/.zshrc

# vim: ft=sh et sw=4 sts=4
