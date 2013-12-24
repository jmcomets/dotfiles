jmcomets' projects
==================

![Pimp My Console](../../blob/master/Misc/pimp-my-console.png?raw=true)

## Features

- *awesome* Vim configuration
- customized bash/zsh prompt (using the [solarized][] theme)

## Installation

### From a basic machine:

Clone this repo:

```bash
# basic clone
git clone https://github.com/jmcomets/projects.git ~/Projects

# including the submodules (mainly Vim plugins)
git clone --recursive https://github.com/jmcomets/projects.git ~/Projects
```

__Note__: if you choose to clone the repo elsewhere, note that there is a
shell alias to cd to ~/Projects, defined in .bash/aliases.

Run the installation script (you may want to backup your ~/.\*rc files,
which will be overwritten by this script). This also sets up some extra
symbolink links (Bundle, .vim, .bash, etc...):

```bash
Projects/Dotfiles/configure.sh # setup links
```

[solarized]: https://github.com/altercation/solarized
