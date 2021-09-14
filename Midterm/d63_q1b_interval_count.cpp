#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long k, input;
    vector<long long> v;
    cin >> n >> m >> k;
    while (n--) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    while (m--) {
        cin >> input;
        auto it1 = lower_bound(v.begin(), v.end(), input - k);
        auto it2 = upper_bound(v.begin(), v.end(), input + k);
        cout << it2 - it1 << " ";
    }
}
/*
5 5 1
1 3 5 9 10
1 2 3 7 20

1 2 1 0 0

3 5 1000000
1000000 1 2000001
1000000 1000001 1 2 3

2 3 2 2 2

3 5 0
4 8 2
1 2 3 4 5

0 1 0 1 0 
*/