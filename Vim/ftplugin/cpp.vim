" Setup correct display
setlocal omnifunc=omni#cpp#complete#Main
setlocal foldmethod=syntax
setlocal path+=/usr/include/c++/4.7/*
setlocal completeopt=menuone,menu,longest,preview
setlocal commentstring=//\ %s

" Clang completion fixes
let g:clang_use_library = 1
setlocal include=^\\s*#\\s*include\ \\(<boost/\\)\\@!

" Build Ctags with Ctrl-F12
nmap <buffer> <C-F12> :!ctags -R --sort=yes --c++-kinds=+px-d --fields=+iaS --extra=+q .<cr>

" OmniCppComplete plugin
let OmniCpp_DefaultNamespaces   = []
let OmniCpp_GlobalScopeSearch   = 1
let OmniCpp_NamespaceSearch     = 1
let OmniCpp_ShowPrototypeInAbbr = 1
let OmniCpp_ShowAccess          = 1
let OmniCpp_MayCompleteArrow    = 0
let OmniCpp_MayCompleteScope    = 0
let OmniCpp_MayCompleteDot      = 0

" Format with astyle
command! -buffer -nargs=0 Format call system('astyle ' . shellescape(expand('%'), 1)) | edit

" Use the "build" directory if there's a CMakeLists.txt
if filereadable("CMakeLists.txt") && isdirectory("build")
    setlocal makeprg=make\ -C\ build
endif
