#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c, time;
    cin >> n >> m;
    vector<int> seat;
    for (int i = 0; i < n; i++) {
        cin >> c;
        seat.push_back(c);
    }
    if (m < n) {
        c = m;
    } else {
        c = n;
    }
    for (int i = 0; i < c; ++i) {
        cout << "0\n";
    }
    sort(seat.begin(), seat.end());
    time = *(seat.begin());
    while (c != m) {
        for (auto &x : seat) {
            if (c == m || time < x)
                break;
            if (time % x == 0) {
                cout << time << "\n";
                c++;
            }
        }
        time++;
    }
}