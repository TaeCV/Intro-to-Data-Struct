#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <set>
#include <vector>
using namespace std;
class DenseGraph {
public:
    DenseGraph() {
        // Your code here
        n = 3;
        isT = false;
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        isT = false;
    }

    DenseGraph(const DenseGraph &G) {
        // Your code here
        n = G.n;
        isT = G.isT;
        e = G.e;
    }

    void AddEdge(int a, int b) {
        // Your code here
        if (isT) {
            e.insert({b, a});
        } else {
            e.insert({a, b});
        }
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        auto it = isT ? e.find({b, a}) : e.find({a, b});
        if (it != e.end()) {
            if (isT) {
                e.erase(it);
            } else {
                e.erase(it);
            }
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return isT ? e.find({b, a}) != e.end() : e.find({a, b}) != e.end();
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph G(*this);
        G.isT = !isT;
        return G;
    }

protected:
    int n;
    // Your code here
    bool isT;
    set<pair<int, int>> e;
};
#endif // __DENSE_GRAPH_H__
