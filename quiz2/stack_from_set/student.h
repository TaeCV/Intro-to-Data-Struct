#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first, typename std::set<T>::iterator last) {
    //write your code ONLY here
    int c = 0;
    for (auto it = first; it != last; ++it)
        c++;
    mData = new T[c]();
    mSize = c;
    mCap = c;
    for (auto it = first; it != last; ++it) {
        mData[--c] = *it;
    }
}

#endif
