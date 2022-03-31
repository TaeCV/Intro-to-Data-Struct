#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, K;
    string A, B;
    cin >> N;
    map<pair<string, string>, int> C;
    for (int i = 0; i < N; ++i) {
        cin >> A >> B;
        if (A < B)
            C[{A, B}]++;
        else
            C[{B, A}]++;
    }
    cin >> K;
    vector<pair<int, pair<string, string>>> tmp;
    for (auto x : C) {
        tmp.push_back({-x.second, x.first});
    }
    sort(tmp.begin(), tmp.end());
    K = K < tmp.size() ? K : tmp.size();
    for (int i = 0; i < K; ++i) {
        cout << tmp[i].second.first << " " << tmp[i].second.second << "\n";
    }
}