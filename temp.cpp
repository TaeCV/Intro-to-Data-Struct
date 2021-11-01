#include <bits/stdc++.h>
using namespace std;

void append_k_list(vector<list<T>> &Ls) {
    for (list<T> &l : Ls) {
        mHeader->prev->next = l.mHeader->next;
        l.mHeader->next->prev = mHeader->prev;
        l.mHeader->prev->next = mHeader;
        mHeader->prev = l.mHeader->prev;
        mSize += l.size();
        l.mHeader->next = mHeader;
        l.mHeader->prev = mHeader;
        l.mSize = 0;
    }
}

int main() {
    vector<int> v, v1;
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        if (find(v1.begin(), v1.end(), tmp) != v1.end() && find(v.begin(), v.end(), tmp) == v.end())
            v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int &x : v) {
        cout << x << " ";
    }
}