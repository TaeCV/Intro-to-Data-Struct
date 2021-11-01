#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
    // write your code here
    std::vector<T> tmp(first, first + k);
    for (iterator it = first; it != last - k; ++it) {
        *it = *(it + k);
    }
    iterator it = last - k;
    for (int i = 0; i < k; ++i) {
        *(it + i) = tmp[i];
    }
}

#endif
