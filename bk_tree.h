#ifndef _BK_TREE_INCLUDED_
#define _BK_TREE_INCLUDED_

#include <bits/stdc++.h>
#include <iostream>
#include <stdexcept>

namespace CV {
    class BK_Tree {
    protected:
        class node {
            friend class BK_Tree;

        protected:
            std::string word;
            node *parent;
            std::unordered_map<size_t, node *> childs;

        public:
            node() : word(""), parent(nullptr) {}
            node(const std::string &word, node *parent) : word(word), parent(parent) {}
        };

        node *root;
        size_t mSize;

    protected:
        node *copy(node *src, node *parent) {
            if (src == NULL)
                return NULL;
            node *tmp = new node();
            tmp->word = src->word;
            for (auto &k : src->childs) {
                tmp->childs[k.first] = copy(k.second, tmp);
            }
            tmp->parent = parent;
            return tmp;
        }

    public:
        BK_Tree() : root(NULL), mSize(0) {}

        BK_Tree(const BK_Tree &other) : mSize(other.mSize) {
            root = copy(other.root, NULL);
        }

        void insert(const string &word) {
            node* u = new node(word);
            
        }
    };
}

#endif