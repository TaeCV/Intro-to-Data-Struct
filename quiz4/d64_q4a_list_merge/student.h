#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
    // write your code here
    for (auto it = ls.begin(); it != ls.end(); ++it) {
        node *tmp = it->mHeader;
        mHeader->prev->next = tmp->next;
        tmp->next->prev = mHeader->prev;
        tmp->prev->next = mHeader;
        mHeader->prev = tmp->prev;
        tmp->next = tmp;
        tmp->prev = tmp;
        mSize += it->mSize;
        it->mSize = 0;
    }
}

#endif
