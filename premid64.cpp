#include <map>
#include <queue>
#include <string>

using namespace std;

class inside_building {
private:
    map<string, pair<queue<pair<string, int>>, map<string, int>>> members_in_buildings;

public:
    void check_in(string building, string name) {
    }

    void check_out(string building, string name) {
    }

    int how_many(string building) {
    }
};