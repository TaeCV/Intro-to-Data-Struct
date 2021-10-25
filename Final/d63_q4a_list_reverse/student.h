#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
    // write your code here
    auto tmp = a;
    while (a.ptr != lastNode) {
        node *tmp = a.ptr;
        ++a;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        tmp->next = it;
        tmp->prev = it->prev;
        it->prev->next = tmp;
        it->prev = tmp;
        it = tmp;
    }
    return a;
}

#endif
