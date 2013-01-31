#ifndef IMAGE_MANAGER_H_INCLUDED_
#define IMAGE_MANAGER_H_INCLUDED_

#include <map>
#include <string>
#include <image.h>

class ImageManager
{
    public:
        // default constructor, takes image base
        // directory and system's directory separator
        // as optional arguments
        ImageManager(const std::string & image_dir = ".", const std::string & dir_sep = "/");

        // RAII managed destructor (frees all loaded images)
        ~ImageManager();

        // loading method, takes relative path
        // to image desired (from base path)
        Image * load(const std::string &);

        // freeing method for manual memory managing
        void free(const std::string &);

        // returns if given relative file path
        // from base directory is loaded in images
        bool is_loaded(const std::string &) const;

    private:
        // disallow copy / assign
        ImageManager(const ImageManager &);
        ImageManager & operator =(const ImageManager &);

        // stored images
        std::map<std::string, Image *> m_images;

        // image base directory
        std::string m_image_dir;
};

#endif
