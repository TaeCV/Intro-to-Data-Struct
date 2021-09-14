#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> m;
    string s;
    while (n--) {
        cin >> s;
        m[s]++;
    }
    for (auto &x : m) {
        if ((x.second) > 1) {
            cout << x.first << " " << x.second << "\n";
        }
    }
}