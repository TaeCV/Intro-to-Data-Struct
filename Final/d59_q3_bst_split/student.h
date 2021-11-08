#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
    // your code here
    CP::map_bst<KeyT, MappedT, CompareT> result;
    node *n = mRoot;
    node *tmpRoot = NULL;
    node *tmpResult = NULL;
    mRoot = NULL;
    result.mRoot = NULL;
    while (n) {
        if (mLess(n->data.first, val)) {
            if (tmpRoot == NULL) {
                mRoot = n;
                mRoot->parent = NULL;
            } else {
                tmpRoot->right = n;
                n->parent = tmpRoot;
            }
            tmpRoot = n;
            n = n->right;
            tmpRoot->right = NULL;
        } else {
            if (!tmpResult) {
                result.mRoot = n;
                result.mRoot->parent = NULL;
            } else {
                tmpResult->left = n;
                n->parent = tmpResult;
            }
            tmpResult = n;
            n = n->left;
            tmpResult->left = NULL;
        }
    }
    return result;
}

#endif
