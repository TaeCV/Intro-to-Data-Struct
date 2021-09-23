#include <bits/stdc++.h>

using namespace std;

class Library {
protected:
    vector<int> stock;                      //map from id to stock
    map<pair<string, string>, int> barcode; // map from author/title to barcode
public:
    void registerNewBook(string author, string title) {
    auto it = barcode.find( {
            author, title}
    }
    if (it == barcode.end()) {
        barcode[{author, title}] = stock.size();
        stock.push_back(1);
    } else {
        stock[it->second]++;
    }
} void borrow(int barcode) {
    stock[barcode]--;
}
void return (int barcode) {
    stock[barcode]++;
}
int current_stock(string title, string author) {
 auto it = stock.find( {
        author, title}
}
if (it == stock.end())
    return -1;
return stock[it->second];
}
vector<pair<string, int>> books_by_author(string author) {
    vector<pair<string, int>> result;
    auto it = stock.find({author, ""});
    while (it != stock.end() && it->first.first == author) {
 result.push_back( {it->first.sefcond, stock[it->second] );
            it++;
 }
 return result;
    }
}
}

template <typename T>
vector<T> alternate(const vector<T> &v1, const vector<T> &v2) {
    vector<T> output(v1.size() + v2.size());
    int n = max(v1.size(), v2.size()), c = 0;
    for (int i = 0; i < n; ++i) {
        if (i < v1.size())
            output[c++] = v1[i];
        if (i < v2.size())
            output[c++] = v2[i];
    }
    return output;
}

void printGrandfatherGrandson(const vector<string> &name, const vector<pair<string, string>> &parent) {
    map<string, vector<string>> m;
    for (auto &x : parent)
        m[x.first].push_back(x.second);
    for (auto &each : name) {
        bool haveGrandChild = false;
        if (m.find(each) != m.end()) {
            for (auto &child : m[each]) {
                if (m.find(child) != m.end()) {
                    if (!haveGrandChild) {
                        cout << each << " is a grand father with the following grandson(s): ";
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

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {8, 9, 10, 11, 12, 13};
    vector<string> name = {"John", "Jack", "Leo", "Eric", "Robert"};
    vector<pair<string, string>> parent = {{"Leo", "John"}, {"John", "Eric"}, {"John", "Robert"}, {"Robert", "Jack"}};
    map<string, int> m;
    m["abc"] = 2;
    for (auto &x : m)
        cout << x.first;
    // printGrandfatherGrandson(name, parent);
    // vector<int> v3 = alternate(v1, v2);
    // for (auto &x : v3) {
    //     cout << x << " ";
    // }
}