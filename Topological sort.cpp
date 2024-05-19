	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    vector<int>topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto&x : adj[node]){
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    return topo;
	    // code here
	}
