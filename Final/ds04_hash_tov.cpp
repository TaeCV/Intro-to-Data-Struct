#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void hash_to_vector(unordered_map<int, string> hash, vector<int> &key, vector<string> &value) {
    // write your code only here
    for (auto each : hash) {
        key.push_back(each.first);
        value.push_back(each.second);
    }
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, string> hash;
    while (n--) {
        int a;
        string st;
        cin >> a >> st;
        hash[a] = st;
    }

    vector<int> k;
    vector<string> v;
    hash_to_vector(hash, k, v);
    for (auto &x : k)
        cout << x << " ";
    cout << endl;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}