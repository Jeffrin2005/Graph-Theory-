class Solution {
private: 
    void dfs(int node, vector<vector<int>>&adjLs,vector<int>&vis){
        vis[node] = 1;
        for(auto&x : adjLs[node]){
            if(!vis[x]){
                dfs(x,adjLs,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>&adj) {
        int V = adj.size();
        vector<vector<int>>adjLs(V); 
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 and i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        vector<int>vis(V, 0); 
        int cnt = 0; 
        for(int i = 0; i < V; i++){
            if(!vis[i]){ 
                cnt++;
                dfs(i,adjLs,vis); 
            }
        }
        return cnt; 
    }
};
