#ifndef COLOR_H_INCLUDED_
#define COLOR_H_INCLUDED_

struct Color
{
    Color(Uint32 red = 0, Uint32 green = 0,
            Uint32 blue = 0, Uint32 alpha = 0);
    virtual ~Color();
    Uint32 r, g, b, a;
};

#endif // COLOR_H_INCLUDED_
