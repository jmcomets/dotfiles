#ifndef LIST_H_
#define LIST_H_

#include <cstddef>

namespace Bundle
{
    template <typename _Val>
        struct _List_Node
    {
        _List_Node * next;
        _Val value;

        _List_Node(const _Val & val): next(0), value(val)
        {
        }

        ~_List_Node()
        {
        }
    };

    template <typename _Val>
        _List_Node<_Val> * _List_Increment(_List_Node<_Val> *);

    template <typename _Val>
        _List_Node<_Val> * _List_Decrement(_List_Node<_Val> *);

    template <typename _Val>
        struct _List_Iterator
    {
        _List_Iterator(_List_Node<_Val> * x = 0): _node(x) {}

        _Val & operator*() const
        {
            return _node->value;
        }

        _Val * operator->() const
        {
            return  &_node->value;
        }

        _List_Iterator<_Val> & operator++()
        {
            _node = _List_Increment<_Val>(_node);
            return *this;
        }

        _List_Iterator<_Val> & operator++(int)
        {
            _List_Iterator<_Val> tmp = *this;
            _node = _List_Increment<_Val>(_node);
            return tmp;
        }

        _List_Iterator<_Val> & operator--()
        {
            _node = _List_Decrement<_Val>(_node);
            return *this;
        }

        _List_Iterator<_Val> & operator--(int)
        {
            _List_Iterator<_Val> tmp = *this;
            _node = _List_Decrement<_Val>(_node);
            return tmp;
        }

        bool operator==(const _List_Iterator<_Val> & x) const
        {
            return &x == this || _node == x._node;
        }

        bool operator!=(const _List_Iterator<_Val> & x) const
        {
            return _node != x._node;
        }

        _List_Node<_Val> * _node;
    };

    template <typename _Val>
        struct _List_Const_Iterator
    {
        _List_Const_Iterator(_List_Node<_Val> * x = 0): _node(x) {}

        const _Val & operator*() const
        {
            return _node->value;
        }

        const _Val * operator->() const
        {
            return  &_node->value;
        }

        _List_Const_Iterator<_Val> & operator++()
        {
            _node = _List_Increment<_Val>(_node);
            return *this;
        }

        _List_Const_Iterator<_Val> & operator++(int)
        {
            _List_Const_Iterator<_Val> tmp = *this;
            _node = _List_Increment<_Val>(_node);
            return tmp;
        }

        _List_Const_Iterator<_Val> & operator--()
        {
            _node = _List_Decrement<_Val>(_node);
            return *this;
        }

        _List_Const_Iterator<_Val> & operator--(int)
        {
            _List_Const_Iterator<_Val> tmp = *this;
            _node = _List_Decrement<_Val>(_node);
            return tmp;
        }

        bool operator==(const _List_Const_Iterator<_Val> & x) const
        {
            return &x == this || _node == x._node;
        }

        bool operator!=(const _List_Const_Iterator<_Val> & x) const
        {
            return _node != x._node;
        }

        _List_Node<_Val> * _node;
    };

    template <class _Val>
        class List
    {
        public:
            typedef _Val value_type;
            typedef _List_Iterator<_Val> iterator;
            typedef _List_Const_Iterator<_Val> const_iterator;
            typedef std::size_t size_type;

            List(): _head(0), _tail(0), _size(0) {}

            ~List()
            {
                erase(begin(), end());
            }

            void append(const value_type & val)
            {
                insert(begin(), val);
            }

            void prepend(const value_type & val)
            {
                insert(end(), val);
            }

            iterator begin()
            {
                return iterator(_head);
            }

            iterator end()
            {
                return iterator(_tail);
            }

            const_iterator begin() const
            {
                return const_iterator(_head);
            }

            const_iterator end() const
            {
                return const_iterator(_tail);
            }

            iterator erase(iterator first, iterator last)
            {
                while (first != last) erase(*first++);
                return first;
            }

            iterator erase(iterator);
            iterator insert(iterator, const value_type &);

        private:
            _List_Node<_Val> * _head;
            _List_Node<_Val> * _tail;
            size_type _size;
    };

    template <typename _Val>
        List<_Val>::iterator List<_Val>::insert(List<_Val>::iterator pos,
                const List<_Val>::value_type & val)
        {
            _List_Node<_Val> * node = new _List_Node<_Val>(val);
            node->next = pos._node;
            node->previous = pos._node->previous;
            pos._node->previous = node;
            if (pos._node->previous)
            {
                pos._node->previous->next = node;
            }
            previous->next = pos._node->next;
            return ++pos;
        }


    template <typename _Val>
        List<_Val>::iterator List<_Val>::erase(List<_Val>::iterator pos)
    {
        _List_Node<_Val> * node = pos._node;
        next->previous = node->previous;
        previous->next = node->next;
        delete (pos++).node;
        return pos;
    }

    template <typename _Val>
        inline _List_Node<_Val> * _List_Increment(_List_Node<_Val> * x)
    {
        return x->next;
    }

    template <typename _Val>
        inline _List_Node<_Val> * _List_Decrement(_List_Node<_Val> * x)
    {
        return x->previous;
    }
}

#endif // LIST_H_
