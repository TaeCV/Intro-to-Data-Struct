void replace(const T &x, list<T> &y) {
    // write your code here
    for (iterator it = begin(); it != end(); ++it) {
        if (*it == x) {
            it = erase(it);
            for (auto &e : y) {
                insert(it, e);
            }
            --it;
        }
    }
}
