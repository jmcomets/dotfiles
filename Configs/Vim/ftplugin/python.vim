" Force PEP8's recommended settings
setl expandtab
setl tabstop=8
setl softtabstop=4
setl shiftwidth=4

" Prevent "#" to go to the start of the line
setl nosmartindent

" Set correct folding method
setl foldmethod=indent

" Auto-completion
setl omnifunc=pythoncomplete#Complete
setl tags+=~/.vim/tags/python

" Use :make to see syntax errors. (:cn and :cp to move around, :dist to see
" all errors)
set makeprg=python\ -c\ \"import\ py_compile,sys;\ sys.stderr=sys.stdout;\ py_compile.compile(r'%')\"
set errorformat=%C\ %.%#,%A\ \ File\ \"%f\"\\,\ line\ %l%.%#,%Z%[%^\ ]%\\@=%m

" `gf` jumps to the filename under the cursor
python << EOF
import os
import sys
import vim

for p in sys.path:
    if os.path.isdir(p):
        vim.command(r'set path+=%s' % (p.replace(' ', r'\ ')))
EOF

" Select a range in visual mode and execute it
python << EOL
import vim
def EvaluateCurrentRange():
    eval(compile('\n'.join(vim.current.range), '', 'exec'), globals())
EOL
vmap <buffer> <F5> :python EvaluateCurrentRange()<cr>

" Execute file being edited with <F5>
nmap <buffer> <F5> :!python %<cr>

" Use F7/Shift-F7 to add/remove a breakpoint (pdb.set_trace)
" Totally cool.
python << EOF
import re
import vim

def SetBreakpoint():
    nLine = int(vim.eval('line(".")'))
    strLine = vim.current.line
    strWhite = re.search('^(\s*)', strLine).group(1)
    vim.current.buffer.append(
       '%(space)spdb.set_trace() %(mark)s Breakpoint %(mark)s' %
         {'space': strWhite, 'mark': '#' * 30}, nLine - 1)
    for strLine in vim.current.buffer:
        if strLine == 'import pdb':
            break
    else:
        vim.current.buffer.append('import pdb', 0)
        vim.command('normal j1')

def RemoveBreakpoints():
    nCurrentLine = int(vim.eval('line(".")'))
    nLines = []
    nLine = 1
    for strLine in vim.current.buffer:
        if strLine == "import pdb" or strLine.lstrip()[:15] == "pdb.set_trace()":
            nLines.append(nLine)
        nLine += 1
    nLines.reverse()
    for nLine in nLines:
        vim.command('normal %dG' % nLine)
        vim.command('normal dd')
        if nLine < nCurrentLine:
            nCurrentLine -= 1
    vim.command('normal %dG' % nCurrentLine)
EOF

nmap <buffer> <silent> <F7> :python SetBreakpoint()<cr>
nmap <buffer> <silent> <S-F7> :python RemoveBreakpoints()<cr>
