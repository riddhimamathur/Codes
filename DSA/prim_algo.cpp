#include <bits/stdc++.h>
using namespace std;

int primMST(vector<vector<int>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    key[0] = 0;
    int cost = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;
        cost += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    return cost;
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
cout << "MST Cost (Prim) = " << primMST(graph, V) << "\n";
    return 0;
}