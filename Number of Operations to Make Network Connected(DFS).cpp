
class Solution {
private:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;  
        for (auto& neighbor : adj[node]) {  
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj); 
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;  

        vector<vector<int>> adj(n);  
        vector<bool> visited(n, 0);
        int components = 0; 
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {  
                dfs(i, visited, adj); 
                components++;  
            }
        }

        return components - 1;  
    }
};
