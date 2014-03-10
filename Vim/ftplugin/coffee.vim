" CS is prettier with 2 spaces
setlocal expandtab
setlocal shiftwidth=2
setlocal softtabstop=2

" Compile current file
nmap <buffer> <F5> :!coffee -c %<cr>
