" Strip plugin
"
" Strip leading/trailing/all whitespace in the current buffer
if v:version < 700 || exists('g:loaded_strip') || &cp
  finish
endif
let g:loaded_strip = 1

" Display an error message.
function! s:Warn(msg) " --- {{{
  echohl ErrorMsg
  echomsg a:msg
  echohl NONE
endfunction " ------------- }}}

" Strip -> strip trailing whitespace in current buffer
function! s:StripTrailingWS() " -------------- {{{
  execute '%substitute/\v\s+$//ge'
endfunction " ----------------------------------- }}}
command! -nargs=0 Strip call s:StripTrailingWS()

" StripLeading -> strip leading whitespace in current buffer
function! s:StripLeadingWS() " -------------- {{{
  execute '%substitute/\v^\s+//ge'
endfunction " ----------------------------------- }}}
command! -nargs=0 StripLeading call s:StripLeadingWS()

" StripAll -> strip all whitespace in current buffer
function! s:StripAllWS() " -------------- {{{
  execute '%substitute/\v\s+//ge'
endfunction " ----------------------------------- }}}
command! -nargs=0 StripAll call s:StripAllWS()

" vim: ft=vim et sw=2 sts=2 fdm=marker
