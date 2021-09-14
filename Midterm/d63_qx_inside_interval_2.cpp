#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long a, b;
    vector<long long> v;
    cin >> n >> m;
    while (n--) {
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    while (m--) {
        cin >> a;
        auto it = lower_bound(v.begin(), v.end(), a);
        if (((it - v.begin()) % 2 == 0 && a < *it) || (it == v.end() && a > *it)) {
            cout << "0 ";
        } else {
            cout << "1 ";
        }
    }
}