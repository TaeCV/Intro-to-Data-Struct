// 1
/*
1.1 map<string,string> key =ป้ายทะเบียน mapped value = ชิ่อเจ้าของรถ
1.2 stack<pair<string,string>>
1.3 set<pair<int,string>>
1.4 map<int,map<string,pair<float,int>>>
*/

// 2
/*
2.1 reverse member of original vector
2.2 return vector of pair ที่มาจาก v โดยเลือก pair ที่มี first เท่ากับ x
2.3 return set ที่มีสมาชิกใน s1 แต่ไม่อยู่ใน s2
2.4 print ค่า pair ใน map ที่มี second > word ตามหลักพจนานุกรมโดย print in this form (first , second)
2.5 เอาค่า v ไปใส่ไว้ในตำแหน่ง i ของ a ถ้า i น้อยกว่า 0 หรือ i มากกว่าขนาดของ a จะไม่ทำอะไร
*/

// 3
void removeSecondMax(priority_queue<int> &pq) {
    queue<int> q;
    for (int i = 0; i < 3 < i++) {
        q.push(pq.top());
        pq.pop();
    }
    for (int i = 0; i < 2; i++) {
        pq.push(q.front());
        q.pop();
    }
}

// 4
bool operator()(const Student &s1, const Student &s2) const {
    if (s1.age != s2.age)
        return s1.age > s2.age;
    if (s1.fname != s2.fname)
        return s1.fname < s2.fname;
    return s1.lname < s2.lname;
}

// 5
map<int, int> get_h(const map<int, int> &f_x, const map<int, int> &g_f, const map<int, int> &h_g) {
    map<int, int> h_x;
    for (auto &x : f_x)
        h_x[x.first] = h_g[g_f[x.second]];
    return h_x;
}

// 6
vecotr<int> get_intersect(const vector<int> &v1, const vector<int> &v2) {
    vector<int> result;
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end()) {
        if (*it1 > *it2)
            it2++;
        else if (*it1 < *it2)
            it1++;
        else {
            res.push(*it);
            it1++;
            it2++;
        }
    }
    return result;
}

// 7
void insert_to(itertator it, const vector<T> &v) {
    int n = v.size(), pos = it.begin();
    ensureCapacity(mSize + n);
    for (int i = pos; i < mSize; i++)
        mData[n + i] = mData[i];
    for (int i = 0; i < n; i++)
        mData[pos + i] = v[i];
    mSize += n;
}

// 8
void make_unique(queue<int> &q) {
    set<int> s;
    for (int i = 0; i < q.size(); i++) {
        if (s.find(q.front()) == s.end()) {
            q.push(q.front());
            s.insert(q.front());
        }
        q.pop();
    }
}

// 9
const T &top() const {
    return (mData.end() - 1)->second;
}

void push(cosnt T &element) {
    mData.insert(make_pair(mData.size(), element));
}

void pop() {
    mData.erase(mData.end() - 1);
}

// 10
class Library {
protected:
    map<pair<string, string>, int> books;
    vector<int> stocks;

public:
    int current_stock(string author, string title) {
        if (books.find({author, title}) != books.end()) {
            return stocks[books[{author, title}]];
        }
        return -1;
    }

    vector<pair<string, int>> books_by_author(string author) {
        vector<pair<string, int>> res;
        auto it = books.find({author, ""});
        while (it != books.end() && it->first == author) {
            res.push_back(make_pair(it->first.second, stocks[it->second]));
            it++;
        }
        return res;
    }

    void registerNewBook(string author, string title) {
        auto it = books.find({author, title});
        if (it != books.end()) {
            stocks[it->second]++;
        } else {
            books[{author, title}] = stocks.size();
            stocks.push_back(1);
        }
    }

    void book_borrow(int barcode) {
        stocks[barcode]--;
    }
    void book_return(int barcode) {
        stocks[barcode]++;
    }
}