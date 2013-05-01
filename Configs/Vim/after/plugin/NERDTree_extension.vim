" NERDTree customization, moved to another file for
" cleaner edit and because of its size
"
" Author: Jean-Marie Comets
" Date: 2013 May 1

if exists("g:loaded_nerdtree_extension")
    finish
endif
let g:loaded_nerdtree_extension = 1

" Change CWD along with NERDTree
let NERDTreeChDirMode = 2

" Files to ignore
let NERDTreeIgnore = ['\.o$', '\.gch$', '\~$', '\.pyc$', '\.swp$']

" Display bookmarks
let NERDTreeShowBookmarks = 1

" Mapping for NERDTree : <F3>
nmap <silent> <F3> :NERDTreeToggle<cr>
imap <F3> <C-o><F3>

" Added keymap for executing a script : <F5>
call NERDTreeAddKeyMap({
       \ 'key': '<F5>',
       \ 'callback': 'NERDTreeExecuteHandler',
       \ 'quickhelpText': 'Execute the current file node',
       \ 'scope': 'FileNode'})
function! NERDTreeExecuteHandler(filenode)
    echo system(a:filenode.path.str({'escape': 1}))
endfunction
