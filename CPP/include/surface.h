#ifndef SURFACE_H_INCLUDED_
#define SURFACE_H_INCLUDED_

#include <SDL/SDL.h>
#include <rect.h>
#include <color.h>

class Surface
{
    public:
        // Default Constructor:
        //   - takes optional low-level SDL_Surface
        //      pointer for reference assignment
        Surface(SDL_Surface * = 0);

        // Building Constructor:
        //   - takes width + height
        Surface(int, int, const Color & = Color());

        // Copy Constructor:
        //   - creates a deep copy
        Surface(const Surface &);

        // Virtual Destructor:
        //   - frees member _surface
        virtual ~Surface();

        // Methods

        // Deep copy method:
        //   - takes source for copy
        void copy(const Surface &);

        // Explicit surface freeing
        //   - frees and resets _surface to 0
        void free();

        // Update the surface's representation
        void update();

        // Quick getter for SDL_Surface
        inline SDL_Surface * to_sdl()
            { return _surface; }

        // Best way of duplicating surface
        SDL_Surface * duplicate();

        // Quick swapping
        SDL_Surface * swap(SDL_Surface *);

        // Drawing methods

        // Main blitting method
        void blit_to(const Surface &, Rect * dstrect = 0,
                Rect * srcrect = 0);

        // Getters / Setters:
        //   - w    => get width
        //   - h    => get height
        //   - setW => set width
        //   - setH => set height
        //
        // Contract:
        //   - member _surface is not NULL
        //      (can be checked with a boolean cast)
        inline int w() const
            { return _surface->w; }
        inline void setW(int w)
            { _surface->w = w; }
        inline int h() const
            { return _surface->h; }
        inline void setH(int h)
            { _surface->h = h; }

        // Operators

        // Assignment operator for deep copy.
        Surface & operator=(const Surface &);

        // Object state checker, corresponds to
        // stored surface's state.
        inline operator bool() const
            { return _surface != 0; }

        // Constants

        // Surface creation (format) flags
        enum Flag
        {
            AnyFormat = SDL_ANYFORMAT,     // Allow any pixel-format *               
            ASyncBlit = SDL_ASYNCBLIT,     // Use asynchronous blit if possible      
            DoubleBuf = SDL_DOUBLEBUF,     // Double buffered *                      
            HWAccel = SDL_HWACCEL,         // Use hardware acceleration blit         
            HWPalette = SDL_HWPALETTE,     // Have an exclusive palette              
            HWSurface = SDL_HWSURFACE,     // Stored in video memory                 
            FullScreen = SDL_FULLSCREEN,   // Full screen surface *                  
            OpenGL = SDL_OPENGL,           // Have an OpenGL context *               
            OpenGLBlit = SDL_OPENGLBLIT,   // Support OpenGL blitting *.             
            Resizable = SDL_RESIZABLE,     // Resizable surface *                    
            RLEAccel = SDL_RLEACCEL,       // Accelerated colorkey blitting with RLE 
            SrcAlpha = SDL_SRCALPHA,       // Use alpha blending blit                
            SrcColorKey = SDL_SRCCOLORKEY, // Use colorkey blitting                  
            SWSurface = SDL_SWSURFACE,     // Stored in the system memory.           
            Prealloc = SDL_PREALLOC        // Use preallocated memory                
        };

        static Uint32 Flags;

        // Display's Bits Per Pixels
        static Uint8 Bpp;

    protected:
        SDL_Surface * _surface;
};

#endif // SURFACE_H_INCLUDED_
