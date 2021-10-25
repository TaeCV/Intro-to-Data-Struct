#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it, size_t pos) {
    // write your code here
    CP::list<T> result;
    if (pos == mSize)
        return result;
    else if (pos == 0) {
        std::swap(result.mHeader, mHeader);
        std::swap(result.mSize, mSize);
        return result;
    }
    node *last = (--end()).ptr;
    it.ptr->prev->next = mHeader;
    mHeader->prev = it.ptr->prev;
    result.mHeader->next = it.ptr;
    it.ptr->prev = result.mHeader;
    last->next = result.mHeader;
    result.mHeader->prev = last;
    result.mSize = mSize - pos;
    mSize = pos;

    return result;
}

#endif
