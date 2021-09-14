#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    string s;
    int n, mx = 0;
    cin >> n;
    while (n--) {
        cin >> s;
        m[s]++;
        if (m[s] > mx) {
            mx = m[s];
        }
    }
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        if (it->second == mx) {
            cout << it->first << " " << it->second;
            break;
        }
    }
}
