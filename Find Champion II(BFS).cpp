

class Solution {
private:
    void bfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (auto& neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        int found = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, 0);
            bfs(i, graph, visited);
            if (count(visited.begin(), visited.end(), 1) == n) {
                if (found) return -1;
                found = 1;
                ans = i;
            }
        }
        return ans;
    }
};
