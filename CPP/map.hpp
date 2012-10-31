#ifndef MAP_H_INCLUDED_
#define MAP_H_INCLUDED_

namespace utilities
{

    template <class K>
        bool less(const K & k1, const K & k2)
    {
        return k1 < k2;
    }

    template <class K, class V, bool (*less)(const K &, const K &) = less<K> >
        class map
    {
        public:
            typedef K key_t;
            typedef V value_t;
            struct exception {};
            struct invalid_key: public exception {};
            struct empty_tree: public exception {};

            map(): root_(nullptr)
            {
            }

            virtual ~map()
            {
                delete root_;
            }

            struct node
            {
                node * parent;
                node * left;
                node * right;
                K key;
                V value;
                bool red;

                node(const K & k, const V & v, node * p = nullptr):
                    parent(p), left(nullptr), right(nullptr),
                    key(k), value(v), red(true)
                {
                }

                virtual ~node()
                {
                    delete left;
                    delete right;
                }

            }; // struct node

            inline const V & get(const K & key) const
            {
                return get(key, root_);
            }

            inline const V & max() const
            {
                return max(root_);
            }

            inline const V & min() const
            {
                return min(root_);
            }

            inline const K & min_sup(const K & key) const
            {
                const K * k = min_sup(key, root_);
                if (k == nullptr)
                {
                    throw invalid_key();
                }
                return *k;
            }

            inline void insert(const K & key, const V & val)
            {
                insert(key, val, root_);
            }

            inline bool empty() const
            {
                return root_ != nullptr;
            }

            inline void preorder(void (*f)(const K &, const V &))
            {
                preorder(f, root_);
            }

            inline void inorder(void (*f)(const K &, const V &))
            {
                inorder(f, root_);
            }

            inline void postorder(void (*f)(const K &, const V &))
            {
                postorder(f, root_);
            }

            inline const V & operator[](const K & key) const
            {
                return get(key, root_);
            }

        protected:
            node * grandparent(node * root)
            {
                return (root && root->parent) ? root->parent->parent : nullptr;
            }

            node * uncle(node * root)
            {
                if (node * g = grandparent(root))
                {
                    return (root->parent == g->left) ? g->right : g->left;
                }
                else
                {
                    return nullptr;
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
                if (root->parent == nullptr)
                {
                    root_ = right;
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
                if (root->parent == nullptr)
                {
                    root_ = left;
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

            const V & get(const K & key, node * root) const
            {
                if (root == nullptr)
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

            const V & min(node * root) const
            {
                if (root == nullptr)
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

            const V & max(node * root) const
            {
                if (root == nullptr)
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

            const K * min_sup(const K & key, node * root) const
            {
                if (root == nullptr)
                {
                    return nullptr;
                }
                if (less(key, root->key))
                {
                    const K * k = min_sup(key, root->left);
                    return (k == nullptr || less(*k, key)) ? &root->key : k;
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
            void insert(const K & key, const V & val, node *& root, node * parent = nullptr)
            {
                if (root == nullptr)
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
                if (root->parent == nullptr) // case 1
                {
                    root->red = false;
                }
                else if (root->parent->red == nullptr) // case 2
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

            void preorder_map(void (*f)(const K &, const V &), node * root)
            {
                if (root)
                {
                    (*f)(root->key, root->value);
                    preorder_map(f, root->left);
                    preorder_map(f, root->right);
                }
            }

            void inorder_map(void (*f)(const K &, const V &), node * root)
            {
                if (root)
                {
                    inorder_map(f, root->left);
                    (*f)(root->key, root->value);
                    inorder_map(f, root->right);
                }
            }

            void postorder(void (*f)(const K &, const V &), node * root)
            {
                if (root)
                {
                    postorder(f, root->left);
                    postorder(f, root->right);
                    (*f)(root->key, root->value);
                }
            }

            node * root_;

    }; // class map

} // namespace utilities

#endif // MAP_H_INCLUDED_
