" Setup correct display
setl omnifunc=omni#cpp#complete#Main
setl foldmethod=syntax
set path+=/usr/include/c++/4.7/*

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
"set tags+=~/.vim/tags/sdl
"set tags+=~/.vim/tags/gl
"set tags+=~/.vim/tags/sfml
set tags+=~/.vim/tags/sfml2
"set tags+=~/.vim/tags/box2d

" Clang completion speedup
let g:clang_use_library = 1

" Fix for boost
set include=^\\s*#\\s*include\ \\(<boost/\\)\\@!

" Build Ctags with Ctrl-F12
nmap <C-F12> :!ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q .<cr>

" OmniCppComplete
let OmniCpp_DefaultNamespaces = ["std"]
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_NamespaceSearch = 1
let OmniCpp_ShowPrototypeInAbbr = 1
let OmniCpp_ShowAccess = 1
let OmniCpp_MayCompleteArrow = 0
let OmniCpp_MayCompleteScope = 0
let OmniCpp_MayCompleteDot = 0
set completeopt=menuone,menu,longest,preview
