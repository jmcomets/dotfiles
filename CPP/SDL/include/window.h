#ifndef WINDOW_H_INCLUDED_
#define WINDOW_H_INCLUDED_

#include <surface.h>

class Window
{
    public:
        // Flags for window video mode
        enum Flags { Fixed, Resizable, FullScreen };

        // First creation of Window
        //   - takes width, height, flags and bpp
        //
        // Contract:
        //   - width, height are positive integers
        //   - flags are valid (use Window::Flags)
        //   - bpp is a valid Bits Per Pixel value (ex: 32)
        static Surface * create(int, int, Flags, Uint8);

        // Closing for video:
        //   - stop video
        //
        // Contract:
        //   - video is started
        static void destroy();

        // Resize current window:
        //   - takes width, height
        //
        // Contract:
        //   - width, height are positive integers
        static void resize(int, int);

        // Return current screen surface
        inline static Surface * current()
            { return _screen; }

        // Destructor, no-op
        virtual ~Window() {}

        // Converts current Window flags to
        // the SDL corresponding ones.
        static Uint32 sdl_flags();

    protected:
        // Big three boilerplate
        Window() {}
        Window(const Window &);
        Window & operator=(const Window &);

    private:
        static Surface * _screen;
        static Flags _flags;
};

#endif // WINDOW_H_INCLUDED_
