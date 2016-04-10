" Vundle
set nocompatible
filetype off

" Set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin('~/.vim/extensions')

" Let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

Plugin 'FelikZ/ctrlp-py-matcher'
Plugin 'kien/ctrlp.vim'
Plugin 'rking/ag.vim'
Plugin 'scrooloose/nerdtree', { 'for': 'NERDTreeToggle' }
Plugin 'tpope/vim-abolish'
Plugin 'tpope/vim-commentary'
Plugin 'tpope/vim-dispatch'
Plugin 'tpope/vim-eunuch'
Plugin 'tpope/vim-fugitive'
Plugin 'tpope/vim-repeat'
Plugin 'tpope/vim-surround'
Plugin 'tpope/vim-unimpaired'

Plugin 'argtextobj.vim'
Plugin 'matchit.zip'
Plugin 'python_match.vim'

" Plugins
call vundle#end()
filetype plugin indent on

" CtrlP
let g:ctrlp_cmd = 'CtrlP'
let g:ctrlp_map = '<leader><leader>'
let g:ctrlp_working_path_mode = 'ra'
let g:ctrlp_extensions = ['tag', 'quickfix', 'line', 'mixed']
let g:ctrlp_match_func = { 'match': 'pymatcher#PyMatch' }
nmap <leader>u :CtrlPMRUFiles<cr>
nmap <leader>j :CtrlPBuffer<cr>
nmap <leader>l :CtrlPLine<cr>
" extra setup if "ag" command is available
if executable('ag')
    let g:ctrlp_user_command = 'ag %s -i --nocolor --nogroup --hidden -g ""'
endif

" Ag

" NERDTree
let NERDTreeChDirMode = 2
let NERDTreeIgnore = [
            \ '\.o$', '\.gch$', '\~$', '\.pyc$', '\.swp$',
            \ '\.acn$', '\.aux$', '\.glo$', '\.glsdefs$', '\.ist$', '\.out$', '\.toc$'
            \ ]
let NERDTreeShowBookmarks = 1
nmap <silent> <leader>e :NERDTreeToggle<cr>

" UltiSnips
let g:UltiSnipsJumpForwardTrigger="<tab>"
let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
let g:UltiSnipsEditSplit = "horizontal"

" Golden view
let g:goldenview__enable_default_mapping = 0

" Dispatch
nmap <silent> <leader>m :Make<cr>

" Tagbar
"nmap <silent> <leader>t :Tagbar<cr>
