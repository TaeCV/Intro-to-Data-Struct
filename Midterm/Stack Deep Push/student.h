#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T &value) {
    //write your code here
    T *data = new T[mSize + 1]();
    for (int i = 0, c = 0; i < mSize + 1; ++i) {
        if (!c && i == mSize - pos) {
            *(data + i) = value;
            c++;
        } else {
            *(data + i) = *(mData + i - c);
        }
    }
    delete[] mData;
    mData = data;
    mSize++;
    mCap = mSize;
}

#endif
