#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k) {
  // write some code here
  // don’t forget to return something
  vector<string>::iterator s, e;
  int pos = it - v.begin();
  if (pos < k) {
    s = v.begin();
  } else {
    s = it - k;
  }
  if (pos + k >= v.size()) {
    e = v.end();
  } else {
    e = it + k + 1;
  }
  v.erase(s, e);
  return v;
}
int main() {
  int n, j, k;
  cin >> n >> j >> k;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << "Result after punch" << endl;
  vector<string> result = punch(v, v.begin() + j, k);
  for (auto &x : result) {
    cout << x << endl;
  }
}