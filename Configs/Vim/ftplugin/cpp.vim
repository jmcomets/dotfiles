if has("autocmd")
    autocmd FileType cpp setl omnifunc=omni#cpp#complete#Main
    autocmd FileType c,cpp setl foldmethod=syntax
endif

" Fswitch
nmap <silent> <leader>of :FSHere<cr>
nmap <silent> <leader>ol :FSRight<cr>
nmap <silent> <leader>oL :FSSplitRight<cr>
nmap <silent> <leader>oh :FSLeft<cr>
nmap <silent> <leader>oH :FSSplitLeft<cr>
nmap <silent> <leader>ok :FSAbove<cr>
nmap <silent> <leader>oK :FSSplitAbove<cr>
nmap <silent> <leader>oj :FSBelow<cr>
nmap <silent> <leader>oJ :FSSplitBelow<cr>

" Ctag locations
set tags+=~/.vim/tags/cpp
"set tags+=~/.vim/tags/boost
"set tags+=~/.vim/tags/gl
"set tags+=~/.vim/tags/sdl
set tags+=~/.vim/tags/sfml

" Build Ctags with Ctrl-F12
map <C-F12> :!ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q .<cr>

" OmniCppComplete
let OmniCpp_DefaultNamespaces=["std", "sf"]
let OmniCpp_GlobalScopeSearch=1
let OmniCpp_NamespaceSearch=1
let OmniCpp_ShowPrototypeInAbbr=1
let OmniCpp_ShowAccess=1
let OmniCpp_MayCompleteArrow=0
let OmniCpp_MayCompleteScope=0
let OmniCpp_MayCompleteDot=0

" Automatically open and close the popup menu / preview window
autocmd CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest,preview
