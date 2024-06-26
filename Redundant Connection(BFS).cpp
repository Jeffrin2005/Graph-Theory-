class Solution {
public:
    int n;

    bool bfs(vector<vector<int>>& adj, int start, int end, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = 1 ; 
            if(curr == end){
                return 1;  
            }
            for(auto&newnode  : adj[curr]) {
                if (!visited[newnode]) {
                    visited[newnode] = 1; 
                    q.push(newnode);
                }
            }
        }

        return 0;  // No path found, no cycle with this edge
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, 0);
        for (auto& edge : edges) {
            fill(visited.begin(), visited.end(), 0);  // reseting the visited array to 0 ,bcoz for each edge we already marked so we not remove that for the new node 
            // Check if adding this edge creates a cycle
            if (!adj[edge[0]].empty() && !adj[edge[1]].empty() && bfs(adj, edge[0], edge[1], visited)) {
                return edge;
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return {};  
    }
};
