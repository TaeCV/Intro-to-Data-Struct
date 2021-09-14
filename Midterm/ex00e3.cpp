#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, temp;
    set<int> s;
    bool is11 = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp < 1 || temp > n) {
            is11 = false;
            break;
        }
        if (s.find(temp) == s.end()) {
            s.insert(temp);
        } else {
            is11 = false;
            break;
        }
    }
    if (is11) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}