" ColorSwitcher plugin
"
" Open a temporary (scratch) buffer with mappings set to switch
" colorschemes while displaying the current one.

if &cp || exists('loaded_colorswitcher')
  finish
endif
if v:version < 700
  echoerr 'ColorSwitcher requires Vim >= 7'
  finish
endif
let loaded_colorswitcher = 1

function! s:GetColorschemes()
  let l:colorschemes = []
  let l:rtps = split(&runtimepath, ',')
  for rtp in l:rtps
    let l:colors_dir = rtp . '/colors'
    if isdirectory(l:colors_dir)
      let l:color_files = glob(l:colors_dir . '/*.vim', 0, 1)
      for f in l:color_files
        let l:color = substitute(f, '.*/colors/\(.*\)\.vim', '\1', 'g')
        let l:colorschemes += [l:color]
      endfor
    endif
  endfor
  return l:colorschemes
endfunction

" Command ':Cswitch' opens the "ColorSwitcher" buffer, refreshes its
" contents and sets up the mappings.
function! s:Cswitch(bang) " -------------- {{{
  TScratch
  resize 1
  augroup ColorSwitcher
      autocmd CursorMoved <buffer> execute 'colorscheme ' . getline('.')
  augroup END
  let l:failed = append(0, s:GetColorschemes())
  set nomodifiable
endfunction " ----------------------------------- }}}

command! -bang -nargs=0 Cswitch call s:Cswitch('<bang>')

" vim: sw=2 sts=2 ts=2 ft=vim et
