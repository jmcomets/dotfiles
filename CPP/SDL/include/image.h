#ifndef IMAGE_H_INCLUDED_
#define IMAGE_H_INCLUDED_

#include <string>
#include <SDL/SDL_image.h>
#include <surface.h>

class Image: public Surface
{
    public:
        Image(const std::string &);
        virtual ~Image();
};

#endif // IMAGE_H_INCLUDED_
