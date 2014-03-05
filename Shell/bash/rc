#!/bin/bash
#
# Main configuration for shell

# If not running interactively, don't do anything
if [ -z "$PS1" ]; then
  return
fi

# Autocorrect typos in path names when using `cd`
shopt -s cdspell

# Append to the history file, don't overwrite it
shopt -s histappend

# Check the window size after each command and, if necessary,
# Update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# Match all files and zero or more directories and subdirectories.
shopt -s globstar

# For setting history length see HISTSIZE and HISTFILESIZE
HISTSIZE=1000
HISTFILESIZE=2000

# Don't put duplicate lines or lines starting with space in the history.
HISTCONTROL=ignoreboth

# Make less more friendly for non-text input files
if [ -x /usr/bin/lesspipe ]; then
  eval "$(SHELL=/bin/sh lesspipe)"
fi

# Private bash runtime path
export BASHRTP=$HOME/.bash
# profile with helpers
source $BASHRTP/profile

# Global scripts
call /etc/bashrc
call /etc/bash_completion

# Extras
source $BASHRTP/colors
source $BASHRTP/completion/*

# Git prompt
call /usr/local/git/contrib/completion/git-completion.bash && \
  GIT_PS1_SHOWDIRTYSTATE=true

# vim: ft=sh et sw=2 sts=2
