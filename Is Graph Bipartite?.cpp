class Solution {    
private:
    bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
        color[node] = col;
        for (int it : adj[node]) {
            // If uncolored
            if (color[it] == -1) {
                if (!dfs(it, !col, color, adj))
                    return false;
            }
            // If previously colored and have the same color
            else if(color[it] == col) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1); 
        // Convert graph to adjacency list format
        vector<int> adj[V];
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                adj[i].push_back(graph[i][j]);
            }
        }
        // Check for bipartiteness in each connected component
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, adj))
                    return false;
            }
        }
        return true;
    }
};
