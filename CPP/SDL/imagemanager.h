#ifndef IMAGE_MANAGER_H_INCLUDED_
#define IMAGE_MANAGER_H_INCLUDED_

#include <map>
#include <string>
#include <stdexcept>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ImageManager
{
    public:
        // default constructor, takes image base
        // directory and system's directory separator
        // as optional arguments
        ImageManager(const char * image_dir = ".", const char * dir_sep = "/");

        // RAII managed destructor (frees all loaded images)
        ~ImageManager();

        // loading method, takes relative path
        // to image desired (from base path)
        SDL_Surface * load(const char *);

        // freeing method for manual memory managing
        void free(const char *);
        
        // returns if given relative file path
        // from base directory is loaded in images
        bool is_loaded(const char *);
    private:
        // disallow copy / assign
        ImageManager(const ImageManager &);
        ImageManager & operator =(const ImageManager &);

        // stored images
        std::map<std::string, SDL_Surface *> images;

        // image base directory
        std::string m_image_dir;
};

#endif
