#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cout << std::fixed << std::setprecision(2);
    int n, score;
    string sid, teacher;
    map<string, int[2]> smap, tmap;
    cin >> n;
    while (n--) {
        cin >> sid >> teacher >> score;
        smap[sid][0] += score;
        smap[sid][1]++;
        tmap[teacher][0] += score;
        tmap[teacher][1]++;
    }
    for (auto &x : smap) {
        cout << x.first << " " << (x.second[0] + 0.0) / x.second[1] << endl;
    }
    for (auto &x : tmap) {
        cout << x.first << " " << (x.second[0] + 0.0) / x.second[1] << endl;
    }
}