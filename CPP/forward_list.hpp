#ifndef FORWARD_LIST_H_INCLUDED_
#define FORWARD_LIST_H_INCLUDED_

namespace utilities
{

template<class T> class forward_list
{
    public:
        forward_list(): m_head(0), m_tail(0)
        {
        }

        ~forward_list()
        {
        }

        struct node
        {
            node * next;
            T value;

            node(const T & val): next(0), value(val)
            {
            }

            ~node()
            {
            }
        };

        class iterator
        {
            public:
                iterator(node * n = 0): item(n)
                {
                }

                iterator(const iterator & it)
                {
                    item = it.item;
                }

                ~iterator()
                {
                }

                iterator & operator=(const iterator & it)
                {
                    if (&it != this)
                    {
                        item = it.item;
                    }
                    return *this;
                }

                bool operator==(const iterator & it) const
                {
                    return item == it.item;
                }

                bool operator!=(const iterator & it) const
                {
                    return item != it.item;
                }

                T & operator*() const
                {
                    return item->value;
                }

                iterator & operator++()
                {
                    item = item->next;
                    return *this;
                }

            private:
                node * item;
        };

        void append(const T & val)
        {
            node * tail = new node(val);
            if (m_tail)
            {
                m_tail->next = tail;
            }
            if (!m_head)
            {
                m_head = tail;
            }
            m_tail = tail;
        }

        void prepend(const T & val)
        {
            node * head = new node(val);
            if (m_head)
            {
                head->next = m_head;
            }
            if (!m_tail)
            {
                m_tail = head;
            }
            m_head = head;
        }

        iterator begin() const
        {
            return iterator(m_head);
        }

        iterator end() const
        {
            return iterator((m_tail) ? m_tail->next : m_tail);
        }

    private:
        node * m_head;
        node * m_tail;
};

} // namespace utilities
#endif // FORWARD_LIST_H_INCLUDED_
