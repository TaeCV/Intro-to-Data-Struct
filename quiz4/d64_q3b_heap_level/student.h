#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "priority_queue.h"
#include <algorithm>
#include <vector>

template <typename T, typename Comp>
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const {
    // write your code here
    // can include anything
    std::vector<T> r;
    CP::priority_queue<T, Comp> tmp(mLess);
    if (pow(2, k) > mSize)
        return r;
    int start = 0;
    for (int i = 0; i < k; ++i)
        start += pow(2, i);
    for (int i = 0; i < pow(2, k); ++i) {
        if (start + i >= mSize)
            break;
        tmp.push(mData[start + i]);
    }
    while (!tmp.empty()) {
        r.push_back(tmp.top());
        tmp.pop();
    }
    return r;
}

#endif