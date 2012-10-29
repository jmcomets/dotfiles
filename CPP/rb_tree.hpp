#ifndef RB_TREE_H_INCLUDED_
#define RB_TREE_H_INCLUDED_

namespace utilities
{

    template <class key_t> bool less(const key_t & k1, const key_t & k2)
    {
        return k1 < k2;
    }

    template <class key_t, class value_t, bool (*less)(const key_t &, const key_t &) = less<key_t> > class rb_tree
    {
        public:
            typedef key_t key_type;
            typedef value_t value_type;
            struct exception {};
            struct invalid_key: public exception {};
            struct empty_tree: public exception {};

            rb_tree(): _root(0)
            {
            }

            virtual ~rb_tree()
            {
                delete _root;
            }

            struct node
            {
                node * parent;
                node * left;
                node * right;
                key_t key;
                value_t value;
                bool red;

                node(const key_t & k, const value_t & v, node * p = 0):
                    parent(p), left(0), right(0),
                    key(k), value(v), red(true)
                {
                }

                ~node()
                {
                    delete left;
                    delete right;
                }

            }; // struct node

            inline const value_t & get(const key_t & key) const
            {
                return get(key, _root);
            }

            inline const value_t & max() const
            {
                return max(_root);
            }

            inline const value_t & min() const
            {
                return min(_root);
            }

            inline const key_t & min_sup(const key_t & key) const
            {
                const key_t * k = min_sup(key, _root);
                if (!k)
                {
                    throw invalid_key();
                }
                return *k;
            }

            inline void insert(const key_t & key, const value_t & val)
            {
                insert(key, val, _root);
            }

            inline bool empty() const
            {
                return !_root;
            }

            inline void preorder_map(void (*f)(const key_t &, const value_t &))
            {
                preorder_map(f, _root);
            }

            inline void inorder_map(void (*f)(const key_t &, const value_t &))
            {
                inorder_map(f, _root);
            }

            inline void postorder_map(void (*f)(const key_t &, const value_t &))
            {
                postorder_map(f, _root);
            }

            inline const value_t & operator[](const key_t & key) const
            {
                return get(key, _root);
            }

        protected:
            node * grandparent(node * root)
            {
                return (root && root->parent) ? root->parent->parent : 0;
            }

            node * uncle(node * root)
            {
                if (node * g = grandparent(root))
                {
                    return (root->parent == g->left) ? g->right : g->left;
                }
                else
                {
                    return 0;
                }
            }

            void rotate_left(node * root)
            {
                node * right = root->right;
                root->right = right->left;
                if (right->left)
                {
                    right->left->parent = root;
                }
                right->parent = root->parent;
                if (!root->parent)
                {
                    _root = right;
                }
                else if (root == root->parent->left)
                {
                    root->parent->left = right;
                }
                else
                {
                    root->parent->right = right;
                }
                right->left = root;
                root->parent = right;
            }

            void rotate_right(node * root)
            {
                node * left = root->left;
                root->left = left->right;
                if (left->right)
                {
                    left->right->parent = root;
                }
                left->parent = root->parent;
                if (!root->parent)
                {
                    _root = left;
                }
                else if (root == root->parent->right)
                {
                    root->parent->right = left;
                }
                else
                {
                    root->parent->left = left;
                }
                left->right = root;
                root->parent = left;
            }

            const value_t & get(const key_t & key, node * root) const
            {
                if (!root)
                {
                    throw invalid_key();
                }
                else if (less(key, root->key))
                {
                    return get(key, root->left);
                }
                else if (less(root->key, key))
                {
                    return get(key, root->right);
                }
                else
                {
                    return root->value;
                }
            }

            const value_t & min(node * root) const
            {
                if (!root)
                {
                    throw empty_tree();
                }
                else if (root->left)
                {
                    return min(root->left);
                }
                else
                {
                    return root->value;
                }
            }

            const value_t & max(node * root) const
            {
                if (!root)
                {
                    throw empty_tree();
                }
                else if (root->right)
                {
                    return min(root->right);
                }
                else
                {
                    return root->value;
                }
            }

            const key_t * min_sup(const key_t & key, node * root) const
            {
                if (!root)
                {
                    return 0;
                }
                if (less(key, root->key))
                {
                    const key_t * k = min_sup(key, root->left);
                    return (!k || less(*k, key)) ? &root->key : k;
                }
                else if (less(root->key, key))
                {
                    return min_sup(key, root->right);
                }
                else
                {
                    return &root->key;
                }
            }

        private:
            void insert(const key_t & key, const value_t & val, node *& root, node * parent = 0)
            {
                if (!root)
                {
                    root = new node(key, val, parent);
                    rebalance(root);
                }
                else if (less(key, root->key))
                {
                    insert(key, val, root->left, root);
                }
                else if (less(root->key, key))
                {
                    insert(key, val, root->right, root);
                }
            }

            void rebalance(node * root)
            {
                node * u = uncle(root);
                node * g = grandparent(root);
                if (!root->parent) // case 1
                {
                    root->red = false;
                }
                else if (!root->parent->red) // case 2
                {
                    return;
                }
                else if (u && u->red) // case 3
                {
                    root->parent->red = false;
                    u->red = false;
                    node * g = grandparent(root);
                    g->red = true;
                    rebalance(g);
                }
                else
                {
                    // case 4
                    if (root == root->parent->right && root->parent == g->left)
                    {
                        rotate_left(root->parent);
                        root = root->left;
                    }
                    else if (root == root->parent->left && root->parent == g->right)
                    {
                        rotate_right(root->parent);
                        root = root->right;
                    }

                    // case 5
                    root->parent->red = false;
                    g->red = true;
                    if (root == root->parent->left)
                    {
                        rotate_right(g);
                    }
                    else
                    {
                        rotate_left(g);
                    }
                }
            }

            void preorder_map(void (*f)(const key_t &, const value_t &), node * root)
            {
                if (root)
                {
                    (*f)(root->key, root->value);
                    preorder_map(f, root->left);
                    preorder_map(f, root->right);
                }
            }

            void inorder_map(void (*f)(const key_t &, const value_t &), node * root)
            {
                if (root)
                {
                    inorder_map(f, root->left);
                    (*f)(root->key, root->value);
                    inorder_map(f, root->right);
                }
            }

            void postorder_map(void (*f)(const key_t &, const value_t &), node * root)
            {
                if (root)
                {
                    postorder_map(f, root->left);
                    postorder_map(f, root->right);
                    (*f)(root->key, root->value);
                }
            }

            node * _root;

    }; // class rb_tree

} // namespace utilities

#endif // RB_TREE_H_INCLUDED_
