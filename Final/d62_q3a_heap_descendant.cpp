#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    vector<int> v;
    queue<int> q;
    cin >> n >> a;
    v.push_back(a);
    q.push(a);
    while (!q.empty()) {
        int tmp;
        if ((tmp = q.front() * 2 + 1) < n) {
            q.push(tmp);
            v.push_back(tmp);
        }
        if ((tmp = q.front() * 2 + 2) < n) {
            q.push(tmp);
            v.push_back(tmp);
        }
        q.pop();
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (auto &x : v) {
        cout << x << " ";
    }
}