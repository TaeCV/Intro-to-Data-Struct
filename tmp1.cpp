void splitList(list<T> &list1, list<T> &list2) {
    // Add your code here
    int l1 = (mSize + 1) / 2;
    int l2 = mSize - l1;
    node *goToL2 = mHeader->next;
    for (int i = 0; i < l1; ++i)
        goToL2 = goToL2->next;
    node *LastL1 = goToL2->prev;
    if (l1) {
        list1.mHeader->prev->next = mHeader->next;
        mHeader->next->prev = list1.mHeader->prev;
        LastL1->next = list1.mHeader;
        list1.mHeader->prev = LastL1;
    }
    if (l2) {
        list2.mHeader->prev->next = goToL2;
        goToL2->prev = list2.mHeader->prev;
        list2.mHeader->prev = mHeader->prev;
        mHeader->prev->next = list2.mHeader;
    }
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
    list1.mSize += l1;
    list2.mSize += l2;
}