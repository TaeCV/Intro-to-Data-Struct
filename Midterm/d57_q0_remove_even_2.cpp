#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v, int a, int b) {
  // write your code only in this function
  auto it = v.begin();
  int n;
  if (a % 2 == 0) {
    n = (b - a) / 2;
    it += a;
  } else {
    n = (b - a - 1) / 2;
    it += a + 1;
  }
  for (int i = 0; i <= n; i++) {
    { v.erase(it + i); }
  }
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
  remove_even(v, a, b);
  // display content of the vector
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}