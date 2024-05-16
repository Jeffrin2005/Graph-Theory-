  private:
     void dfs(int node, vector<int>&vis,stack<int>&st,vector<int>adj[]){
         vis[node] = 1;
         for(auto&x : adj[node]){
             if(!vis[x]) dfs(x,vis,st,adj);
         }
         st.push(node);
     }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    vector<int>ans;
	   while(!st.empty()){
         ans.push_back(st.top());
            st.pop();
        }
	    return ans;
	    // code here
	}
