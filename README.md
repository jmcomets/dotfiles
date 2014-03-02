jmcomets' dotfiles
==================

![Pimp My Console][]

## Features

- *awesome* Vim configuration
- customized bash/zsh prompt (using the [solarized][] theme)

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
~/.dotfiles/Dotfiles/configure.sh # setup links
```

[Pimp My Console]: ../../blob/master/Misc/pimp-my-console.png?raw=true
[aliases]: ../../blob/master/Dotfiles/Shell/aliases
[solarized]: https://github.com/altercation/solarized
