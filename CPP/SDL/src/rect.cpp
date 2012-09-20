#include <rect.h>

Rect::Rect(Uint16 w, Uint16 h, Sint16 x, Sint16 y)
{
    m_rect.w = w;
    m_rect.h = h;
    m_rect.x = x;
    m_rect.y = y;
}

Rect::Rect(const Rect & r)
{
    copy(r);
}

Rect::~Rect()
{
}

void Rect::copy(const Rect & r)
{
    m_rect.w = r.m_rect.w;
    m_rect.h = r.m_rect.h;
    m_rect.x = r.m_rect.x;
    m_rect.y = r.m_rect.y;
}

bool Rect::equals(const Rect & r) const
{
    return (
            m_rect.w == r.m_rect.w &&
            m_rect.h == r.m_rect.h &&
            m_rect.x == r.m_rect.x &&
            m_rect.y == r.m_rect.y
    );
}

Rect & Rect::operator=(const Rect & r)
{
    if (&r != this)
    {
        copy(r);
    }
    return *this;
}

bool Rect::operator==(const Rect & r) const
{
    return equals(r);
}

bool Rect::operator!=(const Rect & r) const
{
    return equals(r);
}
