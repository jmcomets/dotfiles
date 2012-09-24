#include <surface.h>
#include <iostream>
using namespace std;

// Flags available for surface format:
//
// SDL_ANYFORMAT   Allow any pixel-format *
// SDL_ASYNCBLIT   Use asynchronous blit if possible
// SDL_DOUBLEBUF   Double buffered *
// SDL_HWACCEL     Use hardware acceleration blit
// SDL_HWPALETTE   Have an exclusive palette
// SDL_HWSURFACE   Stored in video memory
// SDL_FULLSCREEN  Full screen surface *
// SDL_OPENGL      Have an OpenGL context *
// SDL_OPENGLBLIT  Support OpenGL blitting *.
// SDL_RESIZABLE   Resizable surface *
// SDL_RLEACCEL    Accelerated colorkey blitting with RLE
// SDL_SRCALPHA    Use alpha blending blit
// SDL_SRCCOLORKEY Use colorkey blitting
// SDL_SWSURFACE   Stored in the system memory.
// SDL_PREALLOC    Use preallocated memory
//
// Initialization of surfaces' flags
Uint32 Surface::Flags = SDL_SWSURFACE;

// Initialization of surfaces' default Bits Per Pixel
Uint8 Surface::Bpp = 32;

Surface::Surface(SDL_Surface * surface):
	m_surface(surface)
{
}

Surface::Surface(int w, int h, const Color & mask):
	m_surface(0)
{
    m_surface = SDL_CreateRGBSurface(Surface::Flags, w, h,
            Surface::Bpp, mask.r(), mask.g(), mask.b(), mask.a());
}

Surface::Surface(const Surface & s)
{
	copy(s);
}

Surface::~Surface()
{
	SDL_FreeSurface(m_surface);
}

void Surface::copy(const Surface & s)
{
    m_surface = SDL_ConvertSurface(s.m_surface, s.m_surface->format,
            Surface::Flags);
}

void Surface::free()
{
    if (m_surface != 0)
    {
        SDL_FreeSurface(m_surface);
        m_surface = 0;
    }
}

void Surface::update()
{
    SDL_Flip(m_surface);
}

SDL_Surface * Surface::duplicate()
{
    if (m_surface != 0)
    {
        m_surface->refcount++;
    }
    return m_surface;
}

SDL_Surface * Surface::swap(SDL_Surface * surface)
{
    SDL_Surface * tmp = m_surface;
    m_surface = surface;
    return tmp;
}

void Surface::blit_to(const Surface & dst, Rect * dstrect,
        Rect * srcrect)
{
    SDL_Rect * dest = (dstrect != 0) ? dstrect->to_sdl() : 0;
    SDL_Rect * crop = (srcrect != 0) ? srcrect->to_sdl() : 0;
    SDL_BlitSurface(m_surface, crop, dst.m_surface, dest);
}

Surface & Surface::operator=(const Surface & s)
{
	if (&s != this)
	{
		copy(s);
	}
	return *this;
}
