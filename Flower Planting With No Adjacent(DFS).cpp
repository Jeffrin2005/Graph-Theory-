

class Solution {
private:
    void dfs(int garden, vector<vector<int>>& graph, vector<int>& result) {
        bool used[5] = {}; // Track used flowers, index 0 is unused
        // Mark the flowers used by adjacent gardens
        for (int adj : graph[garden]) {
            if (result[adj] != 0) {
                used[result[adj]] = true;
            }
        }
        // Assign the smallest available flower type to the current garden
        for (int flower = 1; flower <= 4; flower++) {
            if (!used[flower]) {
                result[garden] = flower;
                break;
            }
        }

        // Recursively visit each unvisited adjacent garden
        for (int adj : graph[garden]) {
            if (result[adj] == 0) {
                dfs(adj, graph, result);
            }
        }
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (auto& path : paths) {
            // Convert 1-based index to 0-based
            int u = path[0] - 1;
            int v = path[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> result(n, 0); // Result array, initialized to 0 (no flower)
        for (int i = 0; i < n; i++) {
            if (result[i] == 0) { // If garden i has no flower assigned yet
                dfs(i, graph, result);
            }
        }
        return result;
    }
};
