#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    //write your code here
    if (m <= 0 || a < mData || b < mData || a + m - 1 >= mData + mSize || b + m - 1 >= mData + mSize || std::abs(b - a) < m)
        return false;
    for (int i = 0; i < m; i++) {
        std::swap(*(a + i), *(b + i));
    }
    return true;
}

#endif
