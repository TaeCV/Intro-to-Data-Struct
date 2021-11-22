#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, num, power;
    map<int, int> cards;
    cin >> n >> m;
    while (n--) {
        cin >> power;
        cards[power]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> power;
            auto it = cards.upper_bound(power);
            if (it == cards.end()) {
                cout << i;
                return 0;
            }
            if (it->second > 1) {
                it->second--;
            } else {
                cards.erase(it);
            }
        }
    }
    cout << m + 1;
}