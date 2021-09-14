#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    T *data = new T[mSize]();
    for (int i = 0; i < mSize; i++) {
        data[i] = mData[i];
    }
    delete[] mData;
    mData = data;
    mCap = mSize;
}

#endif
