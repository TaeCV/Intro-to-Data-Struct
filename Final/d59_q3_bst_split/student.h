#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
    // your code here
    CP::map_bst<KeyT, MappedT, CompareT> result;
    node *n = mRoot, *tmp = NULL, *tmp2 = NULL;
    bool isDone = false;
    while (n && !isDone) {
        if (n->data.first >= val) {
            tmp2 = NULL;
            if (tmp) {
                tmp->left = n;
                n->parent = tmp;
            }
            tmp = n;
            n = n->left;
        } else if (n->data.first < val) {
            if (tmp2) {
                tmp2->right = n;
                n->parent = tmp2;
            }
            tmp2 = n;
            n = n->right;
            if (n) {
                result.mRoot = null;
            }
        }
    }
    return result;
}

#endif
