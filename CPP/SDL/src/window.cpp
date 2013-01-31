#include <window.h>

Surface * Window::_screen = 0;
Window::Flags Window::_flags = Window::Fixed;

Surface * Window::create(int w, int h,
        Window::Flags flags, Uint8 bpp)
{
    Window::_flags = flags;
    Surface::Bpp = bpp;
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    _screen = new Surface(SDL_SetVideoMode(w, h, bpp,
                sdl_flags()));

    return _screen;
}

void Window::destroy()
{
    if (_screen != 0)
    {
        delete _screen;
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void Window::resize(int w, int h)
{
    SDL_FreeSurface(_screen->swap(
            SDL_SetVideoMode(w, h, Surface::Bpp, sdl_flags())
    ));
}

Uint32 Window::sdl_flags()
{
    Uint32 sdlflags = 0;
    switch (_flags)
    {
        case Window::Fixed:
            break;

        case Window::Resizable:
            sdlflags = SDL_RESIZABLE;
            break;

        case Window::FullScreen:
            sdlflags = SDL_FULLSCREEN;
            break;

        default:
            break;
    }
    return sdlflags;
}
