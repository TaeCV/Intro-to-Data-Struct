#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    // write your code here
    //  if you use std::vector, your score will be half (grader will report score BEFORE halving)
    if (mSize != other.mSize)
        return mSize < other.mSize;
    int i = 0;
    bool isEqual = false;
    while (i < mSize) {
        if (mData[i] > other.mData[i])
            return false;
        else if (mData[i] == other.mData[i])
            isEqual = true;
        ++i;
    }
    return !isEqual;
}

#endif