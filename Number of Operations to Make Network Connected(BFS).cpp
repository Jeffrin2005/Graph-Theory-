
class Solution {
public:
    void bfs(int start, vector<bool>& visited, const vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; 

        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int components = 0;

        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                bfs(i, visited, graph);
                components++;
            }
        }
        return components - 1;
    }
};
