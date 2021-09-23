#include <bits/stdc++.h>

using namespace std;

// 6
bool operator<(const other &s2) {
    CP::stack<T> a = *this, b = s2;
    while (!a.empty() && !b.empty()) {
        if (a.top() != b.top())
            return a.top() < b.top();
        a.pop();
        b.pop();
    }
    if (b.empty()) {
        return false;
    }
    return true;
}

// 7
template <typename T>
vector(const queue<T> &q) {
    queue<T> tmp = q;
    mData = new T[tmp.size()]();
    for (int i = tmp.size() - 1; i >= 0; --i) {
        mData[i] = tmp.front();
        tmp.pop();
    }
    mCap = tmp.size();
    mSize = tmp.size();
}

// 8
class MultiAuction {
protected:
    map<string, pair<int, priority_queue<pair<pair<int, int>, string>>>> items; // key = item name, mapped value = pair of its document
    // items[item].first = quantity of item, items[item].second= queue of bidding which sort by bidding price and user idx which use pq.size() at the time that user bid
    // items[item].second.top().first = pair of bidding price and idx of bidding, items[item].second.top().second = user name
public:
    void open_auction(string item, int qty) {
        priority_queue<pair<pair<int, int>, string>> pq;
        items[item] = {qty, pq};
    }

    void add_bidding(string user, string item, int price) {
        int n = items[item].second.size();
        items[item].second.push({{price, -n}, user});
    }

    vector<pair<string, int>> close_auction(string item) {
        int total_qty = items[item].first;
        vector<pair<string, int>> res;
        while (total_qty > 0 && !items[item].second.empty()) {
            string user = items[item].second.top().second;
            int price = items[item].second.top().first.first;
            if (ask_user_confirmation(user, item, price)) {
                res.push_back({user, price});
                total_qty--;
            }
            items[item].second.pop();
        }
        // items.erase(item); => no need for the requirement but to reduce memory
        return res;
    }
    // bool ask_user_confirmation(string user,string item,int price) => ask users to confirm bidding
};

// 9
stack<T> union(stack<T> s2) {
    MyClass::stack<T> tmp, res;
    std::set<T> s;
    while (!empty()) {
        s.insert(top());
        tmp.push(top());
        pop();
    }
    while (!s2.empty()) {
        if (s.find(s2.top()) == s.end()) {
            tmp.push(s2.top());
        }
        s2.pop();
    }
    while (!tmp.empty()) {
        res.push(tmp.top());
        tmp.pop();
    }
    return res;
}

// 10
vector<T> removeDup() {
    CP::vector<T> v;
    for (int i = 0; i < mSize; i++) {
        bool isDup = false;
        for (int j = 0; j < v.size(); j++) {
            if (mData[i] == v[j]) {
                isDup = true;
                break;
            }
        }
        if (!isDup)
            v.push_beck(mData[i]);
    }
    return v;
}

// 11
// vector<queue<pair<T,int>>> v
bool empty() const {
}

size_t size() const {
}

const T &top() const {
}

void push(const T &e) {
}

void pop() {
}

// 12
void insertAt(int k, const CP::queue<T> &q) {
    CP::queue<T> newq;
    for (int i = 0; i < k; i++) {
        newq.push(front());
        pop();
    }
    for (int i = 0; i < q.size(); i++) {
        newq.push(q.mData[(i + q.mFront) % q.mCap]);
    }
    for (int i = k; i < mSize; i++) {
        newq.push(front());
        pop();
    }
    *this = newq;
}

// 13
void removeAt(int k, int m) {
    int pos = mSize - k;
    for (int i = pos; i < mSize; i++) {
        mData[pos - m] = mData[pos];
    }
    mSize -= m;
}