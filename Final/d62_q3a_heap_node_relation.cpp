#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        bool isEqual = false;
        cin >> a >> b;
        if (a == b)
            cout << "a and b are the same node\n";
        else {
            if (a > b) {
                while (a > b) {
                    a = (a - 1) / 2;
                    if (a == b) {
                        isEqual = true;
                        cout << "b is an ancestor of a\n";
                    }
                }
            } else {
                while (b > a) {
                    b = (b - 1) / 2;
                    if (a == b) {
                        isEqual = true;
                        cout << "a is an ancestor of b\n";
                    }
                }
            }
            if (!isEqual)
                cout << "a and b are not related\n";
        }
    }
}