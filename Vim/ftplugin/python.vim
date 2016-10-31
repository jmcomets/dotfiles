" Force PEP8's recommended settings
setlocal expandtab
setlocal tabstop=8
setlocal softtabstop=4
setlocal shiftwidth=4

" Prevent "#" to go to the start of the line
setlocal nosmartindent

" Set correct folding method
setlocal foldmethod=indent

" Autocommands
augroup python_autocommands
    autocmd!

    " Strip all spaces before writing
    autocmd BufWritePre *.py :%substitute/\v\s+$//ge
augroup END

" Run the file with python
nmap <buffer> <leader>t :!python %<cr>

" Find python command

" `gf` jumps to the filename under the cursor
function! s:AddPythonPath()
python << EOF
import os
import sys
import vim

for p in sys.path:
    if os.path.isdir(p):
        vim.command(r'set path+=%s' % (p.replace(' ', r'\ ')))
EOF
endfunction

function! s:AddPython3Path()
python3 << EOF
import os
import sys
import vim

for p in sys.path:
    if os.path.isdir(p):
        vim.command(r'set path+=%s' % (p.replace(' ', r'\ ')))
EOF
endfunction

if has('python')
    call s:AddPythonPath()
    setlocal omnifunc=pythoncomplete#Complete
elseif has('python3')
    call s:AddPython3Path()
    setlocal omnifunc=python3complete#Complete
end
