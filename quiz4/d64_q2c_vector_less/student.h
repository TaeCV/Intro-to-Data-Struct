#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    // write your code here
    //  if you use std::vector, your score will be half (grader will report score BEFORE halving)
    if (mSize == 0 && other.mSize)
        return true;
    int i = 0;
    while (i < mSize && i < other.mSize && mData[i] == other.mData[i])
        ++i;
    if (i < mSize && i >= other.mSize)
        return false;
    if (i >= mSize && i < other.mSize)
        return true;
    return mData[i] < other.mData[i];
}

#endif