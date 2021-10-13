#include <map>
#include <queue>
#include <string>

using namespace std;

class inside_building {
private:
    map<string, pair<queue<pair<string, int>>, map<string, int>>> members_in_buildings; //

public:
    int get_time() {
        return 0;
    }

    void check_in(string building, string name) {
        members_in_buildings[building].first.push({name, get_time()});
        members_in_buildings[building].second[name] = get_time();
    }

    void check_out(string building, string name) {
        members_in_buildings[building].second.erase(name);
    }

    int how_many(string building) {
        int checking_time = get_time() - 7200;
        while (members_in_buildings[building].first.front().second > checking_time) {
            if (members_in_buildings[building].second.find(members_in_buildings[building].first.front().first) != members_in_buildings[building].second.end() && members_in_buildings[building].second[members_in_buildings[building].first.front().first] == members_in_buildings[building].first.front().second) {
                members_in_buildings[building].second.erase(members_in_buildings[building].first.front().first);
            }
            members_in_buildings[building].first.pop();
        }
        return members_in_buildings[building].second.size();
    }
};