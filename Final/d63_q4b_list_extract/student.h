#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T &value, iterator a, iterator b, CP::list<T> &output) {
    // write your code here
    if (mSize == 0 || a == b)
        return;
    while (a != b) {
        if (*a == value) {
            node *tmp = a.ptr;
            ++a;
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            tmp->next = output.mHeader->next;
            tmp->prev = output.mHeader;
            output.mHeader->next->prev = tmp;
            output.mHeader->next = tmp;
            output.mSize++;
            mSize--;
        } else {
            ++a;
        }
    }
}

#endif
