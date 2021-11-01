#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
    // write your code here
    std::vector<std::vector<T>> res(k);
    int t = mSize / k, c = 0, idx = 0, add = 0;
    if (mSize % k != 0)
        add = mSize % k;
    for (int i = mSize - 1; i >= 0; --i) {
        res[idx].push_back(mData[i]);
        ++c;
        if (c == t + 1 || idx >= add && c == t) {
            ++idx;
            c = 0;
        }
    }
    return res;
}
#endif
