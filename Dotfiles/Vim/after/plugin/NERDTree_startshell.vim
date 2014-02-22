if exists("g:loaded_nerdtree_start_shell_mapping")
    finish
endif
let g:loaded_nerdtree_start_shell_mapping = 1

" Bind 'S' to NERDTreeStartShell()
call NERDTreeAddKeyMap({
            \ 'key': 'S',
            \ 'callback': 'NERDTreeStartShell',
            \ 'quickhelpText': 'Start a :shell in this directory' })

" Change to the dir of the current node and start a :shell
function! NERDTreeStartShell()
    " Grab the selected dir node (returns the parent dir if a file is selected)
    let n = g:NERDTreeDirNode.GetSelected()

    " Save the cwd so we can restore it after the :shell exits
    let oldCWD = getcwd()
    try
        " Use :lcd to to the selected dir and :shell out
        exec 'lcd ' . n.path.str({'format': 'Cd'})
        redraw!
        shell
    finally
        " Make sure we restore the cwd to its original state
        exec 'lcd ' . oldCWD
    endtry
endfunction
