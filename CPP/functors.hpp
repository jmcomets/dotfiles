#ifndef FUNCTORS_H_INCLUDED_
#define FUNCTORS_H_INCLUDED_

namespace utilities
{

template <class T> struct plus
{
    T operator()(const T & t1, const T & t2) const
    {
        return t1 + t2;
    }
};

template <class T> struct minus
{
    T operator()(const T & t1, const T & t2) const
    {
        return t1 - t2;
    }
};

template <class T> struct multiplies
{
    T operator()(const T & t1, const T & t2) const
    {
        return t1 * t2;
    }
};

template <class T> struct divides
{
    T operator()(const T & t1, const T & t2) const
    {
        return t1 / t2;
    }
};

template <class T> struct less
{
    bool operator()(const T & t1, const T & t2) const
    {
        return t1 < t2;
    }
};

template <class T, class Compare = less<T> > struct largest
{
    T operator()(const T & t1, const T & t2) const
    {
        return Compare()(t1, t2) ? t2 : t1;
    }
};

template <class T, class Compare = less<T> > struct smallest
{
    T operator()(const T & t1, const T & t2) const
    {
        return Compare()(t1, t2) ? t1 : t2;
    }
};

} // namespace utilities

#endif // FUNCTORS_H_INCLUDED_
