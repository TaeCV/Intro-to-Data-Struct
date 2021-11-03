#include <bits/stdc++.h>
using namespace std;

void rec(int step, int end) {
    if (step < end) {
        rec(step + 1, end);
        cout << step << " ";
    }
}

int main() {
    rec(0, 5);
}