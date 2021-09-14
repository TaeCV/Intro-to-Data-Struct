#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, input;
  string key;
  vector<int> v;
  cin >> n;
  while (n--) {
    cin >> key;
    if (key.compare("pb") == 0) {
      cin >> input;
      v.push_back(input);
    } else if (key.compare("sa") == 0) {
      sort(v.begin(), v.end());
    } else if (key.compare("sd") == 0) {
      sort(v.begin(), v.end(), greater<int>());
    } else if (key.compare("r") == 0) {
      int temp = v.size();
      for (int i = v.size() - 2; i >= 0; --i) {
        v.push_back(v[i]);
      }
      v.erase(v.begin(), v.begin() + temp - 1);
    } else if (key.compare("d") == 0) {
      cin >> input;
      v.erase(v.begin() + input);
    }
  }
  for (auto &x : v) {
    cout << x << " ";
  }
}