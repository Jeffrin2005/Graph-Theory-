 public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int>adj[], vector<int>&vis, vector<int>&ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto&x : adj[node]){
            if(!vis[x]){
              dfs(x,adj,vis,ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code 
        vector<int>vis(V,0);
        int start = 0;
        vector<int>ls; 
        dfs(start, adj, vis, ls); 
        return ls; 
    }
