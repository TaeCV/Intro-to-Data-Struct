#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, target, temp;
    unordered_map<int, int> M;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        M[a[i]]++;
    }
    while (m--) {
        cin >> target;
        bool isFound = false;
        for (int i = 0; i < n; ++i) {
            temp = target - a[i];
            if (temp < 0 || temp > 999999)
                continue;
            if (temp == a[i] && M[temp] >= 2) {
                isFound = true;
            } else if (temp != a[i] && M[temp] > 0) {
                isFound = true;
            }
            if (isFound) {
                break;
            }
        }
        if (isFound) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}