#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::shift_left() {
    // your code here
    node *tmp = mHeader->next;
    mHeader->prev->next = tmp;
    tmp->next->prev = mHeader;
    mHeader->next = tmp->next;
    tmp->next = mHeader;
    tmp->prev = mHeader->prev;
    mHeader->prev = tmp;
}

#endif
