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
        Surface(SDL_Surface * s = 0);

        // Building Constructor:
        //   - takes width + height
        Surface(int, int, const Color & color = Color());

        // Copy Constructor:
        //   - creates a deep copy
        Surface(const Surface &);

        // Virtual Destructor:
        //   - frees member m_surface
        virtual ~Surface();

        // Methods

        // Deep copy method:
        //   - takes source for copy
        void copy(const Surface &);

        // Getters / Setters:
        //   - w    => get width
        //   - h    => get height
        //   - setW => set width
        //   - setH => set height
        //
        // Contract:
        //   - member m_surface is not NULL
        //      (can be checked with a boolean cast)
        inline int w() const
            { return m_surface->w; }
        inline void setW(int w)
            { m_surface->w = w; }
        inline int h() const
            { return m_surface->h; }
        inline void setH(int h)
            { m_surface->h = h; }

        // Operators

        // Assignment operator for deep copy.
        Surface & operator=(const Surface &);

        // Object state checker, corresponds to
        // stored surface's state.
        inline operator bool() const
            { return m_surface != 0; }

        // Constants

        // Surface creation (format) flags
        static const Uint32 Flags;

        // Display's Bits Per Pixels
        static const Uint8 Bpp;
    private:
        SDL_Surface * m_surface;
};

#endif // SURFACE_H_INCLUDED_
