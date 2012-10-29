" Vim syntax file
" Language:	C++
" Maintainer:	Ken Shan <ccshan@post.harvard.edu>
" Last Change:	2002 Jul 15

" For version 5.x: Clear all syntax items
" For version 6.x: Quit when a syntax file was already loaded
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

" Read the C syntax to start with
if version < 600
  so <sfile>:p:h/c.vim
else
  runtime! syntax/c.vim
  unlet b:current_syntax
endif

" C++ extentions
syn keyword cppStatement	new delete this friend using decltype
syn keyword cppAccess		public protected private
syn keyword cppType		    inline virtual explicit export bool wchar_t constexpr
syn keyword cppExceptions	throw try catch
syn keyword cppOperator		operator typeid
syn keyword cppOperator		and bitor or xor compl bitand and_eq or_eq xor_eq not not_eq
syn keyword cppStorageClass	mutable nullptr
syn keyword cppStructure	class typename template namespace
syn keyword cppBoolean		true false
syn match cppCast		    "\<\(const\|static\|dynamic\|reinterpret\)_cast\s*<"me=e-1
syn match cppCast		    "\<\(const\|static\|dynamic\|reinterpret\)_cast\s*$"

" The minimum and maximum operators in GNU C++
syn match cppMinMax "[<>]?"

" Default highlighting
hi def link cppAccess		    cppStatement
hi def link cppCast		        cppStatement
hi def link cppExceptions		Exception
hi def link cppOperator		    Operator
hi def link cppStatement		Statement
hi def link cppType		        Type
hi def link cppStorageClass	    StorageClass
hi def link cppStructure		Structure
hi def link cppBoolean		    Boolean

let b:current_syntax = "cpp"

" vim: ts=8
