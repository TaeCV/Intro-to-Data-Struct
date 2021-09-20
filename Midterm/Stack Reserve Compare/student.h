#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int rMe = mCap - mSize, rOther = other.mCap - other.mSize;
    if (rMe < rOther)
        return -1;
    else if (rMe == rOther)
        return 0;
    return 1;
}

#endif