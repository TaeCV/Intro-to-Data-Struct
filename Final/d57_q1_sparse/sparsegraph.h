#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <bits/stdc++.h>

using namespace std;

class SparseGraph {
public:
    SparseGraph() {
        // Your code here
        V = 3;
        isT = false;
    }

    SparseGraph(int n_in) {
        // Your code here
        V = n_in;
        isT = false;
    }

    SparseGraph(const SparseGraph &G) {
        // Your code here
        V = G.V;
        isT = G.isT;
        adj = G.adj;
    }

    void AddEdge(int a, int b) {
        // Your code here
        if (!isT) {
            adj.emplace(a, b);
        } else {
            adj.emplace(b, a);
        }
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if (!isT) {
            if (DoesEdgeExist(a, b)) {
                adj.erase({a, b});
            }
        } else {
            if (DoesEdgeExist(b, a)) {
                adj.erase({b, a});
            }
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return isT ? adj.find({b, a}) != adj.end() : adj.find({a, b}) != adj.end();
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph G(*this);
        G.isT = !isT;
        return G;
    }

public:
    // Your code here
    int V;
    bool isT;
    std::set<pair<int, int>> adj;
};
#endif // __SPARSE_GRAPH_H__
