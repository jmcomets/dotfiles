#include <image.h>

Image::Image(const std::string & filename):
    Surface(IMG_Load(filename.c_str()))
{
    // error if _surface == NULL
    if (_surface != 0)
    {
        SDL_Surface * optimized = SDL_DisplayFormat(_surface);
        if (optimized != 0)
        {
            free();
            _surface = optimized;
        }
        // error optimizing loaded image
    }
    // error loading image
}

Image::~Image()
{
}
