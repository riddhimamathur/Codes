#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DSU with Path Compression + Union by Rank
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path Compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // cycle detected

        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    sort(edges.begin(), edges.end()); // sort by weight

    DSU dsu(V);
    int mst_cost = 0;
    vector<Edge> mst_edges;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_cost += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "MST Edges:\n";
    for (auto &e : mst_edges) {
        cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
    }
    cout << "Total MST Weight = " << mst_cost << "\n";

    return 0;
}
