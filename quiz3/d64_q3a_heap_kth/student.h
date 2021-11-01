#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "priority_queue.h"
#include <algorithm>
#include <queue>
#include <vector>

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
    // write your code here
    // can include anything
    size_t mx = 9;
    std::vector<T> v(std::min(mSize, mx));
    for (int i = 0; i < v.size(); ++i) {
        v[i] = mData[i];
    }
    sort(v.begin(), v.end(), mLess);
    return v[v.size() - k];
}

#endif
