

class Solution {
private:
    void bfs(int start, std::vector<std::vector<int>>& adj, std::vector<int>& ancestors, std::vector<bool>& visited) {
        std::queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (auto& newnode : adj[current]) {
                if (!visited[newnode]) {
                    visited[newnode] = true;
                    ancestors.push_back(newnode);
                    q.push(newnode);
                }
            }
        }
    }

public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        /// reversing the edge 
        for (auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }
        std::vector<std::vector<int>> ancestors(n);
        for (int i = 0; i < n; i++) {
            std::vector<bool> visited(n, false);
            bfs(i, adj, ancestors[i], visited);
            sort(ancestors[i].begin(), ancestors[i].end());
        }
        return ancestors;
    }
};
