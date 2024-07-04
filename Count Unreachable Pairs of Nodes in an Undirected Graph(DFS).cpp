#include <bits/stdc++.h>
#define ll long long 
class Solution {
private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& size) {
        visited[node] = 1;
        size++;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, size);
            }
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> component_sizes;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = 0;
                dfs(i, graph, visited, size);
                component_sizes.push_back(size);
            }
        }

        ll total_pairs = 0;
        ll sum_size = 0;
        for (int size : component_sizes) {
            total_pairs += sum_size * size;
            sum_size += size;
        }

        return total_pairs;
    }
};
