jmcomets' projects
==================

Repository holding useful files I like to keep in remote access
(mainly Vim configuration, Bash configuration/prompt and a few scripts).

## Installation

### From a basic machine:

Clone this repo:

    # basic clone
    git clone https://github.com/jmcomets/projects.git ~/Projects

    # including the submodules
    git clone --recursive https://github.com/jmcomets/projects.git ~/Projects

__Note__: if you choose to clone the repo elsewhere, note that there is a
shell alias to cd to ~/Projects, defined in .bash/aliases.

Run the installation script (you may want to backup your ~/.\*rc files,
which will be overwritten by this script). This also sets up some extra
symbolink links (Bundle, Configs, .vim, .bash, etc...):

    Projects/Configs/configure.sh # setup links

### From an "empty" machine:

The `install.sh` script (in Configs) will do the big installation,
provided you can type on the following command:

    wget -q0- https://raw.github.com/jmcomets/projects/master/Configs/install.sh | sudo sh

This will install some basic packages (build-essential, vim, git, etc...), as well as
PIP (python package manager), a few cool python packages, NodeJS/NPM and some
web development utilities (bower, grunt-cli, etc...).
