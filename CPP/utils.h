#ifndef UTILS_H_INCLUDED_
#define UTILS_H_INCLUDED_

namespace Bundle
{
    template <typename _First, typename _Second>
        struct Pair
    {
        _First first;
        _Second second;

        typedef _First first_type;
        typedef _Second second_type;

        Pair(first_type f, second_type s):
            first(f), second(s)
        {
        }
    };
}

#endif
