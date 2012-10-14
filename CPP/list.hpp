#ifndef LIST_H_INCLUDED_
#define LIST_H_INCLUDED_

namespace utilities
{

template<class value_t> class list
{
    public:
        list(): m_head(0), m_tail(0)
        {
        }

        ~list()
        {
            while (m_head)
            {
                node * n = m_head->next;
                delete m_head;
                m_head = n;
            }
        }

        struct node
        {
            node * next;
            node * previous;
            value_t value;

            node(const value_t & val, node * prev = 0): next(0), previous(prev), value(val)
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

                value_t & operator*() const
                {
                    return item->value;
                }

                iterator & operator++(int)
                {
                    item = item->next;
                    return *this;
                }

                iterator & operator++()
                {
                    item = item->next;
                    return *this;
                }

                iterator & operator--(int)
                {
                    item = item->previous;
                    return *this;
                }

                iterator & operator--()
                {
                    item = item->previous;
                    return *this;
                }

            private:
                node * item;
        };

        void append(const value_t & val)
        {
            node * tail = new node(val, m_tail);
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

        void prepend(const value_t & val)
        {
            node * head = new node(val);
            if (m_head)
            {
                head->next = m_head;
                m_head->previous = head;
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
            return iterator(m_tail ? m_tail->next : m_tail);
        }

        iterator rbegin() const
        {
            return iterator(m_tail);
        }

        iterator rend() const
        {
            return iterator(m_head ? m_head->previous : m_head);
        }

    private:
        node * m_head;
        node * m_tail;
};

} // namespace utilities

#endif // LIST_H_INCLUDED_
