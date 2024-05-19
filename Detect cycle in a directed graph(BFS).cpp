 public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
	    for(int i=0; i<V; i++){
	        for(auto&x : adj[i]){
	            indegree[x]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    int cnt =0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        for(auto&x : adj[node]){
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    if(cnt == V) return false;
	    return true;
	    
    }
