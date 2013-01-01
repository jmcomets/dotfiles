#ifndef STATE_H_INCLUDED_
#define STATE_H_INCLUDED_

struct State
{
    State()
    {
    }

    virtual ~State()
    {
    }

    virtual void enter() = 0;
    virtual void handle() = 0;
    virtual void leave() = 0;
}; // struct State

class Context
{
    public:
        Context(State * s = 0): _state(s)
        {
            if (_state)
            {
                _state->enter();
            }
        }

        virtual ~Context()
        {
        }

        void set_state(State * s)
        {
            _state->leave();
            _state = s;
            _state->enter();
        }

        void handle()
        {
            if (_state)
            {
                _state->handle();
            }
        }

    private:
        State * _state;
}; // class Context

#endif // STATE_H_INCLUDED_
