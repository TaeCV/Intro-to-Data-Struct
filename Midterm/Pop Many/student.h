#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
    //write your code here
    mSize = mSize <= K ? 0 : mSize - K;
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
    //write your code here
    std::stack<T> output;
    K = mSize < K ? mSize : K;
    for (int i = mSize - K; i < mSize; ++i) {
        output.push(mData[i]);
    }
    mSize -= K;
    return output;
    //don't forget to return an std::stack
}

#endif
