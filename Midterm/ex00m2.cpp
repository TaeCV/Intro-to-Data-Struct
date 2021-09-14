#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, amount, user, item, value, count;
    char c;
    unordered_map<int, int> items;
    unordered_map<int, vector<int>> ans;
    cin >> n >> m >> a;
    for (int i = 0; i < n; ++i) {
        cin >> amount;
        items[i] = amount;
    }
    unordered_map<int, map<int, int>> users;
    while (a--) {
        cin >> c;
        if (c == 'B') {
            cin >> user >> item >> value;
            users[item - 1][user - 1] = value;
        } else if (c == 'W') {
            cin >> user >> item;
            users[item - 1][user - 1] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        count = 0;
        priority_queue<pair<int, int>> pq;
        for (auto &x : users[i]) {
            pq.emplace(x.second, x.first);
        }
        while (count != items[i] && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if (temp.first <= 0) {
                break;
            } else {
                ans[temp.second].push_back(i);
                count++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans[i].empty()) {
            cout << "NONE\n";
        } else {
            for (auto &x : ans[i]) {
                cout << x + 1 << " ";
            }
            cout << "\n";
        }
    }
}
