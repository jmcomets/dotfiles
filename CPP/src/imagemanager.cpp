#include <imagemanager.h>

// default constructor, takes image base directory
// and system's directory separator:
//  - ensure that the path has a trailing slash
ImageManager::ImageManager(const std::string & image_dir, const std::string & dir_sep):
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
    for (std::map<std::string, Image *>::iterator it = m_images.begin(); it != m_images.end(); ++it)
    {
        delete (*it).second;
    }
}

// load the desired image:
// if the file hasn't been loaded yet,
// load it from image base path and on
// success add it to the list
Image * ImageManager::load(const std::string & filename)
{
    Image * image = NULL;
    if (is_loaded(filename))
    {
        image = m_images[filename];
    }
    else
    {
        image = new Image(m_image_dir + filename);
        m_images[filename] = image;
    }
    return image;
}

// release memory manually by freeing directly image
void ImageManager::free(const std::string & key)
{
    if (is_loaded(key))
    {
        delete m_images[key];
        m_images.erase(key);
    }
}

// check is filename (eg: key) is in images
bool ImageManager::is_loaded(const std::string & key) const
{
    return (m_images.find(key) != m_images.end());
}
