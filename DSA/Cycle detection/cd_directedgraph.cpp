//using dfs+recusion stack
#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recStack) {
    if (recStack[u]) return true;       // cycle detected
    if (visited[u]) return false;       // already explored

    visited[u] = true;
    recStack[u] = true;

    for (int v : adj[u]) {
        if (dfsCycle(adj, v, visited, recStack)) return true;
    }

    recStack[u] = false;  // backtrack
    return false;
}

bool isCyclic(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false), recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfsCycle(adj, i, visited, recStack))
            return true;
    }
    return false;
}

int main() 
{
    vector<vector<int>> adj = {{1}, {2}, {0, 3}, {}};
    cout << (isCyclic(adj) ? "Cycle Found" : "No Cycle") << endl;
}
