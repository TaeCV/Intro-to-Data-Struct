#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T &value) {
    // write your code here
    int n = mSize;
    node *p = mHeader->next;
    for (int i = 0; i < n; ++i) {
        if (p->data == value) {
            node *tmp = p;
            p = p->next;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            mSize--;
        } else {
            p = p->next;
        }
    }
}

#endif
