" Bclose plugin
"
" Delete buffer while keeping window layout (don't close buffer's windows).
" Version 2008-11-18 from http://vim.wikia.com/wiki/VimTip165
if v:version < 700 || exists('g:loaded_bclose') || &cp
    finish
endif

let g:loaded_bclose = 1
if !exists('g:bclose_multiple')
    let g:bclose_multiple = 1
endif

" Display an error message.
function! s:Warn(msg) " --- {{{
    echohl ErrorMsg
    echomsg a:msg
    echohl NONE
endfunction " ------------- }}}

" Command ':Bclose' executes ':bd' to delete buffer in current window.
" The window will show the alternate buffer (Ctrl-^) if it exists,
" or the previous buffer (:bp), or a blank buffer if no previous.
" Command ':Bclose!' is the same, but executes ':bd!' (discard changes).
" An optional argument can specify which buffer to close (name or number).
function! s:Bclose(bang, buffer) " -------------- {{{
    if empty(a:buffer)
        let btarget = bufnr('%')
    elseif a:buffer =~ '^\d\+$'
        let btarget = bufnr(str2nr(a:buffer))
    else
        let btarget = bufnr(a:buffer)
    endif
    if btarget < 0
        call s:Warn('No matching buffer for '.a:buffer)
        return
    endif
    if empty(a:bang) && getbufvar(btarget, '&modified')
        call s:Warn('No write since last change for buffer '.btarget.' (use :Bclose!)')
        return
    endif
    " Numbers of windows that view target buffer which we will delete.
    let wnums = filter(range(1, winnr('$')), 'winbufnr(v:val) == btarget')
    if !g:bclose_multiple && len(wnums) > 1
        call s:Warn('Buffer is in multiple windows (use ":let g:bclose_multiple=1")')
        return
    endif
    let wcurrent = winnr()
    for w in wnums
        execute w.'wincmd w'
        let prevbuf = bufnr('#')
        if prevbuf > 0 && buflisted(prevbuf) && prevbuf != w
            buffer #
        else
            bprevious
        endif
        if btarget == bufnr('%')
            " Numbers of listed buffers which are not the target to be deleted.
            let blisted = filter(range(1, bufnr('$')), 'buflisted(v:val) && v:val != btarget')
            " Listed, not target, and not displayed.
            let bhidden = filter(copy(blisted), 'bufwinnr(v:val) < 0')
            " Take the first buffer, if any (could be more intelligent).
            let bjump = (bhidden + blisted + [-1])[0]
            if bjump > 0
                execute 'buffer '.bjump
            else
                execute 'enew'.a:bang
            endif
        endif
    endfor
    execute 'bdelete'.a:bang.' '.btarget
    execute wcurrent.'wincmd w'
endfunction " ----------------------------------- }}}
command! -bang -complete=buffer -nargs=? Bclose call s:Bclose('<bang>', '<args>')

" Closing all open buffers except for the current one:
function! s:CloseAllBuffersButCurrent()
    let curr = bufnr("%")
    let last = bufnr("$")

    if curr > 1    | silent! execute "1,".(curr-1)."bd"     | endif
    if curr < last | silent! execute (curr+1).",".last."bd" | endif
endfunction

command! -nargs=0 Bonly call s:CloseAllBuffersButCurrent()

function! s:CloseAllBuffers()
    execute "1," . bufnr("$") . "bdelete"
endfunction

command! -nargs=0 BcloseAll call s:CloseAllBuffers()

function! s:CloseBuffersFor(...)
    let buffers_to_close = []
    for bufinfo in getbufinfo()
        for regex in a:000
            let tail = fnamemodify(bufinfo['name'], ':t')
            if tail =~? regex
                "echo bufinfo['bufnr'] . ' ' . bufinfo['name'] . ' matches ' . regex
                call add(buffers_to_close, bufinfo['bufnr'])
                break
            endif
        endfor
    endfor

    if len(buffers_to_close) > 0
        call uniq(buffers_to_close)
        execute 'bdelete ' . join(buffers_to_close, ' ')
    endif
endfunction

command! -nargs=+ BcloseFor call s:CloseBuffersFor(<f-args>)

" vim: ft=vim et sw=4 sts=4 fdm=marker
