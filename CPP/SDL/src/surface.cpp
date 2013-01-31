#include <surface.h>
#include <iostream>
using namespace std;

// Initialization of surfaces' flags
Uint32 Surface::Flags = SDL_SWSURFACE;

// Initialization of surfaces' default Bits Per Pixel
Uint8 Surface::Bpp = 32;

Surface::Surface(SDL_Surface * surface):
	_surface(surface)
{
}

Surface::Surface(int w, int h, const Color & mask):
	_surface(0)
{
    _surface = SDL_CreateRGBSurface(Surface::Flags, w, h,
            Surface::Bpp, mask.r(), mask.g(), mask.b(), mask.a());
}

Surface::Surface(const Surface & s)
{
	copy(s);
}

Surface::~Surface()
{
	SDL_FreeSurface(_surface);
}

void Surface::copy(const Surface & s)
{
    _surface = SDL_ConvertSurface(s._surface, s._surface->format,
            Surface::Flags);
}

void Surface::free()
{
    if (_surface != 0)
    {
        SDL_FreeSurface(_surface);
        _surface = 0;
    }
}

void Surface::update()
{
    SDL_Flip(_surface);
}

SDL_Surface * Surface::duplicate()
{
    if (_surface != 0)
    {
        _surface->refcount++;
    }
    return _surface;
}

SDL_Surface * Surface::swap(SDL_Surface * surface)
{
    SDL_Surface * tmp = _surface;
    _surface = surface;
    return tmp;
}

void Surface::blit_to(const Surface & dst, Rect * dstrect,
        Rect * srcrect)
{
    SDL_Rect * dest = (dstrect != 0) ? dstrect->to_sdl() : 0;
    SDL_Rect * crop = (srcrect != 0) ? srcrect->to_sdl() : 0;
    SDL_BlitSurface(_surface, crop, dst._surface, dest);
}

Surface & Surface::operator=(const Surface & s)
{
	if (&s != this) { copy(s); }
	return *this;
}
