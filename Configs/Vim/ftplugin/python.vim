" Force PEP8's recommended settings
setlocal expandtab
setlocal tabstop=8
setlocal softtabstop=4
setlocal shiftwidth=4

" Prevent "#" to go to the start of the line
setlocal nosmartindent

" Set correct folding method
setlocal foldmethod=indent

" Auto-completion
setlocal omnifunc=pythoncomplete#Complete
setlocal tags+=~/.vim/tags/python

" Use :make for syntax checking (using pylint)
setlocal makeprg=pylint\ --reports=n\ --output-format=parseable\ %:p
setlocal errorformat=%f:%l:\ %m

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
