// 1
/*
1.1 map<string,vector<float>> key = รหัส, mapped value = list of เกรดเฉลี่ยแต่ละเทอม
1.2 vector<pair<string,int>> 
1.3 map<string,set<string>> key = รหัส, mapped value = setของรหัสวิชา
1.4 pair<pair<float,float>,float>
1.5 map<string,bool> รหัส->เป็นสมาชิกหรือไม่
*/

// 2
/*
2.1 average
2.2 2nd max
2.3 sort by decending order
2.4 max-min
2.5 find key map value which equals to x
*/

// 5
void merge(map<string, int> &m1, const map<string, int> &m2) {
    for (auto &x : m2) {
        m1[x.first] += x.second;
    }
}

vector<pair<int, int>> get_zero_positions(const vector<vector<int>> &v) {
    vector<pair<int, int>> res;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 0)
                res.push_back({i, j});
        }
    }
    return res;
}

map<string, set<string>> get_followers(const map<string, set<string>> following) {
    map<string, set<string>> follow;
    for (auto &x : following) {
        for (string name : x.second) {
            follow[name].insert(x);
        }
    }
    return follow;
}

set<int> common(const set<int> &s1, const set<int> &s2) {
    set<int> s;
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end() && it2 != s2.end()) {
        if (*it1 < *it2)
            it1++;
        else if (*it1 > *it2)
            it2++;
        else {
            s.insert(*it1);
            it1++;
            it2++;
        }
    }
    return s;
}

// 6
// queue
my_queue(const my_queue<T> &q) { pq = q.pq; }
bool empty() const { pq.empty(); }
size_t size() const { pq.size(); }
cosnt T &top() const { pq.top().second; }
void pop() { pq.pop(); }
void push(cosnt T &element) {
    pq.push({-pq.size(), element});
}

// stack
my_stack(const my_stack<T> &q) { pq = q.pq; }
bool empty() const { pq.empty(); }
size_t size() const { pq.size(); }
cosnt T &top() const { pq.top().second; }
void pop() { pq.pop(); }
void push(cosnt T &element) {
    pq.push({pq.size(), element});
}

// 7
bool insert(const T &val) {
    if (find(val) != end())
        return false;
    int i;
    while (i < mSize && mData[i] < val)
        i++;
    for (int j = i; j < mSize; j++) {
        mData[j + 1] = mData[j];
    }
    mData[i] = val;
    mSize++;
    return true;
}

bool erase(const T &val) {
    auto it = find(val);
    if (it == end())
        return false;
    for (int i = it - begin(); i < mSize - 1; i++) {
        mData[i] = mData[i + 1];
    }
    mSize--;
    return true;
}

// 8
class PersonDB {
private:
    map<pair<string, string>, string> info;

public:
    PersonDB() {}
    void addPerson(string &firstName, string &lastName, string &ID) {
        info[{lastName, firstName}] = ID;
    }
    string getIDofPerson(string &firstName, string &lastName) {
        auto it = info.find({lastName, firstName});
        if (it != info.end()) {
            return it->second;
        }
        return "";
    }
    vector<string> getIDofPersonWithLastName(string &lastName) {
        vector<string> v;
        auto it = info.lower_bound({lastName, ""});
        while (it != info.end() && it->first.first == lastName) {
            v.push_back(it->second);
            it++;
        }
        return v;
    }
};

// 9
void eraseAllWithValue(const T &x) {
    int c = 0;
    for (int i = 0; i < mSize; i++) {
        if (mData[i] != x) {
            mData[c++] = mData[i];
        }
    }
    mSize = c;
}

// 10
void insertAt(int k, const std::vector<T> &v) {
    queue<T> q;
    while (k > 0 && !empty()) {
        q.push(front());
        pop();
        k--;
    }
    for (auto x : v)
        q.push(x);
    while (!empty()) {
        q.push(front());
        pop();
    }
    *this = q;
}