augroup vim_filetype_autocommands
    " Remove all previous autocommands from this group
    autocmd!

    " Bash's vi-edition-mode "v" command editor window
    autocmd BufRead,BufNewFile bash-fc-* set filetype=sh

    " C / C++
    autocmd BufNewFile,BufRead,BufEnter *.ih set filetype=cpp
    autocmd BufNewFile,BufRead,BufEnter *.hpp set filetype=cpp
augroup END
