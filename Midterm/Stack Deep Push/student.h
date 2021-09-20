#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T &value) {
    //write your code here
    ensureCapacity(mSize + 1);
    int i;
    for (i = mSize; i > mSize - pos; --i) {
        mData[i] = mData[i - 1];
    }
    mData[i] = value;
    mSize++;
}

#endif
