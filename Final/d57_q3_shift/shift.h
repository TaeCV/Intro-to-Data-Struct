void shift(int k) {
    // TODO: Add your code here
    if (k > 0) {
        for (int i = 0; i < k % mSize; ++i) {
            std::swap(mHeader->data, mHeader->next->data);
            mHeader = mHeader->next;
        }
    } else {
        for (int i = 0; i < (-k) % mSize; ++i) {
            std::swap(mHeader->data, mHeader->prev->data);
            mHeader = mHeader->prev;
        }
    }
}
