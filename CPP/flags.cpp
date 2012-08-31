namespace utilities
{
    // functions library for bit flag handling
    template<class T> class bitset
    {
        public:
            // default constructor
            bitset(T bs = 0):
                m_bitset(bs)
            {
            }

            // copy constructor
            bitset(const bitset & bs):
                m_bitset(bs.m_bitset)
            {
            }

            // assignment operator
            bitset & operator =(const bitset & bs)
            {
                if (&bs != this)
                {
                    m_bitset = bs.m_bitset;
                }
                return *this;
            }

            ~bitset()
            {
            }

            // explicitely check a flag
            inline bool has_flag(const T & flag) const
            {
                return (m_bitset & flag);
            }

            // toggle a flag, conserving other flags
            inline void toggle_flag(const T & flag)
            {
                m_bitset ^= flag;
            }

            // make sure that a flag is set, conserving other flag
            inline void set_flag(const T & flag)
            {
                if (!has_flag(flag))
                    toggle_flag(flag);
            }

            // make sure that a flag is set, conserving other flag
            inline void unset_flag(const T & flag)
            {
                if (has_flag(flag))
                    toggle_flag(flag);
            }
        private:
            T m_bitset;
    }; // end class bitset
} // end namespace utilities

#ifdef DEBUG

// This class tests bitflags library.
// Scheme:
// +--------Car--------+
// | state   00000000  |
// |-------------------|
// | On      00000001  |
// | Off     00000010  |
// | Repair  00000100  |
// | Dead    00001000  |
// +-------------------+
class Car
{
    public:
        Car():
            m_state(0), m_bitset(m_state)
        {
        }

        ~Car()
        {
        }

        // the car's states as binary flags
        enum CarState
        {
            On = 1,
            Off = 2,
            Repair = 4,
            Dead = 8
        };
        
        // car is started <=> On byte set
        bool is_started() const
        {
            return m_bitset.has_flag(On);
        }

        //car is off <=> Off byte set
        bool is_stopped() const
        {
            return m_bitset.has_flag(Off);
        }

        //car is dead <=> Dead byte set
        bool is_dead() const
        {
            return m_bitset.has_flag(Dead);
        }

        //car need repair <=> Repair byte set
        bool needs_repair() const
        {
            return m_bitset.has_flag(Repair);
        }

        // car is startable <=> isn't dead and doesn't need repair
        bool is_startable() const
        {
            return (!is_dead() && !needs_repair());
        }

        // start the car if it can be started
        void start()
        {
            if (is_startable())
            {
                m_bitset.set_flag(On);
                m_bitset.unset_flag(Off);
            }
        }

        // stop the car
        void stop()
        {
            m_bitset.unset_flag(On);
            m_bitset.set_flag(Off);
        }

        // crash the car
        //
        // set the Dead byte and force stopping the car
        void crash()
        {
            m_bitset.set_flag(Dead);
        }

        // when considering the car as a boolean
        // consider if it can be started (besides it being
        // already started)
        operator bool() const
        {
            return is_startable();
        }

    //private:
        //Car(const Car &);
        //Car & operator =(const Car &);
        int m_state;
        utilities::bitset<int> m_bitset;
};

#include <iostream>
#include <stdexcept>
using namespace std;

int main(int argc, char ** argcv)
{
    Car car;
    car.start();
    if (!car.is_started())
    {
        throw runtime_error("Either start() didn't work, or is_started() didn't detect the start");
    }
    car.stop();
    if (car.is_started())
    {
        throw runtime_error("Either stop() didn't work, or is_started() didn't detect the stop");
    }
    if (!car.is_stopped())
    {
        throw runtime_error("Either stop() didn't work, or is_stopped() didn't detect the stop");
    }
    car.crash();
    if (car.is_startable())
    {
        throw runtime_error("Either crash() didn't work, or is_startable() didn't detect the crash");
    }

    return 0;
}

#endif
