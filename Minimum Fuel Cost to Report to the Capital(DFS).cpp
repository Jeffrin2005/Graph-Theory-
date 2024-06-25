#include <bits/stdc++.h>
#define ll long long 
class Solution {
private:
    int dfs(int node, vector<vector<int>>&adj, vector<int>&visited, ll &ans, int &seats, vector<int>&node_count){
            visited[node] = 1;
            ll total = 1;
            for(auto&newnode : adj[node]){
                if(!visited[newnode]){
                    total+=dfs(newnode, adj, visited, ans , seats, node_count);
                }
            }
            node_count[node] = total;
            if(node != 0){
               int temp = (total + seats - 1) / seats; 
                ans+=temp;
            }
            return total; 
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>>adj(n);
        vector<int>visited(n, 0);
        vector<int>node_count(n, 0 );
        for(auto&edge : roads){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        ll ans=0;   
        dfs(0, adj, visited, ans , seats,node_count);

        return ans; 
        
    }
};
