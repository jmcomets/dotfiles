#include <color.h>

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a):
    m_alpha(a)
{
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
}

Color::~Color()
{
}
