8)
map_bst<KeyT,MappedT> toBalancedBST(vector<pair<KeyT,MappedT>> v) {
    map_bst<KeyT, MappedT> t; // create a new empty map_bst
    process(v, t, 0, v.size() - 1);
}

void process(vertor<pair<KeyT, MappedT>> &v, map_bst<KeyT, MappedT> &t, int start, int stop) {
    if (v.empty() || start == stop)
        return;
    int middle = (start + stop) / 2;
    t.insert(v[middle]);
    process(v, t, 0, middle - 1);
    process(v, t, middle + 1, v.size() - 1);
}

9)
void unzip(slist<T>& y) { // เตมโค ิ ดท๊ นี่ ี่
    if (mFirst == NULL)
        return;
    y.mFirst = mFirst;
    y.mSize++;
    mFirst = mFirst->next;
    mSize--;
    node *p = mFirst;
    node *q = y.mFirst;
    q->next = NULL;
    if (p == NULL)
        return;
    while ((p != NULL) && (p->next != NULL)) {
        q->next = p->next;
        p->next = p->next->next;
        mSize--;
        y.mSize++;
        q = q->next;
        q->next = NULL;
        p = p->next;
    }
}
