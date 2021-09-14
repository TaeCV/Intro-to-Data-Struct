#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b) {
  // write your code only in this function
  int s = a - v.begin();
  int e = b - 1 - v.begin();

  for (int i = s; i < e; ++i) {
    v.insert(v.begin() + e + 1, v[i]);
  }
  v.erase(v.begin() + s, v.begin() + e);
}
int main() {
  // read input
  int n, a, b;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    v.push_back(c);
  }
  cin >> a >> b;
  // call function
  reverse(v, v.begin() + a, v.begin() + b + 1);
  // display content of the vector
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}