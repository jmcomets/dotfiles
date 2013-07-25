jmcomets' projects
==================

Just a little repository holding a few projects / useful files
that I like to have closeby (including Vim configuration).

Installation
------------

Clone this repo, including the submodules:

    git clone --recursive https://github.com/jmcomets/projects.git Projects

_Note_: if you choose to clone the repo elsewhere, note that there is a
shell alias to cd to ~/Projects, defined in .bash/aliases (and for zsh).

Run the installation script (you may want to backup your ~/.*rc files,
which will be overwritten by this script). This also sets up some extra
symbolink links (Bundle, Configs, .vim, .bash, .zsh):

    Projects/Configs/configure.sh
