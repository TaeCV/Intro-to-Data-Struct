#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
    //write your code here
    std::sort(data.begin(), data.end());
    int n = mSize + data.size(), cnt = 0;
    T *arr = new T[n]();
    for (int i = 0; i < n; ++i) {
        if (data[cnt].first == i - cnt && cnt < data.size()) {
            arr[i] = data[cnt++].second;
        } else {
            arr[i] = mData[i - cnt];
        }
    }
    delete[] mData;
    mData = arr;
    mSize = n;
    mCap = n;
}

#endif
