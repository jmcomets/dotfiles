#ifndef RAII_LIST_H_INCLUDED_
#define RAII_LIST_H_INCLUDED_

namespace utilities
{
    template <class data_t> class raii_list
    {
        public:
            explicit raii_list(data_t * data):
                m_next(0), m_data(data)
            {
            }

            ~raii_list()
            {
                if (has_next())
                {
                    delete m_next;
                }
                delete m_data;
            }

            inline void add(data_t * data)
            {
                if (m_data == data)
                {
                    return;
                }
                else
                {
                    if (has_next())
                    {
                        m_next->add(data);
                    }
                    else
                    {
                        m_next = new raii_list(data);
                    }
                }
            }

            inline bool has_next() const
            {
                return m_next != 0;
            }
        private:
            raii_list * m_next;
            data_t * m_data;
    };
}

#endif
