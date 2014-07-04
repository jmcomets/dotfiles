" Ruby is prettier with 2 spaces
setlocal expandtab
setlocal shiftwidth=2
setlocal softtabstop=2
setlocal tabstop=2
setlocal nolist

" Run current file
nmap <buffer> <F5> :!ruby %<cr>
