

class Solution {
private:
    void dfs(int current,vector<vector<int>>& adj,vector<int>& ancestors,vector<bool>& visited) {
        visited[current] = true;
        for (auto& newnode : adj[current]) {
            if (!visited[newnode]) {
                ancestors.push_back(newnode);
                dfs(newnode, adj, ancestors, visited);
            }
        }
    }
public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
        // Reversing the edge
        for (auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }
       vector<vector<int>> ancestors(n);
        for (int i = 0; i < n; i++) {
           vector<bool> visited(n, 0);
            dfs(i, adj, ancestors[i], visited);
            sort(ancestors[i].begin(), ancestors[i].end());
        }
        return ancestors;
    }
};
