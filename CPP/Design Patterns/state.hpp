#ifndef STATE_H_INCLUDED_
#define STATE_H_INCLUDED_

struct State
{
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
        Context(State * s = 0): state_(s)
        {
            if (state_)
            {
                state_->enter();
            }
        }

        virtual ~Context()
        {
            //delete state_;
        }

        void set_state(State * s)
        {
            state_->leave();
            state_ = s;
            state_->enter();
        }

        void handle()
        {
            if (state_)
            {
                state_->handle();
            }
        }

    private:
        State * state_;
}; // class Context

#endif // STATE_H_INCLUDED_
