#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long f, s;
    bool isSame;
    map<long long, long long> M;
    cin >> n >> m;
    while (n--) {
        cin >> f >> s;
        M[s] = f;
    }
    while (m--) {
        cin >> f >> s;
        isSame = false;
        if (M.find(f) != M.end() && M.find(s) != M.end() && f != s) {
            if (M.find(M[f]) != M.end() && M.find(M[s]) != M.end()) {
                if (M[M[f]] == M[M[s]]) {
                    isSame = true;
                }
            }
        }
        if (isSame) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
