#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
    // your code here
    k = k >= mSize ? mSize : k;
    int c = 0, s2Size = s2.size();
    m = m >= s2Size ? s2Size : m;
    mCap += m;
    T *arr = new T[mCap]();
    for (int i = 0; i < mSize - k; ++i) {
        arr[c++] = mData[i];
    }
    for (int i = m - 1; i >= 0; --i) {
        arr[c++] = s2.mData[s2Size - 1 - i];
    }
    for (int i = mSize - k; i < mSize; ++i) {
        arr[c++] = mData[i];
    }
    s2.mSize -= m;
    delete[] mData;
    mData = arr;
    mSize = c;
}
#endif
