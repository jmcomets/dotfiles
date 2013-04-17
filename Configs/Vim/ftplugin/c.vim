" Set correct folding
setl omnifunc=ccomplete#Complete
setl foldmethod=syntax

" Fswitch
nmap <silent> <leader>of :FSHere<cr>
nmap <silent> <leader>ol :FSRight<cr>
nmap <silent> <leader>oL :FSSplitRight<cr>
nmap <silent> <leader>oh :FSLeft<cr>
nmap <silent> <leader>oH :FSSplitLeft<cr>
nmap <silent> <leader>ok :FSAbove<cr>
nmap <silent> <leader>oK :FSSplitAbove<cr>
nmap <silent> <leader>oj :FSBelow<cr>
nmap <silent> <leader>oJ :FSSplitBelow<cr>

" Ctag locations
"set tags+=~/.vim/tags/c
"set tags+=~/.vim/tags/sdl
"set tags+=~/.vim/tags/gl
