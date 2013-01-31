#ifndef FUNCTORS_H_INCLUDED_
#define FUNCTORS_H_INCLUDED_

namespace Bundle
{
    template <typename _Tp>
        struct Less
    {
        bool operator()(const _Tp & left, const _Tp & right) const
        {
            return left < right;
        }
    };

    template <typename _Tp>
        struct More
    {
        bool operator()(const _Tp & left, const _Tp & right) const
        {
            return left > right;
        }
    };

    template <typename _Tp>
        struct Plus
    {
        _Tp operator()(const _Tp & left, const _Tp & right) const
        {
            return left + right;
        }
    };

    template <typename _Tp>
        struct Minus
    {
        _Tp operator()(const _Tp & left, const _Tp & right) const
        {
            return left - right;
        }
    };
}

#endif
