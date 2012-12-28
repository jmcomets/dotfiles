" Prevent "#" to go to the start of the line
set nosmartindent

" Set correct folding method
set foldmethod=indent

" Auto-completion
set omnifunc=pythoncomplete#Complete
set tags+=~/.vim/tags/python

" Quickfix configuration (error formatting and result of ":make")
set errorformat=%C\ %.%#,%A\ \ File\ \"%f\"\\,\ line\ %l%.%#,%Z%[%^\ ]%\\@=%m
set makeprg=python

" SuperTab
let g:SuperTabDefaultCompletionType = "context"
