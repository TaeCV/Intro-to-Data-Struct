void splitList(list<T> &list1, list<T> &list2) {
    // Add your code here
    int n = mSize;
    for (int i = 0; i < n; ++i) {
        node *p = mHeader->next;
        mHeader->next->next->prev = mHeader;
        mHeader->next = mHeader->next->next;
        mSize--;
        if (i < (n + 1) / 2) {
            list1.mHeader->prev->next = p;
            p->prev = list1.mHeader->prev;
            p->next = list1.mHeader;
            list1.mHeader->prev = p;
            list1.mSize++;
        } else {
            list2.mHeader->prev->next = p;
            p->prev = list2.mHeader->prev;
            p->next = list2.mHeader;
            list2.mHeader->prev = p;
            list2.mSize++;
        }
    }
}
