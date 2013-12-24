#!/bin/sh
#
#   Setup script for workspace configuration.
#
#   Author: Jean-Marie Comets <jean.marie.comets@gmail.com>
#   Version: 1.5 - 30/10/2013, 17:06
#

WORKSPACE=$HOME
PROJECTS=$WORKSPACE/Projects
DOTFILES=$PROJECTS/Dotfiles
BUNDLE=$WORKSPACE/Bundle

# Refactored link command
setup_link()
{
    rm -f $2 && ln -s $1 $2
    return $?
}

# Setup projects subdirectory links
setup_link $PROJECTS/Bundle $BUNDLE

# Setup Bin file link
setup_link $DOTFILES/Bin ~/bin

# Setup Vim file links
setup_link $DOTFILES/Vim ~/.vim
setup_link ~/.vim/vimrc ~/.vimrc

# Setup shell profile link
setup_link $DOTFILES/Shell/profile ~/.profile
setup_link $DOTFILES/Shell/dircolors ~/.dircolors
# and solarized configuration for gnome terminal
gconftool-2 --set "/apps/gnome-terminal/profiles/Default/use_theme_background" --type bool false
gconftool-2 --set "/apps/gnome-terminal/profiles/Default/use_theme_colors" --type bool false
gconftool-2 --set "/apps/gnome-terminal/profiles/Default/palette" --type string "#070736364242:#D3D301010202:#858599990000:#B5B589890000:#26268B8BD2D2:#D3D336368282:#2A2AA1A19898:#EEEEE8E8D5D5:#00002B2B3636:#CBCB4B4B1616:#58586E6E7575:#65657B7B8383:#838394949696:#6C6C7171C4C4:#9393A1A1A1A1:#FDFDF6F6E3E3"
gconftool-2 --set "/apps/gnome-terminal/profiles/Default/background_color" --type string "#00002B2B3636"
gconftool-2 --set "/apps/gnome-terminal/profiles/Default/foreground_color" --type string "#65657B7B8383"

# Setup Zsh file links
setup_link $DOTFILES/Shell/zsh ~/.zsh
setup_link ~/.zsh/rc ~/.zshrc
setup_link ~/.zsh/env ~/.zshenv

# Setup Bash file links
setup_link $DOTFILES/Shell/bash ~/.bash
setup_link ~/.bash/rc ~/.bashrc
setup_link ~/.bash/inputrc ~/.inputrc
setup_link ~/.bash/profile ~/.bash_profile

# vim: ft=sh et sw=4 sts=4
