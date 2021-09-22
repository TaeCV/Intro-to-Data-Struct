#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T, int> m;
    std::vector<std::pair<T, size_t>> output(k.size());
    for (int i = 0; i < mSize; ++i) {
        m[mData[(mFront + i) % mCap]]++;
    }
    for (int i = 0; i < k.size(); ++i) {
        output[i] = std::make_pair(k[i], m[k[i]]);
    }
    return output;
}

#endif
