#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m = 1;
    int k, c = 0;
    cin >> n >> k;
    if (k == 1)
        cout << n - 1;
    else {
        for (n -= m; n > 0; c++) {
            m *= k;
            n -= m;
        }
        cout << c;
    }
}