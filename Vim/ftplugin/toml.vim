compiler cargo

setlocal wildignore+=/target

if exists(':Make')
    nmap <buffer> <leader>t :Make test<cr>
else
    nmap <buffer> <leader>t :Make test<cr>
endif

