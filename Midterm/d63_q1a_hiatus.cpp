#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, year, month;
    cin >> n >> m;
    set<pair<int, int>> s;
    while (n--) {
        cin >> year >> month;
        s.emplace(year, month);
    }
    while (m--) {
        cin >> year >> month;
        pair<int, int> temp = {year, month};
        auto it = s.lower_bound(temp);
        if (s.find(temp) != s.end()) {
            cout << "0 0 ";
        } else {
            if (it == s.begin()) {
                cout << "-1 -1 ";
            } else {
                it--;
                cout << it->first << " " << it->second << " ";
            }
        }
    }
}