// #ifndef __STUDENT_H_
// #define __STUDENT_H_

// template <typename T>
// void CP::vector<T>::mirror() {
//     //write your code here
//     ensureCapacity(mSize * 2);
//     for (int i = mSize; i < mSize * 2; ++i) {
//         mData[i] = mData[mSize * 2 - i - 1];
//     }
//     mSize *= 2;
// }

// #endif

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
    //write your code here
    ensureCapacity(mSize * 2);
    for (int i = mSize; i < mSize * 2; i++) {
        mData[i] = mData[mSize * 2 - i - 1]; // mSize - (i - mSize + 1) = mSize - i + mSize - 1
    }
    mSize *= 2;
}

#endif
