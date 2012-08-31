// macro for quick disallow copy
#define DISALLOW_COPY(Class) \
    Class(const Class &);

// macro for quick disallow assign
#define DISALLOW_ASSIGN(Class) \
    Class & operator=(const Class &);

//shortcut for both previous
#define DISALLOW_COPY_AND_ASSIGN(Class) \
    DISALLOW_COPY(Class) \
    DISALLOW_ASSIGN(Class)
