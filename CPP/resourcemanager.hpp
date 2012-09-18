#ifndef RESOURCE_MANAGER_H_INCLUDED_
#define RESOURCE_MANAGER_H_INCLUDED_

#include <map>
#include <algorithm>

template <class Resource> void free(Resource * res)
{
    delete res;
    res = 0;
}

template <class Resource, class Key, Resource* (*Loader)(const Key &), void (*Delete)(Resource *) = free<Resource> >
    class ResourceManager
{
    public:
        // load - get a resource
        static const Resource * get(const Key & key)
        {
            ResourceManager<Resource, Key, Loader, Delete> * manager = ResourceManager<Resource, Key, Loader, Delete>::getInstance();

            if (manager->lsResource.find(key) != manager->lsResource.end())
            {
                return (manager->lsResource.find(key)->second);
            }

            if (Resource * r = Loader(key))
            {
                manager->lsResource[key] = r;
                return r;
            }

            return 0;
        }

        // free all resources statically
        static void free()
        {
            if (ResourceManager<Resource, Key, Loader, Delete>::instance)
            {
                delete ResourceManager<Resource, Key, Loader, Delete>::instance;
                ResourceManager<Resource, Key, Loader, Delete>::instance = 0;
            }
        }

        // destructor, free all resources
        ~ResourceManager()
        {
            for (auto it = lsResource.begin(); it != lsResource.end(); ++it)
            {
                Delete(it->second);
                delete it->second;
            }
        }

        // singleton boilerplate
        static ResourceManager * getInstance()
        {
            if (!ResourceManager<Resource, Key, Loader, Delete>::instance)
            {
                ResourceManager<Resource, Key, Loader, Delete>::instance = new ResourceManager<Resource, Key, Loader, Delete>();
            }
            return ResourceManager<Resource, Key, Loader, Delete>::instance;
        }

    private:
        static ResourceManager<Resource, Key, Loader, Delete> * instance;

        // big three boilerplate
        ResourceManager();
        ResourceManager(const ResourceManager &);
        ResourceManager & operator=(const ResourceManager & manager);

        // resources stored by data
        std::map<Key, Resource *> lsResource;
};

template<class Resource, class Key, Resource * (*Loader)(const Key &), void (*Delete)(Resource *)> ResourceManager<Resource, Key, Loader, Delete> * ResourceManager<Resource, Key, Loader, Delete>::instance = 0;

#endif // RESOURCE_MANAGER_H_INCLUDED_
