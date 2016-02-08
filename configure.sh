#!/bin/sh

# Root dotfiles directory
DOTFILES=~/.dotfiles

# Refactored link command
setup_link()
{
    if [ -e $1 ]; then
        rm -rf $2 && ln -s $1 $2
        return $?
    else
        return 1
    fi
}

# A few useful directories
mkdir -p ~/Bundle ~/Vendor

# Local "bin" directory
setup_link $DOTFILES/Bin ~/bin

# Vim
setup_link $DOTFILES/Vim ~/.vim
setup_link ~/.vim/vimrc ~/.vimrc

# Shell
setup_link $DOTFILES/Shell/aliases ~/.aliases
setup_link $DOTFILES/Shell/profile ~/.profile

# Zsh
setup_link $DOTFILES/Shell/zsh ~/.zsh
setup_link ~/.zsh/rc ~/.zshrc
setup_link ~/.zsh/env ~/.zshenv

# Bash
setup_link $DOTFILES/Shell/bash ~/.bash
setup_link ~/.bash/rc ~/.bashrc
setup_link ~/.bash/inputrc ~/.inputrc
setup_link ~/.bash/profile ~/.bash_profile

# Git
setup_link $DOTFILES/Shell/gitconfig ~/.gitconfig
setup_link $DOTFILES/Shell/githelpers ~/.githelpers

# Tmux
setup_link $DOTFILES/Shell/tmux ~/.tmux.conf

# Openbox
setup_link $DOTFILES/Customization/Xresources ~/.Xresources
setup_link $DOTFILES/Customization/openbox ~/.config/openbox
setup_link $DOTFILES/Customization/tint2 ~/.config/tint2
setup_link $DOTFILES/Customization/xinitrc ~/.xinitrc

# vim: ft=sh et sw=4 sts=4
