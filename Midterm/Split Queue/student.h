#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <iostream>
#include <stdexcept>
//#pragma once
#include "queue.h"
#include <queue>
#include <vector>

template <typename T>
std::vector<CP::queue<T>> CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T>> qs(k);
    int i = 0;
    while (!empty()) {
        qs[(i++) % k].push(front());
        pop();
    }
    return qs;
}

#endif
