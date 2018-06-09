compiler cargo

if exists(':Make')
    nmap <buffer> <leader>m :Make build<cr>
    nmap <buffer> <leader>t :Make test<cr>
    nmap <buffer> <leader>g :Make run<cr>
else
    nmap <buffer> <leader>m :make build<cr>
    nmap <buffer> <leader>t :make test<cr>
    nmap <buffer> <leader>g :make run<cr>
endif
