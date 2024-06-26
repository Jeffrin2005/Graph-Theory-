#include <vector>

using namespace std;

class Solution {
public:
    int n;

    bool dfs(vector<vector<int>>& adj, int current, int target, vector<bool>& visited) {
         visited[current] = 1;  // Mark the current node as visited
        if (current == target) {
            return true; 
        }
        for (auto& neighbor : adj[current]) {
            if (!visited[neighbor]) {
                if (dfs(adj, neighbor, target, visited)) {
                    return 1;  // If DFS from neighbor finds the target, return true
                }
            }
        }
        return 0;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<vector<int>> adj(n + 1); 
        vector<bool> visited(n + 1, 0); 
        for (auto&edge : edges) {
            fill(visited.begin(), visited.end(), false);  // Reset visited array for each edge check
            if (!adj[edge[0]].empty() && !adj[edge[1]].empty() && dfs(adj, edge[0], edge[1], visited)) {
                return edge;  
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return {};  
    }
};
