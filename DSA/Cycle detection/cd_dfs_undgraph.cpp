//undirected graphs using dfs only 

class Solution {
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited))
                    return true;
            }
            else if (neighbor != parent) {
                // Visited neighbor which is not the parent
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};