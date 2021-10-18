#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
    //your code here
    for (int i = 0; i < mSize; ++i)
        if (mData[i] == k)
            return true;
    return false;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
    //your code here
    int mem = 0;
    for (int i = 0; i < mSize; ++i)
        if (mData[i] == k)
            mem = i + 1;
    if (mem == 0)
        return -1;
    return (int)log2(mem);
}

#endif
