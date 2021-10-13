// 1
vector<int> removeAll(vector<int> &v1, int x) {
    vector<int> res;
    for (auto &y : v1)
        if (y != x)
            res.push_back(y);
    return res;
}

// 2
string getTodayCleaner() {
    string name;
    if (!q2.empty()) {
        name = q2.front();
        q2.pop();
    } else {
        name = q1.front();
        q1.pop();
    }
    q1.push(name);
    return name;
}

void addNewMember(string name) {
    q2.push(name);
}

// 3
//3.1
/*
a) {3,2,1}
b) {1,2,4,3}
c) {3,5,8,7,6,4,2,1}
*/
//3.2
vector<bool> inverse(vector<int> desired_result) {
    vector<bool> input;
    int number = 1;
    for (auto &x : desired.result) {
        while (number <= x) {
            input.push_back(true);
            number++;
        }
        input.push_back(false);
    }
    return input;
}

// 4
vector<string> getCousin(const vector<string> &name, const vector<pair<string, string>> &father, string query) {
    vector<string> result;
    map<string, string> relation;
    string queryDad, grandDad;
    for (auto &eachP : father) {
        relation[each.second] = each.first;
        if (query == each.second)
            queryDad = each.first;
    }
    auto it = relation.find(queryDad);
    if (queryDad != "" && it != relation.end()) {
        grandDad = it->second;
        for (auto &each : name) {
            if (each != query && relation.find(each) != relation.end() && relation[each] != queryDad && relation.find(relation[each]) != relation.end() && relation[relation[each]] == grandDad) {
                result.push_back(each);
            }
        }
    }
    return result;
}

// 5
void removeMin(priority_queue<int> &pq) {
    if (pq.empty())
        return;
    priority_queue<int> pq2;
    while (pq.size() > 1) {
        pq2.push(pq.top());
        pq.pop();
    }
    pq = pq2;
}

// 6
// a)
ใช้ library vector และ algorithm โดยทำการเก็บข้อมูลลงบน vector โดยทุกครั้งที่เราใส่ข้อมูลเข้ามาใน vector(push)
    ให้ทำการ std::sort หากต้องการจะดูข้อมูลก็สามารถเรียกใช้ back() จาก vector ที่เราเก็บข้อมูลไว้ได้และเราก็สามารถ pop ด้วย pop_back() จาก vector
// b)
#include <algorithm>
#include <vector>

    template <typename T>
    class MyPriorityQ {
public:
    std::vector<T> v;
    T top() {
        return v.back();
    }

    void pop() {
        v.pop_back();
    }

    void push(T x) {
        v.push_back(x);
        std::sort(v.begin(), v.end());
    }
};

// 7
int totalCost() {
    int res = genericCost;
    for (auto &x : elementCost)
        res += x.second;
    return res;
}

bool operator<(const Card &other) {
    int totalCost1 = totalCost(), totalCost2 = other.totalCost();
    if (totalCost1 != totalCost2)
        return totalCost1 < totalCost2;
    return name < other.name;
}

// 8
void duplicateElements(const vector<vector<T>::iterator> &its) {
    mCap = mSize + its.size();
    T *arr = new T[mCap]();
    int c = 0;
    for (int i = 0, j = 0; i < mSize; i++) {
        if (j < its.size() && i == its[j] - begin()) {
            arr[c++] = mData[i];
            j++;
        }
        arr[c++] = mData[i];
    }
    mSize = c;
    delete[] mData;
    mData = arr;
}

// 9
void remove_all(const T &data) {
    int c = 0;
    for (int i = 0; i < mSize; ++i) {
        if (mData[i] != data) {
            mData[c++] = mData[i];
        }
    }
}

// 10
vector<queue<T>> split_queue(int k) {
    vecotr<queue<T>> v(k);
    int c = 0;
    while (!empty()) {
        v[(c++) % k].push(front());
        pop();
    }
    return v;
}