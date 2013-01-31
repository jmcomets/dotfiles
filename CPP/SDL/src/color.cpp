#include <color.h>

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a):
    _alpha(a)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
}

Color::~Color()
{
}
