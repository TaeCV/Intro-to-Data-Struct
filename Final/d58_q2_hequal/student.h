#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::operator==(const CP::priority_queue<T, Comp> &other) const {

    //write your code here
    if (mSize != other.size())
        return false;
    priority_queue<T, Comp> tmp(*this);
    priority_queue<T, Comp> tmp2(other);
    for (int i = 0; i < mSize; ++i) {
        if (tmp.top() != tmp2.top())
            return false;
        tmp.pop();
        tmp2.pop();
    }
    return true; // you can change this line
}

#endif