compiler cargo

setlocal wildignore+=/target

if exists(':Make')
    nmap <buffer> <leader>m :Make build<cr>
    nmap <buffer> <leader>t :Make test<cr>
else
    nmap <buffer> <leader>m :make build<cr>
    nmap <buffer> <leader>t :make test<cr>
endif

