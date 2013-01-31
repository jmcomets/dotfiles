#ifndef RB_TREE_H_
#define RB_TREE_H_

#include <cstddef>

namespace Bundle
{
    template <typename _Val>
        struct _Rb_Tree_Node
    {
        typedef _Rb_Tree_Node _Rb_Tree_Node<_Val>;

        _Rb_Tree_Node<_Val> * parent;
        _Rb_Tree_Node<_Val> * left;
        _Rb_Tree_Node<_Val> * right;
        _Val value;
        bool red;

        _Rb_Tree_Node(const _Val & k, _Rb_Tree_Node<_Val> * p = 0):
            parent(p), left(0), right(0),
            value(k), red(true)
        {
        }

        ~_Rb_Tree_Node()
        {
            delete left;
            delete right;
        }
    };

    template <typename <_Val>
        _Rb_Tree_Node<_Val> * _Rb_Tree_Increment(_Rb_Tree_Node<_Val>);

    template <typename <_Val>
        _Rb_Tree_Node<_Val> * _Rb_Tree_Decrement(_Rb_Tree_Node<_Val>);

    template <typename _Val>
        struct _Rb_Tree_Iterator
    {
        _Rb_Tree_Iterator(_Rb_Tree_Node<_Val> * x = 0):
            _node(x)
        {
        }

        _Val & operator*()
        {
            return _node->value;
        }

        _Val * operator->()
        {
            return &_node->value;
        }

        _Rb_Tree_Iterator<_Val> & operator++()
        {
            _node = _Rb_Tree_Increment<_Val>(_node);
            return *this;
        }

        _Rb_Tree_Iterator<_Val> & operator++(int)
        {
            _Rb_Tree_Iterator<_Val> tmp = *this;
            _node = _Rb_Tree_Increment<_Val>(_node);
            return tmp;
        }

        _Rb_Tree_Iterator<_Val> & operator--()
        {
            _node = _Rb_Tree_Decrement<_Val>(_node);
            return *this;
        }           

        _Rb_Tree_Iterator<_Val> & operator--(int)
        {
            _Rb_Tree_Iterator<_Val> tmp = *this;
            _node = _Rb_Tree_Decrement<_Val>(_node);
            return tmp;
        }

        bool operator==(const _Rb_Tree_Iterator<_Val> & x) const
        {
            return &x == this || x._node == _node;
        }

        bool operator!=(const _Rb_Tree_Iterator<_Val> & x) const
        {
            return x._node != _node;
        }

        _Rb_Tree_Node<_Val> * _node;
    };

    template <typename _Val>
        struct _Rb_Tree_Const_Iterator
    {
        _Rb_Tree_Const_Iterator(_Rb_Tree_Node<_Val> * x = 0):
            _node(x)
        {
        }

        const _Val & operator*()
        {
            return _node->value;
        }

        const _Val * operator->()
        {
            return &_node->value;
        }

        _Rb_Tree_Const_Iterator<_Val> & operator++()
        {
            _node = _Rb_Tree_Increment<_Val>(_node);
            return *this;
        }

        _Rb_Tree_Const_Iterator<_Val> & operator++(int)
        {
            _Rb_Tree_Const_Iterator<_Val> tmp = *this;
            _node = _Rb_Tree_Increment<_Val>(_node);
            return tmp;
        }

        _Rb_Tree_Const_Iterator<_Val> & operator--()
        {
            _node = _Rb_Tree_Decrement<_Val>(_node);
            return *this;
        }           

        _Rb_Tree_Const_Iterator<_Val> & operator--(int)
        {
            _Rb_Tree_Const_Iterator<_Val> tmp = *this;
            _node = _Rb_Tree_Decrement<_Val>(_node);
            return tmp;
        }

        bool operator==(const _Rb_Tree_Const_Iterator<_Val> & x) const
        {
            return &x == this || x._node == _node;
        }

        bool operator!=(const _Rb_Tree_Const_Iterator<_Val> & x) const
        {
            return x._node != _node;
        }

        _Rb_Tree_Node<_Val> * _node;
    };

    template <typename _Val, typename _Compare>
        class _Rb_Tree
    {
        public:
            typedef _Val value_type;
            typedef _Compare compare;
            typedef std::size_t size_type;
            typedef _Rb_Tree_Iterator<_Val> iterator;

            _Rb_Tree():
                _root(0), _size(0), _comp()
            {
            }

            _Rb_Tree(const compare & comp):
                _root(0), _size(0), _comp(comp)
            {
            }

            ~_Rb_Tree()
            {
                delete _root;
            }

            void insert(const value_type & value)
            {
                _insert(value, _root);
            }

            void erase(const value_type & value)
            {
                _erase(value, _root);
            }

            void clear()
            {
                delete _root;
                _root = 0;
                _size = 0;
            }

            bool empty() const
            {
                return _root != 0;
            }

            size_type size() const
            {
                return _size;
            }

        protected:
            _Rb_Tree_Node * get(const value_type & value, _Rb_Tree_Node * x) const
            {
                if (x == 0)
                {
                    return 0;
                }
                else if (_comp(value, x->value))
                {
                    return get(value, x->left);
                }
                else if (_comp(x->value, value))
                {
                    return get(value, x->right);
                }
                else
                {
                    return x;
                }
            }

            _Rb_Tree_Node * min(_Rb_Tree_Node * x) const
            {
                while (x) x = x->left;
                return x;
            }

            _Rb_Tree_Node * max(_Rb_Tree_Node * x) const
            {
                while (x) x = x->right;
                return x;
            }

        private:
            _Rb_Tree_Node * _grandparent(_Rb_Tree_Node * x)
            {
                return x && x->parent ? x->parent->parent : 0;
            }

            _Rb_Tree_Node * _uncle(_Rb_Tree_Node * x)
            {
                if (_Rb_Tree_Node * g = _grandparent(x))
                {
                    return x->parent == g->left ? g->right : g->left;
                }
                else
                {
                    return 0;
                }
            }

            void _rrotate(_Rb_Tree_Node * x)
            {
                _Rb_Tree_Node * right = x->right;
                x->right = right->left;
                if (right->left)
                {
                    right->left->parent = x;
                }
                right->parent = x->parent;
                if (x->parent == 0)
                {
                    _root = right;
                }
                else if (x == x->parent->left)
                {
                    x->parent->left = right;
                }
                else
                {
                    x->parent->right = right;
                }
                right->left = x;
                x->parent = right;
            }

            void _lrotate(_Rb_Tree_Node * x)
            {
                _Rb_Tree_Node * left = x->left;
                x->left = left->right;
                if (left->right)
                {
                    left->right->parent = x;
                }
                left->parent = x->parent;
                if (x->parent == 0)
                {
                    _root = left;
                }
                else if (x == x->parent->right)
                {
                    x->parent->right = left;
                }
                else
                {
                    x->parent->left = left;
                }
                left->right = x;
                x->parent = left;
            }

            void _insert(const value_type & value, _Rb_Tree_Node *& x, _Rb_Tree_Node * parent = 0)
            {
                if (x == 0)
                {
                    x = new _Rb_Tree_Node(value, parent);
                    _size++;
                    _insert_rebalance(x);
                }
                else if (_comp(value, x->value))
                {
                    _insert(value, x->left, x);
                }
                else if (_comp(x->value, value))
                {
                    _insert(value, x->right, x);
                }
            }

            void _insert_rebalance(_Rb_Tree_Node * x)
            {
                _Rb_Tree_Node * u = _uncle(x);
                _Rb_Tree_Node * g = _grandparent(x);
                if (x->parent == 0) // case 1
                {
                    x->red = false;
                }
                else if (x->parent->red == 0) // case 2
                {
                    return;
                }
                else if (u && u->red) // case 3
                {
                    x->parent->red = false;
                    u->red = false;
                    _Rb_Tree_Node * g = _grandparent(x);
                    g->red = true;
                    _insert_rebalance(g);
                }
                else
                {
                    // case 4
                    if (x == x->parent->right && x->parent == g->left)
                    {
                        _rrotate(x->parent);
                        x = x->left;
                    }
                    else if (x == x->parent->left && x->parent == g->right)
                    {
                        _lrotate(x->parent);
                        x = x->right;
                    }

                    // case 5
                    x->parent->red = false;
                    g->red = true;
                    if (x == x->parent->left)
                    {
                        _lrotate(g);
                    }
                    else
                    {
                        _rrotate(g);
                    }
                }
            }

            _Rb_Tree_Node * _root;
            size_type _size;
            compare _comp;
    };

    template <typename <_Val>
        inline _Rb_Tree_Node<_Val> * _Rb_Tree_Increment(_Rb_Tree_Node<_Val> x)
    {
        // TODO
    }

    template <typename <_Val>
        inline _Rb_Tree_Node<_Val> * _Rb_Tree_Decrement(_Rb_Tree_Node<_Val> x)
    {
        // TODO
    }
}

#endif // RB_TREE_H_
