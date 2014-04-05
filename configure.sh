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
gconftool --load $DOTFILES/Shell/gnome-terminal.xml

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
git config --global alias.br 'branch'
git config --global alias.ci 'commit'
git config --global alias.cim 'commit -m'
git config --global alias.co 'checkout'
git config --global alias.cob 'checkout -b'
git config --global alias.st 'status'
git config --global alias.ciam 'commit --amend'
git config --global alias.ciamne 'commit --amend --no-edit'
git config --global user.name 'Jean-Marie Comets'
git config --global user.email 'jean.marie.comets@gmail.com'
git config --global color.ui 'auto'
git config --global push.default simple

# Tmux
setup_link $DOTFILES/Shell/tmux ~/.tmux.conf

# vim: ft=sh et sw=4 sts=4
