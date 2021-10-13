#include <bits/stdc++.h>

using namespace std;

vector<int> moving_median(vector<int> &data, int w) {
    vector<int> result;
    for (int i = w / 2; i < data.size() - w / 2; i++) {
        vector<int> tmp(data.begin() + i - w / 2, data.begin() + i + w / 2 + 1);
        for (auto o : tmp)
            cout << o << " ";
        cout << endl;
        std::sort(tmp.begin(), tmp.end());
        result.push_back(tmp[w / 2]);
    }
    return result;
}
class Card {

public:
    string name, color;
    int power;
    Card(string name, string color, int power) {
        name = name;
        color = color;
        power = power;
    }
    bool operator<(const Card &other) const {
        if (color != other.color) {
            if (color == "B")
                return false;
            else if (color == "R")
                return other.color == "B";
            return true;
        }
        if (power != other.power)
            return power < other.power;
        return name < other.name;
    }
};

int main() {
    // you can add more data here
    map<pair<int, pair<int, string>>, int> m;
    map<string, int> keyCode;
    vector<string> code = {"B", "R", "G"};
    keyCode["B"] = 0;
    keyCode["R"] = 1;
    keyCode["G"] = 2;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, color;
        int power;
        cin >> name >> color >> power;
        if (color == "B")
            m[{0, {power, name}}]++;
        else if (color == "R")
            m[{1, {power, name}}]++;
        if (color == "G")
            m[{2, {power, name}}]++;
    }
    //add your code here

    for (auto &card : m) {
        cout << card.first.second.second << " " << code[card.first.first] << " " << card.first.second.first << " = " << card.second << "\n";
    }
}
