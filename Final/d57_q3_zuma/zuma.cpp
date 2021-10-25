#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, v, l, r, ll, rr, c = 1;
    cin >> n >> k >> v;
    vector<int> line(n + 1);
    l = k - 1;
    r = k;
    for (int i = 0; i <= n; ++i) {
        if (i == k) {
            line[i] = v;
        } else {
            cin >> line[i];
        }
    }
    ll = l;
    rr = r;
    while (l >= 0 || r <= n) {
        while (l >= 0 && line[l] == v)
            --l;
        while (r <= n && line[r] == v)
            ++r;
        if (r - l <= 3 * c) {
            r = rr;
            l = ll;
            break;
        }
        v = line[l];
        ll = l;
        rr = r;
        ++c;
    }
    for (int i = 0; i <= n; ++i) {
        if (i <= l || i >= r) {
            cout << line[i] << " ";
        }
    }
}