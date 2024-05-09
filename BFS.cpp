vector<int> bfsOfGraph(int V, vector<int> adj[]) {

  // adjecent list is already given no need of taking node
         vector<vector<int>>adj(V);
        for(auto&x : edges){
            int u = x.first;
            int v = x.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

  //      BFS
  
         vector<int>vis(V,0);
        vis[0] = 1; 
        queue<int>q;
        q.push(0); 
        
        vector<int>bfs;
        
        while(!q.empty()){
            
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            for(auto&x : adj[node]){
                if(!vis[x]) {
                    vis[x] = 1; 
                    q.push(x); 
                }
            }
        }
        return bfs;
    }
