" Force PEP8's recommended settings
setl expandtab
setl tabstop=8
setl softtabstop=4
setl shiftwidth=4
"setl textwidth=79
"setl colorcolumn=80
"match ErrorMsg '\%>80v.\+'

" Prevent "#" to go to the start of the line
setl nosmartindent

" Set correct folding method
setl foldmethod=indent

" Auto-completion
setl omnifunc=pythoncomplete#Complete
setl tags+=~/.vim/tags/python

" Make == run in interpreter
setl makeprg=python\ %
