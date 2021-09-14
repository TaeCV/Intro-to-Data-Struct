#include <iostream>

using namespace std;

int main() {
    int n, m, target, temp;
    bool chk1[1000000], chk2[1000000];
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (chk1[a[i]]) {
            chk2[a[i]] = true;
        } else {
            chk1[a[i]] = true;
        }
    }
    while (m--) {
        cin >> target;
        bool isFound = false;
        for (int i = 0; i < n; ++i) {
            temp = target - a[i];
            if (temp < 0 || temp > 999999)
                continue;
            if (temp == a[i]) {
                isFound = chk2[temp];
            } else {
                isFound = chk1[temp];
            }
            if (isFound)
                break;
        }
        if (isFound) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}