#include "list.h"
#include "map_avl.h"
#include "map_bst.h"
#include "priority_queue.h"
#include "unordered_map.h"
#include <bits/stdc++.h>

using namespace std;

// bool isWellFormed(const vector<HtmlElement> &v) {
//     std::stack<HtmlElement> s;
//     for (auto &tag : v) {
//         std::string elem = getElementType(tag);
//         if (elem.substr(1, 1).compare("/") == 0) {
//             std::string str = getElementType(s.top()).substr(1);
//             s.pop();
//             if (str.compare(elem.substr(2)) != 0)
//                 return false;
//         } else if (elem.compare("<img>") == 0) {
//         } else {
//             s.push(tag);
//         }
//     }
//     return s.empty();
// }

int main() {
    CP::map_bst<int, int> m;
    int a[] = {9, 7, 6, 5, 10, 13, 12, 3};
    for (int i = 0; i < 8; ++i)
        m[a[i]] = 1;
    std::cout << m.getValue(m.succ(8));
}

// while (true) {
//     int left_size = 0;
//     if (n->left)
//         left_size = n->left.tSize;
//     if (k < left_size)
//         n = n->left;
//     else if (k == left_size)
//         return iterator(n);
//     else {
//         k -= left_size + 1;
//         n = n->right;
//     }
// }

// node *succ(KeyT v) {
//     node *n = mRoot, tmp;
//     while (true) {
//         if (!n)
//             return n;
//         int cmp = compare(n->data.first, v);
//         if (cmp == 0) {
//             n = n->right;
//             while (n && n->left) {
//                 n = n->left;
//             }
//             return n;
//         } else if (cmp < 0) {
//             n = n->right;
//         } else {
//             tmp = n;
//             n = n->left;
//         }
//     }
// }

// QNode *findPointAt(int x, int y) {
//     QNode *ptr = root;
//     while (true) {
//         if (!ptr)
//             return ptr;
//         if (ptr->x == x && ptr->y == y)
//             return ptr;
//         if (ptr->x < x) {
//             if (ptr->y < y) {
//                 ptr = ptr->bottomLeft;
//             } else {
//                 ptr = ptr->topLeft;
//             }
//         } else {
//             if (ptr->y < y) {
//                 ptr = ptr->bottomRight;
//             } else {
//                 ptr = ptr->topRight;
//             }
//         }
//     }
// }

// void mirror(){
// 	process(mRoot);
// }

// void process(node * n){
// 	if(!n) return;
// 	n->left = process(n->right);
// 	n->right = process(n->left);
// 	return n;
// }

T operator[](int k) {
    node *p = mHeader->next;
    if (k < mSize / 2) {
        for (int i = 0; i < k; ++i)
            p = p->next;
    } else {
        k = mSize - k;
        p = mHeader;
        for (int i = 0; i < k; ++i)
            p = p->prev;
    }
    return p->data;
}

bool isAHeap(vector<int> v) {
    for (int i = v.size() - 1; i > 0; --i) {
        if (v[(i - 1) / 2] < v[i])
            return false;
    }
    return true;
}

template <typename T>
class list {
protected:
    class node {
    protected:
        T data;
        node *prev;
        node *next;
        node() : data(T()), prev(this), next(this) {}
        node(const T &data, node *prev, node *next) : data(T(data)), prev(prev), next(next) {}
    };
    node *mHeader; // pointer to a header node
    size_t mSize;
    // ...............
    void eraseEveryOther() {
        // เติม C++ code ตรงนี้
        node *n = mHeader->next;
        while (n != mHeader) {
            node *tmp = n;
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete tmp;
            n = n->next->next;
        }
    }
};

template <typename T>
class list {
protected:
    class node {
    protected:
        T data;
        node *prev;
        node *next;
        node() : data(T()), prev(this), next(this) {}
        node(const T &data, node *prev, node *next) : data(T(data)), prev(prev), next(next) {}
    };
    node *mHeader; // pointer to a header node
    node *mRoot;
    size_t mSize;
    // ...............
    void eraseEveryOther() {
        // เติม C++ code ตรงนี้
        node *p = mHeader;
        while (p->next != mHeader) {
            node *tmp = p->next;
            p->next = p->next->next;
            p->next->prev = p;

            delete tmp;

            p = p->next;
        }
    }

    size_t lev(string a, string b) {
        size_t a_size = a.length();
        size_t b_size = b.length();
        if (a_size == 0)
            return b_size;
        if (b_size == 0)
            return a_size;
        if (a[0] == b[0])
            return lev(a.substr(1), b.substr(1));
        return 1 + min(min(lev(a.substr(1), b), lev(a, b.substr(1))), lev(a.substr(1), b.substr(1)));
    }

    size_t dam_lev(string a, string b) {
        size_t a_size = a.length();
        size_t b_size = b.length();
        if (a_size == 0)
            return b_size;
        if (b_size == 0)
            return a_size;
        if (a[0] == b[0])
            return lev(a.substr(1), b.substr(1));
        return 1 + min(min(lev(a.substr(1), b), lev(a, b.substr(1))), lev(a.substr(1), b.substr(1)));
    }

    node *insert(const string &word) {
        if (mRoot == nullptr) {
            // The BK Tree is empty add it to be a root node
            node *r = new node(word);
            mRoot = r;
            return r;
        } else {
            size_t d; // Levenshtein distance
            // Start with root node
            node *u = mRoot;
            while (u != nullptr) {
                // lev(a,b) refers to edit distance between a and b
                d = lev(word, u->word);
                if (d == 0)
                    return u; // it is the same word with u's word
                // u->childs is a map with size_t key and node* value
                // key of u->childs is a edit distance
                // value of u->childs is child node with key edit distance
                auto it = u->childs.find(d);
                if (it == u->childs.end()) {
                    // Doesn't exist the child of the root with the same edit distance
                    node *v = new node(word);
                    u->childs[d] = v;
                    return v;
                } else {
                    // There exists the child with d edit distance
                    // Set that child to u
                    u = it->second;
                }
            }
        }
    }

vector<string> spell_checking(const string &target, const size_t &T) {
    vector<string> output;
    stack<node *> nodes;
    if (mRoot == nullptr) return output;
    nodes.push(mRoot);
    while (!nodes.empty()) {
        node *u = nodes.top();
        nodes.pop();
        size_t du = lev(u->word, target);
        if (du <= T) output.push_back(u->word);
        int start = du - T, end = du + T;
        if (start <= 0) start = 1;
        for (auto &it : u->childs) {
            // variable it is an iterator of pair{size_t, node*}
            // first = edit distance, second = child node
            if (start <= it->first && it->first <= end) nodes.push(it->second);
        }
    }
    return output;
}

string string_matching(const string &target, const size_t & max_distance){
    string output = "";
    size_t best_distance = max_distance;
    if(mRoot == nullptr) return output;
    stack<node*> nodes;
    nodes.push(mRoot);
    while(!nodes.empty()){
        node *u = nodes.top();
        nodes.pop();
        size_t du = lev(u->word,target);
        if(du < best_distance){
            // set the new best word and its edit distance
            best_distance = du;
            output = u->word;
        }
        if(du == 0) break;
        for(auto &it: u->childs){
            // variable it is an iterator of pair{size_t, node*}
            // first = edit distance, second = child node
            if(abs(it->first - du) < best_distance) nodes.push(it->second);
        }
    }
    return output;
}
};

void pop() {
    mData[0] = mData[mSize - 1];
    T value = mData[0];
    mSize--;
    // fix Down
    size_t index = 0;
    while (2 * index + 1 < mSize) {
        size_t leftChild = 2 * index + 1;
        size_t rightChild = 2 * index + 2;
        size_t maxChild = leftChild;
        if (rightChild < mSize && mLess(leftChild, rightChild)) {
            maxChild = rightChild;
        }
        if (mLess(value, mData[maxChild])) {
            mData[index] = mData[maxChild];
        } else {
            break;
        }
    }
    mData[index] = value;
    index = maxChild;
}
