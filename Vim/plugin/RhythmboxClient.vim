" RhythmboxClient script (source: https://gist.github.com/dhruvasagar/9047851)
if exists('g:loaded_rhythmbox')
  finish
endif
let g:loaded_rhythmbox = 1

if !executable('rhythmbox-client')
  "echoerr 'rhythmbox-client must be installed'
  finish
endif

function! s:RhythmboxClient(action)
  echohl String
  echom system('rhythmbox-client --' . a:action)[:-2]
  echohl None
endfunction

function! s:RhythmboxClientComplete(A,L,C)
  return map(split(system("rhythmbox-client --help | grep '^\\s*\\--' | grep " . a:A . " | awk '{print $1}'")), 'v:val[2:]')
endfunction

command! -bar -nargs=+ -complete=customlist,s:RhythmboxClientComplete Rhythmbox call s:RhythmboxClient(<q-args>)
command! -bar RhythmboxCurr call s:RhythmboxClient('print-playing')
command! -bar RhythmboxPlay call s:RhythmboxClient('play')
command! -bar RhythmboxPlayToggle call s:RhythmboxClient('play-pause')
command! -bar RhythmboxPause call s:RhythmboxClient('pause')
command! -bar RhythmboxNext call s:RhythmboxClient('next')
command! -bar RhythmboxPrev call s:RhythmboxClient('previous')
command! -bar -nargs=1 RhythmboxFile -complete=file call s:RhythmboxClient('play-uri', <q-args>)

nnoremap <silent> <leader>x :RhythmboxCurr<cr>
nnoremap <silent> <leader>xn :RhythmboxNext <bar> :RhythmboxCurr<cr>
nnoremap <silent> <leader>xb :RhythmboxPrev <bar> :RhythmboxCurr<cr>
nnoremap <silent> <leader>xp :RhythmboxPlayToggle<cr>
