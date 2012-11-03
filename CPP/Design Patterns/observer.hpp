#ifndef OBSERVER_H_INCLUDED_
#define OBSERVER_H_INCLUDED_

#include <set>

class Observer;

class Subject
{
    public:
        void Attach(Observer * o)
        {
            obs_.insert(o);
        }

        void Detach(Observer * o)
        {
            obs_.erase(o);
        }

        void Notify()
        {
            std::set<Observer *>::iterator it;
            for (it = obs_.begin(); it != obs_.end(); it++)
            {
                o->Update(this);
            }
        }

    private:
        std::set<Observer *> obs_;
}; // class Subject

class Observer
{
    public:
        virtual void Update(Subject *) = 0;
}; // class Observer

#endif // OBSERVER_H_INCLUDED_
