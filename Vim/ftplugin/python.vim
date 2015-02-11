" Force PEP8's recommended settings
setlocal expandtab
setlocal tabstop=8
setlocal softtabstop=4
setlocal shiftwidth=4

" Prevent "#" to go to the start of the line
setlocal nosmartindent

" Set correct folding method
setlocal foldmethod=indent

" Auto-completion (using jedi-vim now)
setlocal omnifunc=pythoncomplete#Complete

" Use :make for syntax checking (using pylint)
"setlocal makeprg=pylint\ --reports=n\ --output-format=parseable\ %:p
"setlocal errorformat=%f:%l:\ %m

" `gf` jumps to the filename under the cursor
python << EOF
import os
import sys
import vim

for p in sys.path:
    if os.path.isdir(p):
        vim.command(r'set path+=%s' % (p.replace(' ', r'\ ')))
EOF

" Select a range in visual mode and execute it,
" otherwise execute entire buffer
python << EOL
import vim
def EvaluateCurrentRange():
    eval(compile('\n'.join(vim.current.range), '', 'exec'), globals())
EOL
vmap <buffer> <F5> :python EvaluateCurrentRange()<cr>
nmap <buffer> <F5> :!python %<cr>

" Add import with <leader>i
nmap <buffer> <leader>i ggoimport antigravity<esc>viw<C-g>
