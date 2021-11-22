#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "map_bst.h"
#include <algorithm>
#include <vector>

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n) {
    // write your code here
    if (!n)
        return 0;
    return 1 + process(n->left) + process(n->right);
}

template <typename KeyT, typename MappedT, typename CompareT>
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(map_bst<KeyT, MappedT, CompareT> &left, map_bst<KeyT, MappedT, CompareT> &right) {
    // write your code here
    if (mSize == 0)
        return std::pair<KeyT, MappedT>();
    left.mRoot = mRoot->left;
    if (left.mRoot)
        left.mRoot->parent = NULL;
    left.mSize = process(left.mRoot);
    right.mRoot = mRoot->right;
    if (right.mRoot)
        right.mRoot->parent = NULL;
    right.mSize = process(right.mRoot);
    left.mLess = mLess;
    right.mLess = mLess;
    mRoot->left = NULL;
    mRoot->right = NULL;
    mSize = 1;
    return mRoot->data;
}

#endif
