// macro for quick disallow copy
#define DISALLOW_COPY(TypeName) \
    TypeName(const TypeName &);

// macro for quick disallow assign
#define DISALLOW_ASSIGN(TypeName) \
    void operator=(const TypeName &)
