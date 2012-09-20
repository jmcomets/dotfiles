#include <image.h>

Image::Image(const std::string & filename):
    Surface(IMG_Load(filename.c_str()))
{
    // error if m_surface == NULL
}

Image::~Image()
{
}
