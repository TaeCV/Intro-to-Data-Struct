#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    map<string, int> m;
    map<int, int> counting;
    set<int> st;
    cin >> n >> k;
    while (n--) {
        cin >> s;
        m[s]++;
        counting[m[s]]++;
        if (m[s] > 1) {
            counting[m[s] - 1]--;
        }
    }
    if (m.size() <= k) {
        for (auto it = counting.begin(); it != counting.end(); ++it) {
            if (it->second == 0) {
                continue;
            } else if (it->second > 0) {
                cout << it->first;
                break;
            }
        }
    } else {
        for (auto it = counting.rbegin(); it != counting.rend(); ++it) {
            k -= it->second;
            if (k <= 0) {
                cout << it->first;
                break;
            }
        }
    }
}