compiler cargo

if exists(':Make')
    nmap <buffer> <leader>t :Make test<cr>
else
    nmap <buffer> <leader>t :Make test<cr>
endif
