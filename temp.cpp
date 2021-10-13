#include <bits/stdc++.h>
using namespace std;

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