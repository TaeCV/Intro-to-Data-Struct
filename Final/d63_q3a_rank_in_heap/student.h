#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

template <typename T, typename Comp>
size_t CP::priority_queue<T, Comp>::get_rank(size_t pos) const {
    //write your code here
    size_t n = mSize - 1, c = 0;
    T tmp = mData[pos];
    while (n < mSize) {
        if (mLess(tmp, mData[n--]))
            c++;
    }
    return c;
}

#endif
