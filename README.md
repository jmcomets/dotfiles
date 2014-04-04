jmcomets' dotfiles
==================

![Pimp My Console][]

## Features

- *awesome* Vim configuration
- customized shell prompt

## Installation

### From a basic machine:

Clone this repo:

```bash
# basic clone
git clone https://github.com/jmcomets/dotfiles.git ~/.dotfiles

# including the submodules (mainly Vim plugins)
git clone --recursive https://github.com/jmcomets/dotfiles.git ~/.dotfiles
```

Run the installation script (you may want to backup your ~/.\*rc files,
which will be overwritten by this script). This also sets up some extra
symbolic links (.vim, .zsh, .bash, etc...):

```bash
~/.dotfiles/configure.sh # setup links
```

## Scripts

A [simple vim plugin manager script] is available (command: vwp), but requires [docopt] to be used.
Alternatively symlinks can be created in [~/.vim/extensions], pointing to vim plugin directories
(I put them in [~/.vim/bundle]).

[Pimp My Console]: ../../blob/master/Misc/pimp-my-console.png?raw=true
[aliases]: ../../blob/master/Shell/aliases
[~/.vim/extensions]: ../../blob/master/Vim/extensions
[~/.vim/bundle]: ../../blob/master/Vim/bundle
[simple vim plugin manager script]: ../../blob/master/Bin/vwp
[docopt]: https://github.com/docopt/docopt
