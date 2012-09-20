#include <timer.h>

// default constructor for Timer class,
// takes optional framerate argument
Timer::Timer(int fps):
    m_fps(fps),
    m_started(false), m_paused(false),
    m_start_ticks(0), m_pause_ticks(0)
{
}

// copy constructor for Timer class,
// creates a deep copy of argument
Timer::Timer(const Timer & timer):
    m_fps(timer.m_fps),
    m_started(timer.m_started),
    m_paused(timer.m_paused),
    m_start_ticks(timer.m_start_ticks),
    m_pause_ticks(timer.m_pause_ticks)
{
}

// empty destructor for Timer class
Timer::~Timer()
{
    // nothing to do here...
}

// assignment operator
// deep copies argument
Timer & Timer::operator =(const Timer & timer)
{
    m_fps = timer.m_fps;
    m_started = timer.m_started;
    m_paused = timer.m_paused;
    m_start_ticks = timer.m_start_ticks;
    m_pause_ticks = timer.m_pause_ticks;
}

// start the Timer:
//  - store start ticks
//  - set state to started
void Timer::start()
{
    if (!is_started())
    {
        m_start_ticks = raw_ticks();
        m_started = true;
    }
}

// stop the Timer:
//  - reset everything
void Timer::stop()
{
    if (is_started())
    {
        m_start_ticks = 0;
        m_pause_ticks = 0;
        m_started = false;
        m_paused = false;
    }
}

// pause timer:
//  - store paused ticks
//  - set state to paused
void Timer::pause()
{
    if (is_started())
    {
        m_pause_ticks = raw_ticks() - m_start_ticks;
        m_paused = true;
    }
}

// unpause the Timer:
void Timer::unpause()
{
    if (is_paused())
    {
        m_start_ticks = raw_ticks() - m_pause_ticks;
        m_pause_ticks = 0;
        m_paused = false;
    }
}

void Timer::toggle_pause()
{
    if (is_paused())
    {
        unpause();
    }
    else
    {
        pause();
    }
}

// get ticks since program start
Uint32 Timer::raw_ticks() const
{
    return SDL_GetTicks();
}

// sleep for given milliseconds
void Timer::delay(Uint32 ms) const
{
    SDL_Delay(ms);
}

void Timer::fps_delay() const
{
    delay(SECOND / m_fps);
}

Uint32 Timer::ticks() const
{
    if (is_paused())
    {
        return m_pause_ticks;
    }
    else
    {
        return raw_ticks() - m_start_ticks;
    }
}

// return the stored framerate
int Timer::fps() const
{
    return m_fps;
}

// return if pause flag is set
bool Timer::is_paused() const
{
    return m_paused;
}

// return if start flag is set
bool Timer::is_started() const
{
    return m_started;
}
