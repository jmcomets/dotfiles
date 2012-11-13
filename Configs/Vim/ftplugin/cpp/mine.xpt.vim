" Setting priority of cpp to "sub" or "subset of language", makes it override
" all c snippet if conflict
XPTemplate priority=personal

" Variables used by XPT

" Booleans
XPTvar $TRUE          true
XPTvar $FALSE         false
XPTvar $NULL          nullptr

" Linebreaks
XPTvar $BRif     \n
XPTvar $BRloop    \n
XPTvar $BRloop  \n
XPTvar $BRstc \n
XPTvar $BRfun   \n

" Misc
XPTvar $CURSOR_PH      /* cursor */

" Comments
XPTvar $CS   //
XPTvar $CL  /*
XPTvar $CM   *
XPTvar $CR   */

" ========================= Function and Variables ============================= "
let s:f = g:XPTfuncs()

function! s:f.cleanTempl(ctx, ...)
  let cleaned = substitute(a:ctx, '\s*\(class\|typename\|int\|long\)\s*', '', 'g')
  return cleaned
endfunction


" ================================= Snippets =================================== "

XPT class
class `className^
{
    public:
        `className^(`ctorParam^);
        `className^(const `className^ &);
        virtual ~`className^();
        `className^ & operator=(const `className^ &);

    private:
        `cursor^
}; // class `className^
..XPT

XPT functor
struct `structName^
{
    `closure...{{^`type^  `what^;
    `_^R('structName')^(`type^ n`what^) : `what^(n`what^) {}

    `}}^`outType^   operator() (`params^)
    {
        `cursor^
    }
}; // struct  `structName`
..XPT

XPT namespace
namespace `name^
{
    `cursor^
} // namespace `name^
..XPT

XPT tclass
template <`templateParam^> class `className^
{
    public:
        `className^(`ctorParam^)
        {
        }

        `className^(const `className^ & cpy)
        {
        }

        `className^ & operator=(const `className^ & cpy)
        {
        }

        ~`className^()
        {
        }

    private:
        `cursor^
}; // class `className^
..XPT

XPT try wrap=what
try
{
    `what^
}`$BRel^`Include:catch^

XPT catch
catch (`except^)
{
    `cursor^
}

XPT hg wrap
XSET HEADER=S(fileRoot(),'\.','_','g')
XSET HEADER|post=UpperCase(V())
#ifndef `HEADER^_H_INCLUDED_
#define `HEADER^_H_INCLUDED_

`cursor^ 

#endif `$CS^ `HEADER^_H_INCLUDED_
..XPT
