
class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<int>& dist, int elapsed) {
        if (elapsed >= dist[node]) return; // If the current time is not better, skip
        dist[node] = elapsed;
        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int time = edge.second;
            dfs(neighbor, graph, dist, elapsed + time);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& x : times) {
            graph[x[0]].push_back({x[1], x[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dfs(k, graph, dist, 0); 

        int maxDelay = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            maxDelay = max(maxDelay, dist[i]);
        }
        return maxDelay;
    }
};
