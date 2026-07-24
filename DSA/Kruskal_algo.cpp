#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }
    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};

int main() {
    int V = 4, E = 5;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

    DSU dsu(V);
    int cost = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mst.push_back(e);
            cost += e.w;
        }
    }

    cout << "MST Cost = " << cost << "\n";
    cout << "Edges in MST:\n";
    for (auto &e : mst) {
        cout << e.u << " - " << e.v << " (" << e.w << ")\n";
    }
    return 0;
}
