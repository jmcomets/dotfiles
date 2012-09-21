#include <image.h>

Image::Image(const std::string & filename):
    Surface(IMG_Load(filename.c_str()))
{
    // error if m_surface == NULL
    if (m_surface != 0)
    {
        SDL_Surface * optimized = SDL_DisplayFormat(m_surface);
        if (optimized != 0)
        {
            free();
            m_surface = optimized;
        }
        // error optimizing loaded image
    }
    // error loading image
}

Image::~Image()
{
}
