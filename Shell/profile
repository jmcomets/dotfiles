#!/bin/sh
#
# Configuration for shell profile,
# sourced by all shells.

# Prefer US English and use UTF-8
export LC_ALL=en_US.UTF-8
export LANG=UTF-8

# Vim as standard editor
export EDITOR=vim

# Colored man pages
export LESS_TERMCAP_mb=$'\E[01;31m'
export LESS_TERMCAP_md=$'\E[01;38;5;74m'
export LESS_TERMCAP_me=$'\E[0m'
export LESS_TERMCAP_se=$'\E[0m'
export LESS_TERMCAP_so=$'\E[38;33;246m'
export LESS_TERMCAP_ue=$'\E[0m'
export LESS_TERMCAP_us=$'\E[04;38;5;146m'

# Add directory to path (if it exists)
add_to_path()
{
  if [ -d "$1" ] ; then
    export PATH="$1:$PATH"
    return 0
  else
    return 1
  fi
}

# Source shell script (if it exists)
call()
{
  if [ -f "$1" ] ; then
    . "$1"
    return $?
  else
    return 1
  fi
}

# Add bin directories
add_to_path $HOME/.local/bin
add_to_path $HOME/bin

# Shell aliases
call $HOME/.aliases

# base16
BASE16_SHELL="$HOME/.config/base16-shell"
[ -d "$BASE16_SHELL" ] && \
  [ -n "$PS1" ] && \
  [ -s "$BASE16_SHELL/profile_helper.sh" ] && \
  eval "$("$BASE16_SHELL/profile_helper.sh")"

# virtualenvwrapper
#call /usr/local/bin/virtualenvwrapper.sh

# cargo
add_to_path $HOME/.cargo/bin

# rvm
add_to_path $HOME/.rvm/bin && call $HOME/.rvm/scripts/rvm

# nvm
export NVM_DIR=$HOME/.nvm && call $NVM_DIR/nvm.sh

# android sdk
add_to_path $HOME/.local/share/android-sdk/tools
add_to_path $HOME/.local/share/android-sdk/platform-tools

# heroku
add_to_path /usr/local/heroku/bin

# sccache
export RUSTC_WRAPPER=`which sccache`

# vim: ft=sh et sw=2 sts=2
