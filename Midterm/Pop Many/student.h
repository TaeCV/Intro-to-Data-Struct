#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
    //write your code here
    while (!empty() && K--) {
        pop();
    }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
    //write your code here
    std::stack<T> output, temp;
    while (!empty() && K--) {
        temp.push(top());
        pop();
    }
    while (!temp.empty()) {
        output.push(temp.top());
        temp.pop();
    }
    return output;
    //don't forget to return an std::stack
}

#endif
