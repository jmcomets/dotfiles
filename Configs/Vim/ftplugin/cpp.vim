" Setup correct display
setl omnifunc=omni#cpp#complete#Main
setl foldmethod=syntax
setl path+=/usr/include/c++/4.7/*
setl completeopt=menuone,menu,longest,preview

" Clang completion fixes
let g:clang_use_library = 1
setl include=^\\s*#\\s*include\ \\(<boost/\\)\\@!

" Build Ctags with Ctrl-F12
nmap <C-F12> :!ctags -R --sort=yes --c++-kinds=+px-d --fields=+iaS --extra=+q .<cr>

" OmniCppComplete plugin
let OmniCpp_DefaultNamespaces   = []
let OmniCpp_GlobalScopeSearch   = 1
let OmniCpp_NamespaceSearch     = 1
let OmniCpp_ShowPrototypeInAbbr = 1
let OmniCpp_ShowAccess          = 1
let OmniCpp_MayCompleteArrow    = 0
let OmniCpp_MayCompleteScope    = 0
let OmniCpp_MayCompleteDot      = 0
