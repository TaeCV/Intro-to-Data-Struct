#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long n;
    cin >> n;
    if (n)
        cout << (int)pow(2, ceil(log2(n))) - n;
    else
        cout << 1;
}