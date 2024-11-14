class Solution {
    private:
    // Helper DFS function to detect cycle.
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for(auto &neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor, node, adj, visited))
                    return true;
            }
            else if(visited[neighbor]==1 && neighbor != parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
       int V = adj.size();
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
