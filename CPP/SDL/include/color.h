#ifndef COLOR_H_INCLUDED_
#define COLOR_H_INCLUDED_

#include <SDL/SDL.h>

class Color
{
    public:
        Color(Uint8 red = 0, Uint8 green = 0,
                Uint8 blue = 0, Uint8 alpha = 0);
        virtual ~Color();
        inline Uint8 r() const
            { return m_color.r; }
        inline Uint8 b() const
            { return m_color.b; }
        inline Uint8 g() const
            { return m_color.g; }
        inline Uint8 a() const
            { return m_alpha; }
        inline SDL_Color * to_sdl()
            { return &m_color; }
    private:
        SDL_Color m_color;
        Uint8 m_alpha;
};

#endif // COLOR_H_INCLUDED_
