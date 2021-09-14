#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long a, b;
    cin >> n >> m;
    set<pair<long long, long long>> s;
    while (n--) {
        cin >> a >> b;
        s.emplace(a, b);
    }
    while (m--) {
        cin >> a;
        pair<long long, long long> temp(a, a);
        auto it = s.lower_bound(temp);
        if (it == s.begin()) {
            if (a >= it->first && a <= it->second) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        } else {
            if (a == it->first) {
                cout << "1 ";
                continue;
            }
            it--;
            if (a > it->second) {
                cout << "0 ";
            } else {
                cout << "1 ";
            }
        }
    }
}

/*
3 5
10 20
5 7
2 2
5 1 2 100000 20
*/