class Solution {
private:
    int dfs(int node, vector<vector<int>>&graph, vector<int>&quiet, vector<int>&ans, vector<bool>&visited){
        if(visited[node]){
            return ans[node];
        }
        visited[node] = 1;
        ans[node] = node;
        for(auto&newnode : graph[node]){
            int candidate = dfs(newnode, graph, quiet, ans , visited);
            if(quiet[candidate] < quiet[ans[node]]){
                ans[node] = candidate;
            }
        }
        return ans[node];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>graph(n);
        vector<int>ans(n, -1);
        vector<bool>visited(n ,0);
        for(auto&edge : richer){
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,graph,quiet, ans ,visited);
            }
        }
        return ans; 
        
    }
};
