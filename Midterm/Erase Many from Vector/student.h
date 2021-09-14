#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    //write your code here
    T *arr = new T[mSize - pos.size()]();
    int c = 0;
    for (int i = 0; i < mSize; i++) {
        if (pos[c] == i && c < pos.size()) {
            c++;
            continue;
        }
        arr[i - c] = mData[i];
    }
    delete[] mData;
    mData = arr;
    mSize -= pos.size();
    mCap = mSize;
}

#endif
