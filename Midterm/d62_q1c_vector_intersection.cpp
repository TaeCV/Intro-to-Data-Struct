#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    unsigned int temp;
    set<unsigned int> s1, s2;
    cin >> m >> n;
    while (m--) {
        cin >> temp;
        s1.insert(temp);
    }
    while (n--) {
        cin >> temp;
        s2.insert(temp);
    }
    for (auto &x : s1) {
        if (s2.find(x) != s2.end()) {
            cout << x << " ";
        }
    }
}
