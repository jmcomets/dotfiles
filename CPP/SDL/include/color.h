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
            { return _color.r; }
        inline Uint8 b() const
            { return _color.b; }
        inline Uint8 g() const
            { return _color.g; }
        inline Uint8 a() const
            { return _alpha; }
        inline SDL_Color * to_sdl()
            { return &_color; }
    private:
        SDL_Color _color;
        Uint8 _alpha;
};

#endif // COLOR_H_INCLUDED_
