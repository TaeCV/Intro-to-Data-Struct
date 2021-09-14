#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, count, time = 0, temp;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> count;
        pq.push(make_pair(count, count));
    }
    if (m < n) {
        count = m;
    } else {
        count = n;
    }
    for (int i = 0; i < count; ++i) {
        cout << "0\n";
    }
    vector<pair<int, int>> v;
    pair<int, int> p;
    while (count != m) {
        temp = pq.top().first;
        for (int i = 0; i < n; ++i) {
            p = pq.top();
            pq.pop();
            v.push_back(make_pair(p.first - temp, p.second));
        }
        time += temp;
        while (!v.empty()) {
            auto x = v.back();
            v.pop_back();
            if (x.first <= 0) {
                count++;
                cout << time << "\n";
                pq.push(make_pair(x.first + x.second, x.second));
            } else {
                pq.push(make_pair(x.first, x.second));
            }
            if (count == m) {
                break;
            }
        }
    }
}