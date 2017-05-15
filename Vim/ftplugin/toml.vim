compiler cargo

if !exists('g:rustup_default')
    let g:rustup_default = 'stable'
endif

execute 'setlocal makeprg=rustup\ run\ ' . g:rustup_default . '\ cargo\ $*'

setlocal wildignore+=target
