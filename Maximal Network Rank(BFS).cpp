

class Solution {
private:
    void bfs(int start, vector<bool>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (auto& neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        int maxi = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = adj[i].size() + adj[j].size();
                if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    val--; 
                }
                maxi = max(maxi, val);
            }
        }

        return maxi;
    }
};
