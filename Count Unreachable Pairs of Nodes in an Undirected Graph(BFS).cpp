#include <bits/stdc++.h>
#define ll long long 
class Solution {
private:
    int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int size = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            size++;
            for (int newnode : graph[node]) {
                if (!visited[newnode]) {
                    visited[newnode] = true;
                    q.push(newnode);
                }
            }
        }
        return size;
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
                component_sizes.push_back(bfs(i, graph, visited));
            }
        }

        ll total_pairs = 0;
      ll sum_size = 0;
        for (auto&size : component_sizes) {
            total_pairs += sum_size * size;
            sum_size += size;
        }

        return total_pairs;
    }
};
