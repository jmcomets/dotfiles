#ifndef STRATEGY_H_INCLUDED_
#define STRATEGY_H_INCLUDED_

struct Strategy
{
    virtual ~Strategy()
    {
    }

    virtual void Apply() = 0;
}; // struct Strategy

class Context
{
    public:
        Context(Strategy * s):
            strategy_(s)
        {
        }

        virtual ~Context()
        {
            delete strategy_;
        }

        void ApplyStrategy()
        {
            strategy_.Apply();
        }

    private:
        Strategy * strategy_;
}; // class Context

#endif // STRATEGY_H_INCLUDED_
