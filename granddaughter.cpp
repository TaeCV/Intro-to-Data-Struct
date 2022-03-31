#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, M, D, K;
    cin >> N;
    vector<int> p(MAXN), g(MAXN, 0);
    for (int i = 0; i < N; ++i) {
        cin >> M >> D;
        p[D] = M;
    }
    cin >> K;
    for (int i = 1; i < MAXN; ++i)
        if (p[i] && p[p[i]])
            g[p[p[i]]]++;
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i < MAXN; ++i)
        if (g[i])
            pq.push({g[i], -i});
    while (K-- && !pq.empty()) {
        cout << -pq.top().second << "\n";
        pq.pop();
    }
}