#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
    //write your code here
    int c = 0, n = mSize + (last - first);
    T *data = new T[mSize + (last - first)]();
    for (int i = 0; i < position - begin(); ++i) {
        data[c++] = mData[i];
    }
    for (iterator it = first; it != last; ++it) {
        data[c++] = *it;
    }
    for (int i = position - begin(); i < mSize; ++i) {
        data[c++] = mData[i];
    }
    delete[] mData;
    mData = data;
    mSize = n;
    mCap = n;
}

#endif
