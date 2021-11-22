
// void remove_colliding_key(const KeyT &m) {
//     size_t bi = hash_to_bucket(m);
//     mSize -= mBuckets[bi].size();
//     mBuckets[bi].clear();
// }

// vector<size_t> min_hash_signature(set<int> A, vector<HasherT> hs) {
//     vector<size_t> ans(hs.size());

//     for (int i = 0; i < hs.size(); ++i) {
//         size_t mx = 0;
//         auto it = A.begin();
//         ans[i] = hs[i](*it);
//         ++it;
//         while (it != A.end()) {
//             if (hs[i](*it) > ans[i])
//                 ans[i] = hs[i](*it);
//             ++it;
//         }
//     }
// }

// float min_hash_estimate(vector<size_t> as, vector<size_t> bs) {
//     map<size_t, int> m;
//     int dup = 0.0;
//     for (auto &x : as)
//         m[x]++;
//     for (auto &x : bs) {
//         if (m.find(x) != m.end())
//             dup += m[x];
//     }
//     return (dup + 0.0) / as.size();
// }
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 10;
    a -= 5 + 1;
    cout << a;
}

while(true){
    int left_size = 0;
    if(n->left) left_size = n->left.tSize;
    if(k<left_size) n= n->left;
    else if (k == left_size ) return iterator(n);
    else {
        k -= left_size +1;
        n=n->right;
    }
}