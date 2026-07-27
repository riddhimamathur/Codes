#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    for (int i = 0; i < V; i++) parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

    int cost = 0;
    cout << "Edges in MST (Kruskal):\n";
    for (auto &e : edges) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            cout << e.u << " - " << e.v << " (" << e.w << ")\n";
            cost += e.w;
        }
    }
    cout << "Total Cost = " << cost << "\n";
}
