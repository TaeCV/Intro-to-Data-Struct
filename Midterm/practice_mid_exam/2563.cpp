// 1
/*
1.1 map<string,vector<pair<string,string>>> key = สถานที่ mapped value = list of pair ของ ชื่อร้านและประเภทอาหารที่ขาย
1.2 map<pair<string,int>,pair<string,int>> key = pair of ชื่อเรื่องและหมายเลขเล่ม  mapped value = pair of เรื่องย่อและจำนวนเล่ม
1.3 map<string,vector<string>> key = เลขประจำตัว mapped value = list of check in time
*/

// 2
// 35,5

// 3
// A,B,B,A

// 4
/*
5 5 5
16 15 15
32 32 0
*/

// 5
/* 
No 2
No 5
Yes 62
*/

// 7
for (auto &x : m) {
    cout << x.first << "\n";
    while (!x.second.empty()) {
        while (!x.second.front().empty()) {
            cout << x.second.front().top() << " ";
            x.second.front().pop();
        }
        x.second.pop();
    }
}

// 8
void unique() {
    int c = 0;
    for (int i = 0; i < mSize; i++) {
        if (i == mSize - 1 || mData[i] != mData[i + 1]) {
            mData[c++] = mData[i];
        }
    }
    mSize = c;
}

// 9
// a)
typedef pair<string, pair<int, int>> Monster;
// b)
vector<Monster> findAttackGE(vector<Monster> v, int atk) {
    vector<Monster> result;
    for (Monster each : v) {
        if (each.second.first >= atk)
            result.push_back(each);
    }
    return result;
}
// c)
void removeDefBetween(int startValue, int endValue, vector<Monster> &v) {
    vector<Monster> res;
    for (auto &x : v) {
        if (x.second.second < startValue || x.second.second > endValue)
            res.push_back(x);
    }
    v = res;
}

// 10
stack<int> topNBetweenM(stack<int> s1, stack<int> s2, int n, int m) {
    stack<int> tmp;
    n = n > s1.size() ? s1.size() : n;
    m = m > s2.size() ? s2.size() : m;
    for (int i = 0; i < n; i++) {
        tmp.push(s1.top());
        s1.pop();
    }
    for (int i = 0; i < s2.size() - m; i++) {
        s2.pop();
    }
    while (!tmp.empty()) {
        s2.push(tmp.top());
        tmp.pop();
    }
    return s2;
}

// 11
void printQueueFromBack() {
    for (int i = mSize - 1; i >= 0; --i) {
        cout << mData[(mFront + i) % mCap] << " ";
    }
    cout << "\n";
}

void reverse() {
    int front = mFront;
    int back = mFront + mSize - 1;
    while (front < back) {
        std::swap(mData[front % mCap], mData[back % mCap]);
        front++;
        back--;
    }
}

// 12
class inside_building {
protected:
    map<string, int> buildings;                      // key = building's name, mapped value = idx of building's info
    vector<queue<pair<string, int>>> building_queue; // each collect queue of pair of name and checkin time
    vector<map<string, int>> name_checkin_record;    // key = name, mapped value = checkin time

public:
    void check_in(string building, string name) {
        if (buildings.find(building) == buildings.end()) {
            buildings[building] = building_queue.size();
        }
        int idx = buildings[building];
        building_queue[idx].push({name, get_time()});
        name_checkin_record[idx][name] = get_time();
    }
    void check_out(string building, string name) {
        int idx = buildings[building];
        name_checking_record[idx].erase(name);
    }
    int how_many(string building) {
        int idx = buildings[building];
        while (building_queue[idx].front().second < get_time() - 7200) {
            string name = building_queue[idx].front().first;
            auto it = name_checkin_record[idx].find(name);
            if (it != name_checkin_record[idx].end() && it->second == building_queue[idx].front().second) {
                name_checking_record[idx].erase(it);
            }
            building_queue[idx].pop();
        }
        return name_checking_record[idx].size();
    }
};