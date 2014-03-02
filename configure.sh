#!/bin/sh

# Refactored link command
setup_link()
{
    rm -rf $2 && ln -s $1 $2
    return $?
}

# Root dotfiles directory
DOTFILES=~/.dotfiles

# Setup Bin file link
setup_link $DOTFILES/Bin ~/bin

# Setup Vim file links
setup_link $DOTFILES/Vim ~/.vim
setup_link ~/.vim/vimrc ~/.vimrc

# Setup shell profile link
setup_link $DOTFILES/Shell/profile ~/.profile
setup_link $DOTFILES/Shell/dircolors ~/.dircolors

# Setup Zsh file links
setup_link $DOTFILES/Shell/zsh ~/.zsh
setup_link ~/.zsh/rc ~/.zshrc
setup_link ~/.zsh/env ~/.zshenv

# Setup Bash file links
setup_link $DOTFILES/Shell/bash ~/.bash
setup_link ~/.bash/rc ~/.bashrc
setup_link ~/.bash/inputrc ~/.inputrc
setup_link ~/.bash/profile ~/.bash_profile

# Git aliases
git config --global alias.br 'branch'
git config --global alias.ci 'commit'
git config --global alias.cim 'commit -m'
git config --global alias.co 'checkout'
git config --global alias.st 'status'
git config --global alias.ciam 'commit --amend'
git config --global alias.ciamne 'commit --amend --no-edit'
git config --global user.name 'Jean-Marie Comets'
git config --global user.email 'jean.marie.comets@gmail.com'
git config --global color.ui 'auto'

# vim: ft=sh et sw=4 sts=4
