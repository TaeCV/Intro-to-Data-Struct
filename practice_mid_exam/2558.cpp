// 1
/*
1.1 move_right_kth v=<5,4,3,4,1>
1.2 sort_member v=<1,3,4,5,6>
1.3 kth_min 3
1.4 filter_duplicate q=[3,4,1,5]
*/

//2
/*
2.1 vector<vector<float>>
2.2 map<float,map<int,float>>
2.3 vector<float>
*/

//4
template <typename T>
vector<T> alternate(const vector<T> &v1, const vector<T> &v2) {
    vector<T> output(v1.size() + v2.size());
    int n = std::max(v1.size(), v2.size()), c = 0;
    for (int i = 0; i < n; i++) {
        if (i < v1.size())
            output[c++] = v1[i];
        if (i < v2.size())
            output[c++] = v2[i];
    }
    return output;
}

//5
typedef vector<pair<pair<int, int>, float>> SparseMat;
SparseMat addSparseMatrix(const SparseMat &M, const SparseMat &N) {
    map<pair<int, int>, float> m;
    for (auto &x : M)
        m[x.first] += x.second;
    for (auto &x : N)
        m[x.first] += x.second;
    SparseMat output;
    for (auto &x : m)
        if (x.second != 0)
            output.push_back(make_pair(x.first, x.second));
    return output;
}

// 6
string whoWin(const queue<pair<string, int>> &p, const int x) {
    queue<pair<string, int>> q(p);
    string name;
    for (int i = 0; i < x; ++i) {
        int k = q.front().second;
        for (int j = 0; j < k; ++j) {
            q.push(q.front());
            q.pop();
        }
    }
    return q.front().first;
}

// 7
vector<int> getWorkAssignments(const vector<float> &s, int K) {
    vector<int> v(s.size());
    priority_queue<pair<float, int>> pq;
    for (int i = 0; i < s.size(); i++)
        pq.push(make_pair(-1 / s[i], i));
    for (int i = 0; i < K; i++) {
        v[pq.top().second]++;
        pq.push(make_pair(pq.top().first - 1 / s[pq.top().second], pq.top().second));
        pq.pop();
    }
    return v;
}

// 8
void printGrandfatherGrandson(const vector<string> &name, const vector<pair<string, string>> &parent) {
    map<string, vector<string>> m;
    for (auto &x : parent)
        m[x.first].push_back(x.second); // key = dad, value = vector of child
    for (auto &each : name) {
        bool haveGrandChild = false;
        if (m.find(each) != m.end()) {
            // have child
            for (auto &child : m[each]) {
                if (m.find(child) != m.end()) {
                    if (!haveGrandChild) {
                        cout << each << " is a grandfather with the following grandson(s): ";
                        haveGrandChild = true;
                    }
                    for (auto &grand : m[child])
                        cout << grand << " ";
                }
            }
        }
        if (haveGrandChild)
            cout << "\n";
    }
}
// 9
T get_k(int k) {
    return mData[(mFront + k) % mCap];
}

// 10
void make_unique() {
    T *arr = newT[mCap]();
    for (int i = 0, c = 0; i < mSize; ++i) {
        bool isDup = false;
        for (int j = 0; j < i; ++j) {
            if (mData[i] == mData[j]) {
                isDup = true;
                break;
            }
        }
        if (!isDup)
            arr[c++] = mData[i];
    }
    delete[] mData;
    mData = arr;
    mSize = c;
}
