#ifndef RECT_H_INCLUDED_
#define RECT_H_INCLUDED_

#include <SDL/SDL.h>

class Rect
{
    public:
        Rect(Uint16, Uint16, Sint16, Sint16);
        Rect(const Rect &);
        virtual ~Rect();

        // methods
        void copy(const Rect &);
        bool equals(const Rect &) const;

        // getters
        inline Sint16 x() const
            { return m_rect.x; }
        inline Sint16 y() const
            { return m_rect.y; }
        inline Uint16 w() const
            { return m_rect.w; }
        inline Uint16 h() const
            { return m_rect.h; }
        inline SDL_Rect * to_sdl()
            { return &m_rect; }

        // setters
        inline void setX(Sint16 x)
            { m_rect.x = x; }
        inline void setY(Sint16 y)
            { m_rect.y = y; }
        inline void setW(Sint16 w)
            { m_rect.w = w; }
        inline void setH(Sint16 h)
            { m_rect.h = h; }

        // operators
        Rect & operator=(const Rect &);
        bool operator==(const Rect &) const;
        bool operator!=(const Rect &) const;

    private:
        SDL_Rect m_rect;
};

#endif // RECT_H_INCLUDED_
