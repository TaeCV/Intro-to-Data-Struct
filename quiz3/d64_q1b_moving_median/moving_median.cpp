#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v(n);
    vector<int> ans(n - w);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[i] = {a, i};
    }
    set<pair<int, int>> s(v.begin(), v.begin() + w + 1);
    auto it = s.begin();
    for (int i = 0; i < w / 2; ++i, ++it) {
    }
    ans[0] = it->first;
    for (int i = w + 1; i < n; ++i) {
        s.insert(v[i]);
        if (v[i] > *it) {
            if (v[i - w - 1] > *it) {
                --it;
            }
            ++it;
        } else if (v[i] < *it) {
            if (*it > v[i - w - 1]) {
                ++it;
            }
            --it;
        }
        s.erase(v[i - w - 1]);
        ans[i - w] = it->first;
    }
    for (int &x : ans) {
        cout << x << " ";
    }
}