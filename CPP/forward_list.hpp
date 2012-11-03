#ifndef FORWARD_LIST_H_INCLUDED_
#define FORWARD_LIST_H_INCLUDED_

namespace utilities
{

template<class T> class forward_list
{
    public:
        forward_list(): head_(nullptr), tail_(nullptr)
        {
        }

        virtual ~forward_list()
        {
        }

        struct node
        {
            node * next;
            T value;

            node(const T & val): next(nullptr), value(val)
            {
            }

            ~node()
            {
            }
        };

        class iterator
        {
            public:
                iterator(node * n = nullptr): item_(n)
                {
                }

                iterator(const iterator & it)
                {
                    item_ = it.item_;
                }

                ~iterator()
                {
                }

                iterator & operator=(const iterator & it)
                {
                    if (&it != this)
                    {
                        item_ = it.item_;
                    }
                    return *this;
                }

                bool operator==(const iterator & it) const
                {
                    return item_ == it.item_;
                }

                bool operator!=(const iterator & it) const
                {
                    return item_ != it.item_;
                }

                T & operator*() const
                {
                    return item_->value;
                }

                iterator & operator++()
                {
                    item_ = item_->next;
                    return *this;
                }

            private:
                node * item_;
        };

        void append(const T & val)
        {
            node * tail = new node(val);
            if (tail_)
            {
                tail_->next = tail;
            }
            if (!head_)
            {
               _head = tail;
            }
            _tail = tail;
        }

        void prepend(const T & val)
        {
            node * head = new node(val);
            if (head_)
            {
                head->next = head_;
            }
            if (!tail_)
            {
                _tail = head;
            }
            _head = head;
        }

        iterator begin() const
        {
            return iterator(head_);
        }

        iterator end() const
        {
            return iterator((tail_) ? tail_->next : tail_);
        }

    private:
        node * head_;
        node * tail_;
};

} // namespace utilities
#endif // FORWARD_LIST_H_INCLUDED_
