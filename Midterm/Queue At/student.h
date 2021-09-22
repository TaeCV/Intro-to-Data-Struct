#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
T CP::queue<T>::operator[](int idx) {
    return idx >= 0 ? mData[(mFront + idx) % mCap] : mData[(mFront + idx + mSize) % mCap];
}

#endif
