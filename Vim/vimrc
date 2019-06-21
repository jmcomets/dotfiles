" The "m" at the end of Vi
set nocompatible

" Windows / UNIX compatibility
let s:is_windows = (has('win32') || has('win64')) && &shellcmdflag =~ '/'
let s:vim_dir = s:is_windows ? $VIM . '/vimfiles' : $HOME . '/.vim'

let $VIMDIR = s:vim_dir

if s:is_windows
    let $BUNDLE = $USERPROFILE . '/Bundle'
else
    let $BUNDLE = $HOME . '/Bundle'
endif

" Plugins
filetype off

call plug#begin(s:vim_dir . '/bundle')

" obligatory Tim Pope plugins
Plug 'tpope/vim-commentary'
Plug 'tpope/vim-eunuch'
Plug 'tpope/vim-fugitive'
Plug 'tpope/vim-repeat'
Plug 'tpope/vim-rsi'
Plug 'tpope/vim-unimpaired'
"Plug 'tpope/vim-dispatch'
Plug 'tpope/vim-surround'

" window management
"Plug 'roman/golden-ratio'

" fuzzy finder
Plug 'ctrlpvim/ctrlp.vim'
Plug 'FelikZ/ctrlp-py-matcher'

" navigation
Plug 'dietsche/vim-lastplace'
Plug 'tmhedberg/matchit'
Plug 'vim-scripts/python_match.vim'
Plug 'mileszs/ack.vim', { 'on': 'Ack' }

" editing
"Plug 'argtextobj.vim'
"Plug 'chrisbra/NrrwRgn'
Plug 'christoomey/vim-sort-motion'
Plug 'idanarye/vim-casetrate'
Plug 'junegunn/vim-easy-align'
Plug 'zhaocai/GoldenView.Vim'

" IDE features
"Plug 'Valloric/YouCompleteMe', { 'do': './install.py --clang-completer --rust-completer' }
"Plug 'w0rp/ale'
"Plug 'SirVer/ultisnips'

" colorschemes
"Plug 'marciomazza/vim-brogrammer-theme'
"Plug 'w0ng/vim-hybrid'
"Plug 'altercation/vim-colors-solarized'
Plug 'vim-scripts/wombat256.vim'
Plug 'flazz/vim-colorschemes'
Plug 'danielwe/base16-vim'

" not used often, but better than the default
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }

" org-mode for Vim
" Plug 'tpope/vim-speeddating'
" Plug 'jceb/vim-orgmode'

" xolox, used for various utilities (:Open, parallel commands)
Plug 'xolox/vim-misc'
Plug 'xolox/vim-shell'

" Extra syntaxes
Plug 'rust-lang/rust.vim'
Plug 'cespare/vim-toml'

" C++ plugins
Plug 'octol/vim-cpp-enhanced-highlight', { 'for': 'cpp' }

" Rust plugins
"Plug 'racer-rust/vim-racer', { 'for': 'rust'}

" Haskell plugins
"Plug 'Shougo/vimproc.vim'
"Plug 'eagletmt/ghcmod-vim'
"Plug 'eagletmt/neco-ghc'

" Clojure plugins
"Plug 'tpope/vim-classpath'
"Plug 'tpope/vim-fireplace'
"Plug 'tpope/vim-salve'

call plug#end()

filetype plugin indent on

" Leader is "<space>"
let mapleader = "\<space>"

" Sets how many lines of history Vim has to remember
set history=1000

" Reload buffer when its file is changed from the outside
set autoread

" Set UTF8 as standard encoding
set encoding=utf8

" Use Unix as the standard file type
set fileformats=unix,dos,mac

" Disable backup/swap
set nobackup
set nowritebackup
set noswapfile

" Add "$" at end of "change" nouns
set cpoptions+=$

" Set extra options when running in GUI mode
if has('gui_running')
    set guitablabel=%M\ %t
    set guioptions-=r
    set guioptions-=R
    set guioptions-=l
    set guioptions-=L
    set guioptions-=m
    set guioptions-=e
    set guioptions-=T
endif

" Remove startup message
set shortmess+=I

" Don't redraw while executing macros (good performance config)
set lazyredraw

" Title is name of current file
set title

" Set amount of lines above the cursor
set scrolloff=3

" Show line numbers, but relative
set number
set relativenumber

" Always show current position
set ruler

" Height of the command bar
set cmdheight=2

" Status line
set statusline=%t                               " tail of the filename
set statusline+=\ %m                            " modified flag
set statusline+=%h                              " help file flag
set statusline+=%r                              " read only flag
set statusline+=%y                              " filetype
set statusline+=[%{strlen(&fenc)?&fenc:'none'}] " file encoding
set statusline+=[%{&ff}]                        " file format
set statusline+=%=                              " left/right separator
set statusline+=%c,                             " cursor column
set statusline+=%l                              " cursor line
set statusline+=\ %P                            " percent through file

" Always put a status line in, even if there is only one window
set laststatus=2

" Turn on the Wild menu
set wildmenu

" Behave shell-like when completing shell
set wildmode=longest,list

" Ignore compiled files and backups
set wildignore=
set wildignore+=*~
set wildignore+=*.o
set wildignore+=*.class
set wildignore+=*.pyc
set wildignore+=*.gch
set wildignore+=*.obj
set wildignore+=*.pdb
set wildignore+=*.lib
set wildignore+=*.arg
set wildignore+=target
set wildignore+=venv

" Virtual edit
set virtualedit=
set whichwrap+=<,>,h,l " disabled when virtualedit

" Backspace unindents and joins lines
set backspace=start,indent,eol

" Don't notify any errors
set noerrorbells
set visualbell
set t_vb=
set timeoutlen=500

" Hide the mouse pointer while typing
set mousehide

" Mouse activated
set mouse=a

" Enable syntax highlighting
syntax enable

" Enable modeline
set modeline

" Show matching brackets when text indicator is over them
set showmatch

" How many tenths of a second to blink when matching brackets
set matchtime=2

" Default fold method
set foldmethod=indent

" Max number of fold levels
set foldnestmax=10

" Folding everything (disable at start)
set nofoldenable

" Again, folding parent levels
set foldlevel=1

" Default complete function
set omnifunc=syntaxcomplete#Complete

" Complete menu
set completeopt=menuone,preview

" Use spaces instead of tabs
set expandtab

" Be smart when using tabs
set smarttab

" Indent by 4 spaces/tabs
set shiftwidth=4
set softtabstop=4
set tabstop=4

" Round indent to multiple of tabstop/shiftwidth
set shiftround

" Invisible characters
set list listchars=tab:>-,trail:.,extends:>
set showbreak=>\

" Explicit FTW
set autoindent
set smartindent
set wrap

" Regex magic
set magic

" Ignore case
set ignorecase

" Try to be smart about cases
set smartcase

" Highlight results
set hlsearch

" Makes search act like in modern browsers
set incsearch
set wrapscan

" Colors in tmux
if exists('$TMUX') && exists('+termguicolors')
    let &t_8f = "\<Esc>[38;2;%lu;%lu;%lum"
    let &t_8b = "\<Esc>[48;2;%lu;%lu;%lum"
    set termguicolors
endif

" Colorscheme (base16)
if filereadable($HOME . '/.vimrc_background')
    let base16colorspace = 256
    execute 'source ' . $HOME . '/.vimrc_background'
endif

" GUI font
if has('gui_running')
    if s:is_windows
        set guifont=Consolas:h12:cANSI
    else
        set guifont=Consolas\ 12
    endif
endif

" A buffer becomes hidden when it is abandoned
set hidden

" Specify the behavior when switching between buffers
set switchbuf=useopen,usetab

" Tab display
set showtabline=0

" Split towards the right
set splitright

" Windows fixes
if s:is_windows != 0
    set shellslash
    set isfname+=\
    set grepprg=grep\ -n
endif

" Treat long lines as break lines (useful when moving around in them)
nnoremap j gj
nnoremap k gk
" new feature
"nnoremap <silent> <expr> j (v:count == 0 ? 'gj' : 'j')
"nnoremap <silent> <expr> k (v:count == 0 ? 'gk' : 'k')

" Faster <esc>
"cmap jk <C-c> | cmap kj <C-c>
"imap jk <C-[> | imap kj <C-[>

" Console up/down/left/right navigation
cmap <C-j> <down>
cmap <C-k> <up>
cmap <C-h> <left>
cmap <C-l> <right>

" Disable search highlighting
nnoremap <silent> <C-l> <C-l>:nohlsearch<cr>

" Remap Vim 0 to first non-blank character
nmap 0 ^

" Exchange "`" and "'"
nnoremap ' `
nnoremap ` '

" Resolve inconsistency between "Y" (line), and "D" (eol)
"nmap D dd
nmap Y y$

" Visual mode indenting: keep selection after indenting
vmap > >gv
vmap < <gv

" Visual mode incrementing: better default
vnoremap g<C-a> <C-a>
vnoremap <C-a> g<C-a>
" don't invert decrementing for saner usage
"vnoremap g<C-x> <C-x>
"vnoremap <C-x> g<C-x>

" Select pasted text with gV
nmap gV `[v`]

" Replace current word
nmap <leader>r :%s/\v<<C-r><C-w>>//gc<left><left><left>

" Fast saving
nmap <silent> <leader>w :write<bar>nohlsearch<cr>

" Close this buffer
nnoremap <silent> <leader>bd :Bclose!<cr>

" Close all open buffers
nnoremap <silent> <leader>ba :BcloseAll<cr>

" Only keep this buffer open
nnoremap <silent> <leader>bo :Bonly<cr>

" Close current window
nmap <silent> <leader>q :quit<cr>

" Run "make" (makeprg or compiler)
nmap <silent> <leader>m :make<cr>

" Cd to current file
nmap <silent> <leader>cd :cd %:p:h<cr>

" In command mode, insert "%:p" when typing "%%" (very useful)
cnoremap %% <C-r>=expand("%:p")<cr>
" and remove last path component if requested
cnoremap %%<C-w> <C-r>=expand("%:p:h")<cr>/

" Newline above in insert mode
imap <S-cr> <C-o>O

" Replace forward and backward slash
nmap <leader>\ :s-/-\\-g<bar>nohlsearch<cr>
nmap <leader>/ :s-\\-/-g<bar>nohlsearch<cr>
vmap <leader>\ :s-/-\\-g<bar>nohlsearch<cr>gv
vmap <leader>/ :s-\\-/-g<bar>nohlsearch<cr>gv

if executable('ag') | let &grepprg = 'ag --vimgrep' | endif
if executable('rg') | let &grepprg = 'rg --vimgrep' | endif

" Toggle paste mode
nmap <silent> cop :set paste!<cr>

" Copy to clipboard
nmap <leader>y "+y
vmap <leader>y "+y

" Open file copied in clipboard
nmap <silent> <leader>o :edit <C-r>+<cr>
" Copy current file to clipboard
nmap <silent> <leader>p :let @+ = expand('%:p')<cr>

" Open alternate file
nnoremap <silent> <leader>a :buffer #<cr>

" Star/Pound the visual selection
"vmap * "vy/\M<C-r>v<cr>
"vmap # "vy?\M<C-r>v<cr>

" Toggle the quickfix window
command! -bang -nargs=? QFixToggle call ToggleQuickfixWindow()
function! ToggleQuickfixWindow()
    if len(filter(range(winnr('$')), "getbufvar(winbufnr(v:val), '&buftype') == 'quickfix'")) > 0
        cclose
    else
        botright copen
    endif
endfunction
" and its mapping
nmap <silent> <leader>f :QFixToggle<cr>


" Clear the quickfix window
command! QFixClear call ClearQuickfixWindow()
function! ClearQuickfixWindow()
  call setqflist([])
endfunction

" Search for TODO in the current buffer
nmap <silent> ]j /\v<TODO><cr>
nmap <silent> [j ?\v<TODO><cr>

let g:hungarian_prefixes = ['ac', 'c', 'px', 'ppv', 'pv', 'sz', 'f', 'd', 'h', 'b']

function! ConvertHungarianNotation() range
    execute a:firstline . ',' . a:lastline
                \ . 'substitute/\v([^\w])('
                \ . join(g:hungarian_prefixes, '|')
                \ . ')([A-Z])/\1\L\3/gce'
endfunction
command! -range ConvertHungarian <line1>,<line2>call ConvertHungarianNotation()

" CtrlP
let g:ctrlp_cmd = 'CtrlP'
let g:ctrlp_map = '<leader><leader>'
let g:ctrlp_working_path_mode = 'ra'
let g:ctrlp_root_markers = ['Makefile', 'CMakeLists.txt', 'Cargo.toml']
let g:ctrlp_extensions = ['tag', 'quickfix', 'line', 'mixed']
nmap <silent> <leader>j :CtrlPBuffer<cr>
nmap <silent> <leader>u :CtrlPMRUFiles<cr>

" Ack
if exists(':Ack')
    if executable('ag') | let g:ackprg = 'ag --vimgrep' | endif
    if executable('rg') | let g:ackprg = 'rg --vimgrep' | endif
endif

" EasyAlign
vmap ga <Plug>(EasyAlign)
nmap ga <Plug>(EasyAlign)

" NR
"let g:nrrw_rgn_nomap_nr = 1
"let g:nrrw_rgn_nomap_Nr = 1

" Org
"nnoremap <silent> <leader>n :sp ~/Bundle/org/index.org<cr>
"nnoremap <silent> <leader>d :sp ~/Bundle/org/<C-r>=system('printf `date --iso-8601`')<cr>.org<cr>

" Casetrate
" "camel"  => camelCase
" "pascal" => PascalCase
" "snake"  => snake_case
" "upper"  => UPPER_CASE
" "mixed"  => Mixed_Case
let g:casetrate_leader = 'gw'

" CPP Enhanced Highlighting
let g:load_doxygen_syntax = 1
let g:cpp_class_scope_highlight = 1
"let g:cpp_experimental_template_highlight = 1

" Nerdtree
let NERDTreeRespectWildIgnore = 1
nmap <silent> <leader>s :NERDTreeToggle<cr>

" LaTeX-specification
let g:tex_flavor = "latex"

" ALE
let g:ale_sign_column_always = 1

" UltiSnips
let g:UltiSnipsExpandTrigger = "<tab>"
let g:UltiSnipsJumpForwardTrigger = "<tab>"
let g:UltiSnipsJumpBackwardTrigger = "<s-tab>"
let g:UltiSnipsEditSplit = "vertical"
let g:UltiSnipsSnippetDirectories = [s:vim_dir . '/ultisnips']

" GoldenView
let g:goldenview__enable_default_mapping = 0
let g:goldenview__enable_at_startup = 0
