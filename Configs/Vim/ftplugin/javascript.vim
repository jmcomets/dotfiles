" Folding for JavaScript
" source: http://amix.dk/blog/post/19132
function! JavaScriptFold()
    setl foldmethod=syntax
    setl foldlevelstart=1
    syn region foldBraces start=/{/ end=/}/ transparent fold keepend extend
    function! FoldText()
        return substitute(getline(v:foldstart), '{.*', '{...}', '')
    endfunction
    setl foldtext=FoldText()
endfunction

if (has("autocmd"))
    autocmd FileType javascript call JavaScriptFold()
endif
