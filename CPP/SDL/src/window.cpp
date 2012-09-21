#include <window.h>

Surface * Window::m_screen = 0;
Window::Flags Window::m_flags = Window::Fixed;

Surface * Window::create(int w, int h,
        Window::Flags flags, Uint8 bpp)
{
    Window::m_flags = flags;
    Surface::Bpp = bpp;
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    m_screen = new Surface(SDL_SetVideoMode(w, h, bpp,
                sdl_flags()));

    return m_screen;
}

void Window::destroy()
{
    if (m_screen != 0)
    {
        delete m_screen;
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void Window::resize(int w, int h)
{
    SDL_FreeSurface(m_screen->swap(
            SDL_SetVideoMode(w, h, Surface::Bpp, sdl_flags())
    ));
}

Uint32 Window::sdl_flags()
{
    Uint32 sdlflags = 0;
    switch (m_flags)
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
