compiler cargo

setlocal wildignore+=target

if exists(':Make')
    nmap <buffer> <leader>m :Make build<cr>
    nmap <buffer> <leader>t :Make test<cr>
else
    nmap <buffer> <leader>m :make build<cr>
    nmap <buffer> <leader>t :make test<cr>
endif

if exists('g:LanguageClient_autoStart')
    nnoremap <buffer> <silent> K :call LanguageClient_textDocument_hover()<cr>

    nnoremap <buffer> <silent> gr :call LanguageClient_textDocument_references()\|lopen<cr>
    nnoremap <buffer> <silent> gd :call LanguageClient_textDocument_definition()<cr>

    nnoremap <buffer> <silent> <leader>lr :call LanguageClient_textDocument_rename()<cr>
endif
