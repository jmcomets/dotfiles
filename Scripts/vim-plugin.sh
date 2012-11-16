# Installation script for Vim plugins
#
# vim: set ft=sh

git_submodule="/usr/bin/git submodule"
bundle="Configs/Vim/bundle"

$git_submodule add $1 $bundle/$2 || exit 1
$git_submodule init || exit 1
