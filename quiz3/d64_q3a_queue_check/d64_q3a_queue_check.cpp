#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mFront, mSize, mCap, last, correction;
    while (n--) {
        cin >> mFront >> mSize >> mCap >> last >> correction;
        bool isCorrect = true;
        int newValue;
        if (mFront >= mCap || mSize > mCap || last > mCap || last != (mFront + mSize) % mCap)
            isCorrect = false;
        if (correction == 0) {
            if (isCorrect) {
                cout << "OK\n";
            } else {
                cout << "WRONG\n";
            }
        } else if (correction >= 1 && correction <= 4) {
            if (isCorrect) {
                cout << "OK\n";
            } else {
                if (correction == 1) {
                    if (last < mSize) {
                        newValue = last + mCap - mSize;
                    } else {
                        newValue = last - mSize;
                    }
                } else if (correction == 2) {
                    if (last < mFront) {
                        newValue = last + mCap - mFront;
                    } else {
                        newValue = last - mFront;
                    }
                } else if (correction == 3) {
                    if (last == mFront + mSize) {
                        newValue = last + 1;
                    } else {
                        newValue = mSize + mFront - last;
                    }
                } else if (correction == 4) {
                    newValue = (mFront + mSize) % mCap;
                }
                cout << "WRONG " << newValue << "\n";
            }
        }
    }
}