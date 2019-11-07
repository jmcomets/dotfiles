" NERDTree customization, moved to another file for
" cleaner edit and because of its size
"
" Author: Jean-Marie Comets
" Date: 2013 May 1

if exists("g:loaded_nerdtree_runfile") || !exists("loaded_nerd_tree")
    finish
endif
let g:loaded_nerdtree_runfile = 1

" Added keymap for executing a script : <F5>
call NERDTreeAddKeyMap({
       \ 'key': '<F5>',
       \ 'callback': 'NERDTreeExecuteHandler',
       \ 'quickhelpText': 'Execute the current file node',
       \ 'scope': 'FileNode'})
function! NERDTreeExecuteHandler(filenode)
    echo system(a:filenode.path.str({'escape': 1}))
endfunction
