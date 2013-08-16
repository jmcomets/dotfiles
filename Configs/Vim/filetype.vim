augroup vim_filetype_autocommands
    " Remove all previous autocommands from this group
    autocmd!

    " Bash's vi-edition-mode "v" command editor window
    autocmd BufRead,BufNewFile bash-fc-* set filetype=sh

    " C / C++
    autocmd BufNewFile,BufRead,BufEnter *.ih set filetype=cpp
    autocmd BufNewFile,BufRead,BufEnter *.hpp set filetype=cpp

    " JSON / JavaScript
    autocmd BufNewFile,BufRead *.json set filetype=javascript

    " Pascal
    autocmd BufNewFile,BufRead *.pas,*.PAS set filetype=pascal

    " Go
    autocmd BufNewFile,BufRead *.go set filetype=go

    " Markdown
    autocmd BufNewFile,BufRead *.md set filetype=markdown

    " nGINX
    autocmd BufRead,BufNewFile /etc/nginx/*,/usr/local/nginx/conf/* if &ft == '' | setfiletype nginx | endif
augroup END
