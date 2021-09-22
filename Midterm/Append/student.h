#include "queue.h"
#include "stack.h"

namespace CP {
    template <typename T>
    void stack<T>::appendStack(stack<T> s) {
        *this = s;
        for (int i = 0; i < s.size(); ++i) {
            push(s.mData[i]);
        }
    }

    template <typename T>
    void stack<T>::appendQueue(queue<T> q) {
        mCap = mSize + q.size();
        T *arr = new T[mCap]();
        int n = 0;
        for (int i = q.size() - 1; i >= 0; --i) {
            arr[n++] = q.mData[(q.mFront + i) % q.mCap];
        }
        for (int i = 0; i < mSize; ++i) {
            arr[n++] = mData[i];
        }
        mSize = n;
        delete[] mData;
        mData = arr;
    }

    template <typename T>
    void queue<T>::appendStack(stack<T> s) {
        for (int i = s.size() - 1; i >= 0; --i) {
            push(s.mData[i]);
        }
    }

    template <typename T>
    void queue<T>::appendQueue(queue<T> q) {
        for (int i = 0; i < q.size(); ++i) {
            push(q.mData[(q.mFront + i) % q.mCap]);
        }
    }
}
