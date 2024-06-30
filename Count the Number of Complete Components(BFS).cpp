
class Solution {
private:
    void bfs(int start, std::vector<std::vector<int>>& adj, std::vector<int>& visited, int& edgecount, int& vertices_count) {
        std::queue<int> q;
        q.push(start);
        visited[start] = 1;
        vertices_count++;

        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& newnode : adj[node]) {
                if (!visited[newnode]) {
                    visited[newnode] = 1;
                    vertices_count++;
                    q.push(newnode);
                }
                edgecount++;
            }
        }
        edgecount /= 2; 
    }

public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<int> visited(n, 0);
        int ans = 0;

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int edgecount = 0;
                int vertices_count = 0;
                bfs(i, adj, visited, edgecount, vertices_count);
                if (vertices_count * (vertices_count - 1) / 2 == edgecount) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
