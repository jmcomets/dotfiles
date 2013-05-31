" Force PEP8's recommended settings
setl expandtab
setl tabstop=8
setl softtabstop=4
setl shiftwidth=4

" Prevent "#" to go to the start of the line
setl nosmartindent

" Set correct folding method
setl foldmethod=indent

" Auto-completion
setl omnifunc=pythoncomplete#Complete
setl tags+=~/.vim/tags/python

" Execute file being edited with <F5>
nmap <buffer> <F5> :!python %<cr>

" Make -> check with pyflakes
setl makeprg=pyflakes\ %
