#ifndef TIMER_H_INCLUDED_
#define TIMER_H_INCLUDED_

#include <SDL/SDL.h>

// default framerate for timer class
#define TIMER_DEFAULT_FPS 30

// Simple timer class
//
// Currently uses SDL (http://libsdl.org) with the
// SDL_GetTicks() function.
class Timer
{
    public:
        // time units
        enum TimerUnit
        {
            MILLISECOND = 1,
            SECOND = 1000 * MILLISECOND,
            MINUTE = 60 * SECOND,
            HOUR = 60 * MINUTE
        };

        // default constructor with optional framerate argument
        Timer(int fps = TIMER_DEFAULT_FPS);

        // copy constructor behaviour: deep copy
        Timer(const Timer &);

        // destructor
        ~Timer();

        // assignment operator behaviour: deep copy
        Timer & operator =(const Timer &);

        // start the timer flow
        void start();

        // stop the timer (eg: reset)
        void stop();

        // explicit methods handling timer pause state
        void pause();
        void unpause();
        void toggle_pause();

        // sleeper method (helps with CPU consumption)
        // body can be replaced with any `sleeping` function
        void delay(Uint32) const;

        // sleep to conserve an framerate
        void fps_delay() const;

        // time elapsed since program start
        // body can be replaced with any `time-ticking` function
        Uint32 raw_ticks() const;

        // time since timer started
        Uint32 ticks() const;

        // explicit getters
        int fps() const;
        bool is_paused() const;
        bool is_started() const;

    private:
        int m_fps;
        bool m_started, m_paused;
        Uint32 m_start_ticks, m_pause_ticks;
};

#endif
