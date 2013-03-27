" Force PEP8's recommended settings
set expandtab
set tabstop=8
set softtabstop=4
set shiftwidth=4
"set textwidth=79
"set colorcolumn=80
match ErrorMsg '\%>80v.\+'

" Prevent "#" to go to the start of the line
set nosmartindent

" Set correct folding method
set foldmethod=indent

" Auto-completion
set omnifunc=pythoncomplete#Complete
set tags+=~/.vim/tags/python

" Make == run in interpreter
set makeprg=python\ %
