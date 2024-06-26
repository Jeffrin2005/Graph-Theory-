class Solution {
private:
    void bfs(int node, vector<int>& visited, vector<vector<pair<int, int>>>& adj, int& changes) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int nnode = q.front();
            q.pop();
            for (auto& newnode : adj[nnode]){ 
                int neighbour = newnode.first;
                int is_outgoing = newnode.second;
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    if (is_outgoing) {
                        changes++;
                    }
                    q.push(neighbour);
                }
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> visited(n, 0);
        int changes = 0;
        for (auto& edge : connections) {
            adj[edge[0]].push_back({edge[1], 1});  // 1 means outgoing
            adj[edge[1]].push_back({edge[0], 0});  // 0 means incoming
        }
        bfs(0, visited, adj, changes); 
        return changes;
    }
};
