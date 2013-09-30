#!/bin/sh
#
#   Setup script for workspace configuration.
#
#   Author: Jean-Marie Comets <jean.marie.comets@gmail.com>
#   Version: 1.5 - 30/10/2013, 17:06
#

WORKSPACE=$HOME
PROJECTS=$WORKSPACE/Projects
CONFIGS=$WORKSPACE/Configs
BUNDLE=$WORKSPACE/Bundle

# Refactored link command
setup_link()
{
    rm -f $2 && ln -s $1 $2
    return $?
}

# Setup projects subdirectory links
setup_link $PROJECTS/Configs $CONFIGS
setup_link $PROJECTS/Bundle $BUNDLE

# Setup Bin file link
setup_link $CONFIGS/Bin ~/bin

# Setup Vim file links
setup_link $CONFIGS/Vim ~/.vim
setup_link ~/.vim/vimrc ~/.vimrc

# Setup shell profile link
setup_link $CONFIGS/Shell/profile ~/.profile

# Setup Zsh file links
setup_link $CONFIGS/Shell/zsh ~/.zsh
setup_link ~/.zsh/rc ~/.zshrc
setup_link ~/.zsh/env ~/.zshenv

# Setup Bash file links
setup_link $CONFIGS/Shell/bash ~/.bash
setup_link ~/.bash/rc ~/.bashrc
setup_link ~/.bash/inputrc ~/.inputrc
setup_link ~/.bash/dircolors ~/.dircolors
setup_link ~/.bash/profile ~/.bash_profile

# vim: ft=sh et sw=4 sts=4
