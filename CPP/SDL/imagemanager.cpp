#include <imagemanager.h>

// default constructor, takes image base directory
// and system's directory separator:
//  - ensure that the path has a trailing slash
ImageManager::ImageManager(const char * image_dir, const char * dir_sep):
    m_image_dir(image_dir)
{
    if (m_image_dir.find_last_of(dir_sep) != m_image_dir.length() - 1)
    {
        m_image_dir.append(dir_sep);
    }
}

// destructor:
//  - delete all non-null surfaces stored
ImageManager::~ImageManager()
{
    for (std::map<std::string, SDL_Surface *>::iterator it = images.begin(); it != images.end(); ++it)
    {
        SDL_Surface * image = (*it).second;
        if (image != NULL)
        {
            delete image;
        }
    }
}

// load the desired image:
// if the file hasn't been loaded yet,
// load it from image base path and on
// success add it to the list
SDL_Surface * ImageManager::load(const char * filename)
{
    SDL_Surface * image = NULL;
    if (is_loaded(filename))
    {
        image = images[filename];
    }
    else
    {
        std::string filepath(filename);
        filepath = m_image_dir + filepath;
        image = IMG_Load(filepath.c_str());
        if (image != NULL)
        {
            images[filename] = image;
        }
        else
        {
            throw std::runtime_error("File `" + filepath + "` not found");
        }
    }
    return image;
}

// release memory manually by freeing directly image
void ImageManager::free(const char * key)
{
    if (is_loaded(key))
    {
        SDL_FreeSurface(images[key]);
        images.erase(key);
    }
    else
    {
        throw std::logic_error("Cannot free an image which hasn't been loaded yet");
    }
}

// check is filename (eg: key) is in images
bool ImageManager::is_loaded(const char * key)
{
    return (images.find(key) != images.end());
}
