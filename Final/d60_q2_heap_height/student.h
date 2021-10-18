#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::height() const {
    //write your code here
    if (mSize == 0)
        return -1;
    return (int)log2(mSize);
}

#endif
