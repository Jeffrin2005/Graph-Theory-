

class Solution {
public:
    int bfs(int start, int target, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int ans = INT_MAX;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < graph[node].size(); i += 2) {
                int v = graph[node][i];     // neighbor
                int dis = graph[node][i+1]; // distance to neighbor
                ans = min(ans, dis);
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n+1);
        for(auto& edge : roads){ 
            graph[edge[0]].push_back(edge[1]); // u -> v
            graph[edge[0]].push_back(edge[2]); // u -> distance to v
            graph[edge[1]].push_back(edge[0]); // v -> u
            graph[edge[1]].push_back(edge[2]); // v -> distance to u
        }

        vector<int> visited(n+1, 0);
        return bfs(1, n, graph, visited);
    }
};
